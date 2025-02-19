(defun partition-into-pairs (lst)
  (cond
    ;; Base case: empty list will return empty list
    ((null lst) '())

    ;; Single remaining element will wrap it in a list
    ((null (cdr lst)) (list (list (car lst))))

    ;; Process first two elements as a sorted pair, then recurse
    (t
     (cons (sort (list (car lst) (cadr lst)) #'<)   ;; Sort the pair
           (partition-into-pairs (cddr lst))))))    ;; Continue with rest of list
