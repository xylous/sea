#include "builtins.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int exit_shell(char **argv);
int cd(char **argv);

// Maybe replace this array and the next one with a hashmap or a data structure?
char *builtins[] = {
    "exit",
    "cd"
};

int (*builtin_funcs[]) (char**) = {
    &exit_shell,
    &cd
};

// Return the number of builtin commands
int num_builtins(void)
{
    return sizeof(builtins) / sizeof (char *);
}

int cd(char **args)
{
    if (args[1] == NULL)
        args[1] = getenv("HOME");

    char *OLDPWD = getenv("OLDPWD");

    if (strcmp(args[1], "-") == 0)
        args[1] = OLDPWD;

    if(chdir(args[1]) != 0)
        perror("cd");

    setenv("OLDPWD", OLDPWD, 1); // Update OLDPWD

    return 0;
}

// Exit. That's literally it.
int exit_shell(char **args)
{
    exit(EXIT_SUCCESS);
}

// Given the handle ID of a builtin and its supposed arguments, execute it
int exec_builtin(int nth, char **args)
{
    return builtin_funcs[nth](args);
}

// Check if the first element in the given parameter is a builtin command. If it
// is, return its handle ID, otherwise return -1
int is_builtin(char **args)
{
    for (int i = 0; i < num_builtins(); i++) {
        if (strcmp(builtins[i], args[0]) == 0)
            return i;
    }

    return -1;
}
