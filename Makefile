all: clean build run

publish: clean build docker run

clean:
	rm -f output/gas_bill

build:
	clang src/gas_bill.c -o output/gas_bill

run:
	./output/gas_bill

docker:
	docker build . -t eltitodg/gas-bill:dev && docker push eltitodg/gas-bill:dev
