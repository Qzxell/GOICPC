#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>  ;
using vi = vector<int>  ;
#define ln  '\n'
#define ll long long int
#define pb push_back
#define fi first
#define se second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define f(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)

ll rec(ll N){
        if(N <= 0)return 0;
        ll r = N%10;
        return (N/10)*1ll * 45 + 0ll + (r*1ll*(r+1))/2 + rec(N/10);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	int test = 1;
	while (true){
                ll n,m;
                cin >> n >> m;
                if(n<0 and m<0){
                        break;
                }
                if(test++ > 1)cout << '\n';
                ll fu = rec(m) - rec(n-1);
                cout << fu ;
	}
	return 0;
}
