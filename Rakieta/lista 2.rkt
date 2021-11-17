#lang racket
(define (compose f g)
  (lambda (x) (f (g x))))
(define (ad x) x)
(define (ap x) (+ x 1))

;;((compose ap ad) 5)
(define (repeated p n)
  (if (= n 0)
      p
      (compose p (repeated p (- n 1)))))
((repeated ap 2)0)

(define (product val next start end)
  (if (> start end)
      0
      (+ (val start)
         (product val next (next start) end))))

(define (producti val next start end wart)
  (if (> start end)
      wart
         (producti val next (next start) end (+ (val start) wart))))
(product ad ap 0 5)

(define (accumulate  combiner  null-value  term a next b)
  (if (> next b)
      null-value
      (combiner (term a)
         (accumulate  combiner  null-value  term a next b))))
(define (cont-frac num den k)
  (define (cont-frac1 num den l)
  (if (= l k)
      0
      (/ (num l) (+ (den l) (cont-frac1 num den (+ l 1))))
  ))(cont-frac1 num den 1))
;;ZAD 7 31 PRZYBLIZEN
(+ 3(cont-frac (lambda(i) (* (- (* i 2.0) 1.0) (- (* i 2.0) 1.0)))  (lambda(i) 6.0)  31))

;;ZAD 8
(define (atan-cf x k)
  (cont-frac (lambda(i) (if (> i 1) (* (* (- i 1) x) (* (- i 1) x)) x))  (lambda(i) (- (* i 2.0) 1.0)) k))
  
(atan-cf 5 100)
(atan 5)

(define(build n d b)
  (/ n (+ d b)))
(build 3 3 (build 3 3 3))

(define (repeated-build k n d b)
  (define (bbb b1)
    (/ n (+ d b1)))
 (define (repeated p k1)
  (if (< k1 2)
      p
      (compose p (repeated p (- k1 1)))))
  ((repeated bbb k)b)
  )
(repeated-build 2 3 3 3)