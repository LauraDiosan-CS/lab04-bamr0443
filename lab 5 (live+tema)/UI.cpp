#include "UI.h"
#include "Service.h"

void AdaugaExamen(Service& s)
{
	NotaExamen ne;
	cout << "Introduceti datele pentru noul examen: " << endl;
	cin >> ne;
	s.AddNotaExamen(ne);
}

void StergeExamen(Service& s)
{
	NotaExamen ne;
	cout << "Introduceti datele pentru examenul de sters: " << endl;
	cin >> ne;
	s.DeleteNotaExamen(ne);
}

void UpdateExamen(Service& s)
{
	NotaExamen ne;
	NotaExamen neNou;

	cout << "Introduceti datele pentru examenul de updatat: " << endl;
	cin >> ne;
	cout << endl << "Introduceti noile date pentru examen: " << endl;
	cin >> neNou;

	s.UpdateNotaEamen(ne, neNou.GetNota(), neNou.GetData(), neNou.GetNume());
}

void CautaExamen(Service& s)
{
	NotaExamen ne;

	cout << "Introduceti datele pentru examenul de cautat: " << endl;
	cin >> ne;

	int i = s.FindNotaExamen(ne);
	if (i == -1)
		cout << "Examenul nu s-a gasit!" << endl;
	else
		cout << "Examenul s-a gasit pe pozitia " << i << endl;
}

void BonusExamen(Service& s)
{
	char nume[50];

	cout << "Introduceti numele studentului caruia doriti sa-i acordati bonus: " << endl;
	cin >> nume;
	s.AdaugareBonusExamenPentruStudent(nume);
}

void AfisareExameneCuNotaMaiMareCaCeaData(Service& s)
{
	int nota = 0;
	cout << "Introduceti nota prag: " << endl;
	cin >> nota;
	s.AfisareExameneCuNotaPesteNotaData(nota);
}

void AfisareToateExamenele(Service& s)
{
	s.AfisareToateExamenele();
}

void UI()
{
	int optiune = 0;
	Service s;

	do
	{
		cout << endl << endl;
		cout << "0. Iesire" << endl;
		cout << "1. Adauga Examen" << endl;
		cout << "2. Sterge Examen" << endl;
		cout << "3. Updateaza Examen" << endl;
		cout << "4. Cauta Examen" << endl;
		cout << "5. Bonus nota pentru un student" << endl;
		cout << "6. Afisare examene cu nota mai mare decat cea data" << endl;
		cout << "7. Afisare toate examenele" << endl;

		cout << "Introduceti o optiune: ";
		cin >> optiune;
		
		switch (optiune)
		{
			case 0:
				break;
			case 1:
				AdaugaExamen(s);
				break;
			case 2:
				StergeExamen(s);
				break;
			case 3:
				UpdateExamen(s);
				break;
			case 4:
				CautaExamen(s);
				break;
			case 5:
				BonusExamen(s);
				break;
			case 6:
				AfisareExameneCuNotaMaiMareCaCeaData(s);
				break;
			case 7:
				AfisareToateExamenele(s);
				break;
			default:
				cout << "Ati introdus o optiune invalida!" << endl;
				break;
		}

	} while (optiune != 0);
}