#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include "cifrado.h"
#define MAX 100

char cifcad(char CAD[]);
char cifcadp(char CAD[],int n);
char descad(char CAD[]);
char descadp(char CAD[],int n);
int val(char x[]);

int main()
{int i,v,op,n;
char CAD[100],x[2];
do
	{do
		{cifmenu();
		printf("Ingresa la opcion: ");
		scanf("%s",x);
		v=val(x);}
	while(v==0);
	op=atoi(x);
	switch(op)
		{case 1:
			{printf("Ingresa una frase: ");
			fflush(stdin);scanf("%[^\n]",CAD);
			for(i=0;CAD[i]!='\0';i++)
				{CAD[i]=toupper(CAD[i]);}
			break;}
		case 2:
			{printf("Frase original: %s\n",CAD);
			break;}
		case 3:
			{CAD[i]=cifcad(CAD);printf("Cadena cifrada con exito.\n");
			break;}
		case 4:
			{do
				{printf("Ingresa cuantas posiciones quieres recorrer: ");
				scanf("%s",x);
				v=val(x);}
			while(v==0);
			n=atoi(x);
			CAD[i]=cifcadp(CAD,n);
			printf("Cadena cifrada con exito.\n");
			break;}
		case 5:
			{CAD[i]=descad(CAD);printf("Cadena descifrada con exito.\n");
			break;}
		case 6:
			{do
				{printf("Ingresa cuantas posiciones quieres recorrer: ");
				scanf("%s",x);
				v=val(x);}
			while(v==0);
			n=atoi(x);
			CAD[i]=descadp(CAD,n);
			printf("Cadena descifrada con exito.\n");
			break;}
		case 7:
			{printf("Hasta luego.");break;}
		default: 
			{printf("\nValor erroneo. Intente de nuevo.\n\n");break;}
		}
	}
while(!(op==7));
return(0);}

char cifcad(char CAD[])
{int i;
for(i=0;CAD[i]!='\0';i++)
	{if(CAD[i]==' ')
		{CAD[i]=' ';}
	else
		{if(CAD[i]=='Z')
			{CAD[i]='A';}
		else
			{CAD[i]=CAD[i]+1;}}}}
				
char cifcadp(char CAD[],int n)
{int i;
for(i=0;CAD[i]!='\0';i++)
	{if(CAD[i]==' ')
		{CAD[i]=' ';}
	else 
		{if(isalpha(CAD[i])) 
			{CAD[i]=(CAD[i]-'A'+n)%26+'A';}}}}

char descad(char CAD[])
{int i;
for(i=0;CAD[i]!='\0';i++)
	{if(CAD[i]==' ')
		{CAD[i]=' ';}
	else
		{if(CAD[i]=='A')
			{CAD[i]='Z';}
		else
			{CAD[i]=CAD[i]-1;}}}}
				
char descadp(char CAD[],int n)
{int i;
for(i=0;CAD[i]!='\0';i++)
	{if(CAD[i]==' ')
		{CAD[i]=' ';}
	else
		{if(isalpha(CAD[i]))
			{CAD[i]=(CAD[i]-'A'-n+26)%26+'A';}}}}
			
int val(char x[])
{int i;
for(i=0;i<1;i++)
	{if(!(isdigit(x[i])))
		{printf("\nValor erroneo. Ingresa solo numeros.\n\n");return(0);}}
return(1);}
