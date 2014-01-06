#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool found = false;
vector< vector<int> > state;

void print_state(vector<int> a){
	for (int i=0; i <= 8; i++){
		if (i%3 == 2)
			cout << a[i] << endl;
		else
			cout << a[i] << " ";
	//  cout << a[i] << " ";
	}
	cout << endl;
}

bool check_path(vector<int> a){
	bool exist = false;
	vector < vector<int> >::iterator itr;
	for (itr = state.begin(); itr != state.end(); ++itr){
		if (*itr == a){
			exist = true;
			break;
		}
	}
	if (!exist)
		state.push_back(a);
	return exist;
}

bool completeness(vector<int> a){
	bool comp = true;
	int i;
	for (i=0; i<=8; i++){
		if (a[i] != (i+1)%9)
			comp = false;
	}
	return comp;
}

void check_state(vector<int> a){
	int i;
	int p, q;
	vector<int> m;
	if (!found){
		for (i=0; i <= 8; i++){
			if (a[i] == 0){
				p = i/3;
				q = i%3;
			}
		}
		if (completeness(a)){
			//cout << "Found result" << endl;
			print_state(a);
			found = true;
		}
		else{
			print_state(a);
			cout << "----" << endl;
			if ((p+1)<=2){ // down
				m = a;
		   	m[p*3+q] = m[(p+1)*3+q];
		   	m[(p+1)*3+q] = 0;
				if (!check_path(m)){
					//cout << "down : ";
					check_state(m);
				}
			}
			if ((q+1)<=2){ // right
				m = a;
		   	m[p*3+q] = m[p*3+(q+1)];
		   	m[p*3+(q+1)] = 0;
				if (!check_path(m)){
					//cout << "right : ";
					check_state(m);
				}
			}
			if ((p-1)>=0){ // up
				m = a;
				m[p*3+q] = m[(p-1)*3+q];
				m[(p-1)*3+q] = 0;
				if (!check_path(m)){
					//cout << "up : ";
					check_state(m);
				}
			}
			if ((q-1)>=0){ // left
				m = a;
		   	m[p*3+q] = m[p*3+(q-1)];
		   	m[p*3+(q-1)] = 0;
				if (!check_path(m)){
					//cout << "left : ";
					check_state(m);
				}
			}
		}
	}
}

int main (){
	vector<int> a;

	for (int i=0; i <= 8; i++){
		int t;
		cin >> t;
		a.push_back(t);
	}

	check_state(a);

	return 0;
}

