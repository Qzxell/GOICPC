#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> G;
vector<int> parent_, color_;     // 0=blanco, 1=gris, 2=negro
vector<int> best_cycle;

// rota 'cy' para que su representación sea la mínima lexicográfica
static void rotate_to_min(vector<int>& cy) {
    int k = (int)cy.size();
    int best = 0;
    for (int i = 1; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            int a = cy[(i + j) % k];
            int b = cy[(best + j) % k];
            if (a < b) { best = i; break; }
            if (a > b) { break; }
        }
    }
    rotate(cy.begin(), cy.begin() + best, cy.end());
}

// canónica: mínima entre todas las rotaciones de ambas direcciones
static vector<int> canonical_cycle(vector<int> cy) {
    vector<int> a = cy, b = cy;
    rotate_to_min(a);
    reverse(b.begin(), b.end());
    rotate_to_min(b);
    // elegir la menor; si empatan por prefijo, preferir la más corta
    int la = (int)a.size(), lb = (int)b.size();
    for (int i = 0; i < min(la, lb); ++i) {
        if (a[i] < b[i]) return a;
        if (a[i] > b[i]) return b;
    }
    return (la <= lb) ? a : b;
}

static bool lex_less(const vector<int>& a, const vector<int>& b) {
    int la = (int)a.size(), lb = (int)b.size();
    for (int i = 0; i < min(la, lb); ++i) {
        if (a[i] != b[i]) return a[i] < b[i];
    }
    return la < lb; // prefijo más corto es menor
}

void dfs(int u, int p) {
    color_[u] = 1;         // gris
    parent_[u] = p;

    for (int v : G[u]) if (v != p) {
        if (color_[v] == 1) {
            // back-edge a un ancestro => hay ciclo
            int cur = u;
            vector<int> cy;
            while (cur != v) { cy.push_back(cur); cur = parent_[cur]; }
            cy.push_back(v);

            vector<int> can = canonical_cycle(cy);
            if (best_cycle.empty() || lex_less(can, best_cycle)) {
                best_cycle = move(can);
            }
        } else if (color_[v] == 0) {
            dfs(v, u);
        }
    }

    color_[u] = 2;         // negro
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n >> m)) return 0;
    G.assign(n + 1, {});
    parent_.assign(n + 1, -1);
    color_.assign(n + 1, 0);
    best_cycle.clear();

    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    // (opcional) ordenar adyacencias no afecta la corrección
    for (int i = 1; i <= n; ++i) sort(G[i].begin(), G[i].end());

    for (int i = 1; i <= n; ++i)
        if (color_[i] == 0) dfs(i, -1);

    if (best_cycle.empty()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << (int)best_cycle.size() << "\n";
        for (int i = 0; i < (int)best_cycle.size(); ++i) {
            if (i) cout << ' ';
            cout << best_cycle[i];
        }
        cout << "\n";
    }
    return 0;
}

