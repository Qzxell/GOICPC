#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    ll max_a = 0;
    ll max_b = 0;

    for (int i = 0; i < n; i++) {
        ll next_a = max(max_a, max_b + a[i]);
        ll next_b = max(max_b, max_a + b[i]);
        
        max_a = next_a;
        max_b = next_b;
    }

    cout << max(max_a, max_b) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    while (tt--) {
        solve();
    }
    return 0;
}
