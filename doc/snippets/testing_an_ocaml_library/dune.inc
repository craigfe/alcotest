;; dune

;; Define an executable called `my_tests` (implicitly contained in the
;; OCaml module provided by `my_tests.ml`)
(test
 (name my_tests)
 (libraries alcotest)             ;; Use the Alcotest library
 (preprocess (pps ppx_alcotest))) ;; Use Alcotest's syntax extensions

