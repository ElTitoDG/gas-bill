#include<stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "../include/tui.h"

int used_energy = 0;

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
