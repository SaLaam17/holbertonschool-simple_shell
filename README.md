# Simple shell

## Description
Simple shell est un interpréteur de commandes UNIX simple
## Compilation
Utilisez la ligne de commande suivante pour compiler tous les fichiers avec l'extension .c:<br>
**gcc -Wall -Werror -Wextra -pedantic -std=gnu89 `*.c` -o simple_shell**
## Exigences (requirements)
La compilation de nos fichiers sources sera effectué sur un système d'exploitation Ubuntu 20.04 LTS.<br>
Nos programmes répondent aux exigences de style Betty. Ils ont été vérifiés avec betty-style.pl et betty-doc.pl
## Exemples d'utilisation
**Mode interacif:**<br>
MacBook-Pro-de-Laamri-10:holbertonschool-simple_shell laamrisaid$ ./Simple_shell<br>
$ ls<br>
AUTHORS commands.c Images_README man_1_simple_shell README.md shell.h utils.c Simple_shell.c<br>
$<br>
**Mode non-interactif:**<br>
MacBook-Pro-de-Laamri-10:holbertonschool-simple_shell laamrisaid$ echo -e "/bin/ls" | ./Simple_shell<br>
AUTHORS commands.c Images_README man_1_simple_shell README.md shell.h utils.c Simple_shell.c<br>
## Tests
Vérification des éventuelles fuites de mémoire avec l'utilisation de **leaks**:
1. Compiler le programme à vérifier. simple_shell.c, par exemple:
**gcc -Wall -Werror -Wextra -pedantic -std=gnu89 simple_shell.c -o simple_shell**
3. Exécuter le programme en arrière-plan en utilisant l'opérateur &:
**./simple_shell &**
4. Trouver l'ID du programme (simple_shell.c) en utilisant la commande ps. Ici **2237**
5. Utiliser leaks avec le PID du programme.<br>
commande leaks 2237<br>
   ![Capture_ecran](Leaks.png)

![Flowchart_simple_shell drawio](https://github.com/user-attachments/assets/e90b2a35-c884-46f2-918b-50b08da245e3)

