FROM ubuntu:latest

	COPY . /gas-bill
	
	WORKDIR /gas-bill/

  RUN apt update
  RUN apt install -y build-essential clang make
	
	RUN make all
	
	CMD ["./gas_bill"]
