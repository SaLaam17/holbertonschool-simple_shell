#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_ARGS 100

/**
 * read_command - Lire la commande saisie par l'utilisateur.
 * @input: Pointeur vers la chaîne d'entrée.
 * @len: Taille de l'entrée.
 */

void read_command(char **input, size_t *len)
{
	ssize_t read = getline(input, len, stdin);

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
			perror("getline");
			free(*input);
			exit(EXIT_FAILURE);
		}
	}
	(*input)[strcspn(*input, "\n")] = '\0';
/* Supprimer le caractère de nouvelle ligne */
}

/**
 * find_command - Cherche la commande dans les répertoires du PATH.
 * @command: La commande à chercher.
 * Return: Un pointeur vers le chemin complet de la commande si trouvée,
 * NULL sinon.
 */

char *find_command(char *command)
{
	char *path_copy, *dir, full_path[1024];
	char *path = _getenv("PATH");

	if (path == NULL || command == NULL)
	{
		return (NULL);
	}

	if (access(command, X_OK) == 0)
	{
		return (strdup(command));
	}

	path_copy = strdup(path);
	if (path_copy == NULL)
	{
		perror("strdup");
		return (NULL);
	}
	dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (strdup(full_path));
		}
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
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
	char *argv[MAX_ARGS], *command_path;
	(void)program_name;
	splits_string(input, " ", argv);/*Découper l'entrée en commande et options*/
	command_path = find_command(argv[0]);
	if (command_path == NULL)
	{
		fprintf(stderr, "Command not found: %s\n", argv[0]);
		return;
	}

	argv[0] = command_path;
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		free(input);
		free(command_path);
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0) /* Processus enfant */
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("execve");
			free(input);
			free(command_path);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status); /* Processus Parent */
	}
	free(command_path);
}
