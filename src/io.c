#include "io.h"

#include <stdio.h>
#include <stdlib.h>

char *read_line(char *prompt)
{
    size_t len = 1;
    char *buf = malloc(sizeof(char));

    printf("%s", prompt);
    getline(&buf, &len, stdin);

    buf = realloc(buf, (sizeof buf) * (len + 1));
    buf[len] = '\n';

    return buf;
}
