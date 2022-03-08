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
└── my_tests.ml   # OCaml file containing our test assertions
```

First let's set up the necessary build system configuration:

<!-- $MDX file=snippets/testing_an_ocaml_library/dune-project -->
```dune
(lang dune 3.0)
;; dune-project
```

<!-- $MDX file=snippets/testing_an_ocaml_library/dune.inc -->
```dune
;; dune

;; Define an executable called `my_tests` (implicitly contained in the
;; OCaml module provided by `my_tests.ml`)
(test
 (name my_tests)
 (libraries alcotest)             ;; Use the Alcotest library
 (preprocess (pps ppx_alcotest))) ;; Use Alcotest's syntax extensions
```

Now we can write some tests in `my_tests.ml`:

<!-- $MDX file=snippets/testing_an_ocaml_library/my_tests.ml -->
```ocaml
(* my_tests.ml *)

let%test "basic addition" =
  [%check: int] ~expected:5 (2 + 2)

[%%run_tests]
```

Running these tests will give a failure

<!-- $MDX skip -->
```
$ dune runtest
```

<!-- $MDX file=snippets/testing_an_ocaml_library/output/test_output.expected -->
```
Testing `doc/snippets/testing_an_ocaml_library/my_tests.ml'.
This run has ID `PH2QAM84'.

test: internal error, uncaught exception:
      Alcotest_engine__Core.Make(P)(M).Test_error
      
> [FAIL]    basic addition

┌──────────────────────────────────────────────────────────────────────────────┐
│ [FAIL]    basic addition                                                     │
└──────────────────────────────────────────────────────────────────────────────┘
File "doc/snippets/testing_an_ocaml_library/my_tests.ml", line 0, character 0:

   Expected: `5'
   Received: `4'

Raised at Alcotest_engine__Test.check in file "src/alcotest-engine/test.ml", line 196, characters 4-261
Called from Alcotest_engine__Core.Make.protect_test.(fun) in file "src/alcotest-engine/core.ml", line 186, characters 17-23
Called from Alcotest_engine__Monad.Identity.catch in file "src/alcotest-engine/monad.ml", line 24, characters 31-35

Logs saved to `~/t/alcotest/_build/default/doc/snippets/testing_an_ocaml_library/output/_build/_tests/doc-snippets-testing_an_ocaml_library-my_tests.ml/basic addition.output'.
 ──────────────────────────────────────────────────────────────────────────────

Full test results in `~/t/alcotest/_build/default/doc/snippets/testing_an_ocaml_library/output/_build/_tests/doc-snippets-testing_an_ocaml_library-my_tests.ml'.
1 failure! in 0.000s. 1 test run.
```

## Testing an OCaml library

We've now written some self-contained test assertions in a top-level OCaml file,
but tests found in the wild generally don't work this way: you'll instead have
an OCaml _library_[^2] that defines an API to be tested, and a separate set of
unit tests that exercise that library. This can be achieved in any number of
ways with Dune, but a typical project structure might look like this:

<!-- $MDX skip -->
```bash
├── dune-project       # Top-level Dune project definition for Dune
├── lib/
│   ├── dune           # Build rules for the library
│   ├── my_library.ml  # Wrapper module defining the library API
│   ...
│
└── test/
    ├── dune           # Build rules for the library
    └── main.ml        # Wrapper module defining the library API
```

[^2]:
    If the OCaml code you're building is actually an executable rather than a
    library, then there are two common approaches to this: pulling out an
    internal library that is consumed only by the executable and the tets, or
    using [cram tests][dune-cram] to test the binary API itself (or both!).

See the [next section](./02_testable_types.md) or [go back](./).

[dune]: https://dune.readthedocs.io/en/stable/
[dune-cram]: TODO
[opam]: https://opam.ocaml.org/doc/Install.html
