#lang racket
(require quikcheck)

(define (average z y)
  (/ (+ z y) 2))

(define (square x)
  (* x x))

(define (dist x y)
  (abs (- x y)))

(define (abs x)
  (if (< x 0)
      (- x)
      x))

(define (good-enough/c g)
  (lambda (e) (< (dist g (square e))
       0.0001)))

(define/contract (sqrt x)
  (->i ([e positive?])
       (result (e) (and/c
                    positive?
                    (good-enough/c e))))
  
  ;; lokalne definicje
  ;; poprawianie przybliżenia
  (define (improve guess)
    (average guess (/ x guess)))
  ;; sprawdzanie czy przybliżenie jest wystarczająco dobre
  (define (good-enough? g)
    (< (dist x (square g))
       0.0001))
  ;; procedura iterująca poprawianie przybliżenia aż
  ;; osiągniemy wystarczająco dobre przybliżenie
  (define (iter guess)
    (if (good-enough? guess)
        guess
        (iter (improve guess))))
  
  (iter 1.0))

(define (len-lesseq/c l)
    (let ((n (length l)))
        (lambda (l2) (<= (length l2) n))))

(define (check p? xs)
(if (null? xs)
#t
(if (p? (car xs))
    (check p? (cdr xs))
    #f)))

(define/contract (filter p? xs)
    (parametric->/c [a] 
        (->i ([pred (-> a boolean?)]
              [l (listof a)])
              [result (l) (and/c len-lesseq/c (listof a))]
              #:post (pred result)
              (check pred result)))
(if (null? xs)
    null
    (if (p? (car xs)) 
        (cons (car xs) (filter p? (cdr xs)))
        (filter p? (cdr xs)))))


(define-signature  monoid^
((contracted
    [elem?    (-> any/c  boolean?)]
    [neutral  elem?]
    [oper     (-> elem? elem? elem?)])))

(define-unit ints@
  (import)
  (export monoid^)
  
  (define (elem? x)
          (integer? x))
          
  (define neutral 0)
  
  (define (oper x y)
          (+ x y)))

(define-unit lists@
  (import)
  (export monoid^)
  
  (define (elem? xs)
          (list? xs))
          
  (define neutral '())
  
  (define (oper xs ys)
          (append xs ys)))

 #;(quickcheck
  (property ([x arbitrary-integer])
             (==> (elem? x)
                  (and (eq? x (oper x neutral))
                       (eq? x (oper neutral x))))))
 #;(quickcheck
  (property ([x (arbitrary-list arbitrary-integer)])
             (==> (elem? x)
                  (and (eq? x (oper x neutral))
                       (eq? x (oper neutral x))))))
                      
 #;(quickcheck 
  (property ([x arbitrary-integer]
             [y arbitrary-integer]
             [z arbitrary-integer])
             (==> (elem? x)
                  (==> (elem? y)
                       (==> (elem? z)
                             (eq? (oper (oper x y) z) (oper x (oper y z))))))))

(define-signature integers^
  ((contracted
    [elem?          (-> any/c boolean?)]
    [set?           (-> any/c boolean?)]
    [contains?      (-> any/c set? boolean?)]
    [empty-set?     (-> set? boolean?)]
    [empty-set      (and/c set? empty-set?)]
    [singleton      (-> elem? set?)]
    [sum-sets       (-> set? set? set?)]
    [intersect-sets (-> set? set? set?)])))

(define-unit sets@
  (import)
  (export integers^)
  
  (define (elem? x)
          (integer? x))
          
  (define (set? xs) ;; (1)
          (or (empty-set? xs)
              (and (integer? (car xs))
                   (not (member (car xs) (cdr xs)))
                   (set? (cdr xs)))))
  
  (define (contains? x xs)
          (if (null? xs)
              #f
              (if (eq? (car xs) x)
                  #t
                  (contains? x (cdr xs)))))
  
  (define empty-set? null?)

  (define empty-set '())

  (define singleton list)

  (define (sum-sets x y)
          (remove-duplicates (append x y)))
  
  (define (intersect-sets xs ys)
          (filter (lambda (x) (contains? x ys)) xs)))

(quickcheck
  (property ([x arbitrary-integer])
             (not (contains? x empty-set))))

(quickcheck
  (property ([x arbitrary-integer]
             [y arbitrary-integer])
             (and (contains? (singleton x) x)
                  (if (contains? (singleton x) y)
                      (= x y)
                      (not (= x y))))))

(quickcheck
  (property ([xs (arbitrary-list arbitrary-integer)]
             [ys (arbitrary-list arbitrary-integer)])
            (let
                ((res (sum-sets xs ys)))
                (andmap (lambda (e) (or (contains? e xs) (contains? e ys))) res))))

(quickcheck
  (property ([xs (arbitrary-list arbitrary-integer)]
             [ys (arbitrary-list arbitrary-integer)])
            (let
                ((res (sum-sets xs ys)))
                (andmap (lambda (e) (and (contains? e xs) (contains? e ys))) res))))
               
                

 (quickcheck
  (property ([a (arbitrary-list arbitrary-integer)]
             [b (arbitrary-list arbitrary-integer)]
             [c (arbitrary-list arbitrary-integer)])
            (eq? (sum-sets a (intersect-sets b c)) (intersect-sets (sum-sets a b) (sum-sets a c)))))               