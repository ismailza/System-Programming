<h1 align="center">Programmation Système</h1>

<h2>TP1 – Programmation Bash</h2>

<h3>Exercice 1</h3>

Ecrire un programme shell `repcour` qui affiche le nom de connexion de l'utilisateur et le chemin absolu de son répertoire courant de la manière suivante : 
```bash
$ repcour
mon nom de connexion est : ismail
mon repertoire courant est : /home/ismail
$
```

<h3>Exercice 2</h3>

Ecrire un programme shell `untrois` qui demande à l'utilisateur de saisir une suite de mots constituée d'au moins trois mots et qui affiche sur la même ligne le premier et le troisième mot saisis. 

Ex : 
```
$ untrois 
Entrez une suite de mots : un petit coucou de Rodez 
un coucou 
$
```

<h3>Exercice 3</h3>

Ecrire un programme shell `nbmots` qui demande à l'utilisateur de saisir une suite quelconque de mots puis affiche le nombre de mots saisis.
```
$ nbmots
Entrez une suite de mots : un deux trois quatre cinq 
5 => 5 mots ont été saisis 
$
```

<h3>Exercice 4</h3>

Ecrire un programme shell `cp2fois` prenant trois arguments : le premier désigne le nom du fichier dont on veut copier le contenu dans deux fichiers dont les noms sont passés comme deuxième et troisième arguments. Aucun cas d'erreur ne doit être considéré.

<h3>Exercice 5</h3>

Ecrire un programme shell `taille` qui prend un nom de fichier en argument et affiche ses droits d’accès et sa taille. On ne considère aucun cas d'erreur.
<h3>Exercice 6</h3>

A l'aide de la commande unix date, écrire un programme shell jour qui affiche le jour courant du
mois 

```
$ date 
dimanche 22 octobre 2006, 18:33:38 (UTC+0200) 
$ 
$ jour 
22 
$
```

<h3>Exercice 7<h3>

Ecrire un programme shell nbconnect qui affiche le nombre d'utilisateurs connectés sur la machine locale

<h3>Exercice 8<h3>

Ecrire un programme shell uid qui affiche l'uid de l'utilisateur. On utilisera la commande unix id, la commande interne set et la variable prédéfinie IFS.

<h3>Exercice 9<h3>

En utilisant la commande unix ls et le mécanisme de redirection, écrire un programme shell
dansbin prenant un nom de commande en argument et qui affiche 0 si cette commande est
présente dans /bin, une valeur différente de 0 sinon. 

```
$ dansbin ls 
0 
$ dansbin who 
2 
$
```