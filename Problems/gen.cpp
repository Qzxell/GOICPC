#include <bits/stdc++.h>

using namespace std;

int ale(int rng){
        return 1 + (rand() % rng); 
}

int main() {
        srand(time(0));

	int n = 2147483647;
	cout << 1 << '\n';
	cout << ale(n) << '\n';

    return 0;
}
