
#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define ll long long

// Exponenciación rápida O(log exp)
ll fastpow(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

ll count_beautiful_subsequences(vector<int>& a) {
    int n = a.size();
    
    vector<int> pos_1, pos_3, prefix_2(n + 1, 0);
    
    // Preprocesar posiciones de 1, 3 y prefijo de 2s
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) pos_1.push_back(i);
        if (a[i] == 3) pos_3.push_back(i);
        prefix_2[i + 1] = prefix_2[i] + (a[i] == 2);
    }

    if (pos_1.empty() || pos_3.empty()) return 0;

    ll total = 0;
    ll acumulado = 0;  // Guarda respuestas previas para evitar recalcular

    int j = pos_3.size() - 1; // Último `3`

    // Recorremos los `1`s de atrás hacia adelante
    for (int i = pos_1.size() - 1; i >= 0; i--) {
        int idx_1 = pos_1[i];

        // Mover `j` hacia atrás hasta que `3[j] > 1[i]`
        while (j >= 0 && pos_3[j] > idx_1) j--;

        if (j == -1) break; // No hay más `3`s disponibles

        int idx_3 = pos_3[j + 1]; // Primer `3` a la derecha del `1`
        int num_2 = prefix_2[idx_3] - prefix_2[idx_1 + 1];

        if (num_2 > 0) {
            ll nuevos = fastpow(2, num_2, MOD) - 1;
            total = (total + nuevos + acumulado) % MOD;
            acumulado = (acumulado * fastpow(2, num_2, MOD) + nuevos) % MOD;
        }
    }

    return total;
}

int main() {
	int tt;
	cin >> tt;
	while(tt--){
		int n;
		cin >> n;
		vector<int> a(n);
		for(auto &x : a )cin >> x;
		    cout << count_beautiful_subsequences(a) << endl;
	}
    return 0;
}
