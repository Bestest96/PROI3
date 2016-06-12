/*	Lukasz Lepak, 2I4
	prowadzacy: dr inz. Piotr Witonski
	projekt nr 3 (1801)
	symulacja grafu modelujacego abstrakcyjny system kolejek
	w fabryce samochodow
*/
#ifndef SYMULACJA_H
#define SYMULACJA_H

#include <string>
#include <fstream>
#include <unistd.h>
#include "Karoseria.h"

//deklaracje funkcji odpowiedzialnych za symulacje

void symulacja(std::queue<Kar>*, std::queue<Op>*, std::queue<Sil>*, std::queue<PomKar>*, std::queue<PomKarOp>*, std::queue<PomKarOpSil>*, std::vector<PomKarOpSilEl>&, bool&, unsigned int&);
void wczytaj_dane(unsigned int&, unsigned int&, unsigned int&);

#endif // SYMULACJA_H
