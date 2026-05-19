#include <bits/stdc++.h>

using namespace std;

int ale(int rng){
        return 0 + (rand() % rng); 
}

int main() {
        srand(time(0));

	int q= 1000;
	cout << q << '\n';
	while(q--){
		int n = 10000;
		cout << ale(n) << ' ';
		cout << ale(n) << ' ';
		cout << ale(n) << '\n';
	}

    return 0;
}
