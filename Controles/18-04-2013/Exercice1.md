# Exercice 1

1. Vrai, la création d'un processus sous UNIX est réalisée par duplication de l’espace d’adressage et de certaines tables du processus créateur, le processus fils hérite des données de son père à l'instant de la création, mais les deux processus fonctionnent de manière indépendante.

2. 
  2.1. Un processus bloqué peut passer à l'état prêt en raison de deux événements :
    - Terminaison d'une opération d'attente : Un processus peut être bloqué en attendant qu'une ressource (entrée/sortie, un signal, ...) soit disponible. Lorsque cette ressource devient disponible, le processus peut passer de l'état bloqué à l'état prêt.
    - Réception d'un signal : Certains systèmes d'exploitation permettent aux processus de recevoir des signaux (comme le signal SIGCONT). Si un processus est bloqué en raison d'un signal spécifique, la réception de ce signal peut le faire passer de l'état bloqué à l'état prêt.
  
  2.2. En général, un processus en état prêt ne peut pas passer directement à l'état bloqué sans passer par l'exécution. Pour passer de prêt à bloqué, le processus doit d'abord être exécuté et, pendant son exécution, il peut rencontrer des conditions qui le font passer à l'état bloqué.

1. Le nombre maximal de processus crées par la séquence suivante (supposez que le code de `file.exe` ne crée pas de nouveaux processus et que les appels système ne retournent pas d'erreur) :
    ```
    fork(); fork(); execvp("file.exe", com); fork(); fork();
    ```
```
                  P0
        P0                  P1
    P0      P2          P1      P3

```
Le nombre maximal de processus crées est 4 processus.

4. Le programme décrit n'est pas déterministe en raison de l'accès concurrentiel au compteur global par les trois threads.
La valeur finale du compteur dépend de la manière dont les opérations d'incrémentation sont intercalées entre les threads, ce qui peut varier d'une exécution à l'autre en raison de la concurrence.
Les valeurs possibles du compteurs à la fin d'exécution sont : 1, 2 ou 3.

5. Non, car les threads partagent la même table de descripteurs de fichiers. La fermeture fermeture entrainera la perte d'accès au pipe.

6. Lorsqu'un processus est bloqué ou dans une boucle infinie.