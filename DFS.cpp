#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX 100
#define TRUE 1
#define FALSE 0

int G[MAX][MAX], n, chuaxet[MAX], S[MAX], K;

void Init() {
	freopen("matran.txt", "r", stdin);
	cin >> n;
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= n; j++)
		cin >> G[i][j];
}


	
void DFS(int x) {
	int index = 0;
	S[index] = x;
	index++;
	while(index > 0) {
		index--;
		K = S[index];
		if(chuaxet[K] == FALSE) {
			cout << K << "\t";
			chuaxet[K] = TRUE;
		}
		for(int i = n; i >= 1; i--)
			if(G[i][K] == 1 && chuaxet[i] == 0) {
				S[index] = i;
				index++;
			}
	}
 }
int main() {
	int r;
	cout << " Nhap dinh can duyet: "; 
	scanf("%d", &r);
	Init();
	for(int i = 1; i <= n; i++)
		chuaxet[i] = FALSE;
	cout << "Duyet DFS cua dinh " << r << ":\n";
	DFS(r);
}
