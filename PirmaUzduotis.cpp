// PirmaUzduotis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <numeric>

//using std::cout;
//using std::string;
//using std::cin;
//using std::istream;

using namespace std;

struct studentas {
	string vardas;
	string pavarde;
	int* pazymiai;
	float egzaminas;
	float galutinis=0;
};

float galutinis_balas(int* array, int egzaminas) {
	int suma = 0;
	int dydis = sizeof(array);

	for (int i = 0; i < dydis; i++) {
		suma += array[i];
	}

	float vidurkis = suma / dydis;

	float galutinis = 0.4 * vidurkis + 0.6 * egzaminas;

	return galutinis;
}

void print_array(int* array) {
	for (int i = 0; i < sizeof(array); i++) {
		cout << array[i] << ";";
	}
	cout << endl;
}

int main()
{
	cout << "Iveskite studentu, kuriu duomenis pildysite, skaiciu: ";
	int n = 0;
	cin >> n;
	studentas* grupe = new studentas[n];

	cout << "Iveskite studento varda, pavarde, egzamino ivertinima \n";
	for (int i = 0; i < n; i++) {
		cout << i + 1 << "-ojo studento duomenys: ";
		cin >> grupe[i].vardas >> grupe[i].pavarde >> grupe[i].egzaminas;

		cout << "Iveskite namu darbu pazymius: " << endl;
		cout << "Spauskite Enter po kiekvieno ivesto pazymio. " << endl;
		cout << "Norint baigti pazymiu vedima, iveskite 'end' ir spauskite Enter" << endl;

		int* temp = new int[100];

		string dab = "";

		int j = 0;
		while (dab != "end") {
			cin >> dab;
			if (dab == "end") {
				break;
			}

			int value = std::stoi(dab);
			temp[j] = value;
			j++;
		};
		cout << "size of temp: " << sizeof(temp) << endl;
		print_array(temp);
		
		grupe[i].pazymiai = new  int[j];
		//neisspresta problema:
		//masyve atsiranda papildomas nezinomas skaicius (labai didelis ir daznai su minuso zenklu
		//kuris gadina galutinio balo skaiciavimus)
		for (int m = 0; m < j; m++) {
			grupe[i].pazymiai[m] = temp[m];
			cout << grupe[i].pazymiai[m];
		}

		print_array(grupe[i].pazymiai);

		delete[] temp;
	}

	cout << "Ivesti duomenys: \n";
	cout << "--------------------------\n";
	for (int i = 0; i < n; i++) {
		cout << "Studentas: " << grupe[i].vardas << " " << grupe[i].pavarde << " egzamino ivertinimas: " << grupe[i].egzaminas << endl;
		cout << "Pazymiai: " << endl;

		int size = sizeof(grupe[i].pazymiai);

		for (int k = 0; k < size; k++) {
			cout << grupe[i].pazymiai[k] << " ";
		}
		cout << endl;
		cout << "Galutinis balas: " << galutinis_balas(grupe[i].pazymiai, grupe[i].egzaminas);

		delete[] grupe[i].pazymiai;
	}

	delete[] grupe;
}



