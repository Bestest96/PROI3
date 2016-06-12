/*	Lukasz Lepak, 2I4
	prowadzacy: dr inz. Piotr Witonski
	projekt nr 3 (1801)
	symulacja grafu modelujacego abstrakcyjny system kolejek
	w fabryce samochodow
*/
#include "Karoseria.h"
#include "Symulacja.h"

using namespace std;

int main()
{
    while (1)
    {
        system("clear");
        srand(time(NULL));  //zapewnienie losowosci przy niektorych elementach
        string decyzja;  //zmienna sprawdzajaca, czy uzytkownik bedzie chcial powtorzyc symulacje
        unsigned int iteracje, zapis, wstrzymaj; //zmienne odpowiedzialne za przebieg symulacji
        bool czy_do_pliku=false; //zmienna odpowiedzialna za to, czy w danej iteracji zapisujemy do pliku
        ofstream reset("przebieg_testowania.txt", ios::trunc);  //wymazanie zawartosci pliku z danymi lub utworzenie go
        reset.close();
        queue<Kar> kq[2];  //deklaracja kolejek elementow oraz wektora dla gotowych samochodow
        queue<Op> oq[2];
        queue<Sil> sq[2];
        queue<PomKar> pkq[2];
        queue<PomKarOp> pkoq[2];
        queue<PomKarOpSil> pkosq[2];
        vector<PomKarOpSilEl> pkosev;
        wczytaj_dane(iteracje, zapis, wstrzymaj);  //wczytanie danych z pliku
        for (unsigned int i=0;i<iteracje;i++)
        {
            system("clear");  //czyszczenie ekranu
            czy_do_pliku = (i + 1) % zapis == 0 ? true : false;  //sprawdzenie, czy w tej iteracji zapisujemy do pliku
            symulacja(kq, oq, sq, pkq, pkoq, pkosq, pkosev, czy_do_pliku, i);
            sleep(wstrzymaj);
        }
        while (1)
        {
            cout << "Czy chcesz powtorzyc symulacje? (tak/nie)" << endl;
            getline (cin,decyzja);
            if (decyzja=="tak")
                break;
            else if (decyzja=="nie")
            {
                cout << "Dziekuje za skorzystanie z programu" << endl;
                return 0;
            }
            else
            {
                system("clear");
                cout << "Niepoprawna komenda - wpisz \"tak\" albo \"nie\"" << endl;
            }
        }
    }
}
