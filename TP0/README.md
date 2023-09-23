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

