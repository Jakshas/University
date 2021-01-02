#lang racket

; --------------------- ;
; Składnia abstrakcyjna ;
; --------------------- ;
(struct abs (x)        #:transparent)
(struct const (val)    #:transparent)
(struct binop (op l r) #:transparent)
(struct variable ()    #:transparent)
(struct d (fun)        #:transparent)

; 2 + 2 * 2
(define 2+2*2 (binop '+ (const 2)
                        (binop '* (const 2)
                                  (const 2))))

; Co to są wyrażenia?
(define (expr? e)
  (match e
    [(variable) true]
    [(abs x) (expr? x)]
    [(const n) (number? n)]
    [(binop op l r) (and (symbol? op) (expr? l) (expr? r))]
    [_ false]))

; Co to są wartości?
(define (value? v)
  (number? v))

(define (op->proc op)
  (match op ['+ +] ['- -] ['* *] ['/ /] ['^ expt]))



; abstrakcyjna

;;; (binop '+ 
;;;         (const 1)
;;;         (binop '+ (const 2)
;;;                   (binop '+ (binop '*  (const 3) 
;;;                                         (const 4))
;;;                              (const 5))))

; Zadanie 2
(define (square x) (* x x))

(define (cont-frac num den k)
  (define (frac i)
    (if (< i k)
        (binop '/ (const (num i))  (binop '+ (const (den i)) (frac (+ i 1))))
        (binop '/ (const (num i))  (const (den i)))))
  (frac 1))

(define (count-pi-v2 approximation-level)
  (define (num k)
    (if (= k 1)
        1.0
        (square (- (* 2 k) 1))))
  (define (den k)
    6)
  (binop '+ (const 3) (cont-frac num den approximation-level)))

;;; (eval (count-pi-v2 4))

; Zadanie 3

;;; (eval (abs -10))
;;; (eval (binop '^ (const 2) (const 5)))

;;Zadanie 4
;;wersja prostsza
(define (pretty-print2 e)
  (match  e
    [(const n) (number->string n)]
    [(abs arg) (string-append "|" (pretty-print arg) "|")]
    [(binop op l r) (string-append "(" (pretty-print l) " "
                                   (symbol->string op) " "
                                   (pretty-print r) ")")])) 

(define (pretty-print e)
  (define (aux op e)
  (cond
    [(or (abs? e) (const? e) (variable? e)) (pretty-print e)]
    [(and (binop? e) (eq? op (binop-op e))) (pretty-print e)]
    [else (string-append " ( " (pretty-print e) " ) ")]))
  
  (match  e
    [(const n) (number->string n)]
    [(variable) symbol->string "x"]
    [(abs arg) (string-append "|" (pretty-print arg) "|")]
    [(binop op l r) (string-append  (aux op l) " "
                                   (symbol->string op) " "
                                   (aux op r))]))

;;Wskazówka: do wersji trudniejszej skorzystać z łączności operatorów

; 2 + ((3 + 5) + 6)
; (2 + 3) + 5 
; 2 + 3 + 5
; 2 ^ (3 ^ 4) 
; (2 ^ 3) ^ 4
; 2 ^ 3 ^ 4
;;; (pretty-print2 (count-pi-v2 4)) 
;;; (pretty-print (count-pi-v2 4)) 
;;; (pretty-print (binop '+ (const 1) (binop '+ (const 2) (binop '+ (const 3) (const 4)))) ) 

;;Zadanie 5
(define (∂ f) ;  D(f(x) ^ g(x))  = D(log((E ^ f(x)) ^ g(x))) = D(log (E ^ (f * g)) )
 (match f
    [(const n)      (const 0)]
    [(variable)     (const 1)]
    [(binop '+ g h) (binop '+ (∂ g) (∂ h))]
    [(binop '* g h) (binop '+ (binop '* (∂ g) h)
                              (binop '* g (∂ h)))]))


(define (parse q)
  (cond [(number? q) (const q)]
        [(eq? q 'x) (variable)]
        [(and (list? q) (eq? (length q) 2) (eq? 'd (first q)))
          (d (parse (second q)))]
        [(and (list? q) (eq? (length q) 3) (symbol? (first q)))
         (binop (first q) (parse (second q)) (parse (third q)))]))

(define (eval e x)
  (define (der e)
    (match e
      [(d fun) (∂ (der fun))]
      [(binop op l r) (binop op (der l) (der r))]
      [(const n) (const n)]
      [(variable) (variable)]))
    (define (compute e)
      (match e
        [(variable) x]
        [(const n)  n]
        [(binop op l r) ((op->proc op) (compute l) (compute r))]))
  (compute (der e)))

(eval (parse '(d (+ x (d (* x (* x x)))))) 10)

; x ^ x
; x ^ x ^ x


(define (aux op exp)
  (cond
    [(equal? op '+) (simpl-sum exp)]
    [(equal? op '*) (simpl-product exp)]))

(define (simpl exp)
  (match exp
    [(const n) exp]
    [(variable) exp]
    [(binop op l r) (aux op exp) ]))

(define (binop-merge l r)
  (cond
    [(equal? (binop-l l) (binop-l r)) (binop '* (binop-l l) (binop '+ (binop-r l) (binop-r r)))]
    [(equal? (binop-r l) (binop-r r)) (binop '* (binop-r l) (binop '+ (binop-l l) (binop-l r)))]
    [(equal? (binop-l l) (binop-r r)) (binop '* (binop-l l) (binop '+ (binop-r l) (binop-l r)))]
    [(equal? (binop-r l) (binop-l r)) (binop '* (binop-r l) (binop '+ (binop-l l) (binop-r r)))]
    [else (binop '+ l r)]))

(define (merge exp x)
  (cond
    [(and (equal? '+ (binop-op exp)) (const? x) t? e) (variable? e)) (pretty-print e)]
    [(and (binop? e) (eq? op (binop-op e))) (pretty-print e)]
    [else (string-append " ( " (pretty-print e) " ) ")]))
  
  (match  e
    [(const n) (number->string n)]
    [(variable) symbol->string "x"]
    [(abs arg) (string-append "|" (pretty-print arg) "|")]
    [(binop op l r) (string-ap(const? (binop-l exp))) (binop '+ (const (+ (const-val x) (const-val (binop-l exp)))) (binop-r exp))]
    [(and (equal? '+ (binop-op exp)) (const? x) (const? (binop-r exp))) (binop '+ (const (+ (const-val x) (const-val (binop-r exp)))) (binop-l exp))]  
    [(equal? (binop-l exp) x) (binop '* (binop-l exp) (binop '+ (const 1) (binop-r exp)))]
    [(equal? (binop-r exp) x) (binop '* (binop-r exp) (binop '+ (const 1) (binop-l exp)))]
    [else (binop '+ exp x)]))


(define (simpl-merge l r)
  (cond
    [(and (binop? l) (binop? r)) (binop-merge l r)]
    [(binop? l) (merge l r)]
    [(binop? r) (merge r l)]))


(define (simpl-sum exp)
  (let* ((op (binop-op exp)) (l (binop-l exp)) (r (binop-r exp)) (a (simpl l)) (b (simpl r)))
    (cond [(and (const? a) (= 0 (const-val a))) b]
          [(and (const? b) (= 0 (const-val b))) a]
          [(and (const? a) (const? b)) (const (+ (const-val a) (const-val b)))]
          [(and (variable? a) (variable? b)) (binop '* (const 2) (variable))]
          [(or (binop? a) (binop? b)) (simpl (simpl-merge a b))]
          [else (binop op a b)])))

(define (simpl-product exp) 
  (let* ((op (binop-op exp)) (l (binop-l exp)) (r (binop-r exp)) (a (simpl l)) (b (simpl r)))
    (cond [(and (const? a) (= 1 (const-val a))) b]
          [(and (const? b) (= 1 (const-val b))) a]
          [(and (const? a) (const? b)) (const (* (const-val a) (const-val b)))]
          [else (binop op a b)])))
