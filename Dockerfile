FROM gcc:latest

	COPY . /gas-bill
	
	WORKDIR /gas-bill/
	
	RUN gcc -o gas_bill src/gas_bill.c
	
	CMD ["./gas_bill"]
