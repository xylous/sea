#include "exec.h"
#include "builtins.h"

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int exec(char **args)
{
    int builtinID = is_builtin(args);
    if (builtinID != -1) {
        return exec_builtin(builtinID, args);
    }

    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1)
            perror("execvp");
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("fork error");
    } else {
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while(!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return WTERMSIG(status);
}
