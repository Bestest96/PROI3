/*	Lukasz Lepak, 2I4
	prowadzacy: dr inz. Piotr Witonski
	projekt nr 3 (1801)
	symulacja grafu modelujacego abstrakcyjny system kolejek
	w fabryce samochodow
*/
#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

//deklaracja klasy MyException

#include <iostream>
#include <exception>

class MyException: public std::exception
{
public:
    const char* what();
    MyException(const char*);
    ~MyException() throw();
private:
    const char* blad;
};
#endif // MYEXCEPTION_H
