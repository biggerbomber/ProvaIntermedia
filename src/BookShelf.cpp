#include "../include/BookShelf.h"

BookShelf::BookShelf(int initial_capacity){
    m_books = new MyVector(initial_capacity); 
}

void BookShelf::push_back(Book element){
    m_books->push_back(element);
}

Book BookShelf::pop_back(){
    return m_books->pop_back();
}

BookShelf::~BookShelf() {
    delete m_books;
}