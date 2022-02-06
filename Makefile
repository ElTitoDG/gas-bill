all: clean build run

clean:
	rm -f output/gas_bill

build:
	clang src/gas_bill.c -o output/gas_bill

run:
	./output/gas_bill
