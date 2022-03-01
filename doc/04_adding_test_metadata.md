---
id: tags
title: Running tests conditionally
sidebar_label: Running tests conditionally
slug: /tags
---

Sometimes, it's helpful to be able to decide whether or not to run certain tests
at run-time, according to various conditions. For example, we might care about:

- **test duration**
- **platform-dependence**; some tests may rely on 
- **compiler-dependence**; tests may rely on features of the OCaml compiler

This is where [_tags_](TODO) come in. A _tag_ is a piece of metadata that is
attached to a test (or group of tests), which gives information
. Alcotest supplies a few different types of tag by default:

- `Speed_level`
- `System_type`
- `Ocaml_version`
- `Condition` – run tests based on an arbitrary predicate.

It's also possibe to define one's own custom tags 

## Defining custom tags
