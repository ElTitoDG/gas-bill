CC=clang


all: clean build run

publish: clean build docker

clean:
	rm -f gas_bill

build:
	mkdir keys
	$(CC) -c -g bin/src/checkfile.c -o bin/checkfile.o
	$(CC) -c -g src/gas_bill.c -o bin/gas_bill.o 
	$(CC) bin/gas_bill.o bin/checkfile.o -o gas_bill

run:
	./gas_bill

docker:
	docker build . -t eltitodg/gas-bill:dev && docker push eltitodg/gas-bill:dev

delete keys: company individual retired

company:
	rm -r keys/company.txt

individual:
	rm -r keys/individual.txt

retired:
	rm -r keys/retired.txt
