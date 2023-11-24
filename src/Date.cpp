#include "../include/Date.h"

Date::Date(){//Data di default
}

Date::Date(int anno, Month mese, int giorno){
	setYear(anno);
	setMonth(mese);
	setDay(giorno);
}

Date& Date::operator=(const Date& other) {
	y = other.getYear();
	m = other.getMonth();
	d = other.getDay();
	return *this;
}
void Date::setYear(int anno){
	y=anno;
}

void Date::setMonth(Month mese){
	m=mese;
}

void Date::setDay(int giorno){
	if(giorno<0 || giorno>31){
		throw std::out_of_range("Giorno non valido");
	}
	if(m==Month::febbraio && ((giorno>29)||(giorno>28 && !is_leap(y)))){
		throw std::out_of_range("Giorno non valido");
	}
	
	if( (m==Month::aprile || m==Month::giugno || m==Month::settembre || m==Month::novembre) && giorno>30){
		throw std::out_of_range("Giorno non valido");
	}

	d=giorno; // per gennaio, marzo, maggio, luglio, agosto, ottobre, dicembre ricado in casistiche che ho gia' controllato (positivo, <32)
}

bool is_leap(int y){ //controllo sulla bisestilita'
	if(y%4==0){
		if(y%100==0 && y%400==0){
			return true;
		}
		else{
			return false;
		}
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& os, const Date::Month& b) {
	return os << (int)b;
}

std::ostream& operator<<(std::ostream& os, Date& b) {

	return os <<b.getDay()<<'/'<< b.getMonth()<<'/'<<b.getYear();
}

