#include <iostream>
#include <conio.h>
using namespace std;

#define MAX 100
#define TRUE 1
#define FALSE 0

int A[MAX][MAX], n, u; // arrA chua matran, n la so dinh, u la dinh bat dau

void Init() { // khoi tao ( doc file, nhap vao matran A)
	FILE *f = fopen("Matranke.txt", "r");
	(f == NULL) ? cout << "error open file" : cout << "Open file succesfull" << endl;
		
	//nhap ma tran ke

	fscanf(f, "%d", &n);
	for(int i = 1; i <= n; i++) 
	for(int j = 1; j <= n; j++)
		fscanf(f, "%d", &A[i][j]);
}
// kiem tra xem matranke nay co Euler khong 
int Kiemtra() {
	int s, d = 0; 
	for(int i = 1; i <= n; i++) {
		s = 0;
		for(int j = 1; j <= n; j++) 
			s+= A[i][j]; // s là tong cac bac cua dinh i 
		if(s%2 == 1) d++;
	}
	if (d > 0) 
		return FALSE;
	return TRUE;
	
}

void Euler() {
	int v, x, top, dCE;
 	int stack[MAX], CE[MAX];
	top = 1;
 	
 	stack[top]=u;
 	dCE=0;

	do {
	  v = stack[top];
	  x=1;
	  while (x<=n && A[v][x]==0)
	   x++;
	
	  if (x>n) { 
	   dCE++;
	   CE[dCE]=v;
	   top--;
	  }else { 
		   top++;
		   stack[top]=x;
		   A[v][x]=0;
		   A[x][v]=0;
	  }
	} while(top!=0);

	cout<<" Co chu trinh Euler:";
	for(x=dCE; x>0; x--)
		cout<<CE[x]<<"\t";
}

int main() {
	Init();
	cout << "Nhap dinh = "; cin >> u;
 	if(Kiemtra())
  		Euler();
 	else cout << "\n Khong co chu trinh Euler";
 	_getch();
}
