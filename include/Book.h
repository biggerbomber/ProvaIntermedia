#ifndef _BOOK_H
#define _BOOK_H

#include <iostream>
#include <string>
#include "Date.h"

/*
1.
Progettare e implementare la classe Book che rappresenta un libro. Tale classe ha membri per
contenere:
a.
ISBN;
b.
titolo;
c.
nome e cognome autore (due membri diversi) – è previsto un solo autore per libro;
d.
data di copyright – la data è rappresentata usando una apposita classe Date simile a
quella sviluppata a lezione;
e.
stato in prestito / disponibile.
Il codice ISBN è rappresentato mediante una std::string il cui unico requisito è quello di avere
lunghezza 13.
La classe Book deve essere dotata di:
a.
funzioni membro che ritornano i vari dati membro;
b.
costruttori;
c.
funzioni per registrare il prestito e la restituzione;
d.
appositi strumenti (eventualmente implementati nella classe dedicata) per la validazione
della data;
e.
operator== e operator!= che confrontano due Book basandosi sul codice ISBN;
f.
operator<< che stampa titolo, autore, ISBN e la data di copyright su righe separate in
output.
La classe Book deve permette di eseguire la seguente operazione:
a. Book
mybook(“David”,
“Foster
Wallace”,
“Una
cosa
divertente
che
non farò mai più”, “887-521-837-4”);
*/

class Book{
	public:
	
	//COSTRUTTORI
	Book(); //default
	Book(std::string); //ibsn
	Book(std::string, std::string); //titolo, ibsn
	Book(std::string,std::string,std::string,std::string);//nome, cognome, titolo, ibsn
	Book(std::string,std::string,std::string,std::string, Date);//nome, cognome, titolo, ibsn, copyright
	
	// MV/CPY CONSTR
	Book(const Book&); //cpy
	Book(Book&&); //mv
	
	//DISTRUTTORE
	~Book(); //chiama i distruttori delle stringhe
	
	//OVERLOAD DEGLI OPERATORI
	
	Book& operator=(const Book&); //cpy
	Book& operator=(const Book&) const;  //cpy
	
	Book& operator=(Book&&); //mv
	
	//##################FUNZIONI MEMBRO##################
	
	//FUNZIONI MEMBRO GENERICHE 
	
	void presta();
	void restituisci();
	
	//FUNZIONI DI ISPEZIONE
	
	std::string ibsn();
	std::string titolo();
	std::string nomeAutore();
	std::string cognomeAutore();
	bool disponibile();
	Date copyright();
	
	private:
	std::string m_ISBN {"0000000000000"};
	std::string m_titolo {"nessun titolo"};
	std::string m_nomeAutore {"Nessuno"};
	std::string m_cognomeAutore {"Niente"};
	bool m_disponibile {true};
	Date m_copyright;

};

//overload per ostream
std::ostream& operator<<(std::ostream&, Book&);

//overload operatori

bool operator==(Book&, Book&);
bool operator!=(Book&, Book&);

#endif
