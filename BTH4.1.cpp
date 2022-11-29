#include <iostream>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

using namespace std;

typedef struct matran {
	int n;
	int arr[100][100];
}matran;

int d[10000];
matran a;
int ans[100][100], dong = 0, cot = 0; 

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
		for (int i = 1; i <= a.n; i++) 
			d[i] = FALSE;
			
		//xu ly
		int i = 1;
		do {
			if(d[i] == FALSE) {
				duyet(i); cout << endl;
				dong++;
			}
			i++;
		} while(i <= a.n);
		
		cout<< endl << "So thanh phan lien thong: " << dong<< endl;
		
		for(i = 0; i < dong; i++) {
			for(int j = 0; j < cot; j++) 
				if(ans[i][j] != 0) 
					cout << ans[i][j] << "\t";
			cout << endl;
		}		
		fclose(f);
	return 0;
}

void duyet(int x) {
	ans[dong][cot] = x;
	cot++;
	d[x] = TRUE;
	for(int i = 1; i <= a.n; i++) 
		if(a.arr[x][i] == 1 && d[i] == FALSE) {
			duyet(i);
		}	
}
