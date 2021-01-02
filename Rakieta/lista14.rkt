#lang racket


(require racklog)

;; predykat unarny %male reprezentuje zbiór mężczyzn
(define %male
  (%rel ()
        [('adam)]
        [('john)]
        [('joshua)]
        [('mark)]
        [('david)]))

;; predykat unarny %female reprezentuje zbiór kobiet
(define %female
  (%rel ()
        [('eve)]
        [('helen)]
        [('ivonne)]
        [('anna)]))

;; predykat binarny %parent reprezentuje relację bycia rodzicem
(define %parent
  (%rel ()
        [('adam 'helen)]
        [('adam 'ivonne)]
        [('adam 'anna)]
        [('eve 'helen)]
        [('eve 'ivonne)]
        [('eve 'anna)]
        [('john 'joshua)]
        [('helen 'joshua)]
        [('ivonne 'david)]
        [('mark 'david)]))

;; predykat binarny %sibling reprezentuje relację bycia rodzeństwem
(define %sibling
  (%rel (a b c)
        [(a b)
         (%parent c a)
         (%parent c b)]))

;; predykat binarny %sister reprezentuje relację bycia siostrą
(define %sister
  (%rel (a b)
        [(a b)
         (%sibling a b)
         (%female a)]))

;; predykat binarny %ancestor reprezentuje relację bycia przodkiem
(define %ancestor
  (%rel (a b c)
        [(a b)
         (%parent a b)]
        [(a b)
         (%parent a c)
         (%ancestor c b)]))
         
;;zadanie 1

(define %is_mother
    (%rel (mot kid)
         [(mot)
         (%parent mot kid)
         (%female mot)]))

 (define %is_father
    (%rel (mot kid)
         [(mot)
         (%parent mot kid)
         (%male mot)]))


(define %grandson
   (%rel (son grand som)
         [(son grand)
         (%parent som son)
         (%parent grand som)
         (%male son)]))


(define %cousin
    (%rel (cou1 cou2 grand par1 par2)
        [(cou1 cou2)
        (%parent par1 cou1)
        (%parent grand par1)
        (%parent par2 cou2)
        (%parent grand par2)
        (%not (%= par1 par2)
        (%male cou1))]))

;;; zadanie 2

(%find-all () (%ancestor 'mark 'john))

(%find-all (x) (%ancestor 'adam x))

(%find-all (x) (%sister x 'ivonne))

(%find-all (x y) (%cousin x y))


