#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>  ;
using vi = vector<int>  ;
#define ln  '\n'
#define ll long long
#define pb push_back
#define fi first
#define se second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define f(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)

const int N = 5005;
unordered_set<int> S[N];

void so(int test){
        int n;
        cin >> n;
        vi v(n);
        int gc = 0;
        f(i,0,n){
                cin >> v[i];
                gc = gcd(gc,v[i]);
        }
        f(i,0,n) v[i] /= gc;

        int un = 0;
        f(i,0,n){
                if(v[i] == 1)un++;
        }
        if(un){
                cout << n - un  << ln;
                return;
        }

        int ans = n-1 + n -1;

        f(i,0,n){
                int fi = -1;
                for(int len = i; len >= 0;len-- ){
                        for(auto x : S[len]){
                                if(x == 1)fi = len;
                                S[len+1].insert(gcd(x,v[i]));
                                if(gcd(x,v[i]) == 1)fi = len+1;
                        }
                }
                S[1].insert(v[i]);
                if(fi != -1){
                        ans = min(ans,fi-1+n-1);
                }
        }
        f(i,0,n+2)S[i].clear();

        cout << ans << ln;

	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	cin >> tt;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}
