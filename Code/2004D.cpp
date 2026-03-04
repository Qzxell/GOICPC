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
        vector<string> v(n);
        map<string,vi> m;
        f(i,0,n){
                cin >> v[i];
                if(v[i][0] > v[i][1])swap(v[i][0],v[i][1]);
                m[v[i]].pb(i);
        }
        auto eq = [&](int x,int y)->bool{
                f(i,0,2) f(j,0,2){
                        if(v[x][i] == v[y][j])return true;
                }
                return false;
        };
        f(_,0,q){
                int x,y;
                cin >> x >> y;
                x--;y--;
                if(eq(x,y)){
                        cout << abs(x-y) << ln;
                        continue;
                }
                if(x > y)swap(x,y);
                int ans = INT_MAX;
                f(i,0,2) f(j,0,2){
                        string ga;
                        ga += v[x][i] ;
                        ga += v[y][j];
                        if(ga[0] > ga[1])swap(ga[1],ga[0]);
                        if(sz(m[ga]) == 0)continue;
                        int pun = lower_bound(all(m[ga]),x) - m[ga].begin();
                        int id;
                        if(pun != sz(m[ga])){
                                id = m[ga][pun];
                                ans = min(ans, abs(id - x) + abs(y-id));
                        }
                        if(pun-1 >= 0 and !m[ga].empty()){
                                id = m[ga][pun-1];
                                ans = min(ans, abs(id - x) + abs(y-id));
                        }
                }
                if(ans == INT_MAX){
                        cout << -1 << ln;
                        continue;
                }
                cout << ans << ln;
        }

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


