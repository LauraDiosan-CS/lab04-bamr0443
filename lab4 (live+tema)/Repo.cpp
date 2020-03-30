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

void Repo::AddElem(NotaExamen nota)
{
	note[n] = nota;
	n = n + 1;
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
