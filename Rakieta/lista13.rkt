#lang typed/racket

;;; zadanie1

(: prefixes (All (a) (->(Listof a) (Listof (Listof a)))))
(define (prefixes xs)
    (if (null? xs)
        (list null)
        (cons xs (prefixes (reverse (cdr (reverse xs)))))))

(prefixes '(1 2 3 4))

;;; zadanie2

(struct vector2  ([x : Real] [y : Real]) )
(struct vector3  ([x : Real] [y : Real] [z : Real]))


(define-type Vector (U vector2 vector3))


(: vector-length (-> Vector Number))
(define (vector-length vec)
(match vec
    [(vector2 x y)   
        (sqrt (+ (expt x 2) (expt y 2)))]
    [(vector3 x y z) 
        (sqrt (+ (expt x 2) (expt y 2) (expt z 2)))]))

(: vector-length1 (-> Vector Number))
(define (vector-length1 vec)
(cond
    [(vector2? vec) 
        (sqrt (+ (expt (vector2-x vec) 2) (expt (vector2-y vec) 2)))]
    [else 
        (sqrt (+ (expt (vector3-x vec) 2) (expt (vector3-y vec) 2) (expt (vector3-z vec) 2)))]))
 ;zadanie3

; foldr +  "0" [1 2 3 4] -> foldr + (+ 0 1) [2 3 4]
; foldr (lambda (x) (string-append (number->string x))
; foldr 0 + (1 2 3 4) ----> (1 + (2 + 3 + (4 + 0)))

;;; (: foldr (All (a b) (-> (-> a b b) b (Listof a) b)))
;;; (define (foldr op zero l)
;;;     (op (car l) (foldr op zero (cdr l)))

;zadanie 4

(define-type Leaf 'leaf)
(define-type (Node a) (List 'node a (Listof (Tree a))))
(define-type (Tree a) (U Leaf (Node a)))

(define-predicate leaf? Leaf)
(define-predicate node? (Node Any))
(define-predicate tree? (Tree Any))

(: leaf Leaf)
(define leaf 'leaf)

(: node-val (All [a] (-> (Node a) a)))
(define (node-val x)
  (cadr x))


(: make-node (All [a] (-> a (Listof (Tree a)) (Node a))))
(define (make-node v xs)
  (list 'node v xs))

(: print-values (All [a] (-> (Tree a) (Listof a))))
(define (print-values tree)
    (: aux (All [a] (-> (Listof (Tree a)) (Listof a))))
    (define (aux xs)
        (if (null? xs)
            null
            (append (print-values (car xs)) (aux (cdr xs)) )))
    (if (leaf? tree)
        null
        (cons (second tree) (aux (third tree)))))

(print-values (make-node -2 
        (list (make-node 0 (list (make-node -10 null) (make-node -20 null))) 
              (make-node 1 null))))

;;; Zadanie 5
;;; arith.rkt  z wykladu nr 6
(define-type Expr (U binop const))
(struct const ([val : Number])    #:transparent)
(struct binop ([op : Symbol] [l : Expr] [r : Expr]) #:transparent)

; 2 + 2 * 2
(: 2+2*2 Expr)
(define 2+2*2 (binop '+ (const 2)
                        (binop '* (const 2)
                                  (const 2))))

; Co to są wyrażenia?
(: expr? (-> Any Boolean))
(define (expr? e)
  (match e
    [(const n) (number? n)]
    [(binop op l r) (and (symbol? op) (expr? l) (expr? r))]
    [_ false]))

; Co to są wartości?
(: value? (-> Any Boolean))
(define (value? v)
  (number? v))

(: op->proc (-> Symbol (-> Number Number Number)))
(define (op->proc op)
  (match op ['+ +] ['- -] ['* *] ['/ /]))

(: eval (-> Expr Number))
(define (eval e)
  (match e
    [(const n) n]
    [(binop op l r) ((op->proc op) (eval l) (eval r))]))

; ------------------------- ;
; Trochę składni konkretnej ;
; ------------------------- ;
(: parse (-> (Listof Symbol) Expr))
(define (parse q)
  (cond [(number? q) (const q)]
        [(and (list? q) (eq? (length q) 3) (symbol? (first q)))
         (binop (first q) (parse (second q)) (parse (third q)))]))

