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
    float pazymiai[10];
    float vidurkis;
    float egzaminas;
    float galutinis;
};

int main()
{
    studentas eilute;
    cout << "Iveskite studentu, kuriu duomenis pildysite, skaiciu: ";
    int n = 0;
    cin >> n;
    studentas* grupe = new studentas[n];

    cout << "Iveskite studento varda, pavarde, egzamino ivertinima ir semestro namu darbu pazymius: \n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "-ojo studento duomenys: "; 
        cin >> grupe[i].vardas >> grupe[i].pavarde >> grupe[i].egzaminas;
    }
    for (int i = 0; i < n; i++) {
        cout << grupe[i].vardas << " : ";
    }
    cout << std::endl;
    
    studentas* temp = new studentas[n+1];

    for (int i = 0; i < n; i++) temp[i] = grupe[i];

    for (int i = 0; i < n; i++) {
        cout << temp[i].vardas << " : ";
    }
    cout << std::endl;

    //cout << "Iveskite studento varda, pavarde, egzamino ivertinima ir semestro namu darbu pazymius: ";
    //cin >> eilute.vardas >> eilute.pavarde >> eilute.egzaminas;

}
