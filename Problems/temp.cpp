#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int K = 20;  // log2(MAXN) + margen

int st[MAXN][K + 1]; // st[i][j] = máximo en A[i..i + 2^j - 1]
int lg[MAXN];        // log2 de cada número

void precompute_log(int N) {
    lg[1] = 0;
    for (int i = 2; i <= N; ++i)
        lg[i] = lg[i / 2] + 1;
}

void build_sparse_table(const vector<int>& A) {
    int N = A.size();
    precompute_log(N);

    for (int i = 0; i < N; ++i)
        st[i][0] = A[i];

    for (int j = 1; (1 << j) <= N; ++j) {
        for (int i = 0; i + (1 << j) <= N; ++i) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query_max(int L, int R) {
    int j = lg[R - L + 1];
    return max(st[L][j], st[R - (1 << j) + 1][j]);
}

int main() {
    // Entrada de ejemplo
    vector<int> A = {1, 5, 2, 4, 6, 1, 3, 5, 7, 3};

    // Construcción de la tabla
    build_sparse_table(A);

    // Consultas de ejemplo
    cout << "Máximo entre [2, 5]: " << query_max(2, 5) << '\n'; // → 6
    cout << "Máximo entre [0, 9]: " << query_max(0, 9) << '\n'; // → 7
    cout << "Máximo entre [7, 9]: " << query_max(7, 9) << '\n'; // → 7

    return 0;
}

