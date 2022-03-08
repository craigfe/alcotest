# 1. Getting started

The simplest way to get started with Alcotest is to use the supplied
pre-processing extension, `ppx_alcotest`, with the
[Dune](https://dune.readthedocs.io/en/stable/) build system. Install them with
[Opam](https://opam.ocaml.org/doc/Install.html):

<!-- $MDX skip -->
```bash
; opam install dune alcotest ppx_alcotest
```

We'll be writing our tests in a file called `my_tests.ml`, so let's set up a
`dune` file with the right stanza:

```dune
(test
 (name my_tests)
 (libraries alcotest)
 (preprocess (pps ppx_alcotest)))
```

Now we can write some tests in `my_tests.ml`:

```ocaml
let%test "basic addition" =
  [%check: int] ~expected:2 (1 + 1)
```

See the [next section](./02_testable_types.md) or [go back](../).
