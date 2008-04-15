;;;
;;; Test magic
;;;

(use gauche.test)

(test-start "magic")
(use magic)
(test-module 'magic)

;; The following is a dummy test code.
;; Replace it for your tests.
(test* "test-magic" "magic is working"
       (test-magic))

;; epilogue
(test-end)

;; vim: tabstop=2 shiftwidth=2 expandtab softtabstop=2 filetype=scheme
