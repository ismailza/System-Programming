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

<h3>5.	Les éditeurs de texte</h3>

Un éditeur de texte joue un rôle essentiel dans la manipulation et la conservation d'informations sous forme textuelle dans des fichiers. La commande « `cat` » est une première approche simplifiée de ce service.

**Utilisation de la Commande "`cat`" :**

La commande ```$ cat > fich1``` est utilisée pour démarrer une session d'édition de texte interactive avec la commande cat. Elle permet également de rediriger les données saisies vers un fichier spécifié, en l'occurrence, "`fich1`". Cela signifie que tout ce que vous tapez pendant cette session d'édition sera enregistré dans le fichier "fich1".
Après avoir entré le texte souhaité et appuyé sur "`CTRL D`" pour terminer la saisie, les données sont enregistrées dans le fichier "`fich1`".

**Affichage du Contenu du Fichier :**

La commande ```$ cat fich1``` est utilisée pour afficher le contenu du fichier "`fich1`" à l'écran. Le mot "`fich1`" est utilisé ici comme un argument pour la commande `cat`, indiquant que vous souhaitez afficher le contenu de ce fichier spécifique.

Lors de l’exécution de la commande `$ cat fich1`, le statut du mot "`fich1`" est celui d'un fichier existant dans le répertoire de travail. Le contenu du fichier "fich1" sera affiché à l'écran.

Il est important de noter que la commande cat est relativement basique en termes de fonctionnalités d'édition de texte. Pour des tâches d'édition de texte plus avancées, il existe des éditeurs de texte plus sophistiqués tels que `Vi`, `Emacs`, `XEmacs`, et d'autres, qui offrent un large éventail de fonctionnalités pour travailler efficacement avec des fichiers texte complexes.

<h3>7.	Noms génériques et principe de fonctionnement de la commande « ls »</h3>

La commande « `ls -a` » a été utilisée pour éditer la liste triée de tous les noms de fichiers du répertoire courant. Cependant, il est important de comprendre le fonctionnement de la commande « `ls` » et comment le shell gère `les noms génériques` de fichiers, également appelés `méta-caractères`.

**Construction de la sous-arborescence **: 
Une sous-arborescence a été créée sous le répertoire "`rep`" avec plusieurs niveaux de répertoires et de fichiers, y compris des fichiers cachés.

**Résultats des commandes :**

```
$ ls
```
Cette commande affiche les fichiers et répertoires du répertoire courant de manière concise, en excluant les fichiers cachés.

```
$ ls .
```
Cette commande affiche les fichiers et répertoires du répertoire courant de manière concise, y compris les fichiers cachés (notés par un point).

```
$ ls ..
```
Cette commande affiche les fichiers et répertoires du répertoire parent du répertoire courant de manière concise.

```
$ ls -a
```
Cette commande affiche tous les fichiers et répertoires du répertoire courant, y compris les fichiers cachés.

```
$ ls -a .
```
Cette commande affiche tous les fichiers et répertoires du répertoire courant, y compris les fichiers cachés, en spécifiant le répertoire courant avec un point.

```
$ ls -a ..
```
Cette commande affiche tous les fichiers et répertoires du répertoire parent du répertoire courant, y compris les fichiers cachés.

**Expansion des noms génériques :**

Le shell effectue l'expansion des noms génériques en suivant des règles précises de substitution. Voici comment il réalise cette expansion pour certains exemples :
-	`*` : Correspond à n'importe quelle chaîne de caractères.
-	`.*` : Correspond à tous les fichiers et répertoires cachés du répertoire courant.
-	`*/*` : Correspond à tous les fichiers et répertoires situés dans des sous-répertoires du répertoire courant.
-	`*/.*` : Correspond à tous les fichiers cachés situés dans des sous-répertoires du répertoire courant.
-	`.*/*` : Correspond à tous les fichiers et répertoires situés dans des sous-répertoires dont le nom commence par un point.
-	`.*/.*` : Correspond à tous les fichiers et répertoires dont le nom commence par un point situés dans des sous-répertoires dont le nom commence par un point.

Après avoir créé la sous-arborescence sous "`rep`" comme spécifié, les commandes suivantes ont été utilisées pour obtenir les résultats :
Tous les fichiers dont les noms sont un nombre compris entre 20 et 40 :
```
$ ls [2-4][0-9] 
```

Tous les fichiers dont le nom ne commence pas par « s. » :
```
$ ls [!s]* 
```

Recherche la chaîne de caractères "le système unix" en ignorant la casse et compte le nombre de ligne correspondant à l'occurrence de la chaîne :
```
$ grep -i "le système unix" fichier | wc -l 
```

<h4>Exercice 1</h4>

