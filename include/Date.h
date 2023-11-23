#ifndef _DATE_H
#define _DATE_H
#include <iostream>

bool is_leap(int);

class Date {
	public:
		enum class Month{gennaio=1, febbraio, marzo, aprile, maggio, giugno,
						 luglio, agosto, settembre, ottobre, novembre, dicembre};
		Date();
		Date(int, Month, int);
		Date(const Date&) = default;
		
		void setDay(int);
		void setMonth(Month);
		void setYear(int);
		
		int getDay() const {return d;}
		Month getMonth() const {return m;}
		int getYear() const {return y;}
		
		Date& operator=(const Date&);
	private:
		int y;
		Month m;
		int d;
		
		
};
std::ostream& operator<<(std::ostream& os, Date::Month& b);
std::ostream& operator<<(std::ostream& os, Date& b);
#endif                                        
                                                 