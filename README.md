# Simple shell

## Description
Simple shell est un interpréteur de commandes UNIX simple
## Compilation
Utilisez la ligne de commande suivante pour compiler tous les fichiers avec l'extension .c:<br>
**gcc -Wall -Werror -Wextra -pedantic -std=gnu89 `*.c` -o simple_shell_0.4.c**
## Exigences (requirements)
Ubuntu 20.04 LTS<br>
Nos programmes répondent aux exigences de style Betty. Ils ont été vérifiés avec betty-style.pl et betty-doc.pl
## Exemples d'utilisation
**Modes interacif:**<br>
MacBook-Pro-de-Laamri-10:holbertonschool-simple_shell laamrisaid$ ./Simple_shell_0.4<br>
$ ls<br>
AUTHORS commands.c Images_README man_1_simple_shell README.md shell.h Simple_shell_0.4 utils.c Simple_shell_0.4.c<br>
$<br>
**et non-interactif:**<br>
MacBook-Pro-de-Laamri-10:holbertonschool-simple_shell laamrisaid$ echo -e "/bin/ls" | ./Simple_shell_0.4<br>
AUTHORS commands.c Images_README man_1_simple_shell README.md shell.h Simple_shell_0.4 utils.c Simple_shell_0.4.c<br>
## Tests
Vérification des éventuelles fuites de mémoire avec l'utilisation de **leaks**:
1. Compiler le programme à vérifier. simple_shell_0.1.c, par exemple:
**gcc -Wall -Werror -Wextra -pedantic -std=gnu89 simple_shell_0.4.c -o simple_shell_0.4**
3. Exécuter le programme en arrière-plan en utilisant l'opérateur &:
**./simple_shell_0.4 &**
4. Trouver l'ID du programme (simple_shell_0.4.c) en utilisant la commande ps. Ici **99995**
5. Utiliser leaks avec le PID du programme.<br>
commande leaks 99995<br>
