#ifndef _DATE_H
#define _DATE_H

class Date {
	private: enum class Month{Gennaio=1, Febbraio=2, Marzo=3, Aprile=4, Maggio=5, Giugno=6, Luglio=7, Agosto=8, Settembre=9, Ottobre=10, Novembre=11, Dicembre=12};
	public:
		Date();
		Date(int, Month, int);
		
		void setDay(int);
		void setMonth(Month);
		void setYear(int);
		
		int getDay(){return d;}
		Month getMonth(){return m;}
		int getYear(){return y;}
		
		
	private:
		int y;
		Month m;
		int d;
		
		
};

#endif                                        
                                                 