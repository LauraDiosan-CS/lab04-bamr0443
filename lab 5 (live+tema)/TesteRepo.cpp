#include <iostream>
#include <assert.h>
#include "TesteRepo.h"
#include "Repo.h"

using namespace std;


void TesteRepo()
{
	// Test Default (Fara parametri) Constructor
	Repo r1;
	assert(r1.GetSize() == 0);

	// Test Adaugare (AddElem) si Atribuire (operator=)
	Repo r2;
	NotaExamen nota1(10, 5, "George");
	NotaExamen nota2(20, 10, "Daniela");
	r2.AddElem(nota1);
	r2.AddElem(nota2);
	assert(r2.GetSize() == 2);
	r1 = r2;
	assert(r1.GetSize() == 2);
	
	for (int i = 0; i < r1.GetSize(); i++)
	{
		// Comparam Notele de pe pozitia i din fiecare repo
		assert(r1.GetAll()[i] == r2.GetAll()[i]);
	}

	// Test GetElem
	NotaExamen& nota = r2.GetElem(1);
	assert(nota == nota2);

	// Test Adaugare Bonus
	Repo r;
	NotaExamen ne1(10, 5, "Anca");
	NotaExamen ne2(5, 8, "Dan");
	NotaExamen ne3(10, 6, "Anca");
	r.AddElem(ne1);
	r.AddElem(ne2);
	r.AddElem(ne3);

	r.AdaugareBonusPentruStudent("Anca");

	NotaExamen* examene = r.GetAll();
	assert(examene[0].GetNota() == 6);
	assert(examene[2].GetNota() == 7);

	// Test Find
	Repo r3;
	r3.AddElem(ne1);
	r3.AddElem(ne2);
	r3.AddElem(ne3);
	NotaExamen ne4(2, 10, "Denis");
	int i = r3.FindElem(ne4);
	assert(i == -1); // nu se gaseste

	i = r3.FindElem(ne3);
	assert(i == 2);

	// Test Update
	NotaExamen ne5(15, 10, "Camelia");
	r3.AddElem(ne5);
	i = r3.FindElem(ne5); // luam locatia
	r3.UpdateElem(ne5, "Ion", 3, 4);
	assert(r3.GetElem(i).GetData() == 4);
	assert(r3.GetElem(i).GetNota() == 3);
	assert(strcmp(r3.GetElem(i).GetNume(), "Ion") == 0);
	
	// Test Delete
	assert(r3.FindElem(ne3) != -1);
	int sizeInainteDeDelete = r3.GetSize();
	r3.DeleteElem(ne3);
	assert(r3.FindElem(ne3) == -1);
	assert(sizeInainteDeDelete == (r3.GetSize() + 1));
	

	cout << "Au trecut testele pentru Repo" << endl;
}