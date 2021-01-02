#lang racket

(require "graph.rkt")
(provide bag-stack@ bag-fifo@)

;; struktura danych - stos
(define-unit bag-stack@
  (import)
  (export bag^)
  ;; TODO: zaimplementuj
  (define (bag? x)
    (list? x))
  (define empty-bag
    '())
  (define (bag-empty? x)
    (eq? x '()))
  (define (bag-insert x c)
    (cons c x))
  (define (bag-peek x)
    (car x))
  (define (bag-remove x)
    (cdr x)))

;; struktura danych - kolejka FIFO
(define-unit bag-fifo@
  (import)
  (export bag^)
  ;; TODO: zaimplementuj
  (define (bag? x)
    (and (pair? x) (list? (car x)) (list? (cdr x))))
  (define empty-bag
    (cons '() '()))
  (define (bag-empty? x)
    (and (eq? (cdr x) '()) (eq? (car x) '())))
  (define (bag-insert x c)
    (if (bag-empty? x)
        (cons (cons c (car x)) (cdr x))
    (cons (car x) (cons c (cdr x)))))
  (define (bag-peek x)
    (if (eq? (car x) '())
        (car (reverse (cdr x)))
    (car (car x))))
  (define (bag-remove x)
      (if (eq? (car x) '())
          (cons (reverse (cdr x)) '())
          (cons (cdr (car x))(cdr x)))))

;; otwarcie komponentów stosu i kolejki

(define-values/invoke-unit bag-stack@
  (import)
  (export (prefix stack: bag^)))

(define-values/invoke-unit bag-fifo@
  (import)
  (export (prefix fifo: bag^)))

;; testy w Quickchecku
(require quickcheck)

;; testy kolejek i stosów
(define-unit bag-tests@
  (import bag^)
  (export)
  
  ;; test przykładowy: jeśli do pustej struktury dodamy element
  ;; i od razu go usuniemy, wynikowa struktura jest pusta
  (quickcheck
   (property ([s arbitrary-symbol])
             (bag-empty? (bag-remove (bag-insert empty-bag s)))))
  ;; TODO: napisz inne własności do sprawdzenia!
  (quickcheck
   (property ([s arbitrary-symbol])
            (eq? s (bag-peek (bag-insert (bag-insert empty-bag s) s)))))
)

;; uruchomienie testów dla obu struktur danych

(invoke-unit bag-tests@ (import (prefix stack: bag^)))
(invoke-unit bag-tests@ (import (prefix fifo: bag^)))

;; TODO: napisz też testy własności, które zachodzą tylko dla jednej
;; z dwóch zaimplementowanych struktur danych
(define-unit bag-testss@
  (import bag^)
  (export)
    (quickcheck
   (property ([s arbitrary-symbol]
              [l arbitrary-symbol])
            (eq? l (bag-peek (bag-remove (bag-insert (bag-insert empty-bag l) s)))))))

(define-unit bag-testsf@
  (import bag^)
  (export)
    (quickcheck
   (property ([s arbitrary-symbol]
              [l arbitrary-symbol])
            (eq? s (bag-peek (bag-remove (bag-insert (bag-insert empty-bag l) s)))))))

(invoke-unit bag-testss@ (import (prefix stack: bag^)))
(invoke-unit bag-testsf@ (import (prefix fifo: bag^)))
;; otwarcie komponentu grafu
(define-values/invoke-unit/infer simple-graph@)

;; otwarcie komponentów przeszukiwania 
;; w głąb i wszerz
(define-values/invoke-unit graph-search@
  (import graph^ (prefix stack: bag^))
  (export (prefix dfs: graph-search^)))

(define-values/invoke-unit graph-search@
  (import graph^ (prefix fifo: bag^))
  (export (prefix bfs: graph-search^)))

;; graf testowy
(define test-graph
  (graph
   (list 1 2 3 4)
   (list (edge 1 3)
         (edge 1 2)
         (edge 2 4))))
;; TODO: napisz inne testowe grafy

;; uruchomienie przeszukiwania na przykładowym grafie
(bfs:search test-graph 1)
(dfs:search test-graph 1)
;; TODO: uruchom przeszukiwanie na swoich przykładowych grafach