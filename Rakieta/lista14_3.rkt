#lang racket

(require racklog)

(define %my-append
  (%rel (x xs ys zs)
        [(null ys ys)]
        [((cons x xs) ys (cons x zs))
         (%my-append xs ys zs)]))

(define %my-member
  (%rel (x xs y)
        [(x (cons x xs))]
        [(y (cons x xs))
         (%my-member y xs)]))

(define %select
  (%rel (x xs y ys)
        [(x (cons x xs) xs)]
        [(y (cons x xs) (cons x ys))
         (%select y xs ys)]))

;; prosta rekurencyjna definicja
(define %simple-length
  (%rel (x xs n m)
        [(null 0)]
        [((cons x xs) n)
         (%simple-length xs m)
         (%is n (+ m 1))]))

;; test w trybie +- (działa)
;;; (%find-all (a) (%simple-length (list 1 2) a))
;;; ;; test w trybie ++ (działa)
;;; (%find-all () (%simple-length (list 1 2) 2))
;; test w trybie -+ (1 odpowiedź, pętli się)
;(%which (xs) (%simple-length xs 2))
;; test w trybie -- (nieskończona liczba odpowiedzi)
;;; (%which (xs a) (%simple-length xs a))

;;; ;zad3

;;; (%which (xs ys) (%my-append xs xs ys))

;;; (%which (x) (%select x '(1 2 3 4) '(1 2 4)))

;;; (%which (xs) (%my-append '(1 2 3) xs '(1 2 3 4 5)))



;;; zadanie 4
(%find-all (x y) (%append x y (list 1 2)))
;;; (% append x y (list 1 2))
;;;             | 
;;; x = null, y = (list 1 2) **** x = (cons x1 xs), y = ys,  x1 = 1,  zs = '(2)
;;;                                 |
;;;                               (%my-append xs ys '(2))
;;;                             |                       | ((cons x2 xs2) ys (cons x2 zs2))
;;;                     xs = null, ys = '(2)  ****      xs = (cons x2 xs2)   
;;;                     x = (cons 1 null),              (cons x2 zs2) = '(2) --> x2 = 2, zs2 = null
                    ;;; y = (cons 2 null)               (%my-append xs2 ys null)
                                        ;;;                 |                |((cons x3 xs3) ys (cons x3 zs3))
                                    ;;;     xs2 = null, ys = null     ****  xs2 = (cons x3 xs3)
                                    ;;;     xs = '(2), x = (list 1 2)       null = (cons x3 zs3)
                                    ;;;     ys = y,    y = null

;;;    '()  cokolwiek -> OK
;;;    '(1) '(1 2)   -> '() '(2)
;;;    '(1) '(0 1 2) -> '(1) '(1 2)
(define %sublist
    (%rel (x y xs ys)
         [(null ys)]
         [((cons x xs) (cons x ys))
            (%sublist xs ys)]
         [((cons x xs) (cons y ys))
            (%not (%= x y))
            (%sublist (cons x xs) ys)]))

(%find-all (y) (%sublist y (list 1 2)))



(define %perm
    (%rel (x xs ys zs)
          [(null null)]
          [((cons x xs) ys)
            (%select x ys zs)
            (%perm xs zs)]))

(%find-all (y) (%perm y (list 1 2 3)))

(define (list->num xs)
(define (aux x xs n)
    (if (null? xs)
        x
        (aux (+ x (* (car xs) (expt 10 n))) 
             (cdr xs)
             (- n 1))))
    (let ((len (length xs)))
        (aux 0 xs (- len 1))))

(list->num '(1 3 3 7))

(define %numb
    (%rel (x)
    [(x) (%= x 0)]
    [(x) (%= x 1)]
    [(x) (%= x 2)]
    [(x) (%= x 3)]
    [(x) (%= x 4)]
    [(x) (%= x 5)]
    [(x) (%= x 6)]
    [(x) (%= x 7)]
    [(x) (%= x 8)]
    [(x) (%= x 9)]))

(%which (d e m o n s r y)
    (%numb d)
    (%numb e)
    (%numb m)
    (%/= m 0)
    (%numb o)
    (%numb n)
    (%numb s)
    (%/= s 0)
    (%numb r)
    (%numb y)
    (%= (%+ (%list->num (list s e n d))
           (%list->num (list m o r e)))
        (%list->num (list m o n e y))))
