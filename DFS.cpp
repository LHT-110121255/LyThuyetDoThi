#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX 100
#define TRUE 1
#define FALSE 0

int G[MAX][MAX], n, chuaxet[MAX], S[MAX], K, m;

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
 
// chua xong
void BFS_2(int x) {
	int index = 0;
	S[index] = x; //[1,]
	K = S[index];
	for (int g = 1; g <= n; g++){
		if(chuaxet[K] == FALSE ) 
		{
			chuaxet[K] = TRUE;
		for(int i = 1; i <= n; i++)
			if(G[i][K] == 1 && chuaxet[i] == FALSE) 
			{
				index++;
				S[index] = i;
			} 
		} else {
			K = S[g++];
		}
					
	}
	for(int i = 0; i < n; i++)
		cout << S[i] << "\t";
 }
 
 // theo cách th?y
 
 int BFS(int v)
{
	int T[20];
	int t=0;
	T[t]=v;
	t++;
	d[v]=-1;
	while(t!=0)
	{
		int x=T[0];
		printf("%d ",x);
		
		for(int i=0 ; i<t ; i++)
		T[i]=T[i+1];
		t--;
		for(int i=1 ; i<=n ; i++)
		{
		if(a[x][i] != 0 && d[i]==0)
		{
		T[t]=i;
		t++;
		d[i]=-1;			
		}
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
	printf("\nKet qua duyet BFS(%d) la: ", x);
	BFS(x);
}
