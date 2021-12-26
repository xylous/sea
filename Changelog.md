# Changelog

## 0.5.0 - 2021-12-26

(shell NOT usable)

- implement custom tokeniser, where every token has a type and a content
- replace read-fork-exec loop with printing token contents and their types to
stdout

## 0.4.0 - 2021-12-15

(shell usable)

- add a builtin function "lookup table"
- add two builtins, `cd` and `exit`
- change the `exec` function to use builtins

## 0.3.0 - 2021-12-15

(shell usable)

- add an IO module, for taking input from stdin
- link modules together in an "Input-Tokenise-Execute" cycle, making shell
(semi-)usable
- add installation instructions to README
- add roadmap to README

## 0.2.0 - 2021-12-14

(shell not usable)

- add fork/exec module that is tokeniser-compatible

## 0.1.0 - 2021-12-13

(shell not usable)

- add tokeniser module
- add generic Makefile to build project
