#lang racket

(require racklog)

(define %row-ok
  (%rel (x xs y ys x1)
  [(null null)]
  [(xs (cons '_ ys))
   (%row-ok xs ys)]
  [((cons 0 xs) null)
   (%row-ok xs null)]
  [((cons x xs)(cons '* (cons '* ys)))
   (%> x 1)
   (%is x1 (- x 1))
   (%row-ok (cons x1 xs) (cons '* ys))]
  [((cons x xs)(cons '* (cons '_ ys)))
   (%= x 1)
   (%row-ok xs (cons '_ ys))]
  [('(1) '(*))]))

(%which ()(%row-ok '(2 4) '(* * _ _ * * * * _ _)))

