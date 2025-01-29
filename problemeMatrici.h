#pragma once
#include<iostream>
using namespace std;
//1)Se dă o matrice cu n linii şi m coloane şi elemente numere naturale. Determinați suma valorilor pare din matrice.
int sumaPare(int n,int m,int arr[100][100]) {
	int suma = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] % 2 == 0) {
			
				suma = suma + arr[i][j];
			
			}
		
		}
	
	
	
	
	}


	return suma;



}
void sol1() {
	int arr[100][100] = { {22,56,76},{34,59,12},{98,77,14} };


	int linii = 3;
	int coloane = 3;
	
	cout << "suma nr pare din matrice este " << sumaPare(linii, coloane, arr) << endl;

}
//2)Se dă o matrice cu n linii și m coloane și elemente numere naturale. Să se determine suma elementelor de pe fiecare linie.
int sumaLinie(int arr[100][100], int m, int n, int linie) {


	int s = 0;															//				m			n			linie			j<n			s						
																		//				3			3			1				0<3			1
	for (int j = 0; j < n; j++) {										//										1				1<3			3
																		//															
		s += arr[linie][j];												//										1				2<3			6								
																		//										1				3<3F
	}																	//				3			3			2				0<3			3
																		///				3			3			2				1<3			7
																		//				3			3			2				2<3			12
	return s;															//				3			3			2				3<3F
																		//				3			3			3				0<3			6
}																		//				3			3			3				1<3			13
void sol2() {
	int arr[100][100] = { {1,2,3},{3,4,5},{6,7,8} };
	int linii = 3;
	int coloane = 3;
	for (int i = 0; i < linii; i++) {
		cout << "suma pe linia " << i << " este " << sumaLinie(arr, linii, coloane,i) << endl;

	
	
	}
	

}
//2)Se dă o matrice cu m linii și n coloane și elemente numere naturale.Să se determine câte dintre elementele situate pe linii cu indici pari sunt prime.
bool estePrim(int n) {
	if (n == 1 || n == 0) {

		return false;
	}
	for (int i = 2; i <= n/2; i++) {
		if (n % i == 0) {
			return false;
		}
	
	}
	return true;


}
int contorIndiciPar(int arr[100][100], int m, int n) {
	int contor = 0;
	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n; j++) {
		
			if (i % 2 == 0 && j % 2 == 0) {
				contor++;
			}
		
		
		}
	
	
	}
	return contor;



	


}
void sol3() {
	int arr[100][100] = { {1,2,3},{4,5,6},{7,8,9} };
	int linii = 3;
	int coloane = 3;
	cout << "contor nr prime situate pe indici pari este " << contorIndiciPar(arr, 3, 3);




}
//TEMA:
//f1)Cate alem pare ce stau pe o pozitie div cu 2 si 3  avem in matrice?
int contorElemDiv(int arr[100][100], int m, int n) {
	int contor = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
		
			if ((i + j)%6 && arr[i][j]%2==0) {
			
				contor++;
			
			}
		
		
		}
	
	
	
	
	}
	return contor;



}
void f1() {
	int arr[100][100] = { {1,1,1},{3,4,5},{2,2,2} };
	int linii = 3;
	int coloane = 3;
	cout<<"nr de elem este "<<contorElemDiv(arr, linii, coloane);


}
//f2)Sa se afiseze suma elementelor prime ce stau pe linie para si pe o coloana impara
bool estePrim2(int n) {
	if (n == 1 || n == 0) {
		return false;
	
	
	}
	for (int i = 2; i < n / 2; i++) {
		if (n % i == 0) {
			return false;
		
		}
	
	
	}

	return true;

}
int sumaElem(int arr[100][100], int m, int n) {
	int suma = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i % 2 == 0 && j % 2 != 0 && estePrim2(arr[i][j])) {
			
				suma = suma + arr[i][j];
			
			}
		
		
		
		}
	
	}
	return suma;



}
void f2() {
	int arr[100][100] = { {2,3,5},{11,12,17},{5,6,7} };
	int linii = 3;
	int coloane = 3;

	cout << "suma este " << sumaElem(arr, linii, coloane);



}
//f3)Sa se gaseasca minimul de pe linia L si maximul de pe coloana C.Sa se interschimbe aceste doua elem (L si C citite de la tast).Daca se gasesc mai multe elem min si maxime se va schimba primul min cu ultim maxim;
int miniminii(int arr[100][100], int m,int n,int linie) {
	
	int minim = arr[linie][0];

	int coloanaMax = 0;

	for (int i = 0; i < n; i++) {


		if (minim > arr[linie][i]) {
			minim = arr[linie][i];
			coloanaMax = i;
		}
	}
	                     
	return coloanaMax;


}
int maximColoane(int arr[100][100], int m ,int n, int coloana) {
	int maxim = arr[coloana][9];
	int linieMax = 0;
	for (int i = 0; i < m; i++) {
		if (maxim < arr[coloana][i]) {
		
			maxim = arr[coloana][i];
			linieMax = i;
		
		
		}
	
	
	
	
	}

	return linieMax;


}
void interschimbareMaxSiMin(int arr[100][100], int m, int n, int linie, int coloana) {
	int maximC = maximColoane(arr, m, n, coloana);//
	int minimL = miniminii(arr, m, n, linie);
	int aux = arr[maximC][coloana];
	arr[maximC][coloana] = arr[linie][minimL];
	arr[linie][minimL] = aux;

	



}
void afisareMatrice(int arr[100][100], int m , int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {

			cout << arr[i][j] << " ";



		}
		cout << endl;



	}




}
void testare() {
	int arr[100][100] = { { 4,7,9 } ,{1,2,7} ,{8,9,7} };
	int linii = 3;
	int col = 3;
	cout << "matricea initiala este ";
	afisareMatrice(arr, linii, col);
	cout << "matricea dupa interschimbare este ";

	interschimbareMaxSiMin(arr, linii, col, 1, 1);
	
	afisareMatrice(arr, linii, col);






}
//f4)Realizati un nou vector care sa contina toate elem palindroame in rdinea in care apar ele daca am parcurge marricea pe coloane
int invNr(int n) {
	int inv = 0;
	while (n > 0) {
		int cif = n % 10;
		inv = inv * 10 + cif;
	
	
		n = n / 10;
	
	}
	return inv;






}
bool estePalindrom(int n) {

	while (n > 0) {
		if (invNr(n) == n) {
		
			return true;
		}
		return false;

	
	}




}
void afisareVect(int v[], int d) {
	for (int i = 0; i < d; i++) {

		cout << v[i] << " ";


	}






}
void parcurgerePeColoane(int arr[100][100], int m, int n) {
	int v[100] = {};
	int d = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (estePalindrom(arr[i][j])) {
				v[d++] = arr[i][j];
			
			}
				
		
		
		}
	
	
	
	
	}


	afisareVect(v,  d);


}
void f5() {
	int arr[100][100] = { {121,33,45},{111,37,98},{77,84,12} };
	int linii = 3;
	int coloane = 3;

	parcurgerePeColoane(arr, linii, coloane);
	




}
//f6)realizati suma elementelor de pe fiecare linie in parte.Care este maximul dintre acestea 
int sumaLinii(int arr[100][100], int n,int linie ) {
	int suma = 0;
	for (int j = 0; j < n; j++) {
	
		suma = suma + arr[linie][j];
	
	}
	return suma;




}
void sumaMaxima(int arr[100][100], int m, int n) {

	int maxim = 0;
	int maxLinie = 0;
	for (int i = 0; i < m; i++) {
		int suma = sumaLinii(arr, n,i);

		cout << "suma de pe linia " <<  i + 1  << " este " << suma << endl;

		if(suma>maxim){
			maxim = suma;
			maxLinie = i;
		
		
		
		}
	}







}
void afisareMaximSuma(int maxim, int maxlinie) {

	cout << "suma maxima este " << maxim << "pe linia " << maxlinie << endl;
}
void f6() {
	int arr[100][100] = { {3,3,3},{7,1,4},{8,6,2} };
	int linii = 3;
	int coloane = 3;
	int  maxim = 0;
	int maxlinie = 0;

	sumaMaxima(arr, linii, coloane);

	afisareMaximSuma(maxim, maxlinie);

}
//f7Afisati media aritmetica a elementelor de pe linia unde se gaseste elementul cu cele mai multe cifre binare 
int contorCifBinare(int n) {
	int contor = 0;
	while (n > 0) {
		int cif = n % 10;
		if (cif == 0 || cif == 1) {
		
			contor++;
		
		}
		n = n / 10;
	}

	return contor;
}
int  linieMaximBinar(int arr[100][100], int m, int n) {
	int maximCif = 0;
	int maxLinie = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int cif = contorCifBinare(arr[i][j]);
			if (cif > maximCif) {
				maximCif = cif;
				maxLinie = i;
			
			
			}
		
		
		}
	
	
	
	
	
	}
	return maxLinie;


}
int  mediaLinie(int arr[100][100], int n,int maxLinie) {
	int suma = 0;
	for (int j = 0; j < n; j++) {
	
		suma = suma + arr[maxLinie][j];
	
	
	}

	return suma / n;



}
void f7() {
	int arr[100][100] = { {2,4,6}, {10,20,3},{8,8,0} };
	int linii = 3;
	int coloane = 3;
	int maxLinie = linieMaximBinar(arr, linii, coloane);
	int media = mediaLinie(arr, coloane, maxLinie);
	cout << "linia cu elem cu cele mai multe cif binare este " << maxLinie + 1 << " iar media este " << media << endl;







}
//ex2)a)Realizati un nou numar ce sa contina cifra minima din elementul maxim de pe fiecare linie 
int cifMinima(int n) {
	int cifMin = 9;
	while (n > 0) {
		int cif = n % 10;
		if (cif < cifMin) {
			cifMin = cif;

		
		
		}
		
		n = n / 10;
		
		
	}
	return cifMin;
}
int formareNr(int arr[100][100], int m, int n) {
	int nrFinal = 0;
	for (int i = 0; i < m; i++) {
		int maxLinie = 0;
		for (int j = 0; j < n; j++) {
			if (arr[i][j] > maxLinie) {
				maxLinie = arr[i][j];
			
			
			}
		
		
		}
		nrFinal = nrFinal * 10 + cifMinima(maxLinie);
	
	}

	return nrFinal;


}
void solA() {
	int arr[100][100] = { {17,88,33},{32,76,45},{10,87,31} };
	int linii = 3;
	int coloane = 3;
	int nrFinal = formareNr(arr, linii, coloane);
	cout << "nr final este " << nrFinal << endl;



}
//b)Care este media aritmetica a elementelor ce au intre 3 si 5 div proprii?
int contorDivProprii(int n) {
	int contor = 0;
		for (int i = 2; i < n; i++) {
			if (n % i == 0) {
				contor++;
			}
		
		
		}
		return contor;


	}
