#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>

void splits_string(char *str, const char *delim, char **argv);
void read_command(char **input, size_t *len);
char *find_command(char *command);
char *_getenv(const char *name);
void execute_command(char *input);


#endif
