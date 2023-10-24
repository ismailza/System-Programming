<h1 align="center">Programmation Système</h1>

<h2>TP1 – Programmation Bash</h2>

### Exercice 1 
Ecrivez un script qui convertit en minutes et secondes un temps exprimé en secondes (le temps est passé en paramètre). 

### Exercice 2
Ecrivez un script qui affiche, pour tous les utilisateurs passés en arguments du script, le nom de l’utilisateur, le répertoire de connexion et le shell. 

### Exercice 3  
Ecrivez un script qui enregistre dans un fichier les lignes saisies au clavier, et qui affiche le nombre de lignes qui ont été enregistrées. 

### Exercice 4
Ecrivez un script qui prend tous les fichiers ordinaires du directory courant et les copient dans un directory `ARCHIVES`

### Exercice 5 
Ecrivez un script qui détruit tous les fichiers passés en argument : il affiche d’abords les 5 premières lignes et si la personne le veut détruit le fichier. 

### Exercice 6 
Ecrivez un script qui prend un fichier en argument, ajoute en tête du fichier la date. 

### Exercice 7
Créez la commande `copier`. La commande reçoit en argument deux noms de fichiers, la source et la destination. Le script se termine et affiche un message d’erreur si l’une des conditions suivantes est réalisée :
<ul>
  <li>Le nombre d’arguments est incorrect.</li>
  <li>Le fichier source n’existe pas ou il n’est pas copiable (pas d’accès en lecture).</li>
  <li>Le fichier source n’est pas un fichier ordinaire.</li>
  <li>Le fichier destination existe.</li>
  <li>Le répertoire de destination, que l’on peut connaître avec la commande 'dirname', n’est pas accessible en écriture.</li>
  <li>La copie a échoué.</li>
</ul>

### Exercice 8 
Ecrire un script qui concatène deux fichiers dans un troisième. Veuillez  contrôler que les fichiers et les permissions sont valides.

### Exercice 9 
Réaliser un programme de gestion d’agenda téléphonique. Chaque enregistrement contient le nom d’une personne et son numéro de téléphone. Les deux champs sont séparés par une virgule. Le programme affiche le menu suivant : 
``` 
1. Ajouter une nouvelle fiche 
2. Rechercher une fiche (avec une partie du nom)
3. Détruire une fiche 
4. Modifier une fiche 
5. Lister l’annuaire
6. Fin 
Votre choix ? :
```