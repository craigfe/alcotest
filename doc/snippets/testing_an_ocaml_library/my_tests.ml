(* my_tests.ml *)

let%test "basic addition" =
  [%check: int] ~expected:5 (2 + 2)

[%%run_tests]

