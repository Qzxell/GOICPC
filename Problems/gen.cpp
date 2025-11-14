#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <map>

using namespace std;

// Función para obtener una arista canónica (menor, mayor)
pair<int, int> make_edge(int u, int v) {
    return {min(u, v), max(u, v)};
}

int main() {
    // Inicializar el generador de números aleatorios
    srand(time(0));

    int N, C;
    N = 13;
    C = 13;

    if (N < 3) {
        cerr << "Error: N debe ser al menos 3." << endl;
        return 1;
    }

    cout << 1 << '\n';
    vector<vector<int>> adj(N + 1);
    vector<pair<int, int>> edges;
    // Almacena las aristas que ya pertenecen a un ciclo
    set<pair<int, int>> cycle_edges;

    // --- Fase 1: Generar un árbol aleatorio ---
    // Conecta cada nuevo nodo (i) a un nodo ya existente (aleatorio de 1 a i-1)
    for (int i = 2; i <= N; ++i) {
        // Vértice existente al que nos conectaremos
        int u = 1 + (rand() % (i - 1));
        int v = i; // Nuevo vértice

        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }

    // --- Fase 2: Añadir C ciclos ---
    int cycles_added = 0;
    int max_tries = N * N * 2; // Límite de intentos para evitar bucles infinitos
    int tries = 0;

    while (cycles_added < C && tries < max_tries) {
        tries++;

        // 1. Elegir dos vértices aleatorios no adyacentes
        int u = 1 + (rand() % N);
        int v = 1 + (rand() % N);

        if (u == v) continue;

        // Comprobar si ya son adyacentes
        bool adjacent = false;
        for (int neighbor : adj[u]) {
            if (neighbor == v) {
                adjacent = true;
                break;
            }
        }
        if (adjacent) continue;

        // 2. Encontrar el camino entre u y v (BFS)
        queue<int> q;
        map<int, int> parent; // parent[hijo] = padre
        vector<bool> visited(N + 1, false);

        q.push(u);
        visited[u] = true;
        parent[u] = 0; // Raíz

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (curr == v) break; // Camino encontrado

            for (int neighbor : adj[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    parent[neighbor] = curr;
                    q.push(neighbor);
                }
            }
        }
        
        // 3. Verificar si el camino es "limpio" (no usa aristas de ciclo)
        bool path_is_clean = true;
        vector<pair<int, int>> path_edges;
        
        int curr = v;
        while (curr != u) {
            int p = parent[curr];
            if (p == 0) { // No debería pasar si el grafo está conectado
                path_is_clean = false; 
                break;
            }
            
            pair<int, int> path_edge = make_edge(curr, p);
            
            if (cycle_edges.count(path_edge)) {
                path_is_clean = false; // Esta arista ya está en un ciclo
                break;
            }
            path_edges.push_back(path_edge);
            curr = p;
        }

        // 4. Si es limpio, añadir el ciclo
        if (path_is_clean) {
            // Añadir la nueva arista (u, v)
            adj[u].push_back(v);
            adj[v].push_back(u);
            pair<int, int> new_edge = make_edge(u, v);
            edges.push_back({u, v});

            // Marcar todas las aristas del nuevo ciclo como "usadas"
            cycle_edges.insert(new_edge);
            for (const auto& edge : path_edges) {
                cycle_edges.insert(edge);
            }
            
            cycles_added++;
            tries = 0; // Reiniciar contador de intentos
        }
    }

    // --- Fase 3: Imprimir el grafo generado ---
    cout << "\n--- Grafo Cactus Generado ---" << endl;
    cout << N << " " << edges.size() << endl;
    for (const auto& edge : edges) {
        cout << edge.first << " " << edge.second << endl;
    }

    if (cycles_added < C) {
        cerr << "\nAdvertencia: Solo se pudieron anadir " << cycles_added
             << " de los " << C << " ciclos solicitados (limite de intentos alcanzado)." << endl;
    }

    return 0;
}
