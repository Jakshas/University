#lang typed/racket
;;;  boolean.rkt 
; Do let-env.rkt dodajemy wartosci boolowskie
;
; Miejsca, ktore sie zmienily oznaczone sa przez !!!

; --------- ;
; Wyrazenia ;
; --------- ;

(struct const    ([val : Val])      #:transparent)
(struct binop    ([op : Symbol] [l : Expr] [r : Expr])   #:transparent)
(struct var-expr ([id : Symbol])       #:transparent)
(struct let-expr ([id : Symbol] [e1 : Expr] [e2 : Expr]) #:transparent)
(struct if-expr  ([eb : Expr] [et : Expr] [ef : Expr]) #:transparent)
(define-type Val (U Boolean Number))
(define-type Expr (U const binop var-expr let-expr if-expr))
(: expr? (-> Any Boolean))
(define (expr? e)
  (match e
    [(const n) (or (number? n) (boolean? n))] ; <----------------- !!!
    [(binop op l r) (and (symbol? op) (expr? l) (expr? r))]
    [(var-expr x) (symbol? x)]
    [(let-expr x e1 e2)
     (and (symbol? x) (expr? e1) (expr? e2))]
    [(if-expr eb et ef) ; <--------------------------------------- !!!
     (and (expr? eb) (expr? et) (expr? ef))]
    [_ false]))


(: parse (-> (U (Listof Symbol) 'true 'false Number) Expr))
(define (parse q)
  (cond
    [(number? q) (const q)]
    [(eq? q 'true)  (const true)]  ; <---------------------------- !!!
    [(eq? q 'false) (const false)] ; <---------------------------- !!!
    [(symbol? q) (var-expr q)]
    [(and (list? q) (eq? (length q) 3) (eq? (first q) 'let))
     (let-expr (first (second q))
               (parse (second (second q)))
               (parse (third q)))]
    [(and (list? q) (eq? (length q) 4) (eq? (first q) 'if)) ; <--- !!!
     (if-expr (parse (second q))
              (parse (third q))
              (parse (fourth q)))]
    [(and (list? q) (eq? (length q) 3) (symbol? (first q)))
     (binop (first q)
            (parse (second q))
            (parse (third q)))]))

;;; (define (test-parse) (parse '(let [x (+ 2 2)] (+ x 1))))

; ---------- ;
; Srodowiska ;
; ---------- ;

(define-type Env (Listof (Pairof Symbol Val)))


(: env-empty Env)
(define env-empty null)

(: env-add (-> Symbol Val Env Env))
(define (env-add x v env)
   (cons (cons x v) env))
   
(: env-lookup (-> Symbol Env Val))  
(define (env-lookup x env)
  (: assoc-lookup (-> Env Val))
  (define (assoc-lookup xs)
    (cond [(null? xs) (error "Unknown identifier" x)]
          [(eq? x (car (car xs))) (cdr (car xs))]
          [else (assoc-lookup (cdr xs))]))
  (assoc-lookup  env))

; --------- ;
; Ewaluacja ;
; --------- ;

(: op->proc (-> Symbol (-> Val Val Val))) 
(define (op->proc op)
  (match op ['+ +] ['- -] ['* *] ['/ /] ['% modulo] ; <----------- !!!
            ['= =] ['> >] ['>= >=] ['< <] ['<= <=]
            ['and (lambda (x y) (and x y))]
            ['or  (lambda (x y) (or  x y))]))

(: eval-env (-> Expr Env Val))
(define (eval-env e env)
  (match e
    [(const n) n]
    [(binop op l r) ((op->proc op) (eval-env l env)
                                   (eval-env r env))]
    [(let-expr x e1 e2)
     (eval-env e2 (env-add x (eval-env e1 env) env))]
    [(var-expr x) (env-lookup x env)]
    [(if-expr eb et ef) (if (eval-env eb env) ; <----------------- !!!
                            (eval-env et env)
                            (eval-env ef env))]))
(: eval (-> Expr Val))
(define (eval e) (eval-env e env-empty))

;;; (define program
;;;   '(if (or (< (% 123 10) 5)
;;;            true)
;;;        (+ 2 3)
;;;        (/ 2 0)))

;;; (define (test-eval) (eval (parse program)))
