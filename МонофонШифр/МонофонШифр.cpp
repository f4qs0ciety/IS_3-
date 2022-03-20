#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

void encrypt(string main[], string cyphr[]);
void decrypt(string main[], string cyphr[]);

void main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream fin;
	fin.open("Alphabet.txt");
	int option;
	bool stop = false;
	string main_alph[2], cyphr_alph[12];
	for (int i = 0; i < 2; i++) { getline(fin, main_alph[i]); }
	cout << "Исходный алфавит:" << endl;
	for (int i = 0; i < 2; i++) { cout << main_alph[i] << endl; }
	for (int i = 0; i < 12; i++) { getline(fin, cyphr_alph[i]); }
	cout << endl << "Алфавит шифрования:" << endl;
	for (int i = 0; i < 12; i++) { cout << cyphr_alph[i] << endl; }
	do {
		cout << endl << "Выберите режим работы: " << endl << "[1] Шифровка текста" << endl << "[2] Дешифровка текста" << endl << "[3] Выход" << endl << "Выбор: ";
		cin >> option;
		switch (option) {
		case 1: {encrypt(main_alph, cyphr_alph); break; }
		case 2: {decrypt(main_alph, cyphr_alph); break; }
		case 3: stop = true;
		}
	} while (stop != true);
}

void encrypt(string main[], string cyphr[]) {
	string input, output;
	int counter;
	cout << "Введите текст: ";
	cin.ignore();
	getline(cin, input);
	output = input;
	for (int i = 0; i < 33; i++) {
		counter = 0;
		for (int j = 0; j < size(input); j++) {
			if (input[j] == main[0][i] || input[j] == main[1][i]) {
				if (counter == 12) { counter = 0; }
				output[j] = cyphr[counter][i];
				counter++;
			}
		}
	}
	cout << "Зашифрованный текст: " << output << endl;
}

void decrypt(string main[], string cyphr[]) {
	string input, output;
	int counter;
	cout << "Введите текст: ";
	cin.ignore();
	getline(cin, input);
	output = input;
	for (int i = 0; i < 33; i++) {
		counter = 0;
		for (int j = 0; j < size(input); j++) {
			if (input[j] == cyphr[counter][i]) {
				output[j] = main[0][i];
				counter++;
				if (counter == 12) { counter = 0; }
			}
		}
	}
	cout << "Расшифрованный текст: " << output << endl;
}