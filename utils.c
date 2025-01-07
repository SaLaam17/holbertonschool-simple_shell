#include "shell.h"
#include <string.h>
#include <stdlib.h>

/**
 * splits_string - Fonction qui découpe une chaîne de caractères
 * et stocke chaque mot dans un tableau.
 * @str: Chaîne de caractères à découper.
 * @delim: Délimiteur de la chaîne de caractères à découper.
 * @argv: Tableau de pointeurs pour stocker les tokens.
 */
void splits_string(char *str, const char *delim, char **argv)
{
	char *token;
	int i = 0;

	token = strtok(str, delim);

	while (token != NULL)
	{
		argv[i++] = token;
		token = strtok(NULL, delim);
	}
	argv[i] = NULL; /* Terminer le tableau par NULL */
}

/**
 * _getenv - Récupère la valeur d'une variable d'environnement.
 * @name: Le nom de la variable d'environnement à récupérer.
 * Return: Un pointeur vers la valeur de la variable d'environnement,
 * ou NULL si la variable n'existe pas.
 */

char *_getenv(const char *name)
{
	int i = 0;
	size_t name_len = strlen(name);

	while (environ[i] != NULL)
	{
		size_t j;

		for (j = 0; j < name_len; j++)
		{
			if (environ[i][j] != name[j])
			{
				break;
			}
		}

		if (j == name_len && environ[i][j] == '=')
		{
/*Retourne un pointeur vers la valeur de la variable d'environnement*/
			return (environ[i] + name_len + 1);
		}
		i++;
	}

/*Si la variable d'environnement n'est pas trouvée, retourne NULL*/
	return (NULL);
}
