#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.rbegin(), a.rend());
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) sum += a[i];
            else {
                int add = min(a[i], k);
                sum -= (a[i] - add);
                k -= add;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
