#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    // Adyacencia con IDs: adj[u] = { (v, edge_id) }
    vector<vector<pair<int,int>>> adj(N);
    adj.reserve(N);

    for (int i = 0; i < M; ++i) {
        int u, v; 
        cin >> u >> v;        // 0 <= u, v < N
        adj[u].push_back({v, i});
    }

    vector<char> vis(N, 0), in_stk(N, 0);
    vector<int> par_v(N, -1), par_e(N, -1);  // par_e[x] = id de arista (par_v[x] -> x)

    vector<int> cycle; 
    bool found = false;

    function<void(int)> dfs = [&](int u) {
        vis[u] = 1;
        in_stk[u] = 1;

        for (auto [v, eid] : adj[u]) {
            if (found) return;                 // cortar todo al hallar un ciclo
            if (!vis[v]) {
                par_v[v] = u;
                par_e[v] = eid;
                dfs(v);
            } else if (in_stk[v]) {
                // back-edge: u -> v, v está en la pila => hay ciclo
                vector<int> tmp;
                int cur = u;
                // recoger aristas desde u hacia v subiendo por padres (u->..., ..., -> v)
                while (cur != v) {
                    tmp.push_back(par_e[cur]); // arista (par_v[cur] -> cur)
                    cur = par_v[cur];
                }
                reverse(tmp.begin(), tmp.end()); // ahora va de v -> ... -> u
                tmp.push_back(eid);              // cerrar con (u -> v)
                cycle = move(tmp);
                found = true;
                return;
            }
        }

        in_stk[u] = 0;
    };

    for (int i = 0; i < N && !found; ++i) {
        if (!vis[i]) {
            par_v[i] = -1;
            par_e[i] = -1;
            dfs(i);
        }
    }

    if (!found) {
        cout << -1 << '\n';
        return 0;
    }

    cout << (int)cycle.size() << '\n';
    for (int i = 0; i < (int)cycle.size(); ++i) {
        cout << cycle[i] << '\n';
    }
    return 0;
}

