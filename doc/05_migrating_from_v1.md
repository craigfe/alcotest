# 5. Migrating from V1

The simplest way to upgrade an Alcotest 1.x test suite to support Alcotest opam
releases 2.0 and above is to switch to using the _versioned_ API:


```ocaml
module Alcotest = Alcotest.V1

(* + if using a threaded backend *)
module Alcotest_lwt = Alcotest_lwt.V1
module Alcotest_async = Alcotest_async.V1
```
```mdx-error
Line 4, characters 25-40:
Error: Unbound module Alcotest_lwt
```

This API provides stable support for the older style of test registration.
However, to get access to the 2.0-only features, including [flexible test suite
structures](./structure) and [conditional test execution](./tags), you'll need
to modify the way that tests are registered:


```ocaml
(* Old style *)
let () =
  Alcotest.run "my tests"

```
```mdx-error
Line 3, characters 5-28:
Warning 5 [ignored-partial-application]: this function application is partial,
maybe some arguments are missing.
Line 3, characters 5-28:
Error: This expression has type unit Alcotest.test list -> unit
       but an expression was expected of type unit
```
