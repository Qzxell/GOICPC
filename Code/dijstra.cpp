#include <iostream>// Para usar INT_MAX
#include <vector>
#include <queue>
#include <climits>  
using namespace std;

typedef pair<int, int> pii;  // Para almacenar pares de (peso, nodo)

vector<int> dijkstra(int n, vector<vector<pii>>& adj, int inicio) {
    vector<int> dist(n, INT_MAX);  // Inicializar todas las distancias como infinitas
    priority_queue<pii, vector<pii>, greater<pii>> pq;  // Min-heap de (distancia, nodo)

    dist[inicio] = 0;
    pq.push({0, inicio});  // La distancia del nodo inicial es 0

    while (!pq.empty()) {
        int d = pq.top().first;  // Distancia mínima
        int u = pq.top().second; // Nodo con esa distancia
        pq.pop();

        // Si la distancia actual no es mejor, continuamos
        if (d > dist[u]) continue;

        // Relajación de las aristas adyacentes
        for (auto& edge : adj[u]) {
            int peso = edge.first;
            int v = edge.second;

            if (dist[u] + peso < dist[v]) {
                dist[v] = dist[u] + peso;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;  // n: número de nodos, m: número de aristas
    vector<vector<pii>> adj(n);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});  // Agregar arista (u -> v) con peso w
        adj[v].push_back({w, u});  // Si el grafo es no dirigido
    }

    int inicio;
    cin >> inicio;

    vector<int> dist = dijkstra(n, adj, inicio);

    // Imprimir distancias desde el nodo de inicio
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INT_MAX) {
            cout << "INF" << " ";
        } else {
            cout << dist[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
