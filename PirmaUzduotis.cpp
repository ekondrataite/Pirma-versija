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
	float galutinis;
};

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

		string dab;

		int j = 0;
		while (dab != "end") {
			cin >> dab;
			if (dab == "end") {
				break;
			}
			temp[j] = std::stoi(dab);
			j++;
		} ;

		grupe[i].pazymiai = new  int[j];

		for (int m = 0; m < j; m++) {
			grupe[i].pazymiai[m] = temp[m];
		}

		delete[] temp;
	}

	cout << "Ivesti duomenys: \n";
	cout << "--------------------------\n";
	for (int i = 0; i < n; i++) {
		cout << grupe[i].vardas << " " << grupe[i].pavarde << " " << grupe[i].egzaminas;

		int size = sizeof(grupe[i].pazymiai);
		cout << "array size " << size << endl;
		for (int k = 0; k < size - 1; k++) {
			cout << " " << grupe[i].pazymiai[k];
		}
		cout << endl;
		delete[] grupe[i].pazymiai;
	}

	delete[] grupe;
}
