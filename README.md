Suite de rainfall et des recherches de failles de code non protégé via son ASM et possible buffer overflow, de nouveau à travers de petits exercices.

Une fois de plus, le projet s'est effectué dans une VM minutieusement organisée par l'école, avec de très nombreuses sécurités désactivées, où l'élève doit chercher la faille avec son user actuel, et récupérer le mot de passe du suivant. Un compte rendu est écrit dans le ```walkthrough.md``` de chaque niveau, et une reconstruction du code C est présente dans le ```source.c``` fichier.

Failles de chaque niveau:

0. ASM ```cmp```
1. Stack-based buffer overflow - Mauvaise len de strncmp
2. printf format string - Stack dump
3. XOR enconding
4. Stack-based buffer overflow - Obstruction ptrace
5. Stack-based buffer overflow - Global Offset Table
6. Debug avec gdb - Obstruction ptrace
7. Stack-based buffer overflow - Obstruction
8. Erreur de logique - Chemin relatif

Faille de niveau bonus:

9. Double Stack-based buffer overflow - strncmp
