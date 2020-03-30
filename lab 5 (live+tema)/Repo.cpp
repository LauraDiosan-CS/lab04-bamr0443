#include <iostream>
#include "Repo.h"

using namespace std;

Repo::Repo()
{
	n = 0;
}

Repo::Repo(const Repo& other)
{
	n = other.n;
	for (int i = 0; i < n; i++)
	{
		note[i] = other.note[i];
	}
}

Repo::~Repo()
{
}

void Repo::AddElem(NotaExamen& nota)
{
	note[n] = nota;
	n = n + 1;
}

void Repo::DeleteElem(NotaExamen& nota)
{
	int i = FindElem(nota);
	if (i == -1)
		return; // nu s-a gasit
	
	// mutam ultimul element pe pozitia pe care o stergem
	note[i] = note[n - 1];
	n = n - 1; // scade nr de elemente
}

void Repo::UpdateElem(NotaExamen& ne, const char* nume, int nota, int data)
{
	int i = FindElem(ne);
	if (i == -1)
		return; // nu s-a gasit

	note[i].SetNota(nota);
	note[i].SetData(data);
	note[i].SetNume(nume);
}

int Repo::FindElem(NotaExamen& nota)
{
	for (int i = 0; i < n; i++)
	{
		if (note[i] == nota)
			return i; // returnam indicele din array-ul de note
	}

	// -1 -> nu s-a gasit
	return -1;
}

NotaExamen* Repo::GetAll()
{
	return note;
}

int Repo::GetSize()
{
	return n;
}

NotaExamen& Repo::GetElem(int i)
{
	return note[i];
}

void Repo::Afisare()
{
	for (int i = 0; i < n; i++)
	{
		cout << note[i] << endl;
	}
}

void Repo::AfisareNoteMaiMariCa(int nota)
{
	for (int i = 0; i < n; i++)
	{
		if (note[i].GetNota() > nota)
			cout << note[i] << endl;
	}
}

void Repo::AdaugareBonusPentruStudent(const char* nume)
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(note[i].GetNume(), nume) == 0)
		{
			int notaNoua = note[i].GetNota() + 1;
			note[i].SetNota(notaNoua);
		}
	}
}

Repo& Repo::operator=(const Repo& other)
{
	n = other.n;
	for (int i = 0; i < n; i++)
	{
		note[i] = other.note[i];
	}

	return *this;
}
