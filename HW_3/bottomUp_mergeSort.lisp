(defun bottom-up-mergesort (lst)
  (let ((sorted-pairs (partition-into-pairs lst))) ;; Step 1: Partition list into sorted pairs
    (labels ((merge-passes (lists)
               (if (null (cdr lists)) ;; If only one list remains, return it
                   (car lists)
                   (merge-passes (merge-adjacent lists))))) ;; Merge adjacent pairs recursively
      (merge-passes sorted-pairs)))) ;; Start the merging process
