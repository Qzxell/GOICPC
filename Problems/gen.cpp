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

    uniform_int_distribution<int> nn(2, 10);
    uniform_int_distribution<int> ww(1, 20);
    uniform_int_distribution<int> WW(1, 30);
    uniform_int_distribution<int> vv(1, 20);
    int n = nn(rng);
    cout << n << ' ' << WW(rng)<< ln;
    f(i,0,n){
            cout << vv(rng) << ' ' << ww(rng) << ln;
    }
    return 0;
}
