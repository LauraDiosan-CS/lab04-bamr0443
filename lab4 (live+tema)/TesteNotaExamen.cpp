#include <iostream>
#include <assert.h>
#include "TesteNotaExamen.h"
#include "NotaExamen.h"

using namespace std;

void TesteNotaExamen()
{
	// Test Default Constructor (Fara parametri) & Getter
	NotaExamen ne;
	assert(ne.GetData() == 0);
	assert(ne.GetNota() == 0);
	assert(ne.GetNume() == NULL);

	// Test Setter & Getter
	ne.SetData(15);
	assert(ne.GetData() == 15);
	ne.SetNota(9);
	assert(ne.GetNota() == 9);
	ne.SetNume("Andi");
	assert(strcmp(ne.GetNume(), "Andi") == 0);

	// Test Operator Atribuire (=) si Constructor cu param
	NotaExamen ne2(10, 5, "Ion");
	assert(ne2.GetData() == 10);
	assert(ne2.GetNota() == 5);
	assert(strcmp(ne2.GetNume(), "Ion") == 0);
	ne = ne2;
	assert(ne.GetData() == ne2.GetData());
	assert(ne.GetNota() == ne2.GetNota());
	assert(strcmp(ne.GetNume(), ne2.GetNume()) == 0);

	// Test Copy Constructor
	NotaExamen ne3(10, 6, "Alex");
	NotaExamen ne4(ne3);
	assert(ne4.GetData() == 10);
	assert(ne4.GetNota() == 6);
	assert(strcmp(ne4.GetNume(), "Alex") == 0);

	// Test Operator==
	NotaExamen ne5(15, 5, "Ion");
	NotaExamen ne6(15, 5, "Margareta");
	NotaExamen ne7(15, 5, "Ion");
	assert(ne5 == ne7);
	assert(!(ne5 == ne6));
	
	cout << "Au trecut testele pentru NotaExamen" << endl;
}