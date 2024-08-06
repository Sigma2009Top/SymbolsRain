#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>

void fill_array(char **arr, int rows, int colns) {
	for (int i = 0; i < rows; i++) {
		arr[i] = new char[colns];

		for (int j = 0; j < colns; j++) {
			int rnd = rand() % 255;
			if (rnd == 7) { rnd++; }
			arr[i][j] = rnd;
		}
	}
}
void print_array(char **arr, int rows, int colns){
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colns; j++) {
			int rnd = rand() % 256;
			if (rnd == 0) { rnd++; }
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), rnd);
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
void delete_array(char **arr, int rows){
	for (int i = 0; i < rows; i++) {
		delete[] arr[i];
		arr[i] = nullptr;
	}
}

int main()
{
	for (;;) {
		int rows = 1;
		int colns = 40;
		char **arr = new char*[rows];

		fill_array(arr, rows, colns);
		print_array(arr, rows, colns);
		delete_array(arr, rows);

		delete[] arr;
		arr = nullptr;

		Sleep(15);
	}
}