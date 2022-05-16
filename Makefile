CC=clang
FLAGS= -std=c18 -c -g

all: clean keys build run

publish: clean build docker

clean:
	rm -f gas_bill
	rm -r keys/

keys:
	mkdir keys

build:
	$(CC) $(FLAGS) bin/src/checkfile.c -o bin/checkfile.o
	$(CC) $(FLAGS) src/gas_bill.c -o bin/gas_bill.o 
	$(CC) bin/gas_bill.o bin/checkfile.o -o gas_bill

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
