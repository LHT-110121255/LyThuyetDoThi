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
		if(s%2) d++; // neu s%2 khac 0 tuc la bac le thi d++
	}
	if (d > 0) 
		return FALSE; // d > 0 tuc la co dinh bac le => ko co Euler
	return TRUE; // nguoc lai, co Euler
	
}

void Euler() {
	int v, x, top, dCE; // v là dinh, x la canh vX, dCE la so lan qua cac dinh
 	int stack[MAX], CE[MAX]; // stack de chua cac dinh ke, CE de chua ket qua
	top = 1;
 	
 	stack[top]=u; // dua dinh bat dau vao vi tri dau tien
 	dCE=0; 

	do { // chay khi vi tri t trong stack > 0
	  v = stack[top]; // v la dinh can xac dinh dinh ke
	  x=1;
	  while (x<=n && A[v][x]==0) // xac dinh xem vi tri thu x thi xuat hien 1 tuc la co canh ke
	   x++;
	
	  if (x>n) { // neu khong co dinh ke 
	   dCE++; // vi tri trong mang ket qua tang 1
	   CE[dCE]=v; // dua dinh do vao mang ket qua
	   top--; // xoa dinh 
	  }else { // co dinh ke
		   top++; // tang vi tri len 1
		   stack[top]=x; // gan dinh ke vao mang stack de xet
		   A[v][x]--; // 1
		   A[x][v]--;// 2 =? 1+2 xoa canh
	  }
	} while(top!=0);

	cout<<"Co chu trinh Euler:";
	for(x=dCE; x>0; x--) // in mang ket qua
		cout<<CE[x]<<"\t";
}

int main() {
	Init();

 	if(Kiemtra()) {// neu co Euler thi tim 
 		cout << "Nhap dinh = "; cin >> u;
  		Euler();
  }
 	else cout << "\n Khong co chu trinh Euler";
}