bool nAreIntre3Si5Div(int n) {
	int nrDiv = contorDivProprii(n);
	if (nrDiv >= 3 && nrDiv <= 5) {
		return true;
	
	}
	else {
		return false;
	}

}
double mediaDIv(int arr[100][100], int m, int n) {
	int suma = 0;
	int contor = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (nAreIntre3Si5Div(arr[i][j])) {
				suma = suma + arr[i][j];
			
				contor++;
			
			}
		
		
		}
	
	
	
	}
	return suma / n;

}
void solB() {
	int arr[100][100] = { {12,54,22},{12,28,42},{12,76,43} };
	int linii = 3;
	int coloane = 3;
	double media = mediaDIv(arr, linii, coloane);
	cout << "media elem care au intre 3 si 5 div este " << media << endl;






}
//c)Afisati toate dubletele palindroame de pe linia L(L citit de la tatsatura )
//d)Care este cif de control a cif din drapta jos?
int sumaCif(int n) {
	int suma = 0;
	while (n > 0) {
		int cif = n % 10;
		suma = suma + cif;
		n = n / 10;
	
	}
	return suma;

}
void solD() {
	int arr[100][100] = { {12,44,56},{11,55,77},{12,54,8} };
	int linii = 3;
	int coloane = 3;
	int drJos = arr[linii - 1][coloane - 1];
	//int cifDeCOntrol = cifDeCOntrol(drJos);
	//cout << "cif de control din coltul dr jos este " << cifDeCOntrol << endl;





}
//e)Care este frecventa fiecarei cifre citite in parte a elem de pe coloana para si o linie impara din matricea citita?
void frecventaCif(int n, int f[]) {
	while (n != 0) {
		int cif = n % 10;
		f[cif]++;
	
		n = n / 10;
	}


}
void frecvColoanaParaSiLinieImp(int arr[100][100], int m, int n,int f[10]) {
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			
			if (i % 2 != 0 && j % 2 == 0) {

				frecventaCif(arr[i][j],f);
			}
		
		}
	}





}
void solE() {
	int arr[100][100] = { {12,44,31},{17,18,19},{121,73,22} };
	int linii = 3;
	int coloane = 3;
	int f[10] = {};
	frecvColoanaParaSiLinieImp(arr, linii, coloane,f);
	cout << "frecventa este ";
	for (int i = 0; i < 10; i++) {
		if (f[i] > 0) {
		
			cout << "cif " << i << " apare de " << f[i] << endl;
		}
	
	
	
	
	}



}
//Parcurgere diagonala:
void parcurgereDiagonalaPrincipala( int arr[100][100], int m, int n) {
	for (int i = 0; i < n; i++) {
	
		cout << arr[i][i] << " ";
	
	}




}
void parcurgereDiagSec(int arr[100][100], int m, int n) {
	for (int i = 0; i < m; i++) {

		cout << arr[i][m-1-i];
		

		
	}





}
void afisareDreptunghiDeasupraDiagPrincipala(int arr[100][100], int m, int n) {

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n;j++){
			if (i + j < n - 1) {
			
			
				cout << arr[i][j];
			}
			
		}
	
	
	
	}





}
void afisareDreptunghiSubDiagPrincipala(int arr[100][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		for(int j = 0; j< n; j++){
			if (i + j > n - 1) {
				cout << arr[i][j] << " ";
			}
		
		
		}
	
	}



}
void afisareRez() {
int	arr[100][100] = { {1,2,3},{4,5,6},{7,8,9} };

int linii = 3;
int coloane = 3;



afisareDreptunghiSubDiagPrincipala(arr, linii, coloane);



}
//g)Care este cel mai mic numar ce se poate forma din toate cifrele ce nu apar in scrierea elementelor din int matriciei?
void frecvCifMatrice(int arr[100][100], int m, int n, int f[]) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			frecventaCif(arr[i][j], f);
		
		
		}
	
	}





}
int celMaiMicNr(int f[]) {
	int n = 0;
	for (int i = 0; i < 10; i++) {
		if (f[i] == 0) {
			n = n * 10 + i;
		}
	
	
	
	}


	return n;

}
void solG() {
	int arr[100][100] = { {122,7,8},{32,6,1},{5,66,12} };
	int linii = 3;
	int coloane = 3;
	int f[10] = {};
	frecvCifMatrice(arr, linii, coloane, f);
	int nr =  celMaiMicNr(f);
	cout << "cel mai mic nr format este " << nr << endl;


}
//h)Care este a k aparitie a lui Y in matrice(k si Y citite de la tastatura ).Daca k nu apare de cel putin Y ori int vector se va afisa mesajul "NU EXISTA!"
void aparitieK(int arr[100][100], int m, int n, int k, int y) {
	int contor = 0;
	bool  nrGasit = false;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == y) {
				contor++;

				if (contor == k) {

					cout << k << "a fost gasit de " << y << " ori" << endl;
					nrGasit = true;
				}
			
				
			}
		}
	
	
	}
	if (!nrGasit) {
		cout << "NU EXISTA!" << endl;
	}

	
}
void solH() {
	int arr[100][100] = { {12,55,22},{13,65,45},{35,66,95} };
	int linii = 3;
	int coloane = 3;
	int y = 0;
	int k = 0;
	cout << "k=" << endl;
	cin >> k;
	cout << "y=" << endl;
	cin >> y;
	aparitieK(arr, linii, coloane, k, y);
}
//i)Sortati crescator coloana pe care apare elemntul de la pct d)--->NU IMI IESE !
//j)Sa se caute eficient numarul k citit de la tastatura in coloana sortata la pct i
int cautaK(int arr[100][100], int m, int n, int k) {
	for (int i = 0; i < m; i++) {
		if (arr[i][n - 1] == k) {
			return i;
		}
	
	
	
	
	
	}



}
void solJ() {
	int arr[100][100] = { {9,5,3},{7,8,7},{6,5,2} };
	int linii = 3;
	int coloane = 3;
	int k = 0;
	cout << "k=" << endl;
	cin >> k;
	int linie=	cautaK(arr, linii, coloane, k); 
	cout << " numarul " << k << " se afla pe linia " << linie << " din ultima coloana " << endl;




}
//3)a)Sa se schimbe intre ele liniile matriciei astfel incat prima coloana sa fie orodonata crescator --->NU STIU
//b)Care este numarul de componente din matrice ce au in componenta doar cif binare?
bool nCifBinara(int n) {
	while (n > 0) {
		int cif = n % 10;
		if (cif == 0 || cif == 1) {
			return true;
		
		
		}
		n = n / 10;
	
	
	
	}

	return false;


}
int contorCifBinare(int arr[100][100], int m, int n) {
	int contor = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (nCifBinara(arr[i][j])) {
				contor++;
			}
		
		
		
		
		}
	}
	return contor;
}
void sol3a() {
	int arr[100][100] = { {101,10,101},{33,21,45},{65,31,10} };
	int linii = 3;
	int coloane = 3;
	int contor = contorCifBinare(arr, linii, coloane);
	cout << "nr de componenete cu cif binare este " << contor << endl;





}
//c)Realizati un nou vector in care sa se regaseasca toate elementele superprime transformate in baza 16( se presupune ca matricea are un elem superprim )-->Nu mi-a iesit
bool nSuperPrim(int n) {
	while (n > 0) {
		int cif = n % 10;
		if (cif != 2 && cif != 3 && cif != 5 && cif != 7) {
			return false;
		}

		n = n / 10;
	
	}
	return true;



}
void baza16(int n) {
	int nrInBaza = 0;
	while (n > 0) {
		nrInBaza = n % 16;
		if (nrInBaza < 10) {
			cout << nrInBaza;
		
		}
	
		n = n / 16;
	}





}
void elemSuperPrimeInBaza16(int arr[100][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (nSuperPrim(arr[i][j])) {
				baza16(arr[i][j]);
				cout << " ";
			
			}
		
		
		}
	}



	
}
void sol3c() {
	int arr[100][100] = { {32,17,5},{71,29,11},{23,65,33} };
	int linii = 3;
	int coloane = 3;
	cout << "nr superprime in baza 16 sunt " << endl;
		elemSuperPrimeInBaza16(arr, linii, coloane);




}
//d)Afisati elem matriciei pe linie in ordine din desen
void bubbleSortCrec(int arr[100][100], int m, int n, int linie) {

	bool sortat = false;
	do {
		sortat = true;
		for (int i = 0; i < n - 1; i++) {
			if (arr[linie][i] > arr[linie][i + 1]) {
				int aux = arr[linie][i];
				arr[linie][i] = arr[linie][i + 1];
				arr[linie][i + 1] = aux;
				sortat = false;


			}




		}






	} while (sortat == false);
}
void bubblesortDesc(int arr[100][100], int m, int n, int linie) {
		bool sortat = false;
		do {
			sortat = true;
			for (int i = 0; i < n - 1; i++) {
				if (arr[linie][i] < arr[linie][i + 1]) {
					int aux = arr[linie][i];
					arr[linie][i] = arr[linie][i + 1];
					arr[linie][i + 1] = aux;
					sortat = false;
				
				
				
				
				
				
				
				}
			
			}
		
		
		
		
		} while (sortat == false);
	
	
	

	
	}
