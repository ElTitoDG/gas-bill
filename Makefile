CC=clang
FLAGS= -std=c18 -Wall -c -g

all: keys build run clean

publish: build docker clean

clean:
	rm -f gas_bill
	rm -r bin/checkfile.o
	rm -r bin/gas_bill.o
	rm -r keys/

keys:
	mkdir keys

build: checkfile.o gas_bill.o tui.o
	$(CC) bin/gas_bill.o bin/checkfile.o bin/tui.o -o gas_bill

checkfile.o:
	$(CC) $(FLAGS) bin/src/checkfile.c -o bin/checkfile.o

gas_bill.o:
	$(CC) $(FLAGS) src/gas_bill.c -o bin/gas_bill.o

tui.o:
	$(CC) $(FLAGS) bin/src/tui.c -o bin/tui.o

run:
	./gas_bill

docker:
	docker build . -t eltitodg/gas-bill:dev && docker push eltitodg/gas-bill:dev

delete_keys: company individual retired

company:
	rm -r keys/company.txt

individual:
	rm -r keys/individual.txt

retired:
	rm -r keys/retired.txt
