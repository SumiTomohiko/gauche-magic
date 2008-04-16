;;;
;;; magic
;;;

(define-module magic
  (export 
    MAGIC_CHECK
    MAGIC_COMPRESS
    MAGIC_CONTINUE
    MAGIC_DEBUG
    MAGIC_DEVICES
    MAGIC_ERROR
    MAGIC_MIME
    MAGIC_NONE
    MAGIC_NO_CHECK_APPTYPE
    MAGIC_NO_CHECK_ASCII
    MAGIC_NO_CHECK_COMPRESS
    MAGIC_NO_CHECK_ELF
    MAGIC_NO_CHECK_FORTRAN
    MAGIC_NO_CHECK_SOFT
    MAGIC_NO_CHECK_TAR
    MAGIC_NO_CHECK_TOKENS
    MAGIC_NO_CHECK_TROFF
    MAGIC_PRESERVE_ATIME
    MAGIC_RAW
    MAGIC_SYMLINK
    magic-buffer
    magic-check
    magic-close
    magic-compile
    magic-errno
    magic-error
    magic-file
    magic-filename
    magic-filename-mime
    magic-load
    magic-open
    magic-setflags
    magic-string
    magic-string-mime))
(select-module magic)

;; Loads extension
(dynamic-load "magic")

;;
;; Put your Scheme definitions here
;;
(define (call-with-cookie flags proc)
  (let1 cookie (magic-open flags)
    (magic-load cookie "")
    (let1 result (proc cookie)
      (magic-close cookie)
      result)))

(define (magic-filename filename) 
  (call-with-cookie MAGIC_NONE (cut magic-file <> filename)))

(define (magic-string s) 
  (call-with-cookie MAGIC_NONE (cut magic-buffer <> s (string-size s))))

(define (magic-filename-mime filename) 
  (call-with-cookie MAGIC_MIME (cut magic-file <> filename)))

(define (magic-string-mime s) 
  (call-with-cookie MAGIC_MIME (cut magic-buffer <> s (string-size s))))

;; Epilogue
(provide "magic")

;; vim: tabstop=2 shiftwidth=2 expandtab softtabstop=2 filetype=scheme
