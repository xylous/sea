#include <stdio.h>

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

    return 0;
}
