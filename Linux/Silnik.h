/*	Lukasz Lepak, 2I4
	prowadzacy: dr inz. Piotr Witonski
	projekt nr 3 (1801)
	symulacja grafu modelujacego abstrakcyjny system kolejek
	w fabryce samochodow
*/
#ifndef SILNIK_H
#define SILNIK_H

#include <iostream>
#include <cstdlib>

//deklaracje typu wyliczeniowego oraz klasy astrakcyjnej Silnik i po niej dziedziczej

enum Paliwo {benzyna, diesel, gaz, hybryda};

class Silnik
{
public:
	Silnik();
	Silnik(const Silnik&);
	Silnik& operator=(const Silnik&);
	virtual ~Silnik();
	virtual int masa_sil() = 0;
	virtual int moc_sil() = 0;
	virtual int poj_sil() = 0;
	virtual Paliwo pal_sil() = 0;
protected:
	int masa;
	int moc;
	int poj;
	Paliwo pal;
};

class Sil : public Silnik
{
public:
	Sil();
	Sil(const Sil&);
	Sil& operator=(const Sil&);
	~Sil();
	int masa_sil();
	int moc_sil();
	int poj_sil();
	Paliwo pal_sil();
};
#endif //SILNIK_H
