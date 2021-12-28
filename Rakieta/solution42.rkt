#lang racket
(provide heapsort) (require "leftist.rkt")
(define (heapsort l)
  (define (drzewo li tree)
    (if (null? li)
        tree
         (drzewo (cdr li)(heap-merge (make-hnode (car li) 'leaf 'leaf) tree))))
  (define (dolisty li tree)
    (if (heap-empty? tree)
        li
    (dolisty (append li (list (heap-min tree))) (heap-pop tree))))
  (dolisty '() (drzewo (cdr l) (make-hnode (car l) 'leaf 'leaf))))