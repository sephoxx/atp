//
//
#define _CRT_SECURE_NO_WARNINGS

#include "stdafx.h" //ignora asta
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //asta e pt atoi vezi mai jos
#include <conio.h> //asta e pt getch, vezi mai jos

int *count_sort(int *toSort, int n, int maxi) //functia e POINTER pt ca returnezi vectorul
{
	int i, *countArr, *sorted; //countArr e vectorul de frecventa si sorted e vectorul final

	countArr = new int[maxi + 1]; //aceasi lucru ca "int countArr[maxi + 1]", se scria asa doar pt ca maxi nu e un nr constant, + 1 pt ca vectorul incepe de la 1 aici
	sorted = new int[n + 1];

	for (i = 0; i <= maxi; i++) //initializeaza toate elementele cu 0
		countArr[i] = 0;

	for (i = 0; i < n; i++) // numara de cate ori apare fiecare element din vectorul initial
	{
		countArr[toSort[i]]++;
	}

	for (i = 0; i <= maxi; i++)// adauga la elementul urmator elementul curent - vezi videoclipul
	{
		countArr[i + 1] += countArr[i];
	}

	for (i = 0; i < n; i++)// il sorteaza - vezi videoclipul
	{
		sorted[countArr[toSort[i]]] = toSort[i];
		countArr[toSort[i]] -= 1;
	}



	return sorted;
}

int main()
{

	FILE *f; //variabila fisierului, conteaza ca e scrisa cu litere mari
	char inName[30], outName[30]; //numele fisierelor de input si output
	char *c = (char*)malloc(sizeof(char)*1000); //malloca caracterul doar pt ca altfel da eroare
	int n, i, *before, val, maxi, *sorted; // n e numarul de elemente din vectorul initital si final, before e vectorul initial(acelasi lucru cu toSort), maxi e valoarea maxima din vectorul initial,
										   // sorted e ala final

	maxi = 0;

	printf("Input file name to import from:\n");
	scanf("%s", inName);
	printf("\nInput file name to output to:\n");
	scanf("%s", outName);

	fopen_s(&f, inName, "r"); //descide fisierul de input pt citire. campurile vin asa: fopen_s(adresa fisierului, numele fisierului, tipul de actiune(r-ead, w-rite, a-ppend))
	fgets(c, 1000, f);//il citeste pe n, scanf pt fisier, campurile vin: fgets(unde salveaza ce a citit, cate cifre contine, din ce fisier citeste)
					  //atentie ca fgets citeste char nu int
	n = atoi(c); //atoi - ascii to int, transforma valoare char in int

	before = new int[n]; //la fel ca in subprogram
	sorted = new int[n + 1];

	for (i = 0; i < n; i++) //construieste vectorul initial
	{
		fgets(c, 1000, f); // la fel ca mai sus
		val = atoi(c);
		if (val > maxi) //gaseste valoarea maxima in acelasi timp ca sa nu mai scrii un for la fel
			maxi = val;
		before[i] = val;
	}



	fclose(f); //inchde fisierul
	sorted = count_sort(before, n, maxi);

	fopen_s(&f, outName, "w");//deschide fisierul ca sa scrie vectorul sortat, daca fisierul nu exista il creeaza

	fprintf(f, "%d\n", n);//printf pt fisier, asta chiar e la fel. Iti amintesc ca %d - int | %s - string (mai mult decat un caracter) | %c - un singur caracter.
						  // \n e pt linie noua

	for (i = 1; i <= n; i++)
		fprintf(f, "%d\n", sorted[i]);

	fclose(f); //inchide fisier
	free(c);//sterge memoria ocupata de malloc

	printf("\nNumbers sorted successfully!");
	_getch();//asta il pui ca sa nu mai iasa imediat din consola cand rulezi cu debugger ul cum ne enerva pe noi la testul de atp:)
}
