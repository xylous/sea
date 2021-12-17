#include "parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOKEN_ANY 0
#define TOKEN_WHITESPACE 1
#define TOKEN_STRING 2
#define TOKEN_SEMICOLON 3

char **append(char **buf, int length, char *str);
char *append_char(char ch, char *str);
int token_type(char ch);

// Return the tokens in a string
char **tokenise(char *str)
{
    char **buf = calloc(0, sizeof(char *));
    int buflen = 0;

    char *token = calloc(0, sizeof(char));

    for (size_t i = 0; i < strlen(str); ++i) {
        char ch = str[i];
        int crt_token_type = token_type(token[0]);
        int crt_ch_type = token_type(ch);

        // Note: it's only checking TOKEN_SEMICOLON for the time, until I can
        // get a proper parser going
        if (crt_token_type != TOKEN_SEMICOLON
            && crt_token_type != TOKEN_WHITESPACE
            && (crt_ch_type == crt_token_type
                || crt_token_type == TOKEN_ANY)) {
            // Resize token buffer and append new character
            token = realloc(token, sizeof(token) * (strlen(token) + 1));
            token = strncat(token, &ch, 1);
        } else {
            //
            buf = append(buf, buflen++, token);
            token = calloc(0, sizeof(char));
        }
    }

    buf = append(buf, buflen, NULL);

    return buf;
}

// Given a buffer of specified length, resize it and add str as the last element
char **append(char **buf, int length, char *str)
{
    buf = realloc(buf, (sizeof buf) * (length + 1));
    buf[length] = str;
    return buf;
}

// Given a character, return its type
int token_type(char ch)
{
    switch (ch) {
        case '\0':
            return TOKEN_ANY;
        case ' ': case '\t': case '\n':
            return TOKEN_WHITESPACE;
        case ';':
            return TOKEN_SEMICOLON;
        default:
            return TOKEN_STRING;
    }
}
