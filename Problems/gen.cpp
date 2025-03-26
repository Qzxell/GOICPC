#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using vii = vector<ii>;
using vi = vector<int>;

#define ln '\n'
#define ll long long
#define pb push_back
#define fi first
#define se second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define f(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a) for (ll i = (ll)a - 1; i >= (ll)b; i--)

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    uniform_int_distribution<int> dist(10, 20);
    int n = dist(rng);
    // Generate numbers from 1 to n to allow exactly n unique elements
    uniform_int_distribution<int> dis(1, n); // Fixed range

    set<int> s;
    while(sz(s) < n) {
        s.insert(dis(rng));
    }
    cout <<100 << ' '<< n << ln;
    for(auto x : s) cout << x << ' ';
    cout << ln;

    set<int> ss;
    f(i,0,n) {
        int wa = dist(rng); // wa between 10-20
        ss.clear();
        // Create a new distribution with enough range for wa elements
        uniform_int_distribution<int> ss_dis(1, 2*wa); // Ensures sufficient range
        while(sz(ss) < wa) {
            ss.insert(ss_dis(rng));
        }
        cout << wa << ' ';
        for(int d : ss) cout << d << ' ';
        cout << ln;
    }

    return 0;
}
