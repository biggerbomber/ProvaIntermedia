#include "../include/Date.h"

class Invalid{};

Date::Date(){
	y=2023;
	m=Month::Novembre;
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
	if(giorno<0){
		throw Invalid();
	}
		
	if(m==Month::Gennaio || m==Month::Marzo || m==Month::Maggio || m==Month::Luglio || m==Month::Agosto || m==Month::Ottobre || m==Month::Dicembre){
		if(giorno<=31){
			d=giorno;
		}
		else{
			throw Invalid();
		}
	}
	
	if( m==Month::Aprile || m==Month::Giugno || m==Month::Settembre || m==Month::Novembre){
		if(giorno<=30){
			d=giorno;
		}
		else{
			throw Invalid();
		}
	}
	if(m==Month::Febbraio){
		if(y%4==0){
			if(giorno<=29){
			d=giorno;
			}
		}
		else if(giorno<=28){
			d=giorno;
		}
		else{
			throw Invalid();
		}
	}
}