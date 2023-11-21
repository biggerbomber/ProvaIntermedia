#include "../include/Book.h"
Book::Book(const std::string& nomeAutore, 
		const std::string& cognomeAutore, 
		const std::string& titolo, 
		const std::string& isbn) {

	if (!isIsbnValid(isbn)) {
		throw std::invalid_argument("ISBN deve avere 13 caratteri");
	}
	m_ISBN = isbn;
	m_nomeAutore = nomeAutore;
	m_cognomeAutore = cognomeAutore;
	m_titolo = titolo;
	m_disponibile = true;
}

Book::Book(){}//non fa nulla i dati sono inizializzati ai valori di default definiti nel file helper

bool Book::isIsbnValid(const std::string& isbn) {
	return isbn.size() == 13;
}
Book::Book(const std::string& nomeAutore,
	const std::string& cognomeAutore,
	const std::string& titolo,
	const std::string& isbn,
	Date dataCopyright ) {

	if (!isIsbnValid(isbn)) {
		throw std::invalid_argument("ISBN deve avere 13 caratteri");
	}
	m_ISBN = isbn;
	m_nomeAutore = nomeAutore;
	m_cognomeAutore = cognomeAutore;
	m_titolo = titolo;
	m_dataCopyright = dataCopyright;
	m_disponibile = true;
}

Book::Book(const Book& other) {
	m_ISBN = other.m_ISBN;
	m_nomeAutore = other.m_nomeAutore;
	m_cognomeAutore = other.m_cognomeAutore;
	m_disponibile = other.m_disponibile;
	m_dataCopyright = other.m_dataCopyright;
}
Book::Book(Book&& other) {
	m_ISBN = std::move(other.m_ISBN);
	m_nomeAutore = std::move(other.m_nomeAutore);
	m_cognomeAutore = std::move(other.m_cognomeAutore);
	m_disponibile = other.m_disponibile;
	m_dataCopyright = other.m_dataCopyright;
}
Book& Book::operator=(const Book& other) {
	m_ISBN = other.m_ISBN;
	m_nomeAutore = other.m_nomeAutore;
	m_cognomeAutore = other.m_cognomeAutore;
	m_disponibile = other.m_disponibile;
	m_dataCopyright = other.m_dataCopyright;
}
Book& Book::operator=(Book&& other) {
	m_ISBN = std::move(other.m_ISBN);
	m_nomeAutore = std::move(other.m_nomeAutore);
	m_cognomeAutore = std::move(other.m_cognomeAutore);
	m_disponibile = other.m_disponibile;
	m_dataCopyright = other.m_dataCopyright;
}

void Book::presta(){
	if (!m_disponibile) {
		throw std::invalid_argument("Il libro non � disponibile!");
	}
	m_disponibile = false;
}
void Book::restituito() {
	if (m_disponibile) {
		throw std::invalid_argument("Il libro non � stato prestato!");
	}
	m_disponibile = false;
}

void Book::setIbsn(const std::string& isbn){
	if (!isIsbnValid(isbn)) {
		throw std::invalid_argument("ISBN deve avere 13 caratteri");
	}
	m_ISBN = isbn;
}