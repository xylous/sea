#include "io.h"
#include "tokenizer.h"
#include "exec.h"

#include <stdio.h>
#include <string.h>

#define SEA_PROGRAM_NAME "sea"
#define SEA_PROGRAM_VERSION "0.0.0"
#define SEA_PROGRAM_AUTHOR "xylous"
#define SEA_PROGRAM_EMAIL "xylous.e@gmail.com"

void print_help_message(void)
{
    printf("%s v%s, written by %s <%s>\n",
            SEA_PROGRAM_NAME,
            SEA_PROGRAM_VERSION,
            SEA_PROGRAM_AUTHOR,
            SEA_PROGRAM_EMAIL);
}

int main(int argc, char *argv[])
{
    print_help_message();

    // TODO: fix Ctrl-D / EOF constant input
    while (1) {
        char *cmd = read_line("> ");
        struct token **ts = tokenize(cmd);
        for (int i = 0; ts[i] != NULL; i++) {
            printf("type: %d, content: %s\n", ts[i]->type, ts[i]->content);
        }
    }

    return 0;
}
