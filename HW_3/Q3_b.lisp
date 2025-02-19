(defun merge-adjacent (lists)
  (cond
    ;; If no lists, return () list
    ((null lists) '())

    ;; If one list remains, return it as-is
    ((null (cdr lists)) lists)

    ;; Merge first two lists, then recurse on the rest
    (t
     (cons (merge 'list (car lists) (cadr lists) #'<)  ;; Merge first two lists
           (merge-adjacent (cddr lists))))))           ;; Continue merging the rest
