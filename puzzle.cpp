#include <iostream>

using namespace std;

bool found = false;

void print_state(int a[9]){
	for (int i=0; i <= 8; i++){
		if (i%3 == 2)
			cout << a[i] << endl;
		else
			cout << a[i] << " ";
	}
}

void check_state(int a[9], bool s[9]){
	int i;
	int p, q;
	int m[9];
	bool n[9];
	int tmp;
	if (!found){
		for (i=0; i <= 8; i++){
			if (a[i] == 0){
				p = i/3;
				q = i%3;
			}
		}
		if ((a[0] == 1) && (a[1] == 2) && (a[2] == 3) &&
				(a[3] == 4) && (a[4] == 5) && (a[5] == 6) &&
				(a[6] == 7) && (a[7] == 8) && (a[8] == 0)) {
			print_state(a);
			found = true;
		}
		else{
			print_state(a);
			cout << "----" << endl;
			if (((p-1)>=0) && (s[(p-1)*3+q] == false)){
				for (int x=0; x<=8; x++){
					m[x] = a[x];
					n[x] = s[x];
				}
				m[p*3+q] = m[(p-1)*3+q];
				m[(p-1)*3+q] = 0;
				//n[(p-1)*3+q] = true;
				check_state(m, n);
			}
			if (((p+1)<=2) && (s[(p+1)*3+q] == false)){
				for (int x=0; x<=8; x++){
					m[x] = a[x];
					n[x] = s[x];
				}
				m[p*3+q] = m[(p+1)*3+q];
				m[(p+1)*3+q] = 0;
				//n[(p+1)*3+q] = true;
				check_state(m, n);
			}
			if (((q-1)>=0) && (s[p*3+(q-1)] == false)){
				for (int x=0; x<=8; x++){
					m[x] = a[x];
					n[x] = s[x];
				}
				m[p*3+q] = m[p*3+(q-1)];
				m[p*3+(q-1)] = 0;
				//n[p*3+(q-1)] = true;
				check_state(m, n);
			}
			if (((q+1)<=2) && (s[p*3+(q+1)] == false)){
				for (int x=0; x<=8; x++){
					m[x] = a[x];
					n[x] = s[x];
				}
				m[p*3+q] = m[p*3+(q+1)];
				m[p*3+(q+1)] = 0;
				//n[p*3+(q+1)] = true;
				check_state(m, n);
			}
		}
	}
}

int main (){
	int a[9];
	bool s[9];

	for (int i=0; i <= 8; i++){
		cin >> a[i];
		s[i] = false;
	  // if (a[i] == 0)
	  // 	s[i] = true;
	  // else
	  // 	s[i] = false;
	}

	check_state(a, s);

	return 0;
}

