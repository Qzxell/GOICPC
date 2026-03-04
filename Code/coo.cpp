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
        int n;
        cin >> n;
        vector<tuple<int,int,int>> st[n+1];
        int lon = 0;
        f(i,0,n){
                int a,b,c;
                cin >> a >> b >> c;
                tuple<int,int,int> ga = {a,b,c};
                if(lon == 0){
                        st[lon].pb(ga);
                        lon++;
                }else{
                        bool yes = 0;
                        f(i,0,lon){
                                for(auto [aa,bb,cc] : st[i]){
                                        if((aa > a and bb  > b and cc > c)or(aa < a and bb  < b and cc < c)){
                                                st[i].pb(ga);
                                                yes = 1;
                                                break;
                                        }
                                }
                        }
                        if(!yes){
                                st[lon].pb(ga);
                                lon++;
                        }
                }
        }
        int ans = 0;
        f(i,0,lon){
                ans = max(ans,sz(st[i]));
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
