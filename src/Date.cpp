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
	if(giorno<0){
		throw Invalid();
	}
		
	if(m==Month::gennaio || m==Month::marzo || m==Month::maggio || m==Month::luglio || m==Month::agosto || m==Month::ottobre || m==Month::dicembre){
		if(giorno<=31){
			d=giorno;
		}
		else{
			throw Invalid();
		}
	}
	
	if( m==Month::aprile || m==Month::giugno || m==Month::settembre || m==Month::novembre){
		if(giorno<=30){
			d=giorno;
		}
		else{
			throw Invalid();
		}
	}
	if(m==Month::febbraio){
		if(y%4==0){
			if(y%100==0){
				if(y%400==0){
					if(giorno<=29){
					d=giorno;
					}
				}
				else{
					if(giorno<=28){
					d=giorno;
					}
				}
			}
			else if(giorno<=29){
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