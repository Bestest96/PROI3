/*	Lukasz Lepak, 2I4
	prowadzacy: dr inz. Piotr Witonski
	projekt nr 3 (1801)
	symulacja grafu modelujacego abstrakcyjny system kolejek
	w fabryce samochodow
*/
#ifndef OPONA_H
#define OPONA_H

#include <iostream>
#include <cstdlib>

//deklaracje klasy bastrakcyjnej Opona i po niej dziedziczej

enum Bieznik { kierunkowy, symetryczny, asymetryczny };

class Opona
{
public:
	Opona();
	Opona(const Opona&);
	Opona& operator=(const Opona&);
	virtual ~Opona();
	virtual int masa_op() = 0;
	virtual int sred_op() = 0;
	virtual Bieznik biez_op() = 0;
protected:
	int masa;
	int sred;
	Bieznik biez;
};

class Op : public Opona
{
public:
	Op();
	Op(const Op&);
	Op& operator=(const Op&);
	~Op();
	int masa_op();
	int sred_op();
	Bieznik biez_op();
};

#endif //OPONA_H
