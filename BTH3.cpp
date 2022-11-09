#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct matran {
	int n;
	int arr[100][100];
}matran;

int d[10000];
matran a;

void duyet(int x);
int main() {

		FILE *f = fopen("Matranke.txt", "r");
		(f == NULL) ? cout << "error open file" : cout << "Open file succesfull" << endl;
		//nhap ma tran ke

		fscanf(f, "%d", &a.n);
		for(int i = 1; i <= a.n; i++) 
		for(int j = 1; j <= a.n; j++)
			fscanf(f, "%d", &a.arr[i][j]);				
	
		//khoi tao
		for (int i = 0; i <= a.n; i++) 
			d[i] = 0;
		cout << "Nhap dinh x = "; cin >> x;
		duyet(x);
		fclose(f);
	return 0;
}

void duyet(int x) {
	cout << x << "\t";
	d[x] = 1;
	for(int i = 0; i < a.n; i++) 
		if(a.arr[x][i] == 1 && d[i] == 0)
			duyet(i);
}
