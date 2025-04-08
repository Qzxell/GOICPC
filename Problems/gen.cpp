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

    uniform_int_distribution<int> dist(0, 10);
    int n = dist(rng);
    cout << (1<<n) << ln;
    uniform_int_distribution<int> owo(1,(1<<n));
    cout << owo(rng) << ' ' << owo(rng) << ln;
    return 0;
}
