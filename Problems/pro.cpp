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

const int N = 100005;
vi adj[N];
vi v_(N,0);// quien es me leder
vi ans;
int pos = 1;
int leder = 1;
           //
void cic(int ro){
        v_[ro] = 1;
        for(auto x : adj[ro]){
                if(v_[x] == 0){
                        cic(x);
                }else{
                        if(v_[x] == 1){
                                pos = 0;
                        }
                }
        }
        ans.pb(ro);
        v_[ro] = 2;
}


void so(int test){
        int n,k;
        cin >> n >> k;
        vi ned(k);
        f(i,0,k)cin >> ned[i];

        f(i,1,n+1){
                int x;
                cin >> x;
                f(j,0,x){
                        int v;
                        cin >> v;
                        adj[i].pb(v);
                }
        }
        int co = 1;
        for(int x : ned){
                if(!v_[x])cic(x);
        }
        if(!pos){
                cout << -1 << ln;
                return;
        }
        cout << sz(ans) << ln;
        for(auto x: ans){
                cout << x << ' ';
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
