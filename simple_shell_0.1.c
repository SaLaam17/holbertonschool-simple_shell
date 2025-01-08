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
	size_t len = 0;

	(void)argc; /* Supprimer l'avertissement lié à argc non utilisé */

	while (1)
/*
 * la boucle continuera sans interruption,
 * sauf si une instruction
 * comme break ou exit est rencontrée.
 */
	{
		if (isatty(STDIN_FILENO))
		printf("$ "); /* Afficher le prompt */

	read_command(&input, &len);
	execute_command(input, argv[0]);

		if (!isatty(STDIN_FILENO))
		{
			break;
		}
	}
/*
 *Sortir de la boucle en mode non-interactif
 *après l'exécution de la commande
 */
	free(input);
	return (0);
}
