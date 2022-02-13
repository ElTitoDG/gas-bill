all: clean build run

publish: clean build docker

clean:
	rm -f output/gas_bill

build:
	clang src/gas_bill.c -o output/gas_bill

run:
	./output/gas_bill

docker:
	docker build . -t eltitodg/gas-bill:dev && docker push eltitodg/gas-bill:dev

delete keys: company individual retired

company:
	rm -r docs/company.txt

individual:
	rm -r docs/individual.txt

retired:
	rm -r docs/retired.txt
