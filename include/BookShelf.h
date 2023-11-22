#ifndef _BOOKSHELF_H
#define _BOOKSHELF_H

#include "MyVector.h"
#include "Book.h"

class BookShelf{
	
public:

	BookShelf();
	BookShelf(int);
	
	void push_back(Book);
	Book BookShelf::operator[](int a) const;
	Book& BookShelf::operator[](int a);
	Book pop_back();

	//~BookShelf();
private:
	MyVector m_books{0};
};

#endif
