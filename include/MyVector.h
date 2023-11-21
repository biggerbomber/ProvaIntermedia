#ifndef _MYVECTOR_H
#define _MYVECTOR_H

#include <iostream>
#include "Book.h"

class MyVector{
public:
	MyVector();
	explicit MyVector(int);
	MyVector(const MyVector&);
	MyVector(std::initializer_list<Book>);
	~MyVector();

	
	Book operator[](int) const;
	Book& operator[](int);
	
	Book at(int) const;
	Book& at(int);
	
	void reserve(int);

	void push_back(Book);
	Book pop_back();
	
	int size() {return m_size;}//inline
	Book* get_pointer(){return m_data;}
  
	
private:
	Book* m_data {nullptr};
	int m_size {0};
	int m_capacity {0};
	
};

std::ostream& operator<<(std::ostream&, MyVector&);

#endif
