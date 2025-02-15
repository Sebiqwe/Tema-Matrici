#pragma once
#include <iostream>
using namespace std;
//1)Stergeti linia si coloana pe care se afla al doilea nr prim din matrice.Daca matricea nu are cel putin 2 nr prime se va afisa "NU EXISTA"
bool estePrim(int n) {
	if (n == 0 || n == 1) {
		return false;
	}
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return false;
		}
	
	}
	return true;




}
bool pozNrPrim2(int arr[100][100], int m, int n,int &liniePrim, int &coloanaPrim ) {
	int contor = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
		
			if (estePrim(arr[i][j])) {
				contor++;
				if (contor == 2) {
					liniePrim = i;
					coloanaPrim = j;
					return true;
				
				}
			}
		
		
		}
	}
	return false;


}
void stergereLinie(int arr[100][100], int& m, int& n, int pozitie) {
	for (int i = pozitie; i < m - 1; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = arr[i + 1][j];
		
		
		}
	
	
	}

	m--;



}
void stergereColoana(int arr[100][100], int& m, int& n, int pozitie) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n - 1; j++) {
			arr[i][j] = arr[i][j + 1];
		}
	
	}
	n--;


}
void afisareMatrice(int arr[100][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		
		
			
		}
		cout << endl;
	}
	

}
void sol1() {
	int arr[100][100] = { {4,6,11},{5,9,15},{10,13,12} };
	int linii = 3;
	int coloane = 3;
	int liniePrim= 0;
	int coloanaPrim = 0;
	if (!pozNrPrim2(arr, linii, coloane,liniePrim,coloanaPrim)) {
		cout << "NU EXISTA!" << endl;

	}
	stergereLinie(arr, linii, coloane, liniePrim);
	stergereColoana(arr, linii, coloane, coloanaPrim);
	cout << "matricea dupa eliminare este " << endl;
	afisareMatrice(arr, linii, coloane);


}
//2)Stergeti linia care are cel mai rar cifra k in componenta elementelor (k citit de altastatura )
int contorAparitiiK(int n, int k) {
	int contor = 0;
	while (n > 0) {
		int cif = n % 10;
		if (cif == k) {
			contor++;
		}
		n = n / 10;
	}
	return contor;


}
int contorKInLinie(int arr[100][100], int m, int n, int k) {
	int contor = 0;
	for (int j = 0; j < n; j++) {
		contor = contor + contorAparitiiK(arr[m][j], k);
	
	}
	return contor;

}
int linimeCuKCelMaiRar(int arr[100][100], int m, int n, int k) {
	int linieKrar = 0;
	int contorAparitiiPutine = 0;
	for (int i = 0; i < m; i++) {
		int nrAparitii = contorKInLinie(arr, n, i, k);
		if (nrAparitii < contorAparitiiPutine) {
			contorAparitiiPutine = nrAparitii;
			linieKrar = i;
		}
	
	}
	return linieKrar;

}
void sol2() {
	int arr[100][100] = { {12,72,33},{22,14,16},{15,17,19} };
	int linii = 3;
	int coloane = 3;
	int k;
	cout << "k=";
	cin >> k;
	int linieDeSters = linimeCuKCelMaiRar(arr, linii, coloane, k);
	stergereLinie(arr, linii, coloane, linieDeSters);
	cout << "Matricea dupa stergere este " << endl;
	afisareMatrice(arr, linii, coloane);




}
//3)Sa se sterga linia si coloana elementului cu frecventa maxima 
int frecvMaxima(int arr[100][100], int m, int n, int elem) {
	int frecventa = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == elem) {
				frecventa++;
			}
		
		}
	
	}
	return frecventa;


}
void maximFrecventaMatrice(int arr[100][100], int m, int n, int& maximElem, int& linieFrecvMaxima, int& coloanaFrecvMaxima) {
	int frecvMAxima = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int nr = arr[i][j];
			int frecventa = frecvMaxima(arr, m, n, nr);
			if (frecventa > frecvMAxima) {
				frecvMAxima = frecventa;
				maximElem = nr;
				linieFrecvMaxima = i;
				coloanaFrecvMaxima = j;
			
			}
		}
		
	
	}


}
void sol3() {
	int arr[100][100] = { {1,2,7},{4,2,7},{3,9,7} };
	int linii = 3;
	int coloane = 3;
	int maximElem = 0;
	int lineFrecvMaxima = 0;
	int coloanaFrecvMAxima = 0;
	maximFrecventaMatrice(arr, linii, coloane, maximElem, lineFrecvMaxima, coloanaFrecvMAxima);
	stergereLinie(arr, linii, coloane, lineFrecvMaxima);
	stergereColoana(arr, linii, coloane, coloanaFrecvMAxima);
	cout << "matricea dupa stergere este "<<endl;
	afisareMatrice(arr, linii, coloane);



}
//4)Stergeti toate liniile ce nu au elemente ordonate cresc sau desc 
bool esteCresc(int arr[100][100], int m, int n) {
	for (int j = 0; j < n-1; j++) {
		if (arr[m][j] > arr[m][j + 1]) {
		
			return false;
		
		}
	
	}

	return true;

}
bool esteDesc(int arr[100][100], int m, int n) {
	for (int j = 0; j < n - 1; j++) {
		if (arr[m][j] < arr[m][j + 1]) {
			return false;
		
		}
	
	}
	return true;



}
void stergereLinii(int arr[100][100], int& m, int n) {
	for (int i = 0; i < m; i++) {
		if (!esteCresc(arr, i, n) && !esteDesc(arr, i, n)) {
			stergereLinie(arr, m, n, i);
		
		}
	
	
	}



}
void sol4() {
	int arr[100][100] = { {1,2,3},{7,3,9},{6,8,9} };
	int linii = 3;
	int coloane = 3;
	stergereLinii(arr, linii, coloane);
	cout << "matricea dupa stergere este " << endl;
	afisareMatrice(arr, linii, coloane);




}
//5)Inserati dupa a doua coloana cde contine cel putin un patrat perfect rasturnatul fiecarui element din acesta.In caz ca nu avem o astfel de coloana afisati mesajul nu 
bool estePP(int n) {
	int rad = sqrt(n);
	if (rad * rad == n) {
		return true;
	
	}
		return false;


}
int rasturnatNr(int n) {
	int invNr = 0;
	while (n > 0) {
		int cif = n % 10;
		invNr = invNr * 10 + cif;
		n = n / 10;
	}
	return invNr;

}
void inserareColoana(int arr[100][100], int& m, int& n, int pozitie, int coloanaNoua[100]) {
	for (int j = n - 1; j >= pozitie; j--) {
		for (int i = 0; i < m; i++) {
			arr[i][j + 1] = arr[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		arr[i][pozitie] = coloanaNoua[i];
	}
	n++;


}
int coloanaCuPP(int arr[100][100], int m, int n) {
	for (int j = 0; j< n; j++) {
		for (int i = 0; i < m; i++) {
			if (estePP(arr[i][j])) {
				return j;
			}
		
		
		}
	
	}



}
void sol5() {
	int arr[100][100] = { {4,12,25},{16,23,18},{9,45,36} };
	int linii = 3;
	int coloane = 3;
	int coloanaPP = coloanaCuPP(arr, linii, coloane);
	if (coloanaPP == -1) {
		cout << "NU" << endl;
	}
	else {
		int coloanaNoua[100];
		for (int i = 0; i < linii; i++) {
			coloanaNoua[i] = rasturnatNr(arr[i][coloanaPP]);
		}
		inserareColoana(arr, linii, coloane, coloanaPP+1, coloanaNoua);
	
	}
	cout << "matricea dupa inserare este " << endl;
	afisareMatrice(arr, linii, coloane);

}
//6)Sa se insereze dupa linia cu cele mai multe elemente pare dublul ei 
int contorElemPare(int arr[100][100], int m, int n) {
	int contor = 0;
	for (int i = 0; i< m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] % 2 == 0) {
				contor++;
			}
		
		}
	
	}
	return contor;
}
int celeMaiMulteElemPare(int arr[100][100], int m, int n) {
	int maximPare = 0;
	int linieCuMaximPare = -1;
	for (int i = 0; i < m; i++) {
		int contorPare = contorElemPare(arr, m, n);
		if (contorPare > maximPare) {
			maximPare = contorPare;
			linieCuMaximPare = i;
		}
	}

	return linieCuMaximPare;


}
void inserareLinie(int arr[100][100], int& m, int& n, int pozitie, int linieNou[100]) {

	for (int i = m - 1; i > pozitie; i--) {
		for (int j = 0; j < n; j++) {

			arr[i+1][j] = arr[i][j];

		}


	}



	for (int j = 0; j < n; j++) {
		arr[pozitie+1][j] = linieNou[j];

	}

	m++;

}
void sol6() {
	int arr[100][100] = { {1,2,3},{4,5,6},{7,8,9} };
	int linii = 3;
	int coloane = 3;
	int maximPareLinie = celeMaiMulteElemPare(arr, linii, coloane);
	int linieNoua[100]{};
	for (int j = 0; j < coloane; j++) {
	
		linieNoua[j] = 2 * arr[maximPareLinie][j];
	
	}
	inserareLinie(arr, linii, coloane, maximPareLinie+1, linieNoua);
	cout << "matricea dupa inserare este " << endl;
	afisareMatrice(arr, linii, coloane);

}
//7)Inserati dupa fiecare coloana ce este formata din elementele in care fiecare cif de la (0-9) apare cel putin o data, cifra de contorl al fiecarui elem-->NU STIU 
int sumaCif(int n) {
	int suma = 0;
	while (n > 0) {
		int cif = n % 10;
		suma = suma + cif;
		n = n / 10;
	}
	return suma;


}
int cifDeControl(int n) {
	while (n >= 10) {
		n = sumaCif(n);
	
	}
	return n;



}
//8)Inserati dupa linia pe care se gaseste primul element palindrom ce are intre 3 si 5 div proprii, dublul ei 
bool estePalindrom(int n) {
	int invNr = 0;
	int aux = n;
	while (aux > 0) {
		int cif = aux % 10;
		invNr = invNr * 10 + cif;
		aux = aux / 10;
	
	}
	if (n == invNr) {
		return true;
	}
	return false;

}
int contorDivProprii(int n) {
	int contor = 0;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			contor++;
		}
	
	}
	return contor;


}
int linieCuElemPalindrom(int arr[100][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (estePalindrom(arr[i][j]) && contorDivProprii(arr[i][j]) >= 3 && contorDivProprii(arr[i][j]) <= 5) {
				return i;
			
			}
		
		
		}
	
	
	}

	

}
void sol8() {
	int arr[100][100] = { {121,12,13},{5,9,7},{1,2,3} };
	int linii = 3;
	int coloane = 3;
	int liniePalindrom = linieCuElemPalindrom(arr, linii, coloane);
	int linieNoua[100];

	for (int j = 0; j < coloane; j++) {
		linieNoua[j] = 2* arr[liniePalindrom][j];

	}
	inserareLinie(arr, linii, coloane, liniePalindrom, linieNoua);
	cout << "matricea dupa inserare este " << endl;
	afisareMatrice(arr, linii, coloane);

}
//9)Inserati dupa prima coloana ce are toate elementele prime intre ele cu pozitia liniei pe care stau, cifra de control a elementelor-->Nu stiu 
//10)Interschimbati prima linie ce are elementele in ordine crescatoare cu urmatoarea linie.In cazul in care nu exista sortati crescator prima lisine si interschimbati-o cu ultima
bool esteSoratCrescator(int arr[100], int n) {
	for (int i = 0; i < n-1; i++) {
		if (arr[i] > arr[i + 1]) {
			return false;
		}
	
	
	}
	return true;


}
void interschimbareLinii(int arr[100][100], int n, int m, int linie1, int linie2) {
	for (int i = 0; i < m; i++) {
		int aux = arr[linie1][i];
		arr[linie1][i] = arr[linie2][i];
		arr[linie2][i] = aux;



	}


}
void bubbleSortCresc(int arr[100], int n) {
	bool sortat = false;
	do {
		sortat = true;
		for (int i = 0; i < n - 1; i++) {
			while (arr[i] > arr[i + 1]) {
				int aux = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = aux;
				sortat = false;
			
			
			}
		
		
		
		}
	} while (sortat == false);



}
void sol10() {
	int arr[100][100] = { {1,2,3},{7,5,6},{2,1,9} };
	int linii = 3;
	int coloane = 3;
	int liniaSortat = -1;
	for (int i = 0; i < linii; i++) {
		if (esteSoratCrescator(arr[i], coloane)) {
			liniaSortat = i;
		}

	}
	if (liniaSortat < linii - 1) {
		interschimbareLinii(arr,linii,coloane, liniaSortat, liniaSortat + 1);
	
	}
	
	cout << "matricea dupa interschimbare este " << endl;
	afisareMatrice(arr, linii, coloane);




}
//11)Interschimbati linia pe care se afla minimul si linia pe care se afla maximul.Daca elementul minim si maxim se afla pe aceeasi linie afisati mesajul"NU SE POATE INTERSCHIMBA"
void minimLinie(int arr[100][100], int m, int n, int& valMinima, int& linieMin) {
	valMinima = 9;
	linieMin = -1;        

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] < valMinima) {
				valMinima = arr[i][j];
				linieMin = i;        
			}
		}
	}
}
void maximLinie(int arr[100][100], int m, int n, int& valMaxima, int& linieMax) {
	valMaxima = 0;
	linieMax = -1;         

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] > valMaxima) {
				valMaxima = arr[i][j]; 
				linieMax = i;         
			}
		}
	}
}
void sol11() {
	int arr[100][100] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	int linii = 3;
	int coloane = 3;

	int valMinima, linieMin;
	minimLinie(arr, linii, coloane, valMinima, linieMin);

	int valMaxima, linieMax;
	maximLinie(arr, linii, coloane, valMaxima, linieMax);

	if (linieMin == linieMax) {
		cout << "NU SE POATE INTERSCHIMBA" << endl;
	}
	else {
		interschimbareLinii(arr, linii,coloane, linieMin, linieMax);
		cout << "Matricea dupa interschimbare este: " << endl;
	}

	afisareMatrice(arr, linii, coloane);
}
//12)Interschimbati intre ele liniile a.i. prima coloana sa aiba elementele in ordine crescatoare
void bubbleSortCrescColoana(int arr[100][100], int m, int n) {
	bool sortat = false;
	do {
		sortat = true;
		for (int i = 0; i < m - 1; i++) {
			if (arr[i][0] > arr[i + 1][0]) {
				int aux = arr[i][0];
				arr[i][0] = arr[i + 1][0];
				arr[i + 1][0] = aux;
				sortat = false;
			}
		
		}
	
	
	
	} while (sortat == false);





}
void sol12() {
	int arr[100][100] = { {4,5,6},{1,2,3},{7,8,9} };
	int linii = 3;
	int coloane = 3;
	bubbleSortCrescColoana(arr, linii, coloane);
	cout << "matricea dupa sortare este " << endl;
	afisareMatrice(arr, linii, coloane);




}
//d)Stergeti linia si coloana tututror elementelor cu proprietatea ce au exact 3 cifre egale intre ele
bool nAre3CifEgaleIntreEle(int n) {
	int cif1 = n / 100;
	int cif2 = (n / 10) % 10;
	int cif3 = n % 10;
	if (cif1 == cif2 && cif2 == cif3) {
		return true;
	}
	return false;


}
void stergerenrCu3CifEgale(int arr[100][100], int& m, int& n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (nAre3CifEgaleIntreEle(arr[i][j])) {
				stergereLinie(arr, m, n,i);
				stergereColoana(arr, m,n, j);

			}


		}
	}




}
void sol() {
	int arr[100][100] = { {111,222,333},{78,65,33},{121.65,555} };
	int linii = 3;
	int coloane = 3;
	stergerenrCu3CifEgale(arr, linii, coloane);
	cout << "afisare matrice dupa stergere " << endl;
	afisareMatrice(arr, linii, coloane);

}
