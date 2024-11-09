
objects = main.o CustomerPortal.o EmployeePortal.o CustomerManager.o Account.o

all: BankSystem

debug: $(objects)
	g++ -std=c++11 -g -o BankSystem $(objects)

BankSystem: $(objects)
	g++ -std=c++11 -o BankSystem $(objects)

main.o: main.cc CustomerPortal.o EmployeePortal.o CustomerManager.o
	g++ -std=c++11 -c main.cc

CustomerPortal.o: CustomerPortal.h CustomerPortal.cc CustomerManager.o
	g++ -std=c++11 -c CustomerPortal.cc

EmployeePortal.o: EmployeePortal.h EmployeePortal.cc CustomerManager.o
	g++ -std=c++11 -c EmployeePortal.cc

CustomerManager.o: CustomerManager.h CustomerManager.cc Account.o
	g++ -std=c++11 -c CustomerManager.cc

Account.o: Account.h Account.cc
	g++ -std=c++11 -c Account.cc

clean:
	rm -f BankSystem *.o
