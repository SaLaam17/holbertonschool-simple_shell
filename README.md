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
AUTHORS                 commands.c<br>
Images_README           man_1_simple_shell<br>
README.md               shell.h<br>
Simple_shell_0.4        utils.c<br>
Simple_shell_0.4.c
$<br>
**et non-interactif:**<br>
MacBook-Pro-de-Laamri-10:holbertonschool-simple_shell laamrisaid$ echo -e "/bin/ls" | ./Simple_shell_0.4<br>
AUTHORS                 commands.c<br>
Images_README           man_1_simple_shell<br>
README.md               shell.h<br>
Simple_shell_0.4        utils.c<br>
Simple_shell_0.4.c<br>
MacBook-Pro-de-Laamri-10:holbertonschool-simple_shell laamrisaid$
ls; ls -la; pwd; cat; ...
## Tests
Vérification des éventuelles fuites de mémoire avec l'utilisation de **leaks**:
1. Compiler le programme à vérifier. simple_shell_0.1.c, par exemple:
**gcc -Wall -Werror -Wextra -pedantic -std=gnu89 simple_shell_0.1.c -o simple_shell_0.1**
3. Exécuter le programme en arrière-plan en utilisant l'opérateur &:
**./simple_shell_0.1 &**
4. Trouver l'ID du programme (simple_shell_0.1.c) en utilisant la commande ps. Ici **75823**
5. Utiliser leaks avec le PID du programme.
![Capture d'écran 1](images/Leaks_simple_shell_0.1.png)
