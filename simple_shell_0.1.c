#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * read_command - Lire la commande saisie par l'utilisateur.
 * @input: Pointeur vers la chaîne d'entrée.
 * @len: Taille de l'entrée.
 */

void read_command(char **input, size_t *len)
{
	ssize_t read;
	*len =0;
	read = getline(input, len, stdin);

	if (read == -1)
	{
		if (feof(stdin)) /* Vérifier si EOF (Ctrl+D) a été saisi */
		{
			printf("\n");
			free(*input);
			exit(0);
		}
		else
		{
			perror("error getline");
			free(*input);
			exit(EXIT_FAILURE);
		}
	}
	(*input)[strcspn(*input, "\n")] = '\0';
	/* Supprimer le caractère de nouvelle ligne */
}

/**
 * execute_command - Exécuter la commande saisie.
 * @input: Commande à exécuter.
 * @program_name: Nom du programme (argv[0]) pour les messages d'erreur.
 */

void execute_command(char *input, const char *program_name)
{
	pid_t child_pid;
	int status;
	char *argv[2];

	argv[0] = input;
	argv[1] = NULL;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("error fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0) /* Processus enfant */
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", program_name, input);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);/* Processus Parent */
	}
}

/**
 * main - Simple shell pour executer des commandes
 * avec leur chemin d'accès complet,sans options.
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
				execute_command(command, argv[0]);
				command = strtok(NULL, "\n"); /*Avancer vers la commande suivante*/
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
				execute_command(command, argv[0]);
				command = strtok(NULL, "\n");
				/* Avancer vers la commande suivante */
			}
		}
	}

	free(input);
	return (0);
}
