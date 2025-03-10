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

// Random number generator
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    uniform_int_distribution<int> dist(10, 20);
    int n = dist(rng);
    int q = dist(rng);
    uniform_int_distribution<int> owo(1, 3);
    f(i,0,q){
	    int ty = owo(rng);
	    cout << ty << ' ';
	    if(ty == 1){
		    int a,b;
		    a = dist(rng);
		    b = dist(rng);
		    cout << a << ' ' << b << ln;
	    }
	    if(ty == 2){
		    int a,b;
		    a = dist(rng);
		    b = dist(rng);
		    while(b!=a)b=dist(rng);
		    cout << a << ' ' << b << ln;
	    }
	    if(ty==3){
		    cout << dist(rng)<<ln;
	    }
    }

    return 0;
}
