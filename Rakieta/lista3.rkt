#lang racket

(define(display-point p)
  (display "(")
  (display (x-point p))
  (display ", ")
  (display (y-point p))
  (display ")"))
(define(display-vect v)
  (display "[")
  (display-point (vect-begin v))
  (display ", ")
  (display-point (vect-end v))
  (display "]"))


(define make-point cons)
(define x-point car)
(define y-point cdr)

(define (point? p)
    (and (pair? p) (number? (x-point p)) (number? (y-point p)) ))

(define (make-vector x1 y1 x2 y2) 
  (cons (make-point x1 y1) (make-point y1 y2)) )

(define vector-begin car)
(define vector-end cdr)

(define (vector? v)
    (and (pair? v) (point? (car v)) (point? (cdr v)))) ;

; ((x1- x2)^2 + (y1 - y2)^2) ^(1/2)
(define (vect-length v)
  (define (sq x) (* x x))
  
      (sqrt (+ (sq (- (x-point (vect-begin v))
                      (x-point (vect-end v))))
               (sq (- (y-point (vect-begin v))
                      (y-point (vect-end v))))))
      )

; > (cons 1 (cons 2 (cons 3 null)))
; '(1 2 3)
; > (list 1 2 3)
; '(1 2 3)


;(map f l) ->
; '(1 2 3) inc (2 3 4)
; ((f 1) (f 2) (f 3))


(define (map proc items)
  (if (null? items)
      null
      (cons (proc (car items))
            (map proc (cdr items)))))




; () (5 6) -> (5 6)
(define (append l1 l2)
    (if (null? l1)
        l2
        (cons (car l1) (append (cdr l1) l2))))

; (1 2 3 4)
; ( (reverse (2 3 4)     (1)
(define (reverse l)
    (if (null? l)
        '()
        (append (reverse (cdr l))  (list (car l)))))

(define (reverse-iter l)
  (define (iter old new)
    (if (null? old)
      new
      (iter
        (cdr old)
        (cons (car old) new))))
  (iter l '())
)


(define (insert l x) 
(if (null? l)
  (list x)
  (if (> x (car l))
    (cons (car l) (insert (cdr l) x))
    (cons x l))
  ))

; (1 2 1 5 2 7 2) ()
; (2 1 5 2 7 2) (1)
; (1 5 2 7 2) (1 2)
; (5 2 7 2) (1 1 2)
; (2 7 2) (1 1 2 5)
; 
(define (insertion-sort l)
    (define (sort l acc)
      (if (null? l)
        acc
        (sort (cdr l) (insert acc (car l)))))
    (sort l '()))

(define (select-min l)
  (define (sm-search min l)
    (if (null? l)
        min
        (if (< (car l) min)
            (sm-search (car l) (cdr l))
            (sm-search min (cdr l)))))
  
  (define (sm-process x l)
    (if (null? l)
        l
        (if (= x (car l))
            (cdr l)
            (cons (car l) (sm-process x l)))))
    
    
    (let ([x (select-min l)])
        (cons x (sm-process x l)))
)
;  3 ( 1 2 3 4) -> ( 1 2 4)
; (1 2 3)
; perm (2 3)-> ((2 3) (3 2))
; ((1 2 3) (2 1 3) (2 3 1)
;    (1 3 2) (3 1 2) (3 2 1))
; ((1 2 3) (2 1 3) ..)
(define (perm l)
    (if (null? l)
        '()
        (let ([perms (perm (cdr l))])

        )
        )
 )

(define (list? l)
    (or (null? l)
        (and (cons? l) (list? (cdr l)))))

; Dla dowolnych xs i ys, jesli (list? xs) i (list? ys) to (list? (append xs ys)).

; 1. xs == null
(list? (append null ys)) ~ (list? ys)

; zakladamy ze zachodzi dla (list? (append xs ys))

(list? (append (cons a xs) ys))  ~ 
(list? (cons a (append xs ys)) )  ~ 
(and (cons?  (cons a (append xs ys))) (list? (cdr  (cons a (append xs ys))))) ~ 
(list? (cdr  (cons a (append xs ys)))) ~ 
(list? (append xs ys))


