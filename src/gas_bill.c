//Used libraries
#include<stdlib.h>
#include<stdio.h>
#include <sys/stat.h>

// Global Variables for all the functions 
int used_energy = 0;
int opc, opc2;


//tui: main interface for the program
int tui();
//tui2: interface for selecting the client
int tui2();

int checkIfFileExists(const char* filename);

int main()
{

  FILE *fp;

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
        printf("\nCreating Company key file\n");
        fp = fopen("keys/company.txt", "w");
        fputs("Company key", fp);
				printf("Hiring new installation for company\n");
				final_price = 100 + (used_energy*kw) * 0.27;
				printf("Your final bill is: %.2f$\n", final_price);
        printf("\n");  
        fclose(fp);
			}
			else if(opc2 == 2)
			{
        printf("\nCreating Individual key file");
        fp = fopen("keys/individual.txt", "w");
        fputs("Individual key", fp);
				printf("\nHiring new installation for Individual\n");
				final_price = 100 + (used_energy*kw) * 0.23;
				printf("Your final bill is: %.2f$\n", final_price);
        printf("\n");
        fclose(fp);
			}
			else if(opc2 == 3)
			{
				printf("\nCreating Retired key file\n");
        fp = fopen("keys/retired.txt", "w");
        fputs("Retired key", fp);
        printf("\nHiring new installation for Retired\n");
				final_price = 100 + (used_energy*kw) * 0.12;
				printf("Your final bill is: %.2f$\n", final_price);
        printf("\n");
        fclose(fp);
			}
		break;

		//Case 2: Hire more quantity with final bill depending the on the client
		case 2:
			
			tui2();
			scanf("%i", &opc2);
			if(checkIfFileExists("keys/company.txt") && opc2 == 1)
			{
				printf("\nCompany key detected\n");
        printf("Hiring more KW for Company\n");
				final_price = (used_energy*kw) * 0.27;
				printf("Your final bill is: %.2f$\n", final_price);
        printf("\n");
			}
			else if(checkIfFileExists("keys/individual.txt") && opc2 == 2)
			{
				printf("\nHiring more KW for Individual\n");
				final_price = (used_energy*kw) * 0.23;
				printf("Your final bill is: %.2f$\n", final_price);
        printf("\n");
			}
			else if(checkIfFileExists("keys/retired.txt") && opc2 == 3)
			{
				printf("\nHiring more KW for Retired\n");
				final_price = (used_energy*kw) * 0.12;
				printf("Your final bill is: %.2f$\n", final_price);
        printf("\n");
			}
		break;

    case 3:
      remove("keys/company.txt");
      remove("keys/individual.txt");
      remove("keys/retired.txt");
      printf("\nAll user keys deleted\n");
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
  printf("3. Delete user keys\n");
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
