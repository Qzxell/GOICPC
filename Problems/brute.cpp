#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#ifdef LOCAL
#include "/home/pouya/dev/cp/lib/debug.cpp"
#else
#define dbg(...)
#define TC solve
#endif
#define nl '\n'

void solve(int tc) {
    int n, q; cin>> n >> q;
    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    vector<int> pos(n);
    iota(pos.begin(), pos.end(), 0);
    vector<int> at(n);
    iota(at.begin(), at.end(), 0);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int a, b; cin >> a >> b;
            a--, b--;
            // what maps to b?
            at[a] = pos[b];
        } else if (t == 2) {
            int a, b; cin >> a >> b;
            a--, b--;
            swap(id[pos[a]], id[pos[b]]);
            swap(pos[a], pos[b]);
        } else {
            int a; cin >> a;
            a--;
            cout << id[at[a]]+1 << nl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    for (int i=1; i<=t; i++) {
        TC(i);
    }
    return 0;
}

