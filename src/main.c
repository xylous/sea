#include "io.h"
#include "parser.h"
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
        char **tokens = tokenise(cmd);
        if (!tokens[0])
            continue;
        int exec_status = exec(tokens);
        if (exec_status > 0) {
            printf("%d\n", exec_status);
            return exec_status;
        }
    }

    return 0;
}
