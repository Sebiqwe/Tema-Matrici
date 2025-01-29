#pragma once
#include <iostream>
using namespace std;
//Fisa:
//1)a)Sa se calculeze suma elementelor de pe diagonala secundara 
int suma(int arr[100][100], int n) {
	int suma = 0;
	for (int i = 0; i < n; i++) {
		suma = suma + arr[i][n - i - 1];


	}
	return suma;
}
void sol1() {
	int arr[100][100] = { {1,2,3},{4,5,6},{7,8,9} };
	int linii = 3;
	int coloane = 3;
	int s = suma(arr, coloane);
	cout << "suma elementelor de pe diagonala secundara este " << s << endl;




}
//b)Realizati suma elementelor deasupra diagonalei principale 
int sumaElmentelorDeasupraDiagPrincipale(int arr[100][100], int m, int n) {
	int suma = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if ( j > i) {
				suma = suma + arr[i][j];
			}
		
		
		}
	}



	return suma;



}
void sol2() {
	int arr[100][100] = { {1,2,3},{4,5,6},{7,8,9} };
	int linii = 3;
	int coloane = 3;
	int suma = sumaElmentelorDeasupraDiagPrincipale(arr ,linii, coloane);
	cout << "suma elementelor deasupra diag principale este " << suma << endl;



}
//c)Aisati crescator dupa ce au fost sortate elemntele de pe diagonala principala
void interschimbareElemente(int arr[100][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j][j] > arr[j + 1][j + 1]) {
				int aux = arr[j][j];
				arr[j][j] = arr[j + 1][j + 1];
				arr[j + 1][j + 1] = aux;
			
			}
		
		
		}
	
	}


}
void afisareMatrice(int matrice[100][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrice[i][j] << " ";

		}
		cout << endl;
	}
	
}
void sol3() {
	int arr[100][100] = { {4,5,6},{1,2,3},{1,0,1} };
	int linii = 3;
	int coloane = 3;
	interschimbareElemente(arr, linii, coloane);
	afisareMatrice(arr, linii, coloane);

}
//d)Cate elemente superprime situate deasupra diag sec avem?
bool estePrim(int n) {
	if (n == 1 || n == 0) {
		return false;
	}
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return false;
		}
	
	}
	return true;

}
bool esteSuperPrim(int n) {
	while (n > 0) {
		if (!estePrim(n)) {
			return false;
		
		
		}
	
		n = n / 10;
	
	}
	return true;


}
int contorElemSuperprime(int arr[100][100], int m, int n) {
	int contor = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i + j > n - 1 && esteSuperPrim(arr[i][j])) {
			
				contor++;
			}
		
		
		
		
		
		}
	}
	return contor;


}
void sol4() {
	int arr[100][100] = { {233,1,5},{15,7,8}, {1,2,3} };
	int linii = 3;
	int coloane = 3;
	int contor = contorElemSuperprime(arr, linii, coloane);

	cout << "nr de elem superprime deasupra diag secundare este " << contor << endl;



}
//e)Care este suma elementelor situate diasupra diagonalei secundare
int  sumaELem(int arr[100][100], int m, int n) {
	int suma = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i + j < n - 1) {
				suma = suma + arr[i][j];
			
			}
		
		
		
		}
	}


	return suma;

}
void sol5() {
	int arr[100][100] = { {1,2,3},{4,5,6},{7,8,9} };
	int linii = 3;
	int coloane = 3;
	int suma = sumaELem(arr, linii, coloane);
	cout << "suma elem de deasupra diag secundare este " << suma << endl;





}
//f)Afisati media aritmetica din regiunea de nord  a matricei 
int  MedieregiuneDeNord(int arr[100][100], int m, int n ){
	int suma = 0;
	int contor = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i < j && i + j < n - 1) {
			
				suma = suma + arr[i][j];
				contor++;
			
			}
		
		
		
		
		}
	}
	return suma / contor;


}
void sol6() {
	int arr[100][100] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	int linii = 4;
	int coloane = 4;
	int media = MedieregiuneDeNord(arr, linii, coloane);
	cout << "media aritmetica a regiunii de nord este " << media << endl;

}
//g)Cate elemente negative sunt in regiunea de sud a matricei 
int contorElmentNegativeSud(int arr[100][100], int m, int n) {
	int contor = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i > j && i + j > n - 1 && arr[i][j] < 0) {
				contor++;
			}
		
		
		}
	}

	return contor;



}
void sol7() {
	int arr[100][100] = { {1,2,3,},{4,5,6},{7,-8,9} };
	int linii = 3;
	int coloane = 3;
	int contor = contorElmentNegativeSud(arr, linii, coloane);
	cout << "nr de elem negative in regiunea de sud este " << contor << endl;




}
//h)Cate elemente pare sunt in regiunea de est a matriciei
int contorElementePareEst(int arr[100][100], int m, int n) {
	int contor = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (j>i && i+j>=n) {
				if (arr[i][j] % 2 == 0) {
					contor++;
				}
			
			}
		
		
		}
	}

	return contor;

}
void sol8() {
	int arr[100][100] = { {1,2,3,4},{5,6,7,8,},{9,10,11,12},{13,14,15,16} };
	int linii = 4;
	int coloane = 4;
	int contor = contorElementePareEst(arr, linii, coloane);
	cout << "nr de elemente pare din regiunea de est este " << contor << endl;


}
//i)Care este cel mai mare element din vestul matricei?
int maximELemVest(int arr[100][100], int m, int n) {
	int maxim = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i > j) {
				if (arr[i][j] > maxim) {
					maxim = arr[i][j];
				}

			}



		}
	}
	return maxim;

}
void sol9() {
	int arr[100][100] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	int linii = 4;
	int coloane = 4;
	int maximVest = maximELemVest(arr, linii, coloane);
	cout << "maxim din vest este " << maximVest << endl;





}
//2)Care este cmmdc tuturor elementelor de pe diagonala principala
int CMMDC(int a, int b) {
	while (b != 0) {
		int rest = a % b;
		a = b;
		b = rest;
	
	
	}

	return  a;

}
int diagonalaPrincipala(int arr[100][100], int m, int n ) {
	int cmmdc = arr[0][0];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i = j) {
			cmmdc=	CMMDC(cmmdc, arr[i][i]);
			}
		
		
		}
	}
	return cmmdc;





}
void sol10() {
	int arr[100][100] = { {12,7,3},{9,18,1},{3,7,24} };
	int linii = 3;
	int coloane = 3;
	int cmmdc = diagonalaPrincipala(arr, linii, coloane);
	cout << "CMMDC de pe diagonala principala este " << cmmdc << endl;




}
//b)Sa se verifice daca matricea este simetrica fata de diagonala i
bool matriceaEsteSimetrica(int arr[100][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != arr[j][i]) {
				return false;
			}
		
		
		}
	}

	return true;



}
void sol11() {
	int arr[100][100] = { {1,2,3},{2,4,5},{3,5,6} };
	int linii = 3;
	int coloane = 3;
	if (matriceaEsteSimetrica(arr, linii, coloane)) {
		cout << "matricea este simetrica fata de diagonala i" << endl;
	
	}
	else {
		cout << "matricea nu este simetrica fata de diag i" << endl;
	}


}
//c)Afisati triunghiul isoscel cu maximul de numere ce au prima cifra egala cu ultima cifra --->NU STIU
bool primaCifEgalaCuUltima(int n) {
	int uc = n % 10;
	while (n >= 10) {
		n = n / 10;
	
	}
	int primaCif = n;
	if (primaCif == uc) {
		return true;
	
	}
	else {
		return false;
	}


}
//d)Sa se inlocuisca toate aparitiile lui k din triunghiul dreptunghic inferior diagonalei principale cu cif de control(k citit de la tast )-->NU Stiu
int cifDeControl(int n) {
	int suma = 0;
	while (n >0) {
		int cif = n % 10;
		suma = suma + cif;
	
		n = n / 10;
	}
	return suma;

}
void inlocuireKTriunghi(int arr[100][100], int m, int n,int k) {
	int cifControl = cifDeControl(k);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (j>i) {
				if (arr[i][j] == k) {
					arr[i][j] == cifControl;
				}
			
			}
		
		
		}
	
	}


}
void sol13() {
	int arr[100][100] = { {1,2,3},{4,5,6},{7,8,9} };
	int linii = 3;
	int coloane = 3;
	int k = 0;
	cout << "k=" << endl;
	cin >> k;
	inlocuireKTriunghi(arr, linii, coloane, k);
	cout << "matricea dupa inlocuire este" << endl;
	afisareMatrice(arr, linii, coloane);


}
//e)Care este numarul cu cele mai multe cifre distincte de pe diagonola secundara 
int contorCifDistincte(int n) {
	int contor = 0;
	while (n > 0) {
		int cif1 = n % 10;
		n = n / 10;
		int aux = n;
		while (aux > 0) {
		int cif2 = aux % 10;
		if (cif1 != cif2) {
			contor++;
		}
		aux = aux / 10;
		}
	
	}
	
	return contor;

}
int contorDiagSec(int arr[100][100], int m){
	int maximCifDistincte = 0;
	int nrMaxim = 0;
	for (int i = 0; i < m; i++) {
		int n = arr[i][m - i - 1];
		int cifDistincte = contorCifDistincte(n);
		if (cifDistincte > maximCifDistincte) {
		
			maximCifDistincte = cifDistincte;
			nrMaxim = n;
		}
	
	}

	return nrMaxim;



}
void sol14() {
	int arr[100][100] = { {11,22,33},{44,55,66},{73,12,45} };
	int linii = 3;
	int coloane = 3;
	int nr = contorDiagSec(arr, linii);
	cout << "nr cu cele mai multe cif de pe diagonala secundara este " << nr << endl;



}
//f)Sa se verifice daca pe fiecare linie si pe fiecare coloana sunt toate elementele{1.....9} o singura data (tip Sudoku)
bool esteDeTipSudoku(int arr[100][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int nr = arr[i][j];
			if (nr < 1 || nr>9) {
				return false;
			}
		
		
		
		}
	
	}

	return true;

}
void sol15() {
	int arr[100][100] = { {5, 3, 4, 6, 7, 8, 9, 11, 2},{6, 7, 2, 1, 9, 5, 3, 4, 8},{1, 9, 8, 3, 4, 2, 5, 6, 7},{8, 5, 9, 7, 6, 1, 4, 2, 3},{4, 2, 6, 8, 5, 3, 7, 9, 1},{7, 1, 3, 9, 2, 4, 8, 5, 6},{9, 6, 1, 5, 3, 7, 2, 8, 4},{2, 8, 7, 4, 1, 9, 6, 3, 5},{3, 4, 5, 2, 8, 6, 1, 7, 9}, };
	int linii = 9;
	int coloane = 9;
	if (esteDeTipSudoku(arr, linii, coloane)) {
	cout<<"este de tip Sudoku"<<endl;

	}
	else {
	cout<<"nu este de tip sudoku"<<endl;
	}

}
//g)Sa se realizeze un vector cu toate elementele ce au cifra de control un nr Par
void vectorCifDeCOntrolPAra(int arr[100][100], int m, int n, int v[100], int &d) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (cifDeControl(arr[i][j]) % 2 == 0) {
				v[d] = arr[i][j];
				d++;
			}
		
		
		}
	}





}
void afisareVector(int v[100], int d) {
	for (int i = 0; i < d; i++) {
		cout << v[i] << " ";
	}


}
void sol16() {
	int arr[100][100] = { {1,2,3},{4,5,6},{7,8,9} };
	int linii = 3;
	int coloane = 3;
	int v[100] = {};
	int d = 0;
	vectorCifDeCOntrolPAra(arr, linii, coloane, v, d);
	cout << "vectorul rezultat este ";
	afisareVector(v, d);


}
//h)Sortati vectorul de la g crescator pana la mijl si desc dupa (2 sortari cu metode diferite )
void bubbleSortCresc(int v[], int d) {
	bool sortat = false;
	do {
		sortat = true;
		for (int i = 0; i < (d - 1)/2; i++) {
			if (v[i] > v[i + 1]) {
				int aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
				sortat = false;
			
			}
		
		
		}
	
	
	
	
	} while (sortat == false);





}
void sortareSelectie(int v[], int d) {


	for (int i = 0; i < d/2; i++) {


		for (int j = i + 1; j < d/2; j++) {

			if (v[i] < v[j]) {


				int aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}

	}
}
void sol17() {
	int v[100] = { 2,4,6,8 };
	int d = 4;
	bubbleSortCresc(v, d);
	sortareSelectie(v, d);
	cout << "vectorul dupa sortare este ";
	afisareVector(v, d);



}
//j)Interschimbati toate elementele de minim din N cu toate elemntle de maxim din S
int elemMinimN(int arr[100][100], int m, int n) {
	int minim = 9;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i < j && i + j < n - 1) {
				if (arr[i][j] < minim) {
					minim = arr[i][j];
				
				}
			
			
			}
		
		
		
		}
	}
	return minim;


}
int MaximS(int arr[100][100], int m, int n) {
	int maxim = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i > j && i + j > n - 1) {
				if (arr[i][j] > maxim) {
					maxim = arr[i][j];
				}



			}
			
		
		
		}
	}


	return maxim;



}
void interschimbareElem(int arr[100][100], int m, int n) {
	int maxim = MaximS(arr, m, n);
	int minim = elemMinimN(arr, m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i < j && i + j < n - 1 && arr[i][j] == minim) {
				arr[i][j] = maxim;
			}
			if (i > j && i + j > n - 1 && arr[i][j] == maxim) {
				arr[i][j] = minim;
			}
		
		}
	}




}
void sol18() {
	int arr[100][100] = { {1,2,3},{4,5,6},{7,8,9} };
	int linii = 3;
	int coloane = 3;
	interschimbareElem(arr, linii, coloane);
	cout << "matricea dupa interschimbare este " << endl;
	afisareMatrice(arr, linii, coloane);


}
//k)Sortati descrescator diagonala secundara in functie de suma cifrelor din elemente -->Nu stiu (cum sa pun elem din vector inapoi in matrice )
int sumaCif(int n) {
	int suma = 0;
	while (n > 0) {
		int cif = n % 10;
		suma = suma + cif;
	
		n = n / 10;
	}

	return suma;

}
void bubbleSortDescSuma(int v[], int d) {
	bool sortat = false;
	do {
		sortat = true;
		for (int i = 0; i < d - 1; i++) {
			if (sumaCif(v[i]) < sumaCif(v[i + 1])) {
				int aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
				sortat = false;
			}
		
		}
	
	
	} while (sortat == false);






}
void sortareDiagSec(int arr[100][100], int m, int n, int v[], int &d) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i + j > n) {
				v[d++] = arr[i][n - 1 - i];
			
			}
		
		}
	
	}








}
void sol19() {
	int arr[100][100] = { {25,17,31},{46,55,63},{72,84,96} };
	int linii = 3;
	int coloane = 3;
	int v[100] = {};
	int d = 0;
	sortareDiagSec(arr, linii, coloane, v, d);
	//afisareMatrice(arr, linii, coloane);
//	afisareVector(v, d);



}
//l)Care este triunghiul isoscel ce are cea mai mare frecv a lui k (citit de la tastatura)
int frecvS(int arr[100][100], int m, int n,int k) {
	int frecv = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i > j && i + j > n - 1) {
				if (arr[i][j] == k) {
					frecv++;
				}
				
			}
		
		}
	}
	return frecv;

}
int frecvN(int arr[100][100], int m, int n,int k) {
	int frecv = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i<j && i + j<n - 1) {
				if (arr[i][j] == k) {
					frecv++;
				}
				
			
			}
		
		
		}
	
	
	}

	return frecv;


}
int frecvE(int arr[100][100], int m, int n,int k) {
	int frecv = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i < j && i + j >= n-1) {
				if (arr[i][j] == k) {
					frecv++;
				}
				
			}
		
		
		}
	
	
	}

	return frecv;


}
int frecvV(int arr[100][100], int m, int n,int k) {
	int frecv = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i > j && i + j <= n-1) {
				if (arr[i][j] == k) {
					frecv++;
				}
				
			}
		
		
		}

	}
	return frecv;

}
void maximFrecv(int arr[100][100], int m, int n, int k) {
	int frecventaS = frecvS(arr, m, n,k);
	int frecventaN = frecvN(arr, m, n,k);
	int frecventaE = frecvE(arr, m, n,k);
	int frecventaV = frecvV(arr, m, n,k);
	int maximFrecv = 0;
	int triunghi = 0;
	if (frecventaS > maximFrecv) {
		maximFrecv = frecventaS;
		triunghi = 1;
	}
	if (frecventaN > maximFrecv) {
		maximFrecv = frecventaN;
		triunghi = 2;
	}
	if (frecventaE > maximFrecv) {
		maximFrecv = frecventaE;
		triunghi = 3;
	}
	if (frecventaV > maximFrecv) {
		maximFrecv = frecventaV;
		triunghi = 4;
	}

	cout << "triunghiul cu frecv " << k << " este " << triunghi << endl;


}
void sol20() {
	int arr[100][100] = { {1,2,2,3,4,5},{5,6,7,8,9},{5,5,11,12,13},{5,16,17,18,19},{1,2,3,4,5} };
	int linii = 5;
	int coloane = 5;
	int k = 0;
	cout << "k=" << endl;
	cin >> k;
	maximFrecv(arr, linii, coloane, k);

}
//n)Afisati DA daca elem de pe diagonala principala sunt multiplii celor de pe diagonala secundara(se compara a[0][0]cu a[0][n-1] a[1][1] cu a[1][n-2] s.a.m.d);
bool esteMultiplu(int arr[100][100], int n) {
	for (int i = 0; i < n; i++) {
		if (arr[i][i] % arr[i][n - 1 - i] != 0) {
			return false;
		}
	
	
	}
	return true;


}
void sol22() {
	int arr[100][100] = { {5,3,1},{6,10,2},{7,4,14} };
	int linii = 3;
	int coloane = 3;
	if (esteMultiplu(arr, coloane)) {
		cout << "DA" << endl;
	}
	else {
		cout << "NU" << endl;
	}
}