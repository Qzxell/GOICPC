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

map<int,vi> m;
map<int,bool> prop;

void so(int test){
        int n;
        cin >> n;
        vi ind;
        vi v;

        int las = -1;
        f(i,0,n){
                int x;
                cin >> x;
                if(x != las)v.pb(x);
                las = x;
        }

        f(i,0,sz(v)){
                int x = v[i];
                if(m.count(x) == 0)ind.pb(x);
                m[x].pb(i);
        }
        sort(rall(ind));
        vi mark(n+1,0);
        int ans = 0;
        f(_,0,sz(ind)){
                int num = ind[_];
                for(auto in :m[num]){
                        if(!mark[in]){
                                ans++;
                                if(in + 1 <= n)mark[in+1] = 1;
                                if(in - 1 >= 0)mark[in-1] = 1;
                        }else{
                                if(in + 1 <= n)mark[in+1] = 1;
                                if(in - 1 >= 0)mark[in-1] = 1;
                        }
                }
                prop[num] = 1;
        }
        cout << ans << ln;

        m.clear();
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


