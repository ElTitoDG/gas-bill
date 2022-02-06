FROM gcc:latest

	COPY . /usr/src/gas-bill
	
	WORKDIR /usr/src/gas-bill
	
	RUN gcc src/gas_bill.c -o output/gas_bill
	
	CMD ["make run"]
