# Exercice 3

1. Le programme prend en argument en ligne de commande un nombre nb.
Il initialise un compteur i à 0 et crée un tableau tube[2] pour stocker les descripteurs de fichiers du tube.
Le programme lance une boucle do-while, à chaque itération de la boucle, un tube anonyme est crée, et un processus fils est crée.
Si le processus est fils, il ferme le descripteur d'écriture de tube, et affecte à la variable in tube[0].
Si le processus est le parent, il ferme le descripteur de lecture de tube, et affecte tube[1] à la variable out.

nb = 3

## Itération 1: i = 0
`P0`                  `tube1`     `P1`
-in=STDIN_FILENO                  -in=tube[0]
-out=tube[1]                      -out=STDOUT_FILENO
-i=0                              -i=0
                                  -i++

`P0 affiche : Processus 0`

## Itération 2: i = 1

`P1`                  `tube2`     `P2`
-in=tube[0]                       -in=tube[0]
-out=tube[1]                      -out=STDOUT_FILENO
-i=1                              -i=1
                                  -i++

`P1 affiche : Processus 1`

## Itération 3: i = 2 (i < (nb - 1))
P2 sort de la boucle

`P2 affiche : Processus 2`