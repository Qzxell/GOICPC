#include<bits/stdc++.h>


using namespace std;

int main(){
	int n;
	cin >> n;
	int dif = 710;
	int cur = -25000*dif;
	for(int i = 0 ; i < n ; i++){
		cout << cur + i*dif << ' ';
	}
	cout << '\n';

	return 0;
}
