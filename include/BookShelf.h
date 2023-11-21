#ifndef _BOOKSHELF_H
#define _BOOKSHELF_H

#include "include/MyVector.h"
#include "include/Book.h"

class BookShelf{
	
public:
	BookShelf(int);
	
	void push_back(Book);
	
	Book pop_back();
private:
	MyVector m_books;
};

#endif
