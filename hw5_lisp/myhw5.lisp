; Programmer: Jeff Gould
; Instructor: Dr Morales
; File Name: myhw5.lisp
; Description: lisp functions
; *****      Create Lists     *****

; numbers Lists

(setf num `(5 2 5 4 3))

(setf num1 `(1 2 5))

(setf num2 `(0 8 6 1 4 2 7 5))

; Letters Lists
(setf alpha `(a b c d e f g h i i j j k k k k k w a c d v e f f f a j j p))

; *****      Functions     *****

; mylast(L)
; returns last element in Lists
(defun myLast(L)
    (if (eq(cdr L)nil)
      (car L)
      (myLast(cdr L))))

; mycount(X L)
; returns the number of instances of X in a List
(defun myCount (x L)
  (cond
   ((null L) 0)
   ((equal x (car L)) (+ 1 (myCount x (cdr L))))
   (t (myCount x (cdr L)))))

; mymember(X L)
; returns t if X is in L nil if not
(defun myMember(X L)
  (if (eq L nil)
    nil
    (if (eq X (car L))
      T
      (myMember X (cdr L)))))

; mypurge(L)
; returns a list without duplicates
(defun myPurge(L)
  (if (eq L nil)
    nil
    (if (not(myMember (car L) (cdr L)))
      (cons (car L) (myPurge (cdr L)))
      (myPurge (cdr L)))))

; mycommon(L1 L2)
; returns a list of common elements
(defun myCommon(L1 L2)
  (if (eq L1 nil)
    nil
    (if (myMember (car L1) L2)
      (cons (car L1) (myCommon (cdr L1) L2))
      (myCommon (cdr L1) L2))))

; myGen(X Y Z)
; returns list comprised of nums from x to Y by z
(defun myGen(X Y Z)
  (if (<= X Y)
    (cons (+ X ) (myGen (+ X Z) Y Z))
    ()))

; mymap(F L)
; returns a list comprized of applying fnct F to all elements in L)
(defun myMap(F L)
  (if (eq L nil)
    nil
    (cons (funcall F (car L))(myMap F (cdr L)))))

; myReduce(F L)
; cuts list in half
(defun myReduce(F L)
  (if (eq L nil)
    nil
    (cons (funcall F (car L))(myReduce F (cdr L)))))
