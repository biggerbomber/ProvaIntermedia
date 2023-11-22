
#include "../include/Book.h"
#include "../include/BookShelf.h"

#include <iostream>
#include <string>

int main(){

	// TESTER CLASSE BOOK
	
	Book mybook("David", "Foster Wallace", "Una cosa divertente che non faro' mai piu'", "887-521-837-4");

	std::cout<<mybook;

	mybook.presta();

	if(mybook.disponibile()){
		mybook.presta();
	}
	else{
		std::cout<<"Il libro verra' restituito\n";
		mybook.restituito();
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

	BookShelf shelf(10); 
	shelf.push_back(mybook); 
	shelf.pop_back(); 

	return 0;
}
