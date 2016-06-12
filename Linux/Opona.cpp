/*	Lukasz Lepak, 2I4
	prowadzacy: dr inz. Piotr Witonski
	projekt nr 3 (1801)
	symulacja grafu modelujacego abstrakcyjny system kolejek
	w fabryce samochodow
*/
#include "Opona.h"

#define WYPISZ_OPONA 0
#define MASA_OPONA 25
#define SREDNICA_OPONA 17
#define BIEZNIK_OPONA static_cast<Bieznik>(rand() % 3)

using namespace std;

/*definicje konstruktorow, destruktorow oraz funkcji wirtualnych z klasy abstrakcyjnej
Opona dla klasy dziedziczacej po Oponie */

Opona::Opona() : masa(MASA_OPONA), sred(SREDNICA_OPONA), biez(BIEZNIK_OPONA)
{
	if (WYPISZ_OPONA)
		cout << "Konstruktor Opona" << endl;
}

Opona::Opona(const Opona &ao) : masa(ao.masa), sred(ao.sred), biez(ao.biez)
{
	if (WYPISZ_OPONA)
		cout << "Konstruktor Kopiujacy Opona" << endl;
}

Opona& Opona::operator=(const Opona &ao)
{
	masa = ao.masa;
	sred = ao.sred;
	biez = ao.biez;
	return *this;
}

Opona::~Opona()
{
	if (WYPISZ_OPONA)
		cout << "Destruktor Opona" << endl;
}

Op::Op() : Opona()
{
	if (WYPISZ_OPONA)
		cout << "Konstruktor Op" << endl;
}

Op::Op(const Op &o) : Opona(o)
{
	if (WYPISZ_OPONA)
		cout << "Konstruktor Kopiujacy Op" << endl;
}

Op& Op::operator=(const Op &o)
{
	masa = o.masa;
	sred = o.sred;
	biez = o.biez;
	return *this;
}

Op::~Op()
{
	if (WYPISZ_OPONA)
		cout << "Destruktor Op" << endl;
}

int Op::masa_op()
{
	return masa;
}

int Op::sred_op()
{
	return sred;
}

Bieznik Op::biez_op()
{
	return biez;
}

