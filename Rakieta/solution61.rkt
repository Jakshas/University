#lang racket
;Jakub Szajner
(provide (struct-out complex) parse eval)
(struct i () #:transparent)
(struct complex (re im) #:transparent)

(define value?
  complex?)

(struct const (val)    #:transparent)
(struct binop (op l r) #:transparent)

; Co to są wyrażenia?
(define (expr? e)
  (match e
    [(const n) (number? n)]
    [(binop op l r) (and (symbol? op) (expr? l) (expr? r))]
    [_ false]))


(define (op->proc op)
  (match op ['+ +] ['- -] ['* *] ['/ /]))

(define (eval e)
  (match e
    [(const n) n]
    [(binop op l r) (cond [(and (complex? l)
                                (complex? r))
                           [match op
                             ('+
                              (complex (+ (complex-re l)
                                          (complex-re r))
                                       (+ (complex-im l)
                                          (complex-im r))))
                                 ['-
                                  (complex (- (complex-re l)
                                              (complex-re r))
                                           (- (complex-im l)
                                              (complex-im r)))]
                                 ['*
                                  ((lambda (a b c d)
                                     (complex (- (* a c) (* b d)) (+ (* a d) (* b c))))
                                   (complex-re l)
                                   (complex-im l)
                                   (complex-re r)
                                   (complex-im r))]
                                 ['/
                                  ((lambda (a b c d)
                                     (complex (/ (+ (* a c) (* b d)) (+ (* c c) (* d d)))
                                             (/ (- (* b c) (* a d)) (+ (* c c) (* d d)))))
                                   (complex-re l)
                                   (complex-im l)
                                   (complex-re r)
                                   (complex-im r))]]]
                          [(complex? l)
                           (eval (binop op l (eval r)))]
                          [(complex? r)
                           (eval (binop op (eval l) r))]
                          [else (eval (binop op (eval l) (eval r)))])]))

; ------------------------- ;
; Trochę składni konkretnej ;
; ------------------------- ;

(define (parse q)
  (cond [(number? q) (complex q 0)]
        [(eq? 'i q) (complex 0 1)]
        [(and (list? q)
              (eq? (length q) 3)
              (symbol? (first q)))
         (binop (first q)
                (parse (second q))
                (parse (third q)))]))

(define (test) (eval (parse '(+ (* 2 3) (* 4 5)))))
(test)
(eval (parse'(* i i)))
(eval (parse'(+ 3 (* i 8))))
;rozwiazanie stworzone z pomoca Kacpra Bajkiewicza