#ifndef _BOOKSHELF_H
#define _BOOKSHELF_H

#include "MyVector.h"
#include "Book.h"

class BookShelf{
	//classe che fa uso della classe MyVector e Book, crea un array di Books ed emula il comportamento di una libreria.
public:

	//costruttore di default.
	BookShelf();

	//metodi richiesti.
	BookShelf(int);
	void push_back(const Book&);
	Book&& pop_back();

	//metodi utili.
	Book BookShelf::operator[](int a) const;
	Book& BookShelf::operator[](int a);
	
	//un disturttore non e' necessario, quello di default fa tutto quello di cui abbiamo bisogno.
	~BookShelf() = default;

private:
	MyVector m_books{0};
};

#endif
