
#include "../include/Book.h"
#include "../include/BookShelf.h"

#include <iostream>
#include <string>

int main(){

	// TESTER CLASSE BOOK
	
	Book mybook("David", "Foster Wallace", "Una cosa divertente che non faro' mai piu'", "887-521-837-4");

	std::cout<<mybook<<std::endl;

	BookLib::presta(mybook);

	if(mybook.disponibile()){
		BookLib::presta(mybook);
	}
	else{
		std::cout<<"Il libro verra' restituito\n";
		BookLib::restituisci(mybook);
	}

	Book b= mybook;

	if(b==mybook){
		std::cout<<"sono uguali yay\n";
	}

	Book b2("Giovanni","Francesco","Non so cosa scrivere","887-521-837-6");

	if(b2!=mybook){
		std::cout<<"funziona anche il !=\n";
	}
	
	// TESTER CLASSE BOOKSHELF

	std::cout << "sono qui\n";
	BookShelf shelf;
	std::cout << "sono qui1\n";// si blocca dopo questo
	shelf.push_back(mybook); 
	std::cout << "sono qui2\n";//non arriva qui
	std::cout<<shelf.pop_back()<<std::endl;
	std::cout << "sono qui3\n";

	BookShelf ts(10);

	ts[0]= Book("David", "Foster Wallace", "Una cosa divertente che non faro' mai piu'", "887-521-837-4");
	ts[2] = Book("David", "Foster Wallace", "Una cosa divertente che non faro' mai piu'", "887-521-837-4", Date(2024, Date::Month::luglio, 13));
	std::cout << ts[0] << ts[2];

	return 0;
}
