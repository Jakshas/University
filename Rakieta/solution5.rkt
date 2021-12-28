#lang racket
(provide falsifiable-cnf?)
(define (falsifiable-cnf? f)
  (define (conj opnd-a opnd-b)
    (list 'conj opnd-a opnd-b))
  (define (disj opnd-a opnd-b)
    (list 'disj opnd-a opnd-b))
  (define (conj? t)
    (and (list? t)
         (= 3 (length t))
         (eq? 'conj (car t))))
  (define (neg opnd)
    (list 'neg opnd))
  (define cnf list)
  (define (forall l p?)
    (if (null? l)
        true
        (and (p? (car l)) (forall (cdr l) p?))))
  (define (cnf? f)
    (and (list? f)
         (forall f (lambda (l) (disj? l)))))
  (define (disj? t)
    (and (list? t)
         (= 3 (length t))
         (eq? 'disj (car t))))
  (define neg-subf second)
  (define conj-left second)
  (define conj-rght third)
(define disj-left second)
  (define disj-rght third)
  (define (neg? t)
    (and (list? t)
         (= 2 (length t))
         (eq? 'neg (car t))))
  (define (literal v)
    (if (neg? v)
        (list 'lit 'neg (neg-subf v))
        (list 'lit 'pos v)))
  (define (var? t)
  (symbol? t))
  (define (literal? v)
    (and (list? v)
         (= 3 (length v))
         (eq? (car v) 'lit)))
  (define (convert-to-nnf f)
    (define (ctn f flag)
      (cond [(var? f)   (if flag 
                            (literal (neg f))
                            (literal f))]  
            [(neg? f)    (ctn (neg-subf f) (not flag))]
              [(conj? f)   (if flag ;; (A \/ B)
                               (disj (ctn (conj-left f) flag) (ctn (conj-rght f) flag))
                               (conj (ctn (conj-left f) flag) (ctn (conj-rght f) flag)))]
              [(disj? f)   (if flag 
                               (conj (ctn (disj-left f) flag) (ctn (disj-rght f) flag))
                                (disj (ctn (disj-left f) flag) (ctn (disj-rght f) flag)))]
              ))
    (ctn f #f))
  (define (convert-to-cnf f)
    
    (define (ctc-merge xss yss acc)
      (if (null? yss)
          acc
          (ctc-merge xss (cdr yss) 
                     (append (map (lambda (xs) (append (car yss) xs)) xss) acc))))
    
        (cond 
          [(literal? f)   (cnf (list f))]
          [(conj? f)      (let 
                              ([l (convert-to-cnf (conj-left f))]
                               [r (convert-to-cnf (conj-rght f))])
                            (append  l r))]
          [(disj? f)      (let 
                                ([l (convert-to-cnf (disj-left f))]
                                 [r (convert-to-cnf (disj-rght f))])
                            (ctc-merge l r '()))]))
  (define (search lit f flag)
    (if(null? f)
       #t
       (if(eq? lit (caddr (car f)))
          (if(eq? flag (cadr (car f)))
             (search lit (cdr f) flag)
             #f)
          (search lit (cdr f) flag))))
  (define (check? f full )
    (cond
      [(null? f) #t]
      [(eq? (cadr (car f)) 'pos)
       (if(search (car f) full 'pos)
          (check? (cdr f) full )
          #f)]
      [(eq? (cadr (car f)) 'neg)
       (if(search (car f) full 'neg)
          (check? (cdr f) full )
          #f)]))
  (define (check2? f full acc)
    (cond
      [(null? f) acc]
      [(eq? (cadr (car f)) 'pos)
       (if(search (car f) full 'pos)
          (check2? (cdr f) full (cons (list (caddr(car f)) #f) acc))
          #f)]
      [(eq? (cadr (car f)) 'neg)
       (if(search (car f) full 'neg)
          (check2? (cdr f) full (cons (list (caddr(car f)) #t) acc))
          #f)]))
  (define (falseable f)
    (if(null? f)
       #f
       (if(check? (car f) (car f) )
          (check2? (car f) (car f) '())
          (falseable (cdr f)))))
  (falseable (convert-to-cnf (convert-to-nnf f))))
(define p
  (list 'neg (list 'disj (list 'conj 'a 'b) (list 'neg 'a))))
(falsifiable-cnf? p)
;Algorytm który napisałem jako zadanie domowe rózni się od tego zdefiniowanego jako zadanie 4 tym ze on nie przyjnmuje
;ani nie oblicza wszystkich wartosciowań danych zmiennych a jedynie sprawdza czy dana klauzula jest tautologią.
;Metoda z zadania domowego wykozystuje własnosci CNF-u i tego ze jesli zaneguje się jedną klauzule mozna zakończyc algorytm.
;Dzieki temu metoda z zadania dom. działa szybciej niz ta z zadania 4 która niedość ze musi wygenerowac wszystkie wartosciowania
;to na dodatek musi podstawić wartosc dla wszystkich zmiennych i wyliczyc wyrażenie.
;Najdłuższym elementem algorytmu sprawdzajacego cnf jest zamiana wyrazenia na przystępna form CNF czego algorytm z zajeć nie musi robić;