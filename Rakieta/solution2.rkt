#lang racket
(provide cont-frac)
(define (cont-frac num den)
  (define (sprawdz wynik iter a1 a2 b1 b2)
    (define wynik2 (/ (+ (* (den iter) a2)
                 (* (num iter) a1))
                      (+ (* (den iter) b2)
                         (* (num iter) b1) )))
    (if (< (abs(- wynik2 wynik)) 0.0001)
        wynik2
        (sprawdz wynik2 (+ iter 1) a2 (+ (* (den iter) a2)(* (num iter) a1)) b2 (+ (* (den iter) b2)(* (num iter) b1) ))))
  (sprawdz 0 1 1.0 0 0 1.0) )
(cont-frac (lambda(i) 1)  (lambda(i) 1))
(define (atan-cf x)
  (cont-frac (lambda(i) (if (> i 1) (* (* (- i 1) x) (* (- i 1) x)) x))  (lambda(i) (- (* i 2.0) 1.0)) ))

(atan-cf 5)