# Monopoly
Progetto finale laboratorio di programmazione


Note sul progetto:
- A inizio partita le casella angolari sono della banca, quelle normali di nessuno


---
## Note sui prezzi
### Config come da direttive:

| | Economica | Standard | Lusso |
| -- |-----------|----------|-------|
| Acquisto terreno| 6         | 10       | 20    |
| Acquisto casa | 3         | 5        | 10    |
| Miglioramento ad albergo | 3         | 5        | 10    |
| Pernottamento in casa | 2         | 4        | 7     |
| Pernottamento in albergo | 4         | 8        | 14    |

| Variabile | Valore |
| -- | -- |
|**Fiorini iniziali** | 100 |
| **Passaggio per il via** | 20 |
| **Numero turni massimo** | 30 |

`Config config = {{6,3,3,2,4, 'E'},
{10,5,5,4,8, 'S'},
{20,10,10,7,14, 'L'},
100, 20, 30};`

Su 1000 partite simulate, giocate con un giocatore umano ipotetico che risponde "si" ad ogni offerta
(comprare, migliorare), i risultati sono stati i seguenti;
- 978 vittorie di un giocatore computer per numero fiorini
- 20 pareggi tra 2 giocatori computer
- 2 vittorie del giocatore umano per numero fiorini


Con 20 turni massimi per partita:
- 960 vittorie di un giocatore computer per numero fiorini
- 39 pareggi tra 2 giocatori computer
- 1 pareggio tra 3 giocatori computer
- 0 vittorie o pareggi del giocatore umano


### Config sperimentale 1:

| | Economica | Standard | Lusso |
| -- |-----------|----------|-------|
| Acquisto terreno| 90        | 190      | 340   |
| Acquisto casa | 60        | 100      | 150   |
| Miglioramento ad albergo | 60        | 100      | 150   |
| Pernottamento in casa | 40        | 75       | 100   |
| Pernottamento in albergo | 135       | 175      | 250   |

| Variabile | Valore |
| -- |--------|
|**Fiorini iniziali** | 1500   |
| **Passaggio per il via** | 200    |
| **Numero turni massimo** | 100    |

`Config config = {{90,60,60,40,135, 'E'},
{190,100,100,75,175, 'S'},
{340,150,150,100,250, 'L'},
1500, 200, 100};`

Su 1000 partite simulate, giocate con un giocatore umano ipotetico che risponde "si" ad ogni offerta
(comprare, migliorare), i risultati sono stati i seguenti;
- 960 vittore del giocatore umano per numero di fiorini
- 39 vittore di uno dei computer per numero di fiorini
- 1 vittoria del giocatore umano perché è rimasto l'ultimo giocatore
- 0 pareggi

Se riduciamo il numero massimo di turni a 20, si ha:
- 979 vittorie di un giocatore computer per numero fiorini
- 21 pareggi tra 2 giocatori computer
- 0 vittorie o pareggi del giocatore umano

Invece con max_turni = 100 e soldi_al_via = 100:
- 555 vittore del giocatore umano per numero di fiorini
- 301 vittoria del giocatore umano perché è rimasto l'ultimo giocatore
- 144 vittore di uno dei computer per numero di fiorini 
- 0 pareggi