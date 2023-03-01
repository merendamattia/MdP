# Appunti di MdP - Metodologie di Programmazione

Benvenuti nella cartella degli appunti presi a lezione della materia "MdP - Metodologie di Programmazione". In questa cartella troverete una raccolta di appunti e materiali utili per lo studio di questa disciplina.

La materia "MdP - Metodologie di Programmazione" è un corso universitario che ha l'obiettivo di fornire una base solida per lo sviluppo di software di qualità. Durante il corso si studiano diverse metodologie di programmazione, con un'attenzione particolare alle best practices e alle tecniche di sviluppo software.

Gli appunti presenti in questa cartella sono stati presi durante le lezioni del corso e possono risultare utili per lo studio personale o per la preparazione degli esami.

La cartella è organizzata in modo da facilitare la ricerca di specifici argomenti, con file distinti per ogni argomento trattato durante il corso. In questo modo, potrete facilmente trovare gli appunti relativi al tema che vi interessa.

Vi informo inoltre che questa cartella è un progetto aperto e tutti sono invitati a partecipare alla raccolta degli appunti. Se avete preso degli appunti durante le lezioni del corso e volete condividerli con gli altri studenti, siete liberi di contribuire creando una pull request su GitHub.

Per mantenere l'ordine e la coerenza della cartella, vi chiediamo gentilmente di seguire le [linee guida](#linee-guida) per la formattazione e l'organizzazione degli appunti, che troverete nella cartella stessa.

Vi ricordo che gli appunti presenti in questa cartella sono forniti a titolo informativo e non sostituiscono in alcun modo lo studio dei testi di riferimento consigliati dal docente.

Buono studio!

# Linee Guida
Ecco un semplice elenco di linee guida da seguire per mantenere il codice il più ordinato e leggibile possibile.
- Effettuare sempre un `git pull` prima di qualsiasi `git push` e/o `git commit`
- Utilizzare il workframe di _Obsidian_
- Non utilizzare caratteri in stampato nel nome dei file
- Utilizzare sempre la numerazione dei file nel nome (i numeri indicano l'ordine degli argomenti trattati a lezione)
- Nel file `.md` inserire sempre un indice e un "ritorna all'indice" alla fine di ogni paragrafo / argomento
- Utilizzare il carattere `_` al posto degli "spazi" nel nome dei file
- Nel titolo della `pull request`, oltre ad inserire il tema trattato, aggiungere anche il proprio username. Ad esempio il titolo di questa `pull request` sarà: `Aggiunta linee guida (@merendamattia)`

### Esempio ridenominazione file
Il primo argomento trattato a lezione è stato quello del significato di "Hello, world!".
Nome file: `01-helloworld.md`.

---

# Markdown Cheat Sheet

Thanks for visiting [The Markdown Guide](https://www.markdownguide.org)!

This Markdown cheat sheet provides a quick overview of all the Markdown syntax elements. It can’t cover every edge case, so if you need more information about any of these elements, refer to the reference guides for [basic syntax](https://www.markdownguide.org/basic-syntax) and [extended syntax](https://www.markdownguide.org/extended-syntax).

## Basic Syntax
These are the elements outlined in John Gruber’s original design document. All Markdown applications support these elements.

### Heading
# H1
## H2
### H3

### Bold
**bold text**

### Italic
*italicized text*

### Blockquote
> blockquote

### Ordered List
1. First item
2. Second item
3. Third item

### Unordered List
- First item
- Second item
- Third item

### Code
`code`

### Horizontal Rule
---

### Link
[Markdown Guide](https://www.markdownguide.org)

### Image
![alt text](https://www.markdownguide.org/assets/images/tux.png)

## Extended Syntax
These elements extend the basic syntax by adding additional features. Not all Markdown applications support these elements.

### Table
| Syntax | Description |
| ----------- | ----------- |
| Header | Title |
| Paragraph | Text |

### Fenced Code Block
```json
{
  "firstName": "John",
  "lastName": "Smith",
  "age": 25
}
```

### Footnote
Here's a sentence with a footnote. [^1]
[^1]: This is the footnote.

### Heading ID
### My Great Heading {#custom-id}

### Definition List
term
: definition

### Strikethrough
~~The world is flat.~~

### Task List
- [x] Write the press release
- [ ] Update the website
- [ ] Contact the media

### Emoji
That is so funny! :joy:
(See also [Copying and Pasting Emoji](https://www.markdownguide.org/extended-syntax/#copying-and-pasting-emoji))

### Highlight
I need to highlight these ==very important words==.

### Subscript
H~2~O

### Superscript
X^2^