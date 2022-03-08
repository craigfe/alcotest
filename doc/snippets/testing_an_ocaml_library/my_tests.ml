(* my_tests.ml *)

let%test "basic addition" =
  [%check: int] ~expected:2 (1 + 1)

