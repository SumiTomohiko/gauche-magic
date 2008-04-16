;;;
;;; Test magic
;;;

(use file.util)
(use gauche.process)
(use gauche.test)
(use srfi-13)

(test-start "magic")
(use magic)
(test-module 'magic)

(define (exec-file opts path)
  (let1 
      proc 
        (run-process (append '("file") opts (list path)) :output :pipe :wait #t)
    (regexp-replace #/^[^:]+: / (read-line (process-output proc)) "")))

(define (do-test desc file-opts path proc proc-arg)
  (test* 
    desc #f (not (string-scan (exec-file file-opts path) (proc proc-arg)))))

(define (test-magic-filename path)
  (do-test 
    (format #f "test-magic-filename: ~a" path) '() path magic-filename path))

(define (test-magic-filename-mime path)
  (do-test 
    (format #f "test-magic-filename-mime: ~a" path) 
    '("--mime") 
    path
    magic-filename-mime
    path))

(define (file->buffer path)
  (call-with-input-file 
    path
    (lambda (port)
      (let loop ((buffer ""))
        (let1 block (read-block 4096 port)
          (if (eof-object? block)
            buffer
            (loop (string-append buffer block))))))))

(define (test-magic-string path)
  (do-test 
    (format #f "test-magic-string: ~a" path) 
    '() 
    path 
    magic-string 
    (file->buffer path)))

(define (test-magic-string-mime path)
  (do-test 
    (format #f "test-magic-string-mime: ~a" path) 
    '("--mime") 
    path
    magic-string-mime 
    (file->buffer path)))

(let1 dir "tests"
  (for-each 
    (lambda (path)
      (for-each 
        (cut <> path) 
        (list 
          test-magic-filename 
          test-magic-filename-mime 
          test-magic-string 
          test-magic-string-mime)))
    (directory-list 
      dir :children? #t :add-path? #t :filter (cut string<> ".svn" <>))))

;; epilogue
(test-end)

;; vim: tabstop=2 shiftwidth=2 expandtab softtabstop=2 filetype=scheme
