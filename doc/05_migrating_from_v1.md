---
id: migration_v1
title: Upgrading from version 1.x
sidebar_label: Upgrading from version 1.x
slug: /v1_migration
---

The simplest way to upgrade an Alcotest 1.x test suite to support Alcotest opam
releases 2.0 and above is to switch to using the _versioned_ API:


```ocaml
module Alcotest = Alcotest.V1

(* + if using a threaded backend *)
module Alcotest_lwt = Alcotest_lwt.V1
module Alcotest_async = Alcotest_async.V1
```
```mdx-error
Line 1, characters 19-30:
Error: Unbound module Alcotest
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
Line 3, characters 5-17:
Error: Unbound module Alcotest
```
