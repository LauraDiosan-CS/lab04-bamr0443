#include <iostream>
#include "NotaExamen.h"

NotaExamen::NotaExamen()
{
	data = 0;
	nota = 0;
	nume = NULL;
}

NotaExamen::NotaExamen(int Data, int Nota, const char* Nume)
{
	data = Data;
	nota = Nota;

	// alocam memorie pentru nume
	nume = new char[strlen(Nume) + 1];
	// copiem numele dat in constructor in atributul 'nume'
	strcpy_s(nume, strlen(Nume) + 1, Nume);
}

NotaExamen::NotaExamen(const NotaExamen& other)
{
	data = other.data;
	nota = other.nota;

	// alocam memorie pentru nume
	nume = new char[strlen(other.nume) + 1];
	// copiem numele din other in atributul 'nume'
	strcpy_s(nume, strlen(other.nume) + 1, other.nume);
}

int NotaExamen::GetData()
{
	return data;
}

void NotaExamen::SetData(int Data)
{
	data = Data;
}

char* NotaExamen::GetNume()
{
	return nume;
}

void NotaExamen::SetNume(const char* Nume)
{
	// dealocam numele anterior 
	// si alocam cata memorie ne trebuie
	// pentru numele nou
	if (nume != NULL)
	{
		delete[] nume;
	}

	// alocare memorie + copiere nume nou
	nume = new char[strlen(Nume) + 1];
	strcpy_s(nume, strlen(Nume) + 1, Nume);
}

int NotaExamen::GetNota()
{
	return nota;
}

void NotaExamen::SetNota(int Nota)
{
	nota = Nota;
}

NotaExamen& NotaExamen::operator=(const NotaExamen& other)
{
	SetData(other.data);
	SetNume(other.nume);
	SetNota(other.nota);

	return *this;
}

bool NotaExamen::operator==(const NotaExamen& other)
{
	if (data != other.data)
		return false;

	if (nota != other.nota)
		return false;

	if (strcmp(nume, other.nume) != 0)
		return false;

	return true;
}

NotaExamen::~NotaExamen()
{
	delete[] nume;
}

ostream& operator<<(ostream& os, NotaExamen& ne)
{
	os << "Nume: " << ne.nume << endl;
	os << "Nota: " << ne.nota << endl;
	os << "Data: " << ne.data << endl;

	return os;
}

istream& operator>>(istream& is, NotaExamen& ne)
{
	char nume[50];

	cout << "Introduceti numele: ";
	is >> nume;
	ne.SetNume(nume);

	cout << "Introduceti nota: ";
	is >> ne.nota;

	cout << "Introduceti data: ";
	is >> ne.data;

	return is;
}
