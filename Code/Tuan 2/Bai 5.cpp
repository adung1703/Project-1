#include <bits/stdc++.h>
using namespace std;
int a[9][9];
int n = 0;
bool check (int v, int r, int c){ //Co the dien gia tri v vao a[r][c] khong
	for (int i = 0; i < 9; i++) {
		if (a[r][i] == v) return false; //Check theo hang
		if (a[i][c] == v) return false; //Check theo cot
	}
	
	for (int i = r/3*3; i < r/3*3+3; i++) { //Check theo o 3x3
		for (int j = c/3*3; j < c/3*3+3; j++) if (a[i][j] == v) return false;
	}
	return true;
}
void TRY(int r, int c){
	if(r==8 && c==8) {
		n++; //Neu la o cuoi cung (gia tri se la duy nhat)
		return;
	}
	if(a[r][c] != 0) { //Neu o nay da duoc dien
		if (c==8) TRY(r+1, 0); //Duyet o tiep theo
		else TRY(r,c+1);
	}
	else {
		for (int i = 1; i <= 9; i++) { //Gia tri can dien vao o la i
			if (check(i,r,c)) { //Neu dien duoc
				a[r][c] = i;
				if (c==8) TRY(r+1, 0);
				else TRY(r,c+1);
				a[r][c] = 0; //Quay lui 
			}
		}
	}
}
int main(){
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) cin >> a[i][j];
	}
	TRY(0,0);
	cout << n;
}

