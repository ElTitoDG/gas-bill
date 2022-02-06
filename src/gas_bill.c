//Used libraries
#include<stdlib.h>
#include<stdio.h>

// Global Variables for all the functions 
int used_energy = 0;
int opc, opc2;


//tui: main interface for the program
int tui();
//tui2: interface for selecting the client
int tui2();

int main()
{

	float final_price, kw;

	if(used_energy >= 50)
	{
		kw = 0.1;
	}
	else
	{
		kw = 0.05;
	}

	tui();
	scanf("%i", &opc);


	switch(opc)
	{
		//Case 1: hire a new installation and the final bill depending on the client
		case 1:
		
			tui2();
			scanf("%i", &opc2);
			if(opc2 == 1)
			{
				printf("\nHiring new installation for company\n");
				final_price = 100 + (used_energy*kw) * 0.27;
				printf("Your final bill is: %.2f$\n", final_price);	
			}
			else if(opc2 == 2)
			{
				printf("\nHiring new installation for Individual");
				final_price = 100 + (used_energy*kw) * 0.23;
				printf("Your final bill is: %.2f$\n", final_price);
			}
			else if(opc2 == 3)
			{
				printf("\nHiring new installation for Retired\n");
				final_price = 100 + (used_energy*kw) * 0.12;
				printf("Your final bill is: %.2f#$\n", final_price);
			}
		break;

		//Case 2: hire more quantity with final bill depending the on the client
		case 2:
			
			tui2();
			scanf("%i", &opc2);
			if(opc == 1)
			{
				printf("\nHiring more KW for Company\n");
				final_price = (used_energy*kw) * 0.27;
				printf("Your final bill is: %.2f$\n", final_price);
			}
			else if(opc2 == 2)
			{
				printf("\nHiring more KW for Individual\n");
				final_price = (used_energy*kw) * 0.23;
				printf("Your final bill is: %.2f$\n", final_price);
			}
			else if(opc2 == 3)
			{
				printf("\nHiring more KW for Retire\n");
				final_price = (used_energy*kw) * 0.12;
				printf("Your final bill is: %.2f$\n", final_price);
			}
		break;
	}
	return 0;
}

int tui()
{

	//Desing of the tui main interface

	printf("\nWelcome to Pepe's Gas Company\n");
	printf("\n");
	printf("Amount of KW to employ: ");
	scanf("%i", &used_energy);
	
	printf("\n");
	printf("Choose an option: ");
	printf("\n1. New gas installation\n");
	printf("2. Hire more quantity\n");
	printf("Option: ");

	return 0;
}

int tui2()
{
	
	//Desing of the second tui interface

	printf("\n");
	printf("Costumer type: \n");
	printf("1. Company\n");
	printf("2. Individual\n");
	printf("3. Retired\n");
	printf("Option: ");

	return 0;
}

