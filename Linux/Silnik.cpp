/*	Lukasz Lepak, 2I4
	prowadzacy: dr inz. Piotr Witonski
	projekt nr 3 (1801)
	symulacja grafu modelujacego abstrakcyjny system kolejek
	w fabryce samochodow
*/
#include "Silnik.h"

#define WYPISZ_SILNIK 0
#define MASA_SILNIK 250//rand()%200+100
#define MOC_SILNIK rand()%250+150
#define POJ_SILNIK rand()%2000+1500
#define PALIWO_SILNIK static_cast<Paliwo>(rand() % 4)

using namespace std;

/*definicje konstruktorow, destruktorow oraz funkcji wirtualnych z klasy abstrakcyjnej
Silnik dla klasy dziedziczacej po Silniku */

Silnik::Silnik(): masa(MASA_SILNIK), moc(MOC_SILNIK), poj(POJ_SILNIK), pal(PALIWO_SILNIK)
{
	if (WYPISZ_SILNIK)
		cout << "Konstruktor Silnik" << endl;
}

Silnik::Silnik(const Silnik &as) : masa(as.masa), moc(as.moc), poj(as.poj), pal(as.pal)
{
	if (WYPISZ_SILNIK)
		cout << "Konstruktor Kopiujacy Silnik" << endl;
}

Silnik& Silnik::operator=(const Silnik &as)
{
	masa = as.masa;
	moc = as.moc;
	poj = as.poj;
	pal = as.pal;
	return *this;
}

Silnik::~Silnik()
{
	if (WYPISZ_SILNIK)
		cout << "Destruktor Silnik" << endl;
}

Sil::Sil() : Silnik()
{
	if (WYPISZ_SILNIK)
		cout << "Konstruktor Sil" << endl;
}

Sil::Sil(const Sil &s) : Silnik(s)
{
	if (WYPISZ_SILNIK)
		cout << "Konstruktor Kopiujacy Sil" << endl;
}

Sil& Sil::operator=(const Sil &s)
{
	masa = s.masa;
	moc = s.moc;
	poj = s.poj;
	pal = s.pal;
	return *this;
}

Sil::~Sil()
{
	if (WYPISZ_SILNIK)
		cout << "Destruktor Sil" << endl;
}

int Sil::masa_sil()
{
	return masa;
}

int Sil::moc_sil()
{
	return moc;
}

int Sil::poj_sil()
{
	return poj;
}

Paliwo Sil::pal_sil()
{
	return pal;
}
