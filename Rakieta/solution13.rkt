#lang typed/racket
(struct const    ([val : (U Number Boolean 'false 'true)])            #:transparent)
(struct binop    ([op : Symbol] [l : Expr] [r : Expr])   #:transparent)
(struct var-expr ([id : Symbol])                         #:transparent)
(struct let-expr ([id : Symbol] [e1 : Expr] [e2 : Expr]) #:transparent)
(struct if-expr  ([eb : Expr] [et : Expr] [ef : Expr]) #:transparent)

(define-type Expr (U const binop var-expr let-expr if-expr))
(define-type Binop-sym (U '+ '- '* '/ '= '> '< '>= '<= 'and 'or))
(define-type Ide Symbol)
(define-predicate ide? Ide)
(define-predicate expr? Expr)
(define-predicate binop-sym? Binop-sym)
(define-type  EType (U 'real 'boolean))
(provide typecheck parse)

(: parse (-> Any Expr))
(define (parse q)
  (match q
    [_ #:when (or (number? q) (boolean? q) (eq? q 'true) (eq? q 'false))
       (const q)]
    [_ #:when (ide? q)
       (var-expr q)]
    [`(,op ,e1 ,e2) #:when (binop-sym? op)
                    (binop op
                           (parse e1)
                           (parse e2))]
    [`(let (,x ,e1) ,e2) #:when (ide? x)
                         (let-expr x 
                                   (parse e1)
                                   (parse e2))]
    [`(if ,f ,e1 ,e2)
     (if-expr (parse f) 
              (parse e1)
              (parse e2))]))

(define-type Value (U Real Boolean))
(define-type Env (Listof (Pairof Symbol EType)))

(: env-empty Env)
(define env-empty null)

(: env-add (-> Symbol EType Env Env))
(define (env-add x v env)
  (cons (cons x v) env))
   
(: env-lookup (-> Symbol Env EType))  
(define (env-lookup x env)
  (: assoc-lookup (-> Env EType))
  (define (assoc-lookup xs)
    (cond [(null? xs) (error "Unknown identifier" x)]
          [(eq? x (car (car xs))) (cdr (car xs))]
          [else (assoc-lookup (cdr xs))]))
  (assoc-lookup  env))
;(: op->proc (-> Symbol (-> Value Value Value)))
;(define (op->proc op)
;(let ([f (match op ['+ +] ['- -] ['* *] ['/ /] ['< <] ['> >] ['<= <=] ['>= >=] ['= =] ['and (lambda (x y) (and x y))] ['or  (lambda (x y) (or  x y))])])
;(lambda (x y) 
; (if (and (number? x) (number? y))
;     (f x y)
; (error "Type mismatch")))))
(: typecheck-e (-> Expr Env (U EType #f)))
(define (typecheck-e e env)
  (match e
    [(const n) (if (real? n) 'real (if (boolean? n) 'boolean (if (or (eq? n 'true) (eq? n 'false)) 'boolean #f)))]
    [(binop op l r) 
     (if (and (eq? 'real (typecheck-e l env)) (eq? 'real (typecheck-e r env)))
         (match op
           ['+ 'real] ['- 'real] ['* 'real] ['/ 'real] ['< 'boolean] ['> 'boolean] ['<= 'boolean] ['>= 'boolean] ['= 'boolean] [_ #f])
         (if (and (eq? 'boolean (typecheck-e l env)) (eq? 'boolean (typecheck-e r env))) (match op ['and 'boolean] ['or 'boolean] [_ #f]) #f))]
    [(let-expr y e3 e4)
     (let ([f (typecheck-e e3 env)])
       (if (not f)
           #f
           (let ([env-new (env-add y f env)]) (typecheck-e e4 env-new))))]
    [(var-expr v) (env-lookup v env)]
    [(if-expr f e1 e2)
     (if (eq? (typecheck-e f env) 'boolean)
         (if (eq? (typecheck-e e1 env) (typecheck-e e2 env))
             (typecheck-e e1 env)
             #f)
         #f)]))

(: typecheck (-> Expr (U EType #f)))
(define (typecheck e)
  (typecheck-e e env-empty))

(typecheck (parse '(and true false)))
(typecheck (parse '(or true false)))
(typecheck (parse '(* (+ 1 2) 1)))
(typecheck (parse '(- (+ 1 2) 1)))
(typecheck (parse '(+ (+ 1 2) 1)))
(typecheck (parse '(/ (+ 1 true) 1)))
(typecheck (parse '(let (x 1) x)))
(typecheck (parse '(if (= 1 1) 2 1)))

;W kooperacji z Kacperem Bajkiewiczem i Kacperm Gawdzińskim