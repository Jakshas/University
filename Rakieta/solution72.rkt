#lang racket
(provide expr? parse env-empty env-add env-lookup env-delete find-dead-vars)
(provide (struct-out const) (struct-out binop) (struct-out var-expr) (struct-out let-expr) (struct-out var-dead) find-dead-vars)
; --------- ;
; Wyrazenia ;
; --------- ;

(struct const    (val)      #:transparent)
(struct binop    (op l r)   #:transparent)
(struct var-expr (id)       #:transparent)
(struct var-dead (id)       #:transparent)
(struct let-expr (id e1 e2) #:transparent)

(define (expr? e)
  (match e
    [(const n) (number? n)]
    [(binop op l r) (and (symbol? op) (expr? l) (expr? r))]
    [(var-expr x) (symbol? x)]
    [(var-dead x) (symbol? x)]
    [(let-expr x e1 e2) (and (symbol? x) (expr? e1) (expr? e2))]
    [_ false]))

(define (parse q)
  (cond
    [(number? q) (const q)]
    [(symbol? q) (var-expr q)]
    [(and (list? q) (eq? (length q) 3) (eq? (first q) 'let))
     (let-expr (first (second q))
               (parse (second (second q)))
               (parse (third q)))]
    [(and (list? q) (eq? (length q) 3) (symbol? (first q)))
     (binop (first q)
            (parse (second q))
            (parse (third q)))]))

; ---------------------------------- ;
; Wyszukaj ostatnie uzycie zmiennych ;
; ---------------------------------- ;
(struct environ (xs))

(define env-empty (environ null))
(define (env-add x env)
  (environ (cons x (environ-xs env))))
(define (env-lookup x env)
  (define (assoc-lookup xs)
    (cond [(null? xs) #f]
          [(eq? x (car  xs)) #t]
          [else (assoc-lookup (cdr xs))]))
  (assoc-lookup (environ-xs env)))

(define (env-delete x env)
  (define (assoc-lookup xs env1)
    (cond [(null? xs) env1]
          [(eq? x (car xs))(assoc-lookup (cdr xs) env1)]
          [else (assoc-lookup (cdr xs) (env-add (car  xs) env1))]))
  (assoc-lookup (environ-xs env) env-empty))

(define (find-dead-vars formula)
  (define (rename-f formula env)
    (match formula
      [(const n) (list (const n) env)]
      [(var-expr x) (if (not (env-lookup x env))
                        (cons (var-dead x)(env-add x env))
                        (cons (var-expr x) env))]
      [(binop op l r) (let* ([right (rename-f r env)]
                             [left (rename-f l (cdr right))])
                          (cons  (binop op (car left) (car right))(cdr left)))]
      [(let-expr x ex1 ex2) (let* ([new-ex2 (rename-f ex2 env)]
                                   [new-env (env-delete x (cdr new-ex2))]
                                   [new-ex1 (rename-f ex1 new-env)])
                (cons (let-expr x (car new-ex1) (car new-ex2)) new-env))]))
(car (rename-f formula env-empty)))

;(find-dead-vars (let-expr 'x (const  3)(binop'+ (var-expr'x) (var-expr'x))))
(find-dead-vars (let-expr 'x (const  3)(binop'+ (var-expr'x)(let-expr 'x (const  5)(binop'+ (var-expr'x)(var-expr'x))))))
; mozesz tez oczywiscie dopisac tu jakies procedury
(let-expr 'x (const 3)
          (binop '+ (var-dead 'x)
                 (let-expr 'x (const 5)
                           (binop '+ (var-expr 'x)
                                  (var-dead 'x)))))