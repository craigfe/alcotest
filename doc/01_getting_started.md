# 1. Getting started

The simplest way to get started with Alcotest is to use the supplied
pre-processing extension, `ppx_alcotest`, with the [Dune][dune] build system.
Install them with [Opam][opam]:

<!-- $MDX skip -->
```bash
; opam install dune alcotest ppx_alcotest
```

We'll be writing our tests in a file called `my_tests.ml`, meaning we'll need
at least the following structure:

<!-- $MDX skip -->
```bash
├── dune-project  # Top-level Dune project definition for Dune
├── dune          # Build rules for the project
└── my_tests.ml   # OCaml file containing
```

First let's set up the necessary build system configuration:

```dune
;; dune-project
(lang dune 3.0)
```

```dune
;; dune

;; Define an executable called `my_tests` (implicitly contained in the 
;; OCaml module provided by `my_tests.ml`)
(test
 (name my_tests)
 (libraries alcotest)             ;; Use the `alcotest` library
 (preprocess (pps ppx_alcotest))) ;; Use Alcotest's syntax extensions
```

Now we can write some tests in `my_tests.ml`:

```ocaml
(* my_tests.ml *)

let%test "basic addition" =
  [%check: int] ~expected:2 (1 + 1)
```

See the [next section](./02_testable_types.md) or [go back](../).

[dune]: https://dune.readthedocs.io/en/stable/
[opam]: https://opam.ocaml.org/doc/Install.html
