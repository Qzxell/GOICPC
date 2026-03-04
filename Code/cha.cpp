#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const long long INF = LLONG_MAX;

struct Edge {
    int to;
    long long weight;
};

void dijkstra(int start, const vector<vector<Edge>>& graph, vector<long long>& dist) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [current_dist, node] = pq.top();
        pq.pop();

        if (current_dist > dist[node]) continue;

        for (const auto& edge : graph[node]) {
            int neighbor = edge.to;
            long long new_dist = current_dist + edge.weight;

            if (new_dist < dist[neighbor]) {
                dist[neighbor] = new_dist;
                pq.push({new_dist, neighbor});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m, h;
        cin >> n >> m >> h;

        vector<int> horses(h);
        for (int i = 0; i < h; i++) {
            cin >> horses[i];
            horses[i]--;  // Convertir a 0-indexado
        }

        vector<vector<Edge>> graph(n);

        for (int i = 0; i < m; i++) {
            int u, v;
            long long w;
            cin >> u >> v >> w;
            u--, v--;  // Convertir a 0-indexado
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        // Distancias desde Marian (vértice 1) y desde Robin (vértice n)
        vector<long long> dist_marian(n, INF);
        vector<long long> dist_robin(n, INF);

        dijkstra(0, graph, dist_marian);   // Desde vértice 1 (Marian)
        dijkstra(n - 1, graph, dist_robin); // Desde vértice n (Robin)

        // Aplicar reducción de tiempo si hay caballos
        for (int horse_vertex : horses) {
            dist_marian[horse_vertex] /= 2;
            dist_robin[horse_vertex] /= 2;
        }

        // Encontrar el tiempo mínimo en el que Marian y Robin se pueden encontrar
        long long min_meeting_time = INF;
        for (int i = 0; i < n; i++) {
            if (dist_marian[i] != INF && dist_robin[i] != INF) {
                min_meeting_time = min(min_meeting_time, max(dist_marian[i], dist_robin[i]));
            }
        }

        if (min_meeting_time == INF) {
            cout << -1 << '\n';  // No es posible encontrarse
        } else {
            cout << min_meeting_time << '\n';  // Tiempo mínimo de encuentro
        }
    }

    return 0;
}
