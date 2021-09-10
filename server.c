#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "server.h"


void swap(struct database **lhs, struct database **rhs) 
{
	struct database *temp = *lhs;
	*lhs = *rhs;
	*rhs = temp;
}
void selection_sort_name(struct database *p[], int n) // SORTING FUNCTION
{
	int i, pos, j;
	for (i = 0; i < n - 1; i++) {
		pos = i;
		for (j = i + 1; j < n; j++) {
			if (strcmp(p[pos]->name, p[j]->name) > 0)
				pos = j;
		}
		if (pos != i)
			swap(&p[pos], &p[i]);
	}
}
void init_ptr(struct database s[], struct database *p[], int n) 
{
	for (int i = 0; i < n; i++) 
	{
		p[i] = &s[i];
	}
}

void add() 
{
	FILE *fp = fopen("contact.csv", "a");
		int n;
		int i;
		int phone;
		printf("\t\t\tEnter the number of contacts you want to enter:\n");
		scanf("%d", &n);

		contact a[10];
		printf("\t\t\tEnter the details\n\n");
		for (i = 0; i < n; i++) 
		{
			printf("\t\t\t\t\t\tEnter the name:\n");
			scanf("%s", a[i].name);
			printf("\t\t\t\t\t\tEnter the phone no:\n");
			scanf("%s", a[i].phone);
			printf("\t\t\t\t\t\tEnter the email id:\n");
			scanf("%s", a[i].mail);
			fprintf(fp, " ,%s,%s,%s", a[i].name, a[i].phone, a[i].mail);//Contacts are written into the backend file
			fprintf(fp, "\n");
		}
	fclose(fp);
}

void display() 
{
	FILE *fp = fopen("contact.csv", "r");
		int num = 0;
		struct database s[10];
		struct database *p[10];
		char ch[500];
		char *name, *phone, *mail;
		printf("\t\t\t\t\t================================\n");

		while (fgets(ch, 500, fp) != NULL) //Extracting information to the structure
		{
			strtok(ch, ",");
			name = strtok(NULL, ",");
			phone = strtok(NULL, ",");
			mail = strtok(NULL, ",");
			strcpy(s[num].name, name);
			strcpy(s[num].phone, phone);
			strcpy(s[num].mail, mail);
			num++;
		}
		init_ptr(s, p, num);

		selection_sort_name(p, num);//SORTING

		for (int j = 0; j < num; j++) //Printing from the structure
		{
			printf("\t\t\t\t\t\tNAME : %s\n\n", p[j]->name);
			printf("\t\t\t\t\t\tPHONE NUMBER : %s\n\n", p[j]->phone);
			printf("\t\t\t\t\t\tMAIL ID : %s\n", p[j]->mail);
			printf("\t\t\t\t\t================================\n");
		}
	fclose(fp);
}

void edit() {
	FILE *fp = fopen("contact.csv", "r+");
	FILE *fr = fopen("new.csv", "w");
		struct database s[10]; 
		int num = 0;
		char ch[500];
		char *name, *phone, *mail;
		while (fgets(ch, 500, fp) != NULL) 
		{
			strtok(ch, ",");
			name = strtok(NULL, ","); 
			phone = strtok(NULL, ",");
			mail = strtok(NULL, ",");
			mail[strcspn(mail, "\n")] = 0; //To find the location of new line character and making it the end of string
			strcpy(s[num].name, name);
			strcpy(s[num].phone, phone);
			strcpy(s[num].mail, mail);
			num++;
		}
		char name2[20];char name3[20];
		char phone2[20];int found=0;
		char mail2[30];
		printf("\t\t\t\t\t\tEnter the name of the contact to be edited\n\n");
		scanf("%s", name2);
		for (int i = 0; i < num; i++) {
			if (strcmp(s[i].name, name2) == 0) 
			{
				found=1;
				printf("\t\t\t\t\t\tEnter the new name\n");
				scanf("%s",name3);
				printf("\t\t\t\t\t\tEnter the new number\n");
				scanf("%s", phone2);
				printf("\t\t\t\t\t\tEnter the new mail id\n");
				scanf("%s", mail2);
				strcpy(s[i].name,name3);
				strcpy(s[i].mail, mail2);
				strcpy(s[i].phone, phone2);
				break;
			}
		}
		for (int i = 0; i < num; i++) 
		{
			fprintf(fr, " ,%s,%s,%s", s[i].name, s[i].phone, s[i].mail);//Data is written into the new file
			fprintf(fr, "\n");
		}
		if(found==0)
		{
			printf("\t\t\t\t\t\tINVALID NAME\n\n");
		}
		else
		{
			printf("\t\t\t\t\t\tContact has been successfully edited\n");
		}
		fclose(fp);
		fclose(fr);
	
}

void copy() 
{
	FILE *fp = fopen("contact.csv", "w");
	FILE *fr = fopen("new.csv", "r");//Data is being transferred from new file to original file
	char ch;
	while ((ch = fgetc(fr)) != EOF)
		fputc(ch, fp);
	fclose(fr);
	fclose(fp);

}

void search() {
	FILE *fp = fopen("contact.csv", "r");
		char ch[500];
		char a[50];
		char *name;int found=0;
		printf("\t\t\tEnter the name to be searched\n");
		scanf("%s", a);
		while (fgets(ch, 500, fp) != NULL) {
			strtok(ch, ",");
			name = strtok(NULL, ",");
			if (strcmp(a, name) == 0) 
			{
				found=1;
				printf("\t\t\t\t\t\tThe details are:\n\n");
				printf("\t\t\t\t\t================================\n");
				printf("\t\t\t\t\t\tNAME : %s\n\n", name); //name
				name = strtok(NULL, ",");
				printf("\t\t\t\t\t\tPHONE NUMBER : %s\n\n", name); //number
				name = strtok(NULL, ",");
				printf("\t\t\t\t\t\tMAIL : %s\n", name); //mail
				printf("\t\t\t\t\t================================\n");
			}
		}
		if(found==0)
		{
			printf("\t\t\t\t\t\tINVALID NAME\n\n");
		}
	fclose(fp);
}



void Delete()
{
    FILE*fp=fopen("contact.csv","r");
    FILE*fr=fopen("new.csv","w");
    
    int num=0;
        struct database s[10];
        char ch[500];
        char *name,*phone,*mail;
        char name1[20];
        while (fgets(ch,500,fp)!=NULL)
        {
            strtok(ch,",");
            name=strtok(NULL,","); 
            phone=strtok(NULL,",");
            mail=strtok(NULL,",");
			mail[strcspn(mail, "\n")] = 0;
            strcpy(s[num].name,name);
            strcpy(s[num].phone,phone);
            strcpy(s[num].mail,mail);
            num++;
        }
        
        printf("\t\t\t\t\t\tEnter the name of the contact to be deleted\n");
        fflush(stdin);
        scanf("%s",name1);
        for(int i=0;i<num;i++)//DATA is written into the new file and is transferred to original file
        {
            if(strcmp(s[i].name,name1)!=0)
            {
                fprintf(fr," ,%s,%s,%s",s[i].name,s[i].phone,s[i].mail);
				fprintf(fr,"\n");
            }
        }
		printf("\t\t\t\t\t\tContact has been successfully deleted\n");
        fclose(fp);
        fclose(fr);
    
}