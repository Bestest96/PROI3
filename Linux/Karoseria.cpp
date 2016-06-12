/*	Lukasz Lepak, 2I4
	prowadzacy: dr inz. Piotr Witonski
	projekt nr 3 (1801)
	symulacja grafu modelujacego abstrakcyjny system kolejek
	w fabryce samochodow
*/
#include "Karoseria.h"

#define WYPISZ_KAROSERIA 0  //zdefiniowanie stalych i wyrazen losowania
#define MASA_KAROSERIA rand()%1000+1000
#define MASA_ELEKTRONIKA 10
#define NADWOZIE_KAROSERIA static_cast<Nadwozie>(rand() % 6)
#define MARKA_KAROSERIA static_cast<Marka>(rand() % 6)
#define KOLOR_POMKAR static_cast<Kolor>(rand() % 6)
#define ILOSC_OPON 4

using namespace std;

/*definicje konstruktorow, destruktorow oraz funkcji wirtualnych z klasy abstrakcyjnej
Karoseria dla klas dziedziczacych po Karoserii */

Karoseria::Karoseria() : masa(MASA_KAROSERIA), nad(NADWOZIE_KAROSERIA), mar(MARKA_KAROSERIA)
{
	if (WYPISZ_KAROSERIA)
		cout << "Konstruktor Karoseria" << endl;
}

Karoseria::Karoseria(const Karoseria &ak) : masa(ak.masa), nad(ak.nad), mar(ak.mar)
{
	if (WYPISZ_KAROSERIA)
		cout << "Konstruktor kopiujacy Karoseria" << endl;
}

Karoseria::~Karoseria()
{
	if (WYPISZ_KAROSERIA)
		cout << "Destruktor Karoseria" << endl;
}

Kar::Kar() : Karoseria()
{
	if (WYPISZ_KAROSERIA)
		cout << "Konstruktor Kar" << endl;
}

Kar::Kar(const Kar &k) : Karoseria(k)
{
	if (WYPISZ_KAROSERIA)
		cout << "Konstruktor kopiujacy Kar" << endl;
}

Kar::~Kar()
{
	if (WYPISZ_KAROSERIA)
		cout << "Destruktor Kar" << endl;
}

int Kar::masa_kar()
{
	return masa;
}

Nadwozie Kar::nad_kar()
{
	return nad;
}

Marka Kar::mar_kar()
{
	return mar;
}

PomKar::PomKar(queue<Kar> &k) : Kar(k.front()), kolor(KOLOR_POMKAR)
{
	if (WYPISZ_KAROSERIA)
		cout << "Konstruktor PomKar" << endl;
	k.pop();
}

PomKar::PomKar(const PomKar &pk) : Kar(pk), kolor(pk.kolor)
{
	if (WYPISZ_KAROSERIA)
		cout << "Konstruktor kopiujacy PomKar" << endl;
}

PomKar::~PomKar()
{
	if (WYPISZ_KAROSERIA)
		cout << "Destruktor PomKar" << endl;
}

int PomKar::masa_kar()
{
	return masa;
}

PomKarOp::PomKarOp(queue<PomKar> &pkq, queue<Op> &oq): PomKar(pkq.front())
{
	if (WYPISZ_KAROSERIA)
		cout << "Konstruktor PomKarOp" << endl;
	pkq.pop();
	opony = new Op[ILOSC_OPON];
	for (int i = 0;i < ILOSC_OPON;i++)
	{
		opony[i] = oq.front();
		oq.pop();
	}
}

PomKarOp::PomKarOp(const PomKarOp &pko) : PomKar(pko)
{
	if (WYPISZ_KAROSERIA)
		cout << "Konstruktor Kopiujacy PomKarOp" << endl;
	opony = new Op[ILOSC_OPON];
	for (int i = 0;i < ILOSC_OPON;i++)
		opony[i] = pko.opony[i];
}

PomKarOp::~PomKarOp()
{
	if (WYPISZ_KAROSERIA)
		cout << "Destruktor PomKarOp" << endl;
	delete[] opony;
}

int PomKarOp::masa_kar()
{
	int masa1 = masa + opony[0].masa_op() + opony[1].masa_op() + opony[2].masa_op() + opony[3].masa_op();
	return masa1;
}

PomKarOpSil::PomKarOpSil(queue<PomKarOp> &pkoq, queue<Sil> &sq) : PomKarOp(pkoq.front())
{
	if (WYPISZ_KAROSERIA)
		cout << "Konstruktor PomKarOpSil" << endl;
	pkoq.pop();
	silnik = new Sil(sq.front());
	sq.pop();
}

PomKarOpSil::PomKarOpSil(const PomKarOpSil &pkos) : PomKarOp(pkos)
{
	if (WYPISZ_KAROSERIA)
		cout << "Konstruktor Kopiujacy PomKarOpSil" << endl;
	silnik = new Sil(*pkos.silnik);
}

PomKarOpSil::~PomKarOpSil()
{
	if (WYPISZ_KAROSERIA)
		cout << "Destruktor PomKarOpSil" << endl;
	delete silnik;
}

int PomKarOpSil::masa_kar()
{
	int masa1 = masa + opony[0].masa_op() + opony[1].masa_op() + opony[2].masa_op() + opony[3].masa_op() + silnik->masa_sil();
	return masa1;
}

PomKarOpSilEl::PomKarOpSilEl(queue<PomKarOpSil> &pkosq) : PomKarOpSil(pkosq.front()), elektronika(1), masa_el(MASA_ELEKTRONIKA)
{
	if (WYPISZ_KAROSERIA)
		cout << "Konstruktor PomKarOpSilEl" << endl;
	pkosq.pop();
}

PomKarOpSilEl::PomKarOpSilEl(const PomKarOpSilEl &pkose) : PomKarOpSil(pkose), elektronika(pkose.elektronika), masa_el(pkose.masa_el)
{
	if (WYPISZ_KAROSERIA)
		cout << "Konstruktor Kopiujacy PomKarOpSilEl" << endl;
}

PomKarOpSilEl::~PomKarOpSilEl()
{
	if (WYPISZ_KAROSERIA)
		cout << "Destruktor PomKarOpSilEl" << endl;
}

bool PomKarOpSilEl::czy_elek()
{
	return elektronika;
}

int PomKarOpSilEl::masa_kar()
{
	int masa1 = masa + opony[0].masa_op() + opony[1].masa_op() + opony[2].masa_op() + opony[3].masa_op() + silnik->masa_sil() + masa_el;
	return masa1;
}
