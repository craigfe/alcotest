---
id: promises
title: Testing threaded programs
sidebar_label: Testing threaded programs
slug: /promises
---

Alcotest provides `Alcotest_lwt` and `Alcotest_async` modules for writing test
cases that use promises / fibres.

You 

You get given a switch, which will be turned off when the test case
  finishes (or fails). You can use that to free up any resources.

  For instance:

```ocaml
let free () = print_endline "freeing all resources"; Lwt.return ()

let test_lwt switch () =
  Lwt_switch.add_hook (Some switch) free;
  Lwt.async (fun () -> failwith "All is broken");
  Lwt_unix.sleep 10.

let () =
  Lwt_main.run @@ Alcotest_lwt.run "foo" [
    "all", [
      Alcotest_lwt.test_case "one" `Quick test_lwt
    ]
  ]
```
```mdx-error
Line 9, characters 21-37:
Error: Unbound module Alcotest_lwt
```

If you're using `ppx_alcotest`, these can be added simply using:
