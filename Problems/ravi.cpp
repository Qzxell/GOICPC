#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int l, r;
    cin >> l >> r;
    // l == 0;
    vector<int> res(r + 1, -1);
    for (int i = r; i >= l; --i) {
        if (res[i] != -1) continue;
        if (i == 0) {
            res[i] = 0;
            continue;
        }
        int bit = -1;
        for (int j = 30; j >= 0; j--) {
            if ((i >> j) & 1) {
                bit = j + 1;
                break;
            }
        }
        int tmp = (1 << bit) - 1;
        res[i] = tmp - i;
        res[tmp - i] = i;
    }
    i64 ans = 0;
    for (int i = 0; i <= r; ++i) {
        ans += (i | res[i]);
    }
    cout << ans << "\n";
    for (int i = 0; i <= r; ++i) {
        cout << res[i] << " \n"[i == r];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


 
