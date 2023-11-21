#ifndef _DATE_H
#define _DATE_H

class Date {
	public:
		enum class Month{gennaio=1, febbraio, marzo, aprile, maggio, giugno, luglio, agosto, settembre, ottobre, novembre, dicembre};
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
                                                 