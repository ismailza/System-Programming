<h1 align="center">Programmation Système</h1>

<h2>TP0 – Rappel sur Système d’exploitation UNIX</h2>

<h3>1.  Connexion au système et ouverture de sessions de travail</h3>
<h4>1.1.  Session d'Ouverture</h4>

  Avant de pouvoir travailler sur le système, il est impératif de se connecter en utilisant un compte d'utilisateur associé à un mot de passe. Chaque utilisateur possède son propre espace de stockage en mémoire secondaire, appelé « `home directory` », ainsi qu'un environnement d'interprétation par défaut, tel que le `Shell bash` sous Linux. Ces informations sont stockées dans le fichier `/etc/passwd`, qui répertorie les utilisateurs du système.

<h4>1.2.  Manipulation de Fichiers</h4>

  Pour interagir avec le système et les fichiers, nous avons utilisé diverses commandes, notamment `cat`, `passwd`, `cal`, `date`, etc. La commande `cat` est utile pour afficher le contenu d'un fichier texte, comme illustré par l'exemple 
```
$ cat /etc/passwd
```

  En exécutant cette commande, nous avons pu visualiser la liste des utilisateurs du système ainsi que leurs informations associées. Cette sortie nous a permis de mieux comprendre la structure du fichier `/etc/passwd` et de voir comment les informations des utilisateurs sont stockées.

<h4>1.3.	Changement de Mot de Passe</h4>

  Après avoir ouvert une session en utilisant notre compte d'utilisateur personnel, nous avons exploré la possibilité de changer notre mot de passe pour des raisons de sécurité ou de gestion de compte.
  Pour changer le mot de passe, nous avons utilisé la commande suivante : 
```
$ passwd
```

<h4>1.4.	Sortie de la boucle du Shell</h4>

  Le Shell suit un cycle continu où il affiche le prompt (invite) pour attendre des commandes, interprète ces commandes, puis revient à l'invite pour attendre de nouvelles instructions. Cela crée une boucle de travail continue.
  Pour sortir de cette boucle et quitter la session du Shell, nous avons utilisé la commande suivante : 
  ```
  $ exit
  ```
  Lorsque nous avons exécuté cette commande, le Shell a immédiatement arrêté la session en cours et nous a déconnectés du système. Cela nous a permis de revenir à l'environnement de travail précédent ou de quitter complètement la session, selon le contexte.

<h3>2.  Les commandes</h3>

  Parmi les informations dont peut avoir besoin une commande, on trouve les options et les paramètres. C'est ainsi qu'une commande peut être lancée seule, avec une ou plusieurs options, un ou plusieurs paramètres ou les deux (`options` et `paramètres`). Unix est un système multi-utilisateur, c'est-à-dire qu'il permet plusieurs sessions d'être ouvertes en même temps. La commande « `who` » permet de connaître les sessions en cours.

<h4>2.1.  Analyse des Commandes et Commentaires</h4>

```
$ who
```
Cette commande affiche la liste des utilisateurs actuellement connectés au système. Elle fournit des informations telles que le nom de l'utilisateur, le terminal ou la session à laquelle il est connecté, ainsi que la date et l'heure de la connexion.

