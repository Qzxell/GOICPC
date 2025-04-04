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

    uniform_int_distribution<int> dist(6, 7);
    cout << 1 << ln;
    int n = dist(rng);
    uniform_int_distribution<int> dis(1, n); // Fixed range
        cout << n << ln;
        vi v(2*n);
        f(i,0,n){
                v[i] = dis(rng);
        }
        sort(all(v));
        f(i,0,n){
                cout << v[i] << ' ';
        }


    return 0;
}
