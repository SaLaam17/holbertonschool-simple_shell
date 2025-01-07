#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>

extern char **environ;

/*fonctions utilitaires*/
void splits_string(char *str, const char *delim, char **argv);
char *_getenv(const char *name);
/*fonctions de commandes*/
void read_command(char **input, size_t *len);
char *find_command(char *command);
void execute_command(char *input, const char *program_name);

#endif
