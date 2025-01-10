#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * main - Simple shell pour exécuter des commandes
 * avec leur chemin d'accès complet, avec options.
 * @argc: Nombre d'arguments.
 * @argv: Tableau d'arguments.
 * Return: Toujours (0)
 */
int main(int argc, char **argv)
{
	char *input = NULL;
	char *command;
	size_t len = 0;

	(void)argc; /* Supprimer l'avertissement lié à argc non utilisé */

	if (!isatty(STDIN_FILENO))
	{
		while (getline(&input, &len, stdin) != -1)
		{
			command = strtok(input, "\n");
			while (command != NULL)
			{
				if (strcmp(command, "exit") == 0)
				{
					free(input);
					exit(0);
				}
				execute_command(command, argv[0]);
				command = strtok(NULL, "\n");
			}
		}
	}
	else
	{
		while (1)
		{
			printf("$ "); /* Afficher le prompt */
			read_command(&input, &len);
			command = strtok(input, "\n");
			while (command != NULL)
			{
				if (strcmp(command, "exit") == 0)
				{
					free(input);
					exit(0);
				}
				execute_command(command, argv[0]);
				command = strtok(NULL, "\n");
			}
		}
	}

	free(input);
	return (0);
}
