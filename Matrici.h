#pragma once
#include <iostream>
using namespace std;
//
void afisare(int arr[100][2], int m, int n) {
	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n; j++) {

			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

}


void teorie1() {

	int arr[5][2] = { 12,32,43,21,31,31,33,13,42 ,23 };
	//a00 a01 a02
	//a10 a11 12





	afisare(arr, 5, 2);






}

