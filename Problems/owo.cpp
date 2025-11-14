#include <bits/stdc++.h>

using namespace std;

int N, E;
vector<vector<int>> adj;
int depth[82];
int parent[82];
set<pair<int, int>> used_edges;
unsigned long long total_ways;

/**
 * Realiza una Búsqueda en Profundidad (DFS) para encontrar ciclos.
 * u: nodo actual
 * p: nodo padre (en el árbol DFS)
 * d: profundidad actual
 */
void dfs(int u, int p, int d) {
    depth[u] = d;
    parent[u] = p;

    for (int v : adj[u]) {
        if (v == p) continue; // No volver al padre inmediato

        // Arista canónica (u, v)
        pair<int, int> edge = {min(u, v), max(u, v)};

        if (depth[v] == -1) {
            // Nodo v no visitado, continuar DFS
            dfs(v, u, d + 1);
        } else if (depth[v] < depth[u]) {
            // Arista de retroceso (back-edge) a un ancestro
            // Hemos encontrado un ciclo.
            
            // Verificar si esta arista ya forma parte de un ciclo contado
            if (used_edges.count(edge)) {
                continue;
            }

            // Calcular la longitud del ciclo
            // El ciclo es u -> ... -> v -> u
            // La longitud es (profundidad[u] - profundidad[v]) + 1
            int cycle_len = (d - depth[v]) + 1;
            
            // Multiplicar al total de formas
            total_ways *= (unsigned long long)cycle_len;

            // Marcar todas las aristas de este ciclo como usadas
            used_edges.insert(edge);
            int curr = u;
            while (curr != v) {
                int par = parent[curr];
                used_edges.insert({min(curr, par), max(curr, par)});
                curr = par;
            }
        }
    }
}

void solve(int case_num) {
    cin >> N >> E;
    
    // Limpiar estructuras de datos para el nuevo caso
    adj.assign(N + 1, vector<int>());
    used_edges.clear();
    total_ways = 1;
    memset(depth, -1, sizeof(depth)); // Marcar todos como no visitados
    memset(parent, 0, sizeof(parent));

    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // El grafo es conexo, así que un solo DFS desde el nodo 1 es suficiente
    dfs(1, 0, 0); 

    cout << "Case " << case_num << ": " << total_ways << "\n";
}

int main() {
    // Optimización de I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        solve(i);
    }
    return 0;
}
