#include "parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **append(char **buf, int length, char *str);

// Returns the tokens in a string, delimited by SEA_PARSER_DELIMITERS
char **tokenise(char *str)
{
    char *copy = malloc(sizeof(char) * (strlen(str) + 1));
    strcpy(copy, str);

    char **buf = malloc(sizeof(char *));
    int i = 0;

    char *token = strtok(copy, SEA_PARSER_DELIMITERS);
    buf = append(buf, i++, token);
    while (token != NULL) {
        token = strtok(NULL, SEA_PARSER_DELIMITERS);
        buf = append(buf, i++, token);
    }

    return buf;
}

// Given a buffer of length, resize it and add str as the last element
char **append(char **buf, int length, char *str)
{
    buf = realloc(buf, (sizeof buf) * (length + 1));
    buf[length] = str;
    return buf;
}
