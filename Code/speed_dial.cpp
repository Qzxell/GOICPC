#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
	int child[10];
	long long endWeight;      // sum of mi for numbers ending exactly here
	long long subtreeWeight;  // sum of mi in entire subtree
	int depth;                // length of prefix represented by this node
	TrieNode(int d = 0) : endWeight(0), subtreeWeight(0), depth(d) {
		for (int i = 0; i < 10; ++i) child[i] = -1;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	if (!(cin >> n >> k)) return 0;

	vector<TrieNode> trie;
	trie.emplace_back(0); // root at depth 0

	long long totalLenPresses = 0; // sum mi * len(si)
	long long totalCalls = 0;      // sum mi

	for (int i = 0; i < n; ++i) {
		string s; long long m;
		cin >> s >> m;
		totalCalls += m;
		totalLenPresses += (long long)s.size() * m;
		int v = 0;
		for (char ch : s) {
			int d = ch - '0';
			if (trie[v].child[d] == -1) {
				trie[v].child[d] = (int)trie.size();
				trie.emplace_back(trie[v].depth + 1);
			}
			v = trie[v].child[d];
		}
		trie[v].endWeight += m;
	}

	int V = (int)trie.size();
	vector<int> order; order.reserve(V);
	// Postorder stack to compute subtree weights and DP later
	vector<int> st = {0};
	vector<int> parent(V, -1);
	while (!st.empty()) {
		int v = st.back(); st.pop_back();
		order.push_back(v);
		for (int d = 0; d < 10; ++d) {
			int u = trie[v].child[d];
			if (u != -1) {
				parent[u] = v;
				st.push_back(u);
			}
		}
	}
	// Reverse to get postorder
	reverse(order.begin(), order.end());

	// DP arrays: F[v][t] absolute best sum of w(l)*depth(deepest selected ancestor) within subtree v using t selections.
	//            G[v][t] extra over baseline depth(v) * subtreeWeight(v) when baseline depth(v) is guaranteed.
	vector<vector<long long>> F(V, vector<long long>(k + 1, LLONG_MIN/4));
	vector<vector<long long>> G(V, vector<long long>(k + 1, LLONG_MIN/4));

	for (int v : order) {
		// compute subtreeWeight
		long long sw = trie[v].endWeight;
		for (int d = 0; d < 10; ++d) {
			int u = trie[v].child[d];
			if (u != -1) sw += trie[u].subtreeWeight;
		}
		trie[v].subtreeWeight = sw;

		// Initialize base arrays for merging
		vector<long long> g(k + 1, LLONG_MIN/4); // for G children merge
		vector<long long> h(k + 1, LLONG_MIN/4); // for F children-no-select merge
		g[0] = 0;
		h[0] = 0;

		for (int d = 0; d < 10; ++d) {
			int u = trie[v].child[d];
			if (u == -1) continue;
			vector<long long> ng(k + 1, LLONG_MIN/4);
			vector<long long> nh(k + 1, LLONG_MIN/4);
			for (int t1 = 0; t1 <= k; ++t1) if (g[t1] > LLONG_MIN/8) {
				for (int t2 = 0; t2 + t1 <= k; ++t2) {
					// For G merge: baseline is depth(v). Child contributes G[u][t2] - S(u).
					long long addG = G[u][t2];
					if (addG > LLONG_MIN/8) {
						ng[t1 + t2] = max(ng[t1 + t2], g[t1] + addG - trie[u].subtreeWeight);
					}
				}
			}
			for (int t1 = 0; t1 <= k; ++t1) if (h[t1] > LLONG_MIN/8) {
				for (int t2 = 0; t2 + t1 <= k; ++t2) {
					long long addF = F[u][t2];
					if (addF > LLONG_MIN/8) {
						nh[t1 + t2] = max(nh[t1 + t2], h[t1] + addF);
					}
				}
			}
			g.swap(ng);
			h.swap(nh);
		}

		// Build G[v]
		for (int t = 0; t <= k; ++t) G[v][t] = g[t];

		// Build F[v]: either don't select v, or select v and add baseline + children G merge
		for (int t = 0; t <= k; ++t) F[v][t] = h[t];
		long long base = (long long)trie[v].depth * trie[v].subtreeWeight;
		for (int t = 1; t <= k; ++t) {
			if (g[t - 1] > LLONG_MIN/8)
				F[v][t] = max(F[v][t], base + g[t - 1]);
		}
	}

	long long best = 0;
	for (int t = 0; t <= k; ++t) best = max(best, F[0][t]);

	long long minimalPresses = totalLenPresses - (best - totalCalls);
	cout << minimalPresses << '\n';
	return 0;
}


