/*	Lukasz Lepak, 2I4
	prowadzacy: dr inz. Piotr Witonski
	projekt nr 3 (1801)
	symulacja grafu modelujacego abstrakcyjny system kolejek
	w fabryce samochodow
*/
#include "Symulacja.h"
#include "MyException.h"

#define ILOSC_STANOWISK_OPONY 4
#define ILOSC_STANOWISK 2
#define MAX_KOLEJKI 10
#define WYJATEK 0
#define STWORZENIE 0
#define DANE_CZAS 3
#define DEFAULT_ITERACJE 40
#define DEFAULT_ZAPIS 5
#define DEFAULT_WSTRZYMAJ 2

using namespace std;

void symulacja(queue<Kar> kq[2], queue<Op> oq[2], queue<Sil> sq[2], queue<PomKar> pkq[2], queue<PomKarOp> pkoq[2], queue<PomKarOpSil> pkosq[2], vector<PomKarOpSilEl> &pkosev, bool &czy_do_pliku, unsigned int &ktora_iteracja)
{
	Op *o[ILOSC_STANOWISK_OPONY];  //deklaracja wskaznikow dla nowych obiektow
	Kar *k[ILOSC_STANOWISK];
	Sil *s[ILOSC_STANOWISK];
	PomKar *pk[ILOSC_STANOWISK];
	PomKarOp *pko[ILOSC_STANOWISK];
	PomKarOpSil *pkos[ILOSC_STANOWISK];
	PomKarOpSilEl *pkose[ILOSC_STANOWISK];
	ofstream przeb_test("przebieg_testowania.txt", ios::app);  //otwarcie pliku do zapisu
	if (czy_do_pliku)  //zapis do pliku numeru iteracji
        przeb_test << "Numer iteracji symulacji: " << ktora_iteracja+1 << "\r\n";
	for (int i = 0;i < ILOSC_STANOWISK_OPONY;i++)
	{
		try //proba utworzenia opon
		{
			o[i] = NULL;  //inicjalizacja wskaznikow
			if (oq[0].size() > MAX_KOLEJKI && oq[1].size() > MAX_KOLEJKI) //za duze kolejki
				throw MyException("Za duzo opon w kolejnych kolejkach");
			o[i] = new Op;
			if (STWORZENIE)
				cout << "Stworzono opone" << endl;
			if (czy_do_pliku && STWORZENIE)
                przeb_test << "Stworzono opone\r\n";
		}
		catch (MyException &e)
		{
			if (WYJATEK)
				cout << e.what() << endl;
		}
	}
	for (int i = 0;i < ILOSC_STANOWISK;i++)
	{
		k[i] = NULL;  //inicjalizacja wskaznikow
		s[i] = NULL;
		pk[i] = NULL;
		pko[i] = NULL;
		pkos[i] = NULL;
		pkose[i] = NULL;
		//proby utworzenia obiektow z symulacji
		try
		{
			if (kq[0].size() > MAX_KOLEJKI && kq[1].size() > MAX_KOLEJKI) //za duze kolejki
				throw MyException("Za duzo karoserii w kolejnych kolejkach");
			k[i] = new Kar;
			if (STWORZENIE)
				cout << "Stworzono karoserie" << endl;
			if (czy_do_pliku && STWORZENIE)
                przeb_test << "Stworzono karoserie\r\n";
		}
		catch (MyException &e)
		{
			if (WYJATEK)
				cout << e.what() << endl;
		}
		try
		{
			if (sq[0].size() > MAX_KOLEJKI && sq[1].size() > MAX_KOLEJKI) //za duze kolejki
				throw MyException("Za duzo silnikow w kolejnych kolejkach");
			s[i] = new Sil;
			if (STWORZENIE)
				cout << "Stworzono silnik" << endl;
			if (czy_do_pliku && STWORZENIE)
                przeb_test << "Stworzono silnik\r\n";
		}
		catch (MyException &e)
		{
			if (WYJATEK)
				cout << e.what() << endl;
		}
		try
		{
			if (kq[i].size() == 0)  //brak skladnikow do utworzenia obiektu
				throw MyException("Brak skladowych pomalowanej karoserii w kolejkach");
			if (pkq[0].size() > MAX_KOLEJKI && pkq[1].size() > MAX_KOLEJKI) //za duze kolejki
				throw MyException("Za duzo pomalowanych karoserii w kolejnych kolejkach");
			pk[i] = new PomKar(kq[i]);
			if (STWORZENIE)
				cout << "Stworzono pomalowana karoserie" << endl;
			if (czy_do_pliku && STWORZENIE)
                przeb_test << "Stworzono pomalowana karoserie\r\n";
		}
		catch (MyException &e)
		{
			if (WYJATEK)
				cout << e.what() << endl;
		}
		try
		{
			if (pkq[i].size() == 0 || oq[i].size()<4) //brak skladnikow do utworzenia obiektu
				throw MyException("Brak skladowych pomalowanej karoserii z oponami w kolejkach");
			if (pkoq[0].size() > MAX_KOLEJKI && pkoq[1].size() > MAX_KOLEJKI) //za duze kolejki
				throw MyException("Za duzo pomalowanych karoserii z oponami w kolejnych kolejkach");
			pko[i] = new PomKarOp(pkq[i], oq[i]);
			if (STWORZENIE)
                cout << "Stworzono pomalowana karoserie z oponami" << endl;
			if (czy_do_pliku && STWORZENIE)
                przeb_test << "Stworzono pomalowana karoserie z oponami\r\n";
		}
		catch (MyException &e)
		{
			if (WYJATEK)
				cout << e.what() << endl;
		}
		try
		{
			if (pkoq[i].size() == 0 || sq[i].size()==0) //brak skladnikow do utworzenia obiektu
				throw MyException("Brak skladowych pomalowanej karoserii z oponami i silnikiem w kolejkach");
			if (pkosq[0].size() > MAX_KOLEJKI && pkosq[1].size() > MAX_KOLEJKI) //za duze kolejki
				throw MyException("Za duzo pomalowanych karoserii z oponami i silnikiem w kolejnych kolejkach");
			pkos[i] = new PomKarOpSil(pkoq[i], sq[i]);
			if (STWORZENIE)
				cout << "Stworzono pomalowana karoserie z oponami i silnikem" << endl;
			if (czy_do_pliku && STWORZENIE)
                przeb_test << "Stworzono pomalowana karoserie z oponami i silnikiem\r\n";
		}
		catch (MyException &e)
		{
			if (WYJATEK)
				cout << e.what() << endl;
		}
		try
		{
			if (pkosq[i].size() == 0) //brak skladnikow do utworzenia obiektu
				throw MyException("Brak skladowych pomalowanej karoserii z oponami, silnikiem i elektronika");
			pkose[i] = new PomKarOpSilEl(pkosq[i]);
			if (STWORZENIE)
                cout << "Stworzono pomalowana karoserie z oponami, silnikiem i elektronika" << endl;
			if (czy_do_pliku && STWORZENIE)
                przeb_test << "Stworzono pomalowana karoserie z oponami, silnikiem i elektronika\r\n";
		}
		catch (MyException &e)
		{
			if (WYJATEK)
				cout << e.what() << endl;
		}
	}
	for (int i = 0;i < ILOSC_STANOWISK_OPONY;i++) //dodawanie obiektow do odpowiednich kolejek
	{
		if (oq[0].size() <= oq[1].size())
		{
			if (o[i] != NULL)
				oq[0].push(*o[i]);
		}
		else
		{
			if (o[i] != NULL)
				oq[1].push(*o[i]);
		}
	}
	for (int i = 0;i < ILOSC_STANOWISK;i++) //dodawanie obiektow do odpowiednich kolejek
	{
		if (kq[0].size() <= kq[1].size())
		{
			if (k[i] != NULL)
				kq[0].push(*k[i]);
		}
		else
		{
			if (k[i] != NULL)
				kq[1].push(*k[i]);
		}

		if (sq[0].size() <= sq[1].size())
		{
			if (s[i] != NULL)
				sq[0].push(*s[i]);
		}
		else
		{
			if (s[i] != NULL)
				sq[1].push(*s[i]);
		}

		if (pkq[0].size() <= pkq[1].size())
		{
			if (pk[i] != NULL)
				pkq[0].push(*pk[i]);
		}
		else
		{
			if (pk[i] != NULL)
				pkq[1].push(*pk[i]);
		}

		if (pkoq[0].size() <= pkoq[1].size())
		{
			if (pko[i] != NULL)
				pkoq[0].push(*pko[i]);
		}
		else
		{
			if (pko[i] != NULL)
				pkoq[1].push(*pko[i]);
		}

		if (pkosq[0].size() <= pkosq[1].size())
		{
			if (pkos[i] != NULL)
				pkosq[0].push(*pkos[i]);
		}
		else
		{
			if (pkos[i] != NULL)
				pkosq[1].push(*pkos[i]);
		}

		if (pkose[i] != NULL)
			pkosev.push_back(*pkose[i]);
	}
	for (int i = 0;i < ILOSC_STANOWISK_OPONY;i++)  //usuwanie zaalokowanej dynamicznie pamieci
		if (o[i] != NULL)
			delete o[i];
	for (int i = 0;i < ILOSC_STANOWISK;i++)  //usuwanie zaalokowanej dynamicznie pamieci
	{
		if (k[i] != NULL)
			delete k[i];
		if (s[i] != NULL)
			delete s[i];
		if (pk[i] != NULL)
			delete pk[i];
		if (pko[i] != NULL)
			delete pko[i];
		if (pkos[i] != NULL)
			delete pkos[i];
		if (pkose[i] != NULL)
			delete pkose[i];
	} //wypisanie stanu kolejek
	cout << "Kolejka karoserii do stanowiska malowania karoserii 1: " << kq[0].size() << endl;
	cout << "Kolejka karoserii do stanowiska malowania karoserii 2: " << kq[1].size() << endl;
    cout << "Kolejka opon do stanowiska montowania opon 1: " << oq[0].size() << endl;
	cout << "Kolejka opon do stanowiska montowania opon 2: " << oq[1].size() << endl;
	cout << "Kolejka karoserii do stanowiska montowania opon 1: " << pkq[0].size() << endl;
	cout << "Kolejka karoserii do stanowiska montowania opon 2: " << pkq[1].size() << endl;
    cout << "Kolejka silnikow do montowania silnika 1: " << sq[0].size() << endl;
	cout << "Kolejka silnikow do montowania silnika 2: " << sq[1].size() << endl;
	cout << "Kolejka karoserii z oponami do montowania silnika 1: " << pkoq[0].size() << endl;
	cout << "Kolejka karoserii z oponami do montowania silnika 2: " << pkoq[1].size() << endl;
	cout << "Kolejka karoserii z oponami i silnikiem do montowania elektroniki 1: " << pkosq[0].size() << endl;
	cout << "Kolejka karoserii z oponami i silnikiem do montowania elektroniki 2: " << pkosq[1].size() << endl;
	cout << "Ilosc kompletnych samochodow: " << pkosev.size() << endl;
	if (czy_do_pliku)  //zapisanie stanu kolejek do pliku
	{
		przeb_test << "Kolejka karoserii do stanowiska malowania karoserii 1: " << kq[0].size() << "\r\n";
		przeb_test << "Kolejka karoserii do stanowiska malowania karoserii 2: " << kq[1].size() << "\r\n";
        przeb_test << "Kolejka opon do stanowiska montowania opon 1: " << oq[0].size() << "\r\n";
		przeb_test << "Kolejka opon do stanowiska montowania opon 2: " << oq[1].size() << "\r\n";
		przeb_test << "Kolejka karoserii do stanowiska montowania opon 1: " << pkq[0].size() << "\r\n";
		przeb_test << "Kolejka karoserii do stanowiska montowania opon 2: " << pkq[1].size() << "\r\n";
        przeb_test << "Kolejka silnikow do montowania silnika 1: " << sq[0].size() << "\r\n";
		przeb_test << "Kolejka silnikow do montowania silnika 2: " << sq[1].size() << "\r\n";
		przeb_test << "Kolejka karoserii z oponami do montowania silnika 1: " << pkoq[0].size() << "\r\n";
		przeb_test << "Kolejka karoserii z oponami do montowania silnika 2: " << pkoq[1].size() << "\r\n";
		przeb_test << "Kolejka karoserii z oponami i silnikiem do montowania elektroniki 1: " << pkosq[0].size() << "\r\n";
		przeb_test << "Kolejka karoserii z oponami i silnikiem do montowania elektroniki 2: " << pkosq[1].size() << "\r\n";
		przeb_test << "Ilosc kompletnych samochodow: " << pkosev.size() << "\r\n" << "\r\n" << "\r\n";
	}
	przeb_test.close();
}