void sol3d() {
	int arr[100][100] = { {3,7,2},{3,6,2},{1,9,6} };
	int linii = 3;
	int coloane = 3;
	int linie = 0;
	bubbleSortCrec(arr, linii, coloane, 0);
	bubblesortDesc(arr, linii, coloane, 1);
	bubbleSortCrec(arr, linii, coloane, 2);
	afisareMatrice(arr, linii, coloane);




}
//e)Cate linii simetrice contine matricea?(o linie este simetrica daca elem egal departate de capetele linie sunt egale )
bool esteSimetrica(int arr[100][100], int n, int linie) {
	for (int i = 0; i < n; i++) {
		if (arr[linie][i] != arr[linie][n - 1 - i]) {
			return false;


		}

	}
	return true;
}
int contorSimetrice(int arr[100][100], int m, int n) {
	int contor = 0;
	for (int i = 0; i < m; i++) {
		if (esteSimetrica(arr,n,i)) {
			contor++;
		}



	}
	return contor;
}
void sol3e() {
	int arr[100][100] = { {1,2,1},{2,1,7},{4,5,4} };
	int linii = 3;
	int coloane = 3;
	int contor = contorSimetrice(arr, linii, coloane);
	cout << "nr de linii simetrice este " << contor << endl;




}
//f)Sunt toate elementele prime intre ele cu rasturnatul lor?Afisati un mesaj relevant 
bool nrEstePrim(int n) {
	if (n == 1 || n == 2) {
		return false;
	}
	for (int i = 2; i < n / 2; i++) {
		if (n % i == 0) {
			return false;
		}
	
	}

	return true;

}
int inversNr(int n) {
	int inv = 0;
	while (n > 0) {
		int cif = n % 10;
		inv = inv * 10 + cif;
		n = n / 10;
	}

	return inv;




}
bool primCuInv(int arr[100][100], int m, int n) {

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int nr = arr[i][j];
			int invNr = inversNr(nr);
			if (nrEstePrim(nr) || nrEstePrim(invNr)) {
			
				return false;
			
			}
		
		
		
		
		}

	}

	return true;


}
void sol3f() {
	int arr[100][100] = { {12,77,21},{17,71,33},{13,14,41} };
	int linii = 3;
	int coloane = 3;
	if (primCuInv (arr, linii, coloane)){
		cout << "toate elem sunt prime cu rasturnatul lor" << endl;
	}
	else {
		cout << "nu toate elem sunt prime cu rast lor " << endl;
	}
	


}
void interschimbareLinii(int arr[100][100],int n ,int m, int linie1, int linie2) {			                     
	                                                                                       //   1 2 3 4          i=0   interschimba   arr[1][0] cu a44[2[0]
	                                                                                       //   1 6 7 8          i=1                  arr[1][
	                                                                                       //   5 4 3 2     
	                                                                                       //   3 5 8 0
	for (int i = 0; i < m; i++) {
		int aux = arr[linie1][i];
		arr[linie1][i] = arr[linie2][i];
		arr[linie2][i] = aux;
	
	
	}






}
void interschimbareColoane(int arr[100][100], int n, int m, int col1, int col2) {
	for (int i = 0; i < n; i++) {
		int aux = arr[i][col1];
		arr[i][col1] = arr[i][col2];
		arr[i][col2] = aux;
	
	
	
	}






}
void testareInterschimbare() {
	int arr[100][100] = { {1,2,3},{4,5,6},{7,8,9} };
	int linii = 3;
	int coloane = 3;
	interschimbareColoane(arr, linii,coloane,1,2);
	afisareMatrice(arr, linii, coloane);

}
//i)Sortati crescator coloana pe care apare elemntul de la pct d)
void sortareUltimaColoana(int arr[100][100], int m, int n ,int coloana) {
	bool sortat = false;
	do {
		sortat = true;
		for (int i = 0; i < n-1; i++) {
		
	
			if (arr[i][coloana] > arr[i + 1][coloana]) {

				interschimbareLinii(arr, n, m, i, i + 1);

				sortat = false;
			}

		
		
		
		}
	
	
	} while (sortat == false);








}
void testareI() {

	int arr[100][100] = { {4,5,7},{1,2,3},{7,8,9} };
	int linii = 3;
	int coloane = 3;
	sortareUltimaColoana(arr, linii, coloane, 2);
	afisareMatrice(arr, linii, coloane);

}
//Sa se schimbe intre ele liniile matriciei astfel incat prima coloana sa fie orodonata crescator
void sortarePrimaColoana(int arr[100][100], int n, int m, int coloana) {
	bool sortat = false;
	do {
		sortat = true;
		for (int i = 0; i < n-1; i++) {
			if (arr[i][coloana] > arr[i + 1][coloana]) {
				interschimbareLinii(arr, n, m, i, i + 1);
				sortat = false;
			
			}
		
		
		
		
		}
	
	
	
	
	
	
	} while (sortat == false);









}
void testare3A() {
	int arr[100][100] = { {4,5,6},{2,1,4},{3,9,1} };
	int linii = 3;
	int coloane = 3;
	sortarePrimaColoana(arr, linii, coloane, 2);
	afisareMatrice(arr, linii, coloane);


}
//Realizati un nou vector in care sa se regaseasca toate elementele superprime transformate in baza 16(se presupune ca matricea are un elem superprim)
bool  nrPrim(int n) {
	if (n == 1 || n == 0) {
		return false;
	}
	for (int i = 2; i < n / 2; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;


}
bool nrSuperPrim(int n) {
	int prefix = 0;
	while (n > 0) {
		int cif = n % 10;
		prefix = prefix * 10 + cif;
		n = n / 10;
		if (nrPrim(prefix)) {
			return true;
		
		}
	
	}
	return false;
}
void testareSuperPrim() {

	int arr[100][100] = { {7,12,111},{13,171,120},{14,76,44} };
	int linii = 3;
	int coloane = 3;
	for (int i = 0; i < linii; i++) {
		for (int j = 0; j < coloane; j++) {
			if (nrSuperPrim(arr[i][j])) {
				cout << "matricea contine elemente superprime " << endl;

			}
		
		
		}
	
	
	
	}
	




}
//PbInfo:
//Se dă o matrice cu n linii și n coloane și elemente numere naturale.Calculați diferența în valoare absolută dintre sumele elementelor de pe cele două diagonale.
int sumaDiagPrimcipala(int arr[100][100], int m, int n) {
	int suma = 0;
	for (int i = 0; i < m; i++) {
		 suma = suma + arr[i][i];
	
	
	
	}

	return suma;

}
int sumaDiagSecundara(int arr[100][100], int m, int n) {
	int suma = 0;
	for (int i = 0; i < m; i++) {
		suma = suma + arr[i][n - i-1];
	
	
	}


	return suma;


}
void solPb1() {
	int arr[100][100] = { {1,2,3},{4,5,6},{7,8,9} };
	int linii = 3;
	int coloane = 3;
	int suma1 = sumaDiagPrimcipala(arr, linii, coloane);
	int suma2 = sumaDiagSecundara(arr, linii, coloane);
	int dif = suma1 - suma2;
	cout << "diferenta dintre cele doua diag este " << dif << endl;

}
//2)Se dă o matrice cu n linii şi n coloane şi elemente numere întregi. Pentru fiecare linie din matrice, calculaţi cea mai mare valoare care de află pe diagonala principală sau pe diagonala secundară.
int ceaMaiMareValPrincipala(int arr[100][100], int m, int n) {
	int valMaxima = 0;
	for (int i = 0; i < m; i++) {
		if (arr[i][i] > valMaxima) {
			valMaxima = arr[i][i];
		}
	
	
	}

	return valMaxima;

}
void solPb2() {
	int arr[100][100] = { {1,2,3},{4,5,6},{7,8,9} };
	int linii = 3;
	int coloane = 3;
	int valMaxima = ceaMaiMareValPrincipala(arr, linii, coloane);
	cout << "cea mai mare val de pe diag principala este " << valMaxima << endl;



}
//3)Se dă o matrice cu n linii şi n coloane şi elemente numere naturale. Calculaţi cel mai mare divizor comun al sumei elementelor de deasupra diagonalei principale și al sumei elementelor de sub diagonala principală.
int sumaElemDeSuBDiagPrincipala(int arr[100][100], int m, int n) {
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
int sumaElemDeasupraDiagPrincipale(int arr[100][100], int m, int n) {
	int suma = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i + j > n - 1) {
			
				suma = suma + arr[i][j];
			}
	
		
		
		}
	}

	return suma;


}
int CMMDC(int a, int b) {
	while (b > 0) {
		int rest = a % b;
		a = b;
		b = rest;
	
	}
	return a;


}
void solPb3() {
	int arr[100][100] = { {1,2,3},{4,5,6},{7,8,9} };
	int linii = 3;
	int coloane = 3;
	int suma1 = sumaElemDeSuBDiagPrincipala(arr, linii, coloane);
	int suma2 = sumaElemDeasupraDiagPrincipale(arr, linii, coloane);
	
	cout << "suma1 este" << suma1 << endl;
	cout << "suma2 este" << suma2 << endl;
	cout << "CMMDC este " << CMMDC(suma1,suma2);
}
//4)Se dă o matrice cu n linii şi n coloane şi elemente numere naturale.Să se construiască o matrice care să fie simetrica față de diagonala principală a matricei date.

void construiesteMatrice(int arr[100][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < n; j++) {
			int aux = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = aux;
		
		
		
		}
	
	
	}





}
void solPb4() {
	int arr[100][100] = { {1,2,3},{4,5,6},{7,8,9} };
	int linii = 3;
	int coloane = 3;
	 construiesteMatrice (arr, linii, coloane);
	 afisareMatrice(arr, linii, coloane);


}