```
$ who -H
```
L'option -H modifie le format de sortie de la commande who en incluant des en-têtes de colonnes pour une meilleure lisibilité. Le résultat affiche les en-têtes "`NOM D'UTILISATEUR`", "`TERMINAL`", et "`DATE DE CONNEXION`" avant la liste des utilisateurs connectés.

```
$ whoami
```
Cette commande affiche uniquement les informations de l'utilisateur actuel, c'est-à-dire celui qui a lancé la commande. Elle indique le nom de l'utilisateur et le terminal de la session en cours.

```
$ who -y
```
L'option `-y` n'est pas une option valide pour la commande who. L'exécution de cette commande générera un message d'erreur indiquant que l'option est inconnue.

```
$ who --help
```
L'option `--help` est souvent utilisée pour afficher un message d'aide sur la manière d'utiliser la commande. Elle renverra généralement une brève description des options disponibles pour la commande who.

```
$ wich
```
Cette commande permet de retrouver le fichier exécutable correspondant à une commande donnée.
Par exemple, en tapant la commande `$ which who`, nous cherchons à localiser l'emplacement du fichier exécutable associé à la commande `who`.
Dans cet exemple, "`who`" n'est pas considéré comme une option de la commande "which". Au contraire, "`who`" est l'argument de la commande "which", ce qui signifie que nous recherchons l'emplacement de l'exécutable "`who`".

```
$ man commande_choisie
```
Cette commande permet d’obtenir des informations détaillées sur l'utilisation d'une commande, où "`commande_choisie`" est le nom de la commande pour laquelle on souhaite des informations.
Pour quitter le manuel, il suffit de taper la lettre « `q` » (comme « `quit` »).
```
$man man
```
Cette commande permet d’accéder au manuel de la commande "`man`" elle-même.

<h3>3.	Quelques commandes utiles</h3>

```
$ cat
``` 
Cette commande est utilisée pour concaténer et afficher le contenu des fichiers texte.

```
$ date
``` 
Cette commande affiche la date et l'heure actuelles du système.

```
$ wc
``` 
Cette commande compte le nombre de lignes, de mots et d'octets dans un fichier.

```
$ wc -l
``` 
Cette commande compte uniquement le nombre de lignes dans un fichier.

```
$ cal
``` 
Cette commande affiche un calendrier du mois en cours.

```
$ cal -j
``` 
Cette commande affiche un calendrier en utilisant le format julien, qui est un système de comptage des jours.

```
$ which
```
Cette commande recherche et affiche le chemin de l'exécutable d’une commande.

```
$ touch 
```
Cette commande crée un nouveau fichier vide dans le répertoire courant.

```
$ grep
```
Cette commande recherche un mot dans un fichier et affiche toutes les lignes qui contiennent ce mot.

```
$ dd 
```
Cette commande est un utilitaire de transfert de données puissant et flexible. Si elle est utilisée sans arguments, elle attend que l'utilisateur fournisse une entrée.

<h3>4.	Répertoire de travail</h3>

```
$ pwd 
```
Cette commande affiche le répertoire de travail actuel.

```
$ ls 
```
Cette commande liste les fichiers et répertoires du répertoire de travail.

```
$ ls -l 
```
Cette commande liste les fichiers et répertoires du répertoire de manière détaillée, montrant les permissions, le propriétaire, la taille, la date de modification, etc.

```
$ ls -a
```
Cette commande liste tous les fichiers et répertoires, y compris ceux qui sont cachés.

```
$ ls -al 
```
Cette commande liste tous les fichiers et répertoires du répertoire de manière détaillée, y compris les fichiers et répertoires cachés.

```
$ rm essai 
```
Cette commande supprime le fichier nommé "essai" du répertoire de travail.

```
$ ls -l 
```
Cette commande liste à nouveau les fichiers et répertoires du répertoire après avoir supprimé le fichier "essai".

```
$ mkdir SE_essais 
```
Cette commande crée un nouveau répertoire nommé "SE_essais" dans le répertoire de travail.

```
$ ls -l 
```
Cette commande liste à nouveau les fichiers et répertoires du répertoire après avoir créé le répertoire "SE_essais".

```
$ cd SE_essais
```
Cette commande change le répertoire de travail actuel pour le répertoire "SE_essais".

```
$ pwd 
```
Cette commande affiche le nouveau répertoire de travail actuel, qui est maintenant "SE_essais".

```
$ ls 
```
Cette commande liste les fichiers et répertoires du répertoire "SE_essais".

```
$ touch toto 
```
Cette commande crée un nouveau fichier nommé "toto" dans le répertoire "SE_essais".

```
$ ls -l 
```
Cette commande liste les fichiers et répertoires du répertoire "SE_essais" après avoir créé le fichier "toto".

```
$ cd 
```
Cette commande ramène le répertoire de travail actuel à votre répertoire personnel.
```
$ pwd 
```
Cette commande affiche le répertoire de travail actuel, qui est votre répertoire personnel.

```
$ ls -l 
```
Cette commande liste les fichiers et répertoires de votre répertoire personnel.

```
$ cd /etc 
```
Cette commande change le répertoire de travail actuel pour le répertoire système "/etc", qui contient les fichiers de configuration du système.

```
$ pwd 
```
Cette commande affiche le nouveau répertoire de travail actuel, qui est maintenant "/etc".

```
$ ls -l 
```
Cette commande liste les fichiers et répertoires du répertoire "/etc".

```
$ which cd 
```
Cette commande recherche et affiche le chemin de l'exécutable de la commande "cd".

```
$ which date 
```
Cette commande recherche et affiche le chemin de l'exécutable de la commande "date".

```
$ cd /bin 
```
Cette commande change le répertoire de travail actuel pour le répertoire système "/bin", qui contient les exécutables de base du système.

```
$ pwd 
```
Cette commande affiche le nouveau répertoire de travail actuel, qui est maintenant "/bin".

```
$ ls -l 
```
Cette commande liste les fichiers et répertoires du répertoire "/bin".

```
$ cd 
```
Cette commande ramène le répertoire de travail actuel à votre répertoire personnel.

```
$ pwd 
```
Cette commande affiche à nouveau votre répertoire personnel.

```
$ ls -l 
```
Cette commande liste les fichiers et répertoires de votre répertoire personnel.

