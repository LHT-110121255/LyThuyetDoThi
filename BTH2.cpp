#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct matran {
	int n;
	int arr[100][100];
}matran;

		/*
		luu y: cuoi file nhap them so 0 de dung lai
		vd:
			4
			0 1 1 0 
			1 0 1 1
			1 1 0 0
			0 1 0 1
			4 
			0 0 1 0 
			1 0 1 1
			1 1 0 0
			0 1 0 1
			0
		*/
		
int main() {

		FILE *f = fopen("Matranke.txt", "r");
		(f == NULL) ? cout << "error open file" : cout << "Open file succesfull" << endl;

		//nhap ma tran ke
		matran a;
		fscanf(f, "%d", &a.n);
		while (a.n != 0) {
			for(int i = 1; i <= a.n; i++) 
			for(int j = 1; j <= a.n; j++)
				fscanf(f, "%d", &a.arr[i][j]);
				
			// xuat ma tran ke
			cout << "Ma tran ke" << endl;
			for(int i = 1; i <= a.n; i++) {
				for(int j = 1; j <= a.n; j++)
					cout <<"\t" << a.arr[i][j]; 
				cout << endl;
			}
			
			// kiem tra do thi vo huong hay co huong
			int kt = 0, deg = 0, x;
			for(int i = 1; i <= a.n; i++) 
				for(int j = 1; j <= a.n; j++)
					if(a.arr[i][j] != a.arr[j][i])
						kt++;
			if(kt == 0)
			{
				// vo huong
				cout << "Nhap dinh can tim bac x = "; cin >> x;
				for(int i = 1; i <= a.n; i++)
					(x == i) ? deg += a.arr[x][i]*2 : deg += a.arr[x][i];
				cout << "Bac cua x la " << deg << endl; 
				
			}	else {
				//co huong
				int BV = 0, BR = 0;
				cout << "Nhap dinh can tim bac x = "; cin >> x;
				for(int i = 1; i <= a.n; i++) 
					BV += a.arr[i][x];
				for(int i = 1; i <= a.n; i++) 
					BR += a.arr[x][i];	
				cout << "Bac vao: " << BV << endl << "Bac ra: " << BR << endl;
			}
			fscanf(f, "%d", &a.n);
		}
		fclose(f);
	return 0;
}
