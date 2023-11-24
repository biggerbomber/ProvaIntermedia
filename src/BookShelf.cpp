#include "../include/BookShelf.h"

//crea un vettore di MyVector con size=0 e capacity=1
BookShelf::BookShelf() {
    m_books.reserve(1);
}

//crea un vettore di MyVector con size=capacity=initial_size
BookShelf::BookShelf(int initial_size){
    m_books.resize(initial_size); 
}

Book BookShelf::operator[](int a) const {
    return m_books[a];
}

Book& BookShelf::operator[](int a) {
    return m_books[a];
}

void BookShelf::push_back(const Book& element){
    m_books.push_back(element);
}

//ritorna una rvalue reference e fa il move degli elementi che vanno eliminati
Book&& BookShelf::pop_back(){
    return m_books.pop_back();
}
