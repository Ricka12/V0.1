#include "Mylib.h"
struct studentas {
	string vardas = "", pavarde = "";
	int* paz = NULL;
	int egz = 0;
};
void pildymas(studentas& temp);
void print(studentas& temp);
double vid(studentas& temp);
double mid(studentas& temp);

int stud_sk;
int paz_sk;
int atsitiktinai = 0;

int main() {
	srand(time(NULL));
	studentas* grupe=NULL;
	int pildau = 0;
	int Noriu_iseiti = 0;
	do {
		cout << "Kiek studentu norite uzpildyti?(0 jei nezinote):  ";
		cin >> stud_sk;
		if (stud_sk < 0)
		{
			cout << "Iveskite teigiama skaiciu " << endl;
		}
	} while (stud_sk < 0);
	do {
		cout << "Kiek pazymiu turi studentai?():  ";
		cin >> paz_sk;
		if (paz_sk <= 0)
		{
			cout << "Iveskite skaiciu didesni uz 0" << endl;
		}
	} while (paz_sk <= 0);
	cout << "Ar norite kad pazymiai butu generuojami atsitiktinai(1 jei taip, 0 jei ne):  ";
	cin >> atsitiktinai;
	if (stud_sk > 0)
	{
		grupe = new studentas[stud_sk];
		for (int i = 0; i < stud_sk; i++)
		{
			pildymas(grupe[i]);
		}
	}
	else {// Neveikia bet veiktu jei copy normaliai copijuotu pazymius man atrodo
		stud_sk = 1;
		studentas* temp = NULL;
		do {
			grupe = new studentas[stud_sk];
			pildymas(grupe[pildau]);
			cout << "Ar norite pratesti pildyma? jei taip spasukit bet ka isskirus 0 kitu atveju spauskit 0: " << endl;
			cin >> Noriu_iseiti;
			if(Noriu_iseiti==0)
			{
			temp = new studentas[stud_sk];
			copy(grupe, grupe + stud_sk, temp);
			delete[] grupe;
			stud_sk = stud_sk + 1;
			grupe = new studentas[stud_sk];
			copy(temp, temp + stud_sk-1, grupe);
			pildau++;
			}
		} while (Noriu_iseiti == 0);
	}
	cout << "sk" << stud_sk << " pildau" << pildau << endl;
	cout << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis(Vid.)" << " /" << " Galutinis(Med)" << endl;

	for (int i = 0; i < stud_sk; i++)
	{
		print(grupe[i]);
	}
	delete[] grupe;
}

void pildymas(studentas& temp)
{
	cout << "Iveskite varda ir pavarde: ";
	cin >> temp.vardas >> temp.pavarde;
	if (atsitiktinai == 1)
	{
		int randomsk;
		temp.paz = new int[paz_sk];
		for (int i = 0; i < paz_sk; i++)
		{
			randomsk = (rand() % 10) + 1;
			temp.paz[i] = randomsk;
		}
		randomsk = (rand() % 10) + 1;
		temp.egz = randomsk;
	}
	else
	{
		cout << "Iveskite " << paz_sk << " pazymius: ";
		temp.paz = new int[paz_sk];
		for (int i = 0; i < paz_sk; i++)
		{
			cin >> temp.paz[i];
		}
		cout << "Iveskite egzamino pazymi: ";
		cin >> temp.egz;
	}


}

void print(studentas& temp)
{

	cout << temp.vardas << setw(15) << temp.pavarde << setw(20);
	cout << setw(20) << vid(temp) << setw(20) << mid(temp)<<endl;
	delete[] temp.paz;
}
double vid(studentas& temp)
{
	double rezultatas = 0;
	for (int i = 0; i < paz_sk; i++)
	{
		rezultatas += temp.paz[i];
	}
	rezultatas = rezultatas / paz_sk;
	rezultatas = 0.4 * rezultatas + 0.6 * temp.egz;
	return rezultatas;
}
double mid(studentas& temp)
{
	double rezultatas = 0;
	for (int i = 0; i < paz_sk; i++)
	{
		for (int j = i+1; j < paz_sk; j++)
		{
			if (temp.paz[i] > temp.paz[j])
			{
				swap(temp.paz[i], temp.paz[j]);
			}
		}
	}
	/*for (int i = 0; i < paz_sk; i++)
	{
		cout << "paz" << temp.paz[i] << endl;
	}//Patikra*/

	if (paz_sk % 2 == 1)
	{
		//cout <<"as "<< temp.paz[paz_sk / 2 ] << " " << paz_sk / 2  << endl;//Patikra

		rezultatas = 0.4 * temp.paz[paz_sk /2] + 0.6 * temp.egz;
	}

	else {
		//cout << "as " << temp.paz[paz_sk / 2] << " " << temp.paz[paz_sk / 2 - 1] << " " << 1.0 * ((temp.paz[paz_sk / 2] + temp.paz[paz_sk / 2 - 1]) / 2.0) << endl;//Patikra

		rezultatas = 0.4 * ((temp.paz[paz_sk / 2 ] + temp.paz[paz_sk / 2-1]) / 2.0) + 0.6 * temp.egz;
	}

	return rezultatas;
}