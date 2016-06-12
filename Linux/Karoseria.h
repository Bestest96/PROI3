/*	Lukasz Lepak, 2I4
	prowadzacy: dr inz. Piotr Witonski
	projekt nr 3 (1801)
	symulacja grafu modelujacego abstrakcyjny system kolejek
	w fabryce samochodow
*/
#ifndef KAROSERIA_H
#define KAROSERIA_H

#include <queue>
#include <vector>
#include <ctime>
#include "Opona.h"
#include "Silnik.h"

//deklaracje typow wyliczeniowych, klasy bastrakcyjnej Karoseria i po niej dziedziczacych

enum Nadwozie { SUV, sedan, coupe, kabriolet, hatchback, combi };
enum Kolor { bialy, czarny, czerwony, niebieski, zielony, szary };
enum Marka { Suzuki, BMW, Mercedes, Nissan, Toyota, Fiat};

class Karoseria
{
public:
	Karoseria();
	Karoseria(const Karoseria&);
	virtual ~Karoseria();
	virtual int masa_kar() = 0;
	virtual Nadwozie nad_kar() = 0;
	virtual Marka mar_kar() = 0;
protected:
		int masa;
		Nadwozie nad;
		Marka mar;
};

class Kar: public Karoseria
{
public:
	Kar();
	Kar(const Kar&);
	~Kar();
	int masa_kar();
	Nadwozie nad_kar();
	Marka mar_kar();
};

class PomKar : public Kar
{
public:
	PomKar(std::queue<Kar>&);
	PomKar(const PomKar&);
	~PomKar();
	int masa_kar();
protected:
	Kolor kolor;
};

class PomKarOp : public PomKar
{
public:
	PomKarOp(std::queue<PomKar>&, std::queue<Op>&);
	PomKarOp(const PomKarOp&);
	~PomKarOp();
	int masa_kar();
protected:
	Op *opony;
};

class PomKarOpSil : public PomKarOp
{
public:
	PomKarOpSil(std::queue<PomKarOp>&, std::queue<Sil>&);
	PomKarOpSil(const PomKarOpSil&);
	~PomKarOpSil();
	int masa_kar();
protected:
	Sil *silnik;
};

class PomKarOpSilEl : public PomKarOpSil
{
public:
	PomKarOpSilEl(std::queue<PomKarOpSil>&);
	PomKarOpSilEl(const PomKarOpSilEl&);
	~PomKarOpSilEl();
	bool czy_elek();
	int masa_kar();
private:
	bool elektronika;
	int masa_el;
};


#endif //KAROSERIA_H
