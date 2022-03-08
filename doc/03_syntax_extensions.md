# 2. Syntax extensions

The recommended way to use Alcotest is via `ppx_alcotest`. This has several advantages:

- Some basic inference

- All tests and test groups get _source code location_ information attached to
  them, meaning that failure messages can point to specific lines of code.

### Defining tests

```ocaml
module%test Alpha = struct
  let%test "a" = (* ... *)
  let%test "b" = (* ... *)
end

module%test Beta = struct

end

```
```mdx-error
Line 4, characters 3-6:
Error: Syntax error
```


- `module%test`
- `let%test`

### Assertion functions

<!-- $MDX skip -->
```ocaml
val [%check: typ] :
  ?here:Source_code_position.here -> 
  ?msg:string -> 
  expected:typ -> typ -> unit
  
val [%assert] :
  ?here:Source_code_position.here -> 
  ?msg:string ->
  bool -> unit
  
val [%here] : Source_code_position.here
```
