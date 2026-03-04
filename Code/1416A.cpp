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
        vector<vi> ind(n+1);
        f(i,0,n){
                int nu;
                cin >> nu;
                ind[nu].pb(i);
        }
        vi ans(n+1,-1);
        int ul = n;
        f(i,0,n+1){
                if(ind[i].empty())continue;
                int ma = ind[i][0]+1;
                f(j,1,sz(ind[i])){
                        ma = max(ma,ind[i][j] - ind[i][j-1]);
                }
                ma = max(n-ind[i].back(),ma);
                f(j,ma,ul+1){
                        ans[j] = i;
                }
                if(ma -1 < ul) ul = ma-1;
        }
        f(i,1,n+1){
                cout << ans[i] << ' ';
        }
        cout << ln;
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
