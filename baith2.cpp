#include <iostream>
#include <stdio.h>

using namespace std;

#define VoCuc 10000001
#define Dinh 100
#define TRUE 1
#define FALSE 0

int arr1[2][Dinh];
int arr2[Dinh];
int arr3[Dinh][Dinh];
int n, i, j, t = 1;

void init() {
	FILE *f = fopen("DoThi.txt", "r");
	(f != NULL) ? cout << "open file succesfull" : cout << "Error";
	fscanf(f, "%d", &n);
	for(i = 1; i <= n; i++)
	for(j = 1; j <= n; j++)
		fscanf(f, "%d", &arr3[i][j]);
	fclose(f);
	for(i = 1; i <= n; i++) {
		arr1[1][i] = VoCuc;
		arr1[2][i] = FALSE;
		arr2[i] = FALSE;
	}
}

void DuongDiNganNhat() {
	int g, dinh = -1;
	int min;
	arr1[1][1] = 0;
	for(g = 1; g <= n; g++)
	{
		min = VoCuc;
		for(int h = 1; h <= n; h++) {
			if(arr1[2][h] ==  FALSE) {
				if(min > arr1[1][h]) {
					min = arr1[1][h];
					dinh = h;
					
				}
			}
		}
		arr1[2][dinh] = TRUE;
		// cap nhat
		for(int i = 1; i <= n; i++) 
		{
			if(arr3[dinh][i] != 0 && arr1[2][i] == FALSE) {
				if( arr1[1][i] > arr1[1][dinh] + arr3[dinh][i]) {
					arr1[1][i] = arr1[1][dinh] + arr3[dinh][i];
					arr2[i] = dinh; 
				}
			}		
		}
	}
	
	// in ra
	cout << "\nDuong di ngan nhat = " << arr1[1][n] <<"\n";
	for(int i = 1; i <= n; i++) {
		if(arr2[i] == arr2[i+1]) 
			i++;
		cout << arr2[i] << " -> ";
	}
	if(n != arr2[n-1]) 
		cout << n;

}

int main() {
	init();
	DuongDiNganNhat();
}


