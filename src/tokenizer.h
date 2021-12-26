#ifndef SEA_TOKENIZER_H
#define SEA_TOKENIZER_H

enum token_type {
    whitespace,
    string,
    semicolon,
    assignment,
    ampersand,
    vertical_bar,
    round_paren,
};

struct token {
    enum token_type type;
    char *content;
};

struct token **tokenize(char *str);

#endif
