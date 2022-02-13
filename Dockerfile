FROM ubuntu:latest

	COPY . /gas-bill
	
	WORKDIR /gas-bill/

  RUN apt update
  RUN apt install -y build-essential
	
	RUN gcc -o gas_bill src/gas_bill.c
	
	CMD ["./gas_bill"]
