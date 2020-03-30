#pragma once

#include "Repo.h"

class Service
{
private:
	Repo repo;
public:
	Service();
	Service(Repo& repo);

	void AddNotaExamen(NotaExamen& ne);
	void DeleteNotaExamen(NotaExamen& ne);
	void UpdateNotaEamen(NotaExamen& ne, int nota, int data, const char* nume);
	int FindNotaExamen(NotaExamen& ne);
	void AdaugareBonusExamenPentruStudent(const char* nume);
	void AfisareExameneCuNotaPesteNotaData(int nota);

	int GetSize();
	NotaExamen* GetNoteExamene();
	Repo& GetRepo();
	void AfisareToateExamenele();

	void SetRepo(Repo& Repo);
};

