#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randint(int l, int r) {
    uniform_int_distribution<int> dist(l, r);
    return dist(rng);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; // número de testcases (ajústalo)
    cout << t << "\n";

    int total_n = 0, total_q = 0;

    for (int tc = 0; tc < t; tc++) {
        int n = randint(5, 10);   // tamaño del array (ajusta a tu gusto)
        int q = randint(5, 10);   // número de queries

        total_n += n;
        total_q += q;

        cout << n << " " << q << "\n";

        // generar array inicial
        for (int i = 1; i <= n; i++) {
            cout << randint(1, 1000000) << (i == n ? "\n" : " ");
        }

        bool has_type2 = false;

        // generar queries
        for (int i = 0; i < q; i++) {
            int type;
            if (!has_type2 && i == q-1) {
                type = 2; // forzar al menos una query de tipo 2
            } else {
                type = randint(1, 2);
            }

            if (type == 1) {
                int l = randint(1, n);
                int r = randint(l, n);
                cout << "1 " << l << " " << r << "\n";
            } else {
                int x = randint(1, n);
                cout << "2 " << x << "\n";
                has_type2 = true;
            }
        }
    }

    cerr << "Generado con total_n=" << total_n 
         << " total_q=" << total_q << "\n";
}

