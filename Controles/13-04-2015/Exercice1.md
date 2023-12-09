# Exercice 1

1. Un appel à `fork()` retourne 0:\
  <input type="checkbox" disabled> dans le père\
  <input type="checkbox" disabled checked> dans le fils\
  <input type="checkbox" disabled> dans les deux\
  <input type="checkbox" disabled> en cas d'erreur

2. Processus appelant les primitives `wait` se met en état:\
  <input type="checkbox" disabled checked> endormi\
  <input type="checkbox" disabled> zombi\
  <input type="checkbox" disabled> prêt

3. La commande shell pour afficher le nombre d'erreur de compilations dans le fichier `test.c`:\
  <input type="checkbox" disabled checked> gcc test.c | grep err | wc -l\
  <input type="checkbox" disabled> wc -l err\
  <input type="checkbox" disabled> gcc test.c | wc -l

4. Un processus `zombi`:\
  <input type="checkbox" disabled> peut tuer son père\
  <input type="checkbox" disabled> peut seulement recevoir SIGCHLD\
  <input type="checkbox" disabled> devient orphelin quand son père se termine\
  <input type="checkbox" disabled checked> disparaît quand son père fait waitpid

5. L'exécution de `execlp("echo", "-n", "marron", NULL); printf("vert);` affiche:\
  <input type="checkbox" disabled> "vert"\
  <input type="checkbox" disabled> "marronvert"\
  <input type="checkbox" disabled checked> "marron"\
  <input type="checkbox" disabled> n'affiche rien 

6. Un processus qui a fait `pipe(t); close(t[0]); write(t[1], buf, strlen(buf));` \
  <input type="checkbox" disabled checked> est bloqué pour toujour\
  <input type="checkbox" disabled> ne peut plus jamais lire sur le tube\
  <input type="checkbox" disabled checked> reçoit le signal SIGPIPE\
  <input type="checkbox" disabled> est bloqué jusqu'à ce que les strlen(buf) caractères sont écrits

7. Après l'appel à `dup2(open("test", O_RDWR), 1);`\
  <input type="checkbox" disabled checked> la sortie standard est redirigée vers le fichier test\
  <input type="checkbox" disabled> l'écriture dans test est redirigée vers la sortie standard\
  <input type="checkbox" disabled> descripteur de fichier pour test est fermé\
  <input type="checkbox" disabled> le processus n'a plus de terminal

8. Un processus peut attendre l'arrivée d'un `signal` en utilisant la fonction\
  <input type="checkbox" disabled checked> pause\
  <input type="checkbox" disabled> wait\
  <input type="checkbox" disabled> sigprocmask

9. Après l'exécution du code `sigemptyset(&set); sigaddset(&set, SIGALARM); sigprocmask(SIG_BLOCK, &set, NULL);`, le processus:\
  <input type="checkbox" disabled checked> bloque tous les signaux sauf SIGALARM\
  <input type="checkbox" disabled> attend SIGALARM\
  <input type="checkbox" disabled> bloque SIGALARM