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
        int n,q;
        cin >> n >> q;
        vi a(n);vi b(n);
        ll tot = 0;
        f(i,0,n)cin >> a[i];
        f(i,0,n)cin >> b[i];
        f(i,0,n){
                tot += min(a[i],b[i]);
        }
        f(i,0,q){
                char op;
                cin >> op;
                int x,v;
                cin >> x >> v;
                x--;
                if(op == 'A'){
                        tot -= min(a[x],b[x]);
                        a[x] = v;
                        tot += min(a[x],b[x]);
                        cout << tot << ln;
                }else{
                        tot -= min(a[x],b[x]);
                        b[x] = v;
                        tot += min(a[x],b[x]);
                        cout << tot << ln;
                }
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