void wczytaj_dane(unsigned int &iteracje, unsigned int &zapis, unsigned int &wstrzymaj)
{
	ifstream dane_wej; //plik z poczatkowymi danymi
	string tmp;
	while (1) //wykonuje sie do wpisania poprawnej nazwy albo komendy default
	{
		cout << "Podaj nazwe pliku do wczytania (z rozszerzeniem):" << endl;
		getline (cin, tmp);
		if (tmp=="default")
        {
            cout << "Dane nie zostana wczytane z pliku" << endl;
            cout << "Ilosc iteracji zostanie ustawiona na domyslna: " << DEFAULT_ITERACJE << endl;
            cout << "Czestosc zapisu zostanie ustawiona na domyslna: " << DEFAULT_ZAPIS << endl;
			cout << "Czas wstrzymania zostanie ustawiony na domyslny: " << DEFAULT_WSTRZYMAJ << endl;
            iteracje = DEFAULT_ITERACJE;
            zapis = DEFAULT_ZAPIS;
			wstrzymaj = DEFAULT_WSTRZYMAJ;
            sleep(DANE_CZAS);
            system("clear");
            return;
        }
		try
		{
			dane_wej.open(tmp.c_str());
			if (!dane_wej)
				throw MyException("Taki plik nie istnieje - podaj nazwe jeszcze raz");
			break;
		}
		catch (MyException &e)
		{
			cout << e.what() << endl;
			continue;
		}
	}
	try //proba wczytania ilosci iteracji
	{
		if (dane_wej.eof())
			throw MyException("Nieprawidlowe dane - ilosc iteracji zostanie ustawiona na domyslna: " + DEFAULT_ITERACJE);
		dane_wej >> tmp;
		for (unsigned int i = 0;i < tmp.size();i++)
			if (!isdigit(tmp[i]))
				throw MyException("Nieprawidlowe dane - ilosc iteracji zostanie ustawiona na domyslna: " + DEFAULT_ITERACJE);
		iteracje = atoi(tmp.c_str());
		cout << "Ustawiono ilosc iteracji na " << iteracje << endl;
	}
	catch (MyException &e)
	{
		cout << e.what() << endl;
		iteracje = DEFAULT_ITERACJE;
	}
	try //proba wczytania czestosci zapisu
	{
		if (dane_wej.eof())
			throw MyException("Nieprawidlowe dane - czestosc zapisu zostanie ustawiona na domyslna: " + DEFAULT_ZAPIS);
		dane_wej >> tmp;
		for (unsigned int i = 0;i < tmp.size();i++)
			if (!isdigit(tmp[i]))
				throw MyException("Nieprawidlowe dane - czestosc zapisu zostanie ustawiona na domyslna: " + DEFAULT_ZAPIS);
		zapis = atoi(tmp.c_str());
		if (zapis == 0)
			throw MyException("Nieprawidlowe dane - czestosc zapisu zostanie ustawiona na domyslna: " + DEFAULT_ZAPIS);
		cout << "Ustawiono czestosc zapisu na " << zapis << endl;
	}
	catch (MyException &e)
	{
		cout << e.what() << endl;
		zapis = DEFAULT_ZAPIS;
	}
	try //proba wczytania czasu wstrzymania
	{
		if (dane_wej.eof())
			throw MyException("Nieprawidlowe dane - czas wstrzymania zostanie ustawiony na domyslny: " + DEFAULT_WSTRZYMAJ);
		dane_wej >> tmp;
		for (unsigned int i = 0;i < tmp.size();i++)
			if (!isdigit(tmp[i]))
				throw MyException("Nieprawidlowe dane - czas wstrzymania zostanie ustawiony na domyslny: " + DEFAULT_WSTRZYMAJ);
		wstrzymaj = atoi(tmp.c_str());
		if (wstrzymaj == 0)
			throw MyException("Nieprawidlowe dane - czas wstrzymania zostanie ustawiony na domyslny: " + DEFAULT_WSTRZYMAJ);
		cout << "Ustawiono czas wstrzymania na " << wstrzymaj << endl;
	}
	catch (MyException &e)
	{
		cout << e.what() << endl;
		wstrzymaj = DEFAULT_WSTRZYMAJ;
	}
	dane_wej.close();
	sleep(DANE_CZAS);
}
