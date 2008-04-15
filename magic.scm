;;;
;;; magic
;;;

(define-module magic
  (export test-magic ;; dummy
          )
  )
(select-module magic)

;; Loads extension
(dynamic-load "magic")

;;
;; Put your Scheme definitions here
;;

;; Epilogue
(provide "magic")

;; vim: tabstop=2 shiftwidth=2 expandtab softtabstop=2 filetype=scheme
