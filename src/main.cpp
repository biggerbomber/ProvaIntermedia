
#include "../include/Book.h"
#include "../include/BookShelf.h"

#include <iostream>
#include <string>

int main(){

	//########################## TESTER CLASSE BOOK ##########################
	
	//creo un Book con il costruttore completo
	Book mybook("David", "Foster Wallace", "Una cosa divertente che non faro' mai piu'", "887-521-837-4");

	std::cout<<mybook<<std::endl; //lo stampo

	BookLib::presta(mybook); //prendo in prestito mybook

	if(mybook.disponibile()){
		BookLib::presta(mybook); //se e' disponibile, prendi in prestito 
	}
	else{ //se non e' disponibile, restituisci
		std::cout<<"Il libro verra' restituito\n";
		BookLib::restituisci(mybook);
	}

	Book b = mybook; //invoco l'operatore = di copia

	if(b==mybook){
		std::cout<<"sono uguali\n";
	}

	Book b2("Giovanni","Francesco","Non so cosa scrivere","887-521-837-6"); // creo un secondo libro

	//controllo dell'operatore =!
	if(b2!=mybook){
		std::cout<<"funziona anche il !=\n";
	}
	
	//########################## TESTER CLASSE BOOKSHELF ##########################

	std::cout << "sono qui\n";
	BookShelf shelf; //creo una shelf
	std::cout << "sono qui1\n";
	shelf.push_back(mybook); //aggiungo il promo libro
	std::cout << "sono qui2\n";
	std::cout<<shelf.pop_back()<<std::endl; //faccio il pop del libro
	std::cout << "sono qui3\n";

	BookShelf ts(10); //creo una shelf di 10

	//aggiungo due libri 
	ts[0]= Book("David", "Foster Wallace", "Una cosa divertente che non faro' mai piu'", "887-521-837-4");
	ts[2] = Book("David", "Foster Wallace", "Una cosa divertente che non faro' mai piu'", "887-521-837-4", Date(2024, Date::Month::luglio, 13));
	std::cout << ts[0] << ts[2];

	return 0;
}