Pour que l'utilisateur "c1" modifie les droits d'accès sur le fichier "Fich1" afin d'obtenir la permission souhaitée "`-rwxr-xr-x 1 c1 cours884 Jul 7 Fich1`", il peut utiliser la commande chmod. Voici deux solutions : une solution numérique et une solution avec les actions.

**Solution numérique :**

La notation numérique des droits d'accès est une méthode couramment utilisée pour définir les permissions. Chaque type de permission est associé à un chiffre :
-	Lecture (r) : 4
-	Écriture (w) : 2
-	Exécution (x) : 1

Pour obtenir "`-rwxr-xr-x`", l'utilisateur "c1" doit donner toutes les permissions à lui-même (`7`) et les permissions de lecture et d'exécution aux autres (`5`). Voici la commande :
```
$ chmod 755 Fich1
```

**Solution avec les actions :**

On peut également modifier les droits d'accès en utilisant des actions "+" et "-" pour ajouter ou supprimer des permissions. Voici la séquence d'actions pour atteindre le résultat souhaité :
```
$ chmod u=rwx Fich1   # Donne toutes les permissions à l'utilisateur c1 (rwx).
```
```
$ chmod go=rx Fich1   # Donne la permission de lecture et d'exécution aux autres (go).
```

<h4>Exercice 2</h4>

Pour déterminer si les utilisateurs « c1 », « c2 » et « guest » peuvent exécuter les commandes données dans chaque configuration, nous devons examiner les droits d'accès sur le répertoire « d1 » ainsi que les droits d'accès sur le fichier « f1 » dans chaque configuration, en utilisant les règles suivantes :

