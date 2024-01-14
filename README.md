# Monopoly
Progetto finale Laboratorio di Programmazione

## Descrizione del Progetto
Il progetto è un'implementazione semplificata del 
celebre gioco da tavolo Monopoly, sviluppato come test finale del 
corso di "Laboratorio di Programmazione" del secondo anno di Ingegneria Informatica.

## Membri del Gruppo
- Matteo Trevisan
- Elia Tolfo
- Andrea Sacchetto

## Struttura del Codice

[Project structure](Project_Structure_Canvas.png)
![Project structure](Project_Structure_Canvas.png)

## Funzionalità Implementate
- Ogni terreno può essere migliorato costruendo una casa, oopure un albergo (per
semplicità, si suppone che su ogni proprietà esista al massimo una casa, e il passaggio successivo sia l'albergo).
- Nel progetto sono state implementate tutte le funzionalità richieste all'interno del file pdf contenente la 
consegna dettagliata. Si tratta di funzionalità che riprendono i caratteri generali del gioco originale, ma su 
cui sono state apportate alcune modifiche o semplificazioni per la sua realizzazione.
- Resta comunque quella che è l'idea originale del gioco, nel quale diversi giocatori concorrono strategicamente
su un tabellone composto da 28 caselle. Queste rappresentano terreni, ognuno appartenente a differenti categorie, 
facendo così in modo che ogni terreno abbia proprietà differenti.
- I giocatori a turno lanciano i dadi e avanzano di tante caselle quanto è il risultato ottenuto. A seconda della 
casella su cui si capita sarà possibile per il giocatore acquistare il territorio, in caso nessun altro ne sia 
già in possesso, o edificarci sopra una casa o un hotel nel caso il giocatore stesso ne sia già proprietario.
- L'acquisto e l'edificazione di un terreno fanno in modo che se nei turni successivi un giocatore diverso dal 
proprietario "cada" su quella casella, si troverà obbligato a pagare al proprietario una determinata somma di 
fiorini, la quale verrà identificata in base alle diverse tipologie di terreni.


## Screenshot

## Istruzioni alla compilazione
Il progetto è compilato utilizzando CMake; per procedere con la compilazione, seguire le istruzioni di seguito:

`$ mkdir build`

`$ cd build`

`$ cmake ..`

`$ make`

oppure usare lo script _build_project.sh_ dedicato.
(Potrebbe essere necessario formire il permesso di esecuzione `$ sudo chmod +x build_project.sh`)

## Esempi di Utilizzo



## Possibili Miglioramenti Futuri