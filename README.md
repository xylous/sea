# sea

A shell. Seashell. Seash?. Written in C

For a detailed history of the project, check [the Changelog](./Changelog.md)

## Getting started

### Requirements

For building:

- GNU Make
- a C compiler, preferably GCC

### Installation

Clone this repository locally, `cd` into the newly downloaded directory and run
`make`:

```
git clone https://github.com/xylous/sea.git sea
cd sea
make
```

And voilà, a binary called `sea` should appear in that directory. You could move
it onto `$PATH` afterwards.

### Usage

To run, invoke it on the command line; for the time being, it takes no
arguments. Running it starts an interactive session. You can press `Enter` or
`Ctrl-D` to exit.

## Roadmap

- [ ] custom tokeniser (which can recognise `;`, `&&`, `||` etc)
- [ ] parse expressions into AST
- [ ] `if-then-else` expressions
- [ ] `do-while` expressions
- [ ] variable assignment/`let` expressions
- [ ] `export` expressions
- [ ] function definitions, function calls (+ `local` keyword for... local variables)
- [ ] RC file (conform to XDG base spec)
- [ ] custom aliases
- [ ] customisable prompt
- [ ] keep track of history

## Contributing

Pull requests are welcome. For major changes, please open an issue first to
discuss what you would like to change.
