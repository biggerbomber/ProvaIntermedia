#ifndef _BOOK_H
#define _BOOK_H

#include <iostream>
#include <string>
#include "Date.h"



class Book{
public:
	
	//COSTRUTTORI
	//Book(); //default
	//Book(const std::string&); //ibsn
	//Book(const std::string&, const std::string&); //titolo, ibsn
	Book();
	Book(const std::string&, const std::string&, const std::string&, const std::string&);//nome, cognome, titolo, ibsn
	Book(const std::string&, const std::string&, const std::string&, const std::string&, Date);//nome, cognome, titolo, ibsn, copyright
	
	// MV/CPY CONSTR
	Book(const Book&); //cpy
	Book(Book&&); //mv
	
	//DISTRUTTORE
	//~Book(); //chiama i distruttori delle stringhe
	
	//OVERLOAD DEGLI OPERATORI
	
	Book& operator=(const Book&); //cpy
	//Book& operator=(const Book&) const;  //cpy ERRORE
	
	Book& operator=(Book&&); //mv
	
	//##################FUNZIONI MEMBRO##################

	//FUNZIONI DI ISPEZIONE
	
	std::string isbn() { return m_ISBN; };
	std::string titolo() { return m_titolo; };
	std::string nomeAutore() { return m_nomeAutore; };
	std::string cognomeAutore() { return m_cognomeAutore; };
	bool disponibile() { return m_disponibile; };
	Date copyright() { return m_dataCopyright; };
	
	//Funzioni di set.

	void setIsbn(const std::string& isbn);
	void setTitolo(const std::string& titolo) { m_titolo=titolo; };
	void setNomeAutore(const std::string& nomeAutore) { m_nomeAutore = nomeAutore; };
	void setCognomeAutore(const std::string& cognomeAutore) { m_cognomeAutore=cognomeAutore; };
	void setDisponibile(bool b) { m_disponibile = b; };
	void setCopyright(Date dataCopyright) { m_dataCopyright = dataCopyright; };


private:
	std::string m_ISBN {""};
	std::string m_titolo {""};
	std::string m_nomeAutore {""};
	std::string m_cognomeAutore {""};
	bool m_disponibile {false};
	Date m_dataCopyright;

	bool isIsbnValid(const std::string&);

};

//overload per ostream
std::ostream& operator<<(std::ostream&, Book&);

//overload operatori

bool operator==(Book&, Book&);
bool operator!=(Book&, Book&);

//funzioni helper generiche
void presta(Book&);
void restituisci(Book&);
	
#endif
