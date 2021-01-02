#lang racket
(provide partition quicksort)
(define (partition n xs)
  (cons (filter (lambda (x)(<= x n)) xs)(filter (lambda (x)(> x n)) xs)))
(define (quicksort lista)
  (if
    (< (length lista) 2) lista
    (append (quicksort(car (partition (car lista) (cdr lista)))) (list (car lista)) (quicksort(cdr (partition (car lista) (cdr lista)))))))
(quicksort (list 3 6 4 1))
(quicksort (list 1 7 6 6 1))
;Jakub Szajner
;posiłkowałem sie https://learningtogetolder.wordpress.com/2013/06/14/merge-sort-in-racket/
