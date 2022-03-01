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

```lisp
(test
 (name my_tests)
 (libraries alcotest)
 (preprocess (pps ppx_alcotest)))
```

Now we can write some tests in `my_tests.ml`:

```ocaml title="my_tests.ml"
let%test "basic addition" =
  [%check] ~expected:2 (1 + 1)
```
```mdx-error
Line 1, characters 5-9:
Error: Uninterpreted extension 'test'.
```

See the [next section](./02_testable_types.md) or [go back](../).
