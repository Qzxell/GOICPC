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

void so(int test){
        int n,d;
        cin >> n >> d;
        vii v(n);
        f(i,0,n){
                int a,b;
                cin >>a >> b;
                v[i].fi = a;
                v[i].se = b;
        }
        f(i,1,d+1){
                ll ma = 0;
                f(j,0,n){
                        ma = max(ma,v[j].fi*(v[j].se+i));
                }
                cout << ma << ln;
        }
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}
