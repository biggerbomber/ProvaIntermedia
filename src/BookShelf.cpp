#include "../include/BookShelf.h"

BookShelf::BookShelf() {
    m_books.reserve(1);
}
BookShelf::BookShelf(int initial_size){
    m_books.resize(initial_size); 
}

void BookShelf::push_back(Book element){
    m_books.push_back(element);
}

Book BookShelf::pop_back(){
    return m_books.pop_back();
}

/*BookShelf::~BookShelf() {
    delete m_books;
}*/