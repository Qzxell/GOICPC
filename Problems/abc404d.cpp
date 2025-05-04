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
        vi cost(n);// cost of zoo i
        f(i,0,n)cin >> cost[i];

        vi zoo_animal[n];// by animal

        f(i,0,m){
                int cant_zoo ;
                cin >> cant_zoo;
                f(j,0,cant_zoo){
                        int zoo;
                        cin >> zoo;
                        zoo--;
                        zoo_animal[zoo].pb(i);
                }
        }
        ll ans = 1e17;
        f(mask,0,(1<<(2*n))){
                vi freq(m);
                ll all_cost = 0;
                f(j,0,2*n)if((mask>>j)&1){
                        int ne = j % n;
                        all_cost += cost[ne];
                        int le = sz(zoo_animal[ne]);
                        f(k,0,le){
                                freq[zoo_animal[ne][k]]++;
                        }
                }
                bool yes = 1;
                f(i,0,m){
                        if(freq[i] < 2)yes = 0;
                }
                if(yes){
                        ans = min(all_cost,ans);
                }
        }
        cout << ans << ln;

	
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
