OBJS=main.o Symulacja.o Karoseria.o Opona.o Silnik.o
CXX=g++
CFLAGS=-Wall
LFLAGS=

projekt2.out: $(OBJS) Symulacja.h Karoseria.h Opona.h Silnik.h
	$(CXX) $(OBJS) -o projekt3.out

main.o: main.cpp
	$(CXX) -c $(CFLAGS) main.cpp -o main.o

Karoseria.o: Karoseria.cpp
	$(CXX) -c $(CFLAGS) Karoseria.cpp -o Karoseria.o

Symulacja.o: Symulacja.cpp
	$(CXX) -c $(CFLAGS) Symulacja.cpp -o Symulacja.o

Opona.o: Opona.cpp
	$(CXX) -c $(CFLAGS) Opona.cpp -o Opona.o

Silnik.o: Silnik.cpp
	$(CXX) -c $(CFLAGS) Silnik.cpp -o Silnik.o

clean:
	rm -f *.o
.PHONY: clean