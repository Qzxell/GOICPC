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
        int n,m;
        cin >> n >> m;
        vi deg(n+1,0);
        f(i,0,m){
                int u,v;
                cin >> u >> v;
                deg[u]++;deg[v]++;
        }
        map<int,int> ma;
        f(i,1,n+1)if(deg[i] != 1){
                ma[deg[i]]++;
        }
        if(sz(ma) == 1){
                int va,vb;
                for(auto [a,b] : ma){
                        va = a ; vb = b;
                }
                cout << va << ' '<< va -1 << ln;
                return;
        }
        int x,y;
        for(auto [a,b] : ma){
                if(b == 1){
                        x = a;
                }else{
                        y = a -1;
                }
        }
        cout << x << ' ' << y << ln;

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
