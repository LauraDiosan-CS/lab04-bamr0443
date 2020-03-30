#include <iostream>
#include <assert.h>
#include "TesteService.h"
#include "Service.h"
#include "Repo.h"
#include "NotaExamen.h"

using namespace std;

void TesteService()
{
	Service s1;

	// Test Adaugare (AddElem)
	NotaExamen nota1(10, 5, "George");
	NotaExamen nota2(20, 10, "Daniela");
	s1.AddNotaExamen(nota1);
	s1.AddNotaExamen(nota2);
	assert(s1.GetSize() == 2);

	// Test Adaugare Bonus
	Service s2;
	NotaExamen ne1(10, 5, "Anca");
	NotaExamen ne2(5, 8, "Dan");
	NotaExamen ne3(10, 6, "Anca");
	s2.AddNotaExamen(ne1);
	s2.AddNotaExamen(ne2);
	s2.AddNotaExamen(ne3);

	s2.AdaugareBonusExamenPentruStudent("Anca");

	NotaExamen* examene = s2.GetNoteExamene();
	assert(examene[0].GetNota() == 6);
	assert(examene[2].GetNota() == 7);

	// Test Find
	Service s3;
	s3.AddNotaExamen(ne1);
	s3.AddNotaExamen(ne2);
	s3.AddNotaExamen(ne3);
	NotaExamen ne4(2, 10, "Denis");
	int i = s3.FindNotaExamen(ne4);
	assert(i == -1); // nu se gaseste

	i = s3.FindNotaExamen(ne3);
	assert(i == 2);

	// Test Update
	NotaExamen ne5(15, 10, "Camelia");
	s3.AddNotaExamen(ne5);
	i = s3.FindNotaExamen(ne5); // luam locatia
	s3.UpdateNotaEamen(ne5, 3, 4, "Ion");
	assert(s3.GetRepo().GetElem(i).GetData() == 4);
	assert(s3.GetRepo().GetElem(i).GetNota() == 3);
	assert(strcmp(s3.GetRepo().GetElem(i).GetNume(), "Ion") == 0);

	// Test Delete
	assert(s3.FindNotaExamen(ne3) != -1);
	int sizeInainteDeDelete = s3.GetSize();
	s3.DeleteNotaExamen(ne3);
	assert(s3.FindNotaExamen(ne3) == -1);
	assert(sizeInainteDeDelete == (s3.GetSize() + 1));


	cout << "Au trecut testele pentru Service" << endl;
}