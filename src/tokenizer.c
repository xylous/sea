#include "tokenizer.h"

#include <stdlib.h>
#include <string.h>

struct token *new_token(enum token_type type);
enum token_type type(char *p);
void save_token(struct token ***buf, int length, struct token *t);
void append_to_string(char **str, char *ch);
int should_be_one_char_token(struct token *t);

// Return a NULL-terminated list of tokens in the given string
struct token **tokenize(char *str)
{
    struct token **buf = calloc(0, sizeof(struct token*));
    int buflen = 0;

    struct token *tok = new_token(type(&str[0]));

    for (char *ch = str; *ch != '\0'; ch++) {
        // if they're of the same type, then it's part of the same token
        // ...except if it's a parenthesis of any kind
        if (type(ch) == tok->type && !should_be_one_char_token(tok)) {
            append_to_string(&(tok->content), ch);
        } else { // different token; save current one into token buffer, even if it's a whitespace token
            save_token(&buf, buflen++, tok);
            tok = new_token(type(ch--));
            // we need to decrement because otherwise it'd skip the current
            // character (especially with multiple whitespace characters) which
            // would be the beginning of a new token
        }
    }

    save_token(&buf, buflen, NULL);

    return buf;
}

// Return a pointer to a new token in heap memory, with the specified type and
// an empty `content` field
struct token *new_token(enum token_type type)
{
    struct token *t = malloc(sizeof(struct token));
    t->content = calloc(0, sizeof(char));
    t->type = type;
    return t;
}

// Given a character, return the type of token it would be part of
enum token_type type(char *p)
{
    switch (*p) {
        case ' ': case '\t': case '\n':
            return whitespace;
        case ';':
            return semicolon;
        case '=':
            if (*(p-1) && type(p-1) == string)
                return assignment;
            else
                return string;
        case '&':
            return ampersand;
        case '|':
            return vertical_bar;
        case '(': case ')':
            return round_paren;
        case '[': case ']':
            return square_paren;
        case '{': case '}':
            return curly_paren;
        case '$':
            return dollar_sign;
        default:
            return string;
    }
}

// Add a token to the given buffer of specified length
// The buffer must be allocated with malloc/calloc/realloc
void save_token(struct token ***buf, int length, struct token *t)
{
    *buf = realloc(*buf, sizeof(struct token *) * (length + 1));
    (*buf)[length] = t;
}

// Append a character to a string
// The buffer must be allocated with malloc/calloc/realloc
void append_to_string(char **str, char *ch)
{
    int len = strlen(*str);
    *str = realloc(*str, sizeof(*str) * (len + 1));
    (*str)[len] = *ch;
}

// Determine if the given token is of a parenthesis type or a dollar sign type
// and has exactly one character in it
int should_be_one_char_token(struct token *t)
{
    int b = 0;
    if (t->type == round_paren
        || t->type == square_paren
        || t->type == curly_paren
        || t->type == dollar_sign) {
        b = 1;
    }
    return b && strlen(t->content) == 1;
}
