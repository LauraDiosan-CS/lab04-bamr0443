#pragma once

#include "NotaExamen.h"

class Repo
{
private:
	int n;
	NotaExamen note[50];

public:
	// Constructori
	Repo();
	Repo(const Repo& other);
	~Repo();

	// Adaugare
	void AddElem(NotaExamen nota);

	// Getteri
	NotaExamen* GetAll();
	int GetSize();
	NotaExamen& GetElem(int i);

	// Afisare
	void Afisare();
	void AfisareNoteMaiMariCa(int nota);

	// Adaugare bonus de 1 punct pentru un student dat
	void AdaugareBonusPentruStudent(const char* nume);

	// Operatori
	Repo& operator= (const Repo& other);
};

//{ne0, DEL, ne2, ne3}

//{ne0, ne2, ne2, ne3}
//{ne0, ne2, ne3}

//
//
//for (int i = j; j < n - 1; j++)
//{
//	note[i] = note[i+1]
//}

//n = n - 1;
//{ne0, ne2, ne3}
