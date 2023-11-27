
#include "../include/Book.h"

//############################## COSTRUTTORI ##############################
//costruttore senza data
Book::Book(const std::string& nomeAutore, 
		   const std::string& cognomeAutore, 
		   const std::string& titolo, 
		   const std::string& isbn) {

	if (!BookLib::isIsbnValid(isbn)) {
		throw std::invalid_argument("ISBN deve avere 13 caratteri"); //se isbn non ha 13 cifre, non e' valido
	}
	//assegno alle variabili membro
	m_ISBN = isbn;
	m_nomeAutore = nomeAutore;
	m_cognomeAutore = cognomeAutore;
	m_titolo = titolo;
	m_disponibile = true;
}

//costruttore completo
Book::Book(const std::string& nomeAutore,
		   const std::string& cognomeAutore,
		   const std::string& titolo,
		   const std::string& isbn,
		   Date dataCopyright ) {

	if (!BookLib::isIsbnValid(isbn)) {
		throw std::invalid_argument("ISBN deve avere 13 caratteri"); //se isbn non ha 13 cifre, non e' valido
	}
	//assegno alle variabili membro
	m_ISBN = isbn;
	m_nomeAutore = nomeAutore;
	m_cognomeAutore = cognomeAutore;
	m_titolo = titolo;
	m_dataCopyright = dataCopyright;
	m_disponibile = true;
}
//costruttore di copia
Book::Book(const Book& other) {
	//copio tutte le variabili membro da "other"
	m_ISBN = other.m_ISBN;
	m_nomeAutore = other.m_nomeAutore;
	m_cognomeAutore = other.m_cognomeAutore;
	m_titolo = other.m_titolo;
	m_disponibile = other.m_disponibile;
	m_dataCopyright = other.m_dataCopyright;
}

//costruttore di move 
Book::Book(Book&& other) {
	m_ISBN = std::move(other.m_ISBN);
	m_nomeAutore = std::move(other.m_nomeAutore);
	m_cognomeAutore = std::move(other.m_cognomeAutore);
	m_titolo = std::move(other.m_titolo);
	m_disponibile = other.m_disponibile;
	m_dataCopyright = other.m_dataCopyright;
}

//move assignment
Book& Book::operator=(const Book& other) {
	m_ISBN = other.m_ISBN;
	m_nomeAutore = other.m_nomeAutore;
	m_cognomeAutore = other.m_cognomeAutore;
	m_titolo = other.m_titolo;
	m_disponibile = other.m_disponibile;
	m_dataCopyright = other.m_dataCopyright;
	return *this;
}

//move assignment
Book& Book::operator=(Book&& other) {
	//utilizziamo std::move per spostare stringhe in modo efficiente
	m_ISBN = std::move(other.m_ISBN);
	m_nomeAutore = std::move(other.m_nomeAutore);
	m_cognomeAutore = std::move(other.m_cognomeAutore);
	m_titolo = std::move(other.m_titolo);
	m_disponibile = other.m_disponibile;
	m_dataCopyright = other.m_dataCopyright;
	return *this;
}

//funzione che fa il set di ibsn, facendo il controllo della lunghezza
void Book::setIsbn(const std::string& isbn){
	if (!BookLib::isIsbnValid(isbn)) {
		throw std::invalid_argument("ISBN deve avere 13 caratteri");
	}
	m_ISBN = isbn;
}

//############################## OVERLOADS ##############################

//overload di ostream d
std::ostream& operator<<(std::ostream& os, const Book& b) {
	os << b.titolo() << std::endl;
	os << b.nomeAutore() << std::endl;
	os << b.cognomeAutore() << std::endl;
	os << b.isbn() << std::endl;
	os << b.copyright();
	return os;
}

//overload == 
bool operator==(Book& b1, Book&b2) {
	return b1.isbn() == b2.isbn();
}
//overload =!
bool operator!=(Book& b1, Book& b2) {
	return !(b1 == b2);
}

//############################## HELPER FUNCTIONS ##############################

//presta 
void BookLib::presta(Book& b){
	if (!b.disponibile()) {
		throw std::invalid_argument("Il libro non e' disponibile!"); //se non e' disponiobile, non lo posso prestare
	}
	b.setDisponibile(true);
}
void BookLib::restituisci(Book& b) {
	if (b.disponibile()) {
		throw std::invalid_argument("Il libro non e' stato prestato!"); //se e' disponibile, non puo' essere restituito
	}
	b.setDisponibile(false);
}

//controllo sulla lunghezza di ibsn
bool BookLib::isIsbnValid(const std::string& isbn) {
	return isbn.size() == 13; 
}