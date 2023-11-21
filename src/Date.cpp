#include "../include/Date.h"

class Invalid{};

Date::Date(){
	y=2023;
	m=Month::gennaio;
	d=20;
}

Date::Date(int anno, Month mese, int giorno){
	setYear(anno);
	setMonth(mese);
	setDay(giorno);
}

void Date::setYear(int anno){
	if (anno < -1400 || anno>= 2023) throw Invalid{};
	//scelta progettuale accetto gli anni negativi e "pubblicare nel futuro non e' consentito"
	
	y=anno;
}

void Date::setMonth(Month mese){
	m=mese;
}

void Date::setDay(int giorno){
	if(giorno<0 || giorno>31){
		throw Invalid();
	}
	if(m==Month::febbraio && ((giorno>29)||(giorno>28 && !is_leap(y)))){
			throw Invalid();
	}
	
	if( (m==Month::aprile || m==Month::giugno || m==Month::settembre || m==Month::novembre) && giorno>30){
		throw Invalid();
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