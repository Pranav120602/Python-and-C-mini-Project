#include<stdio.h>
#include<stdlib.h>
#include "server.h"
void menudriven();
int main() {
	printf("\t\t\t\t\t\tWELCOME\n");
	menudriven();
}

void menudriven() {
	printf("\n");
	printf(
			"\t\t\t\t\t\tCHOOSE\n\n\t\t\t\t\t\t 1)ADD\n\n\t\t\t\t\t\t 2)EDIT\n\n\t\t\t\t\t\t 3)DELETE \n\n\t\t\t\t\t\t 4)DISPLAY\n\n\t\t\t\t\t\t 5)SEARCH\n\n\t\t\t\t\t\t 0)EXIT\t\t\t\n\n ");
	int n;
	scanf("%d", &n);

	switch (n) {
	case 0: //exit
	{   
		printf("\t\t\t\t\t\tTHANK YOU:) ");
		break;
	}
	case 1: //add contacts
	{
		add();
		menudriven();
		break;
	}
	case 2:  //edit contacts
	{

		edit();
		copy();
		menudriven();
		break;
	}
	case 3: //delete contacts
	{
		Delete();
		copy();
		menudriven();
		break;
	}
	case 4: //display all contacts
	{
		display();
		menudriven();
		break;
	}

	case 5: //search contacts
	{
		search();
		menudriven();
		break;
	}
	default: 
	{
		printf("\t\t\t\t\t\tPlease enter a valid choice\n\n");
		menudriven();
		break;
	}
	}

}