a.	Pour accéder à un fichier, il faut avoir le droit de passage dans chacun des répertoires qui constituent son chemin (le droit de passage dans un répertoire est le droit d'exécution « x »).

b.	Pour écrire dans un fichier, il faut avoir l'autorisation d'écriture (« w ») sur ce fichier.

c.	Pour modifier les droits d'un fichier, il faut en être le propriétaire.

d.	Pour créer ou détruire un fichier, il faut avoir le droit d'écriture dans le répertoire contenant ce fichier, puisqu'il s'agit d'ajouter ou de supprimer un lien dans un répertoire.

**1.	Configuration 1 :**
```
drwxr-xr-- 2 c1 cours 1152 Jul 7 14:49 d1
-rw-rw-r-- 1 c1 cours 884 Jul 7 14:52 d1/f1
```

- `$ cp /tmp/x f1` Les utilisateurs "c1" et "c2" peuvent exécuter cette commande car ils ont le droit d'écriture sur le fichier "f1" en tant que membres du groupe "cours".
-	`$ cp /tmp/x f2` Seul l’utilisateur "c1" peut exécuter cette commande car c’est le seul qui a le droit d'écriture dans le répertoire "d1".
-	`$ rm f1` Seul l’utilisateur "c1" peut exécuter cette commande car c’est le seul qui a le droit d'écriture dans le répertoire "d1".

**2.	Configuration 2 :**
```
drwxrwxr-x 2 c1 cours 1152 Jul 7 14:49 d1
-rw-r--r-- 1 c1 cours 884 Jul 7 14:52 d1/f1
```
-	`$ cp /tmp/x f1` Seul l’utilisateur "c1" permet d’exécuter cette commande, car c’est le seul qui a le droit d’écriture sur le fichier "f1".
-	`$ cp /tmp/x f2` Les utilisateurs "c1" et "c2" peuvent également exécuter cette commande car ils ont le droit d'écriture dans le répertoire "d1" en tant que membres du groupe "cours".
-	`$ rm f1` Les utilisateurs "c1" et "c2" peuvent exécuter cette commande car ils ont le droit d'écriture sur "f1".

**3.	Configuration 3 :**
```
drwxrwxr-x 2 c1 cours 1152 Jul 7 14:49 d1
--------- 1 c1 cours 884 Jul 7 14:52 d1/f1
```
-	`$ cp /tmp/x f1` Aucun des utilisateurs ne peut pas exécuter cette commande, car ils n’ont pas le droit d’écriture sur le fichier "f1".
-	`$ cp /tmp/x f2` Les utilisateurs "c1" et "c2" peuvent également exécuter cette commande car ils ont le droit d'écriture dans le répertoire "d1" en tant que membres du groupe "cours".
-	`$ rm f1` Les utilisateurs "c1" et "c2" peuvent exécuter cette commande car ils ont le droit d'écriture sur "f1".

<h4>Exercice 3</h4>

La commande "`umask`" est utilisée pour définir les permissions par défaut des fichiers nouvellement créés dans un système Unix ou Linux. Elle agit en masquant les permissions que vous ne souhaitez pas accorder par défaut. En d'autres termes, elle spécifie les autorisations qui seront retirées des fichiers lors de leur création. La valeur de la commande "`umask`" est soustraite des autorisations par défaut pour déterminer les autorisations réelles des fichiers créés.

Pour créer un sous-répertoire "rep1" avec les droits "`rwxrw-r--`" dès sa création, on doit utiliser la commande "`umask`" pour définir la valeur appropriée avant de créer le répertoire. 

En comparant les permissions du répertoire "`rep1`" et du fichier "`f1`", on constate que le répertoire "rep1" a les droits "`drwxrw-r--`", tandis que le fichier "f1" a les droits "`-rw-rw-r--`".

Cela démontre que la commande "`umask`" affecte les valeurs par défaut des permissions des fichiers et des répertoires nouvellement créés. Les répertoires ont généralement des permissions par défaut plus permissives que les fichiers, car ils doivent permettre l'accès aux fichiers qu'ils contiennent.

<h4>Exercice 4</h4>

Pour tester l'existence d'un fichier ou d'un répertoire dans un système Unix ou Linux, on peut utiliser la commande "`test`" avec l'option "`-e`". La syntaxe générale est la suivante :

```
$ test -e chemin_vers_le_fichier_ou_répertoire
```
Ou en utilisant la forme abrégée avec des crochets :

```
$ [ -e chemin_vers_le_fichier_ou_répertoire ]
```
Si le fichier ou le répertoire existe, la commande renverra un code de retour (exit code) de 0, ce qui indique le succès. Si le fichier ou le répertoire n'existe pas, la commande renverra un code de retour différent de 0, ce qui indique l'échec.

Pour récupérer le résultat, on peut afficher le code de retour par la commande : 
```
$ echo $? 
```
ou bien utiliser un script shell pour conditionner des actions en fonction de l'existence d'un fichier ou d'un répertoire :
```
if [ -e "/chemin/vers/le/fichier_ou_repertoire" ]; then
    echo "Le fichier ou répertoire existe."
else
    echo "Le fichier ou répertoire n'existe pas."
fi
```

<h3>8.  Communication entre processus : première approche</h3>
<h4>Exercice 1</h4>

1. Exécuter la ligne de commande :
```
$ ps -alx | grep bash
```

2. Création d'un fichier `text1`:
```
cat > text1
1 : la commande pipe sert à la communication entre processus
3 : la commande tee est utile pour capturer les informations qui circulent dans un pipe
2 : la commande tee recopie son entrée standard sur sa sortie standard et sur un fichier
4 : la commande tee peut être utilisée pour sauvegarder dans un fichier les traces des informations qui circulent sur sa sortie standard.
1 : qu’est-ce qu’un pipe et que fait la commande tee ?
```
  i. le nombre de ligne contenant le mot « `pipe` » dans le fichier « text1 »:
  ```
  $ grep pipe text1 | wc -l
  ```

  ii. récupérer dans un fichier « `text2` » les lignes contenant le mot « `pipe` »:
  ```
  $ grep pipe text1 | tee text2
  ```

  iii. Ecrire une ligne de commande qui permettent de créer un fichier « text3 » qui contiendra les lignes du fichier « text1 » contenant le mot « `pipe` ». Ces lignes devront être triées sur le premier champ de chaque ligne. Enfin la commande affiche le nombre de ces lignes:
  ```
  $ grep pipe text1 | sort -n | tee text3 | wc -l
  ```

<h4>Exercice 2</h4>

  a.	Nombre de processus actifs sur le système : 
  ```
  $ ps | wc -l
  ```

  b.	
  -	Nombre d’utilisateurs connectés sur le système :   
    ```
    $ who | wc -l 
    ```
  -	Liste triée des utilisateurs connectés sur le système
    
    i.	Par ordre alphabétique : 
      ```
      $ who | sort
      ```
    ii.	Selon l’heure de connexion : 
      ```
      $ who | sort -k3,4
      ```

  c.	Nombre de fichiers répertoire dans le répertoire "`/etc`" : 
  ```
  $ ls -l /etc | grep "^-" | wc -l
  ```

  d.	Nombre de sous-répertoires dans le répertoire "`/etc`" : 
  ```
  $ ls -l /etc | grep "^d" | wc -l
  ```

  e.	Liste des fichiers du répertoire courant, triée par ordre de taille des fichiers : 
  ```
  $ ls -lS
  ```

<h4>Exercice 3</h4>

  1.	Création des fichiers fich1 et fich2 en utilisant la commande "`cat`" :
  ```
  $ cat > fich1
  Contenu du fichier fich1.
  ^D 	# sauvegarder le fichier
  $ cat > fich2
  Contenu du fichier fich2.
  ^D 	# sauvegarder le fichier
  ```
  
  Création de fichier fich3 constituant la concaténation de fich1 et fich2 :
  ```
  $ cat fich1 fich2 > fich3
  ```

  2.	En exécutant la commande 
  ```
  $ cat fich1 fich-inexistant 
  ```
  avec "fich1" existant et "fich-inexistant" inexistant, elle affiche le contenu du fichier "fich1" puis un message d’erreur indiquant que "fich-inexistant" n'existe pas.

  3.	Les deux commandes 
  ```
  $ cat fich1 fich-inexistant > trace 
  ```
  et 
  ```
  $ cat fich1 fich-inexistant 1>trace 
  ```
  redirigent la sortie standard vers un fichier nommé "`trace`". La différence réside dans la façon dont la redirection est spécifiée. La première commande utilise uniquement `>`, tandis que la deuxième utilise `1>` pour indiquer explicitement la redirection de la sortie standard.

  4.	Pour lancer la commande 
  ```
  $ cat fich1 fich-inexistant
  ```
  en redirigeant la sortie d'erreur vers le fichier "`err`", on peut utiliser `2>` pour la redirection de la sortie d'erreur : 
  ```
  $ cat fich1 fich-inexistant 2> err
  ```
<h3>9.	Gestion des processus</h3>

Pour commencer, nous avons créé les fichiers de commandes "`com1`", "`com2`", et "`com3`". Cependant, lors de l'exécution de "com1", nous avons rencontré un problème où "com1" n'était pas trouvé. Pour résoudre ce problème, nous avons suivi les étapes suivantes :

**1.	Spécifier le chemin du fichier exécutable ou ajouter au PATH**

Lors de l'exécution de "com1" avec ````$ ./com1````, nous avons spécifié le chemin relatif du fichier "`com1`". Pour que cela fonctionne, nous pouvons également ajouter le chemin du répertoire contenant "com1" au `PATH` en utilisant la commande suivante :
```
$ PATH=$PATH:`pwd`
```
Cela permet au shell de rechercher les exécutables dans le répertoire actuel.

**2.	Ajouter le droit d'exécution**

Après avoir résolu le problème de recherche de fichier, nous avons rencontré un autre problème de permissions. Pour résoudre ce problème, nous avons ajouté le droit d'exécution au fichier "com1" en utilisant la commande `chmod` :
```
$ chmod u=rwx com1
```
Cela accorde le droit d'exécution au fichier "com1", permettant son exécution.

**3.	Ajouter le droit d'exécution à "com2" et "com3"**

Enfin, pour exécuter "com1" avec succès, nous avons ajouté le droit d'exécution aux fichiers "com2" et "com3" en utilisant les commandes suivantes :
```
$ chmod u=rwx com2
$ chmod u=rwx com3
```
Après avoir suivi ces étapes, nous avons pu lancer "com1" avec succès en utilisant la commande `$ com1`. Pour rediriger les traces dans un fichier "trace1", nous avons utilisé la commande 
```
$ com1 > trace1
```

**Utilisation de la commande "."**

Pour utiliser la commande "`.`", nous avons repris les fichiers correspondant aux commandes "com1", "com2", et "com3" et remplacé les appels aux commandes "com?" par ". com?". Nous avons créé de nouveaux fichiers "com1p", "com2p", et "com3p" ainsi modifiés.

Après la création de ces fichiers, nous avons ajouter le droit d’exécution à ces fichiers en utilisant la commande chmod.
Pour lancer "com1p" en utilisant la commande `$ ./com1p` et rediriger les traces dans le fichier "trace2", nous avons utilisé la commande suivante :
```
$ ./com1p > trace2
```

**Utilisation de la commande ” exec ”**

Pour utiliser la commande " exec ", nous avons repris les fichiers correspondant aux commandes "com1", "com2", et "com3" et remplacé les appels aux commandes "com?" par "exec com?". Nous avons créé de nouveaux fichiers "com1e", "com2e", et "com3e" ainsi modifiés.

Pour lancer "com1e" en utilisant la commande exec et rediriger les traces dans le fichier "trace3", nous avons utilisé la commande suivante :
```
$ exec com1e > trace3
```

**Conclusion**

La gestion des processus en utilisant le shell Bash nécessite une attention particulière aux `chemins` d'accès aux fichiers exécutables et aux `permissions`. Les problèmes liés à la recherche de fichiers peuvent être résolus en spécifiant des chemins relatifs ou absolus ou en modifiant la variable `$PATH`. 
De plus, les problèmes de permissions peuvent être résolus en utilisant la commande chmod pour accorder les droits d'exécution nécessaires aux fichiers.
