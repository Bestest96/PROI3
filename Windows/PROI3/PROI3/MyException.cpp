/*	Lukasz Lepak, 2I4
	prowadzacy: dr inz. Piotr Witonski
	projekt nr 3 (1801)
	symulacja grafu modelujacego abstrakcyjny system kolejek
	w fabryce samochodow
*/
#include "MyException.h"

//definicje konstruktorow i metod dla klasy MyException

using namespace std;

MyException::MyException(const char* b): blad(b) {};

const char* MyException::what()
{
    return blad;
}

MyException::~MyException() throw() {};
