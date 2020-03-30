#pragma once

#include <iostream>

using namespace std;

class NotaExamen
{
private:
	// Doar ziua
	int data;
	char* nume;
	int nota;

public:
	// Constructori
	NotaExamen();
	NotaExamen(int Data, int Nota, const char* Nume);
	NotaExamen(const NotaExamen& other); // Copy Constructor

	// Setter & Getter pt data
	int GetData();
	void SetData(int Data);

	// Setter & Getter pt nume
	char* GetNume();
	void SetNume(const char* Nume);
	
	// Setter & Getter pt nota
	int GetNota();
	void SetNota(int Nota);

	// Operator = (atribuire)
	NotaExamen& operator=(const NotaExamen& other);

	// Operator << (pt afisare cu cout)
	friend ostream& operator<<(ostream& os, NotaExamen& ne);

	// Operator >> (pt citire cu cin)
	friend istream& operator>>(istream& os, NotaExamen& ne);

	// Operator == (verificare egalitate)
	bool operator==(const NotaExamen& other);

	// Destructor
	~NotaExamen();
};