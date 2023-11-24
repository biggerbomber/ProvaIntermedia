#ifndef _DATE_H
#define _DATE_H
#include <iostream>

//fh
bool is_leap(int);

class Date {
	public:
		//enum dei mesi piuttosto che gestire i mesi con i numeri.
		enum class Month{gennaio=1, febbraio, marzo, aprile, maggio, giugno,
						 luglio, agosto, settembre, ottobre, novembre, dicembre};

		//costruttori (default, standard e copy)
		Date();

		//formato anno/mese/giorno
		Date(int, Month, int);
		Date(const Date&) = default;
		
		//metodi di set
		void setDay(int);
		void setMonth(Month);
		void setYear(int);

		//metodi di get (in-line)		
		int getDay() const {return d;}
		Month getMonth() const {return m;}
		int getYear() const {return y;}
		
		//overloading dell'operatore uguale (puo' essere utile)
		Date& operator=(const Date&);

	private:
		int y{ 800 };
		Month m{ Month::dicembre };
		int d{ 25 };

		//variabili membro inizializzate ad una data di default
		
		
};

//overloading di << su Month e su Date
std::ostream& operator<<(std::ostream& os, Date::Month& b);
std::ostream& operator<<(std::ostream& os, Date& b);
#endif                                        
                                                 