#ifndef _DATE_H
#define _DATE_H

bool is_leap(int);

class Date {
	public:
		enum class Month{gennaio=1, febbraio, marzo, aprile, maggio, giugno, luglio, agosto, settembre, ottobre, novembre, dicembre};
		Date();
		Date(int, Month, int);
		Date(const Date&);
		
		void setDay(int);
		void setMonth(Month);
		void setYear(int);
		
		int getDay(){return d;}
		Month getMonth(){return m;}
		int getYear(){return y;}
		
		Date operator=(const Date&);
	private:
		int y;
		Month m;
		int d;
		
		
};

#endif                                        
                                                 