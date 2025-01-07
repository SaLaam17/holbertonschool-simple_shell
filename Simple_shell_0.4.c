#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * main - Simple shell pour exécuter des commandes
 * avec leur chemin d'accès complet, avec options.
 * Return: Toujours (0)
 */
int main(void)
{
	char *input = NULL;
	size_t len = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
/* vérifie si l'entrée standard est associée à un terminal interactif */
		{
			printf("$ "); /* Afficher le prompt */
		}

		read_command(&input, &len);
		execute_command(input);

		if (!isatty(STDIN_FILENO))
/*
 * le programme est exécuté dans un contexte non interactif.
 * Dans ce cas, le prompt n'est pas affiché.
 */
		{
			break;
		}
	}

	free(input);
	return (0);
}
