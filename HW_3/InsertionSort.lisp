;; Function to insert an element into the sorted list at the correct position
(defun insert-element (item sorted)
  (if (or (null sorted) (< item (car sorted)))  ; Base case: Empty or found position
      (cons item sorted)  ; Insert item at correct position
      (cons (car sorted)  ; Otherwise, keep the current element
            (insert-element item (cdr sorted)))))  ; Recurse with remaining elements

;; Recursive insertion sort function
(defun insertion-sort (unsorted &optional (sorted '()))
  (if (null unsorted)  ; Base case: If no elements are left to sort
      sorted           ; Return the sorted list
      (insertion-sort (cdr unsorted)  ; Remove first element from unsorted list
                      (insert-element (car unsorted) sorted))))  ; Insert into sorted list
