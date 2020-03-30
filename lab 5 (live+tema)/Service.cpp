#include "Service.h"

Service::Service()
{
}

Service::Service(Repo& Repo)
{
	repo = Repo;
}

void Service::AddNotaExamen(NotaExamen& ne)
{
	repo.AddElem(ne);
}

void Service::DeleteNotaExamen(NotaExamen& ne)
{
	repo.DeleteElem(ne);
}

void Service::UpdateNotaEamen(NotaExamen& ne, int nota, int data, const char* nume)
{
	repo.UpdateElem(ne, nume, nota, data);
}

int Service::FindNotaExamen(NotaExamen& ne)
{
	return repo.FindElem(ne);
}

void Service::AdaugareBonusExamenPentruStudent(const char* nume)
{
	repo.AdaugareBonusPentruStudent(nume);
}

void Service::AfisareExameneCuNotaPesteNotaData(int nota)
{
	repo.AfisareNoteMaiMariCa(nota);
}

void Service::AfisareToateExamenele()
{
	repo.Afisare();
}

int Service::GetSize()
{
	return repo.GetSize();
}

NotaExamen* Service::GetNoteExamene()
{
	return repo.GetAll();
}

Repo& Service::GetRepo()
{
	return repo;
}


void Service::SetRepo(Repo& Repo)
{
	repo = Repo;
}
