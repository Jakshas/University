#lang racket
(provide merge split mergesort)
(define (merge l1 l2)
  (cond
    [(null? l1) l2]
    [(null? l2) l1]
    [(< (car l1) (car l2)) (cons (car l1) (merge l2 (cdr l1)))]
    [(>= (car l1) (car l2)) (cons (car l2) (merge l1 (cdr l2)))]
))
(define (split lst)
  (if (= (length lst) 1) lst
  (let-values (((head tail) (split-at lst (ceiling(/ (length lst) 2)))))
    (cons head tail))))

(define (mergesort lista)
  (if (or (null? lista) (null? (cdr lista))) lista
      (merge (mergesort (car (split lista))) (mergesort(cdr (split lista))))))

(mergesort (list 3 6 4 1))
(mergesort (list 1 7 6 6 4))

;Jakub Szajner
;posiłkowałem sie https://news.ycombinator.com/item?id=7596788