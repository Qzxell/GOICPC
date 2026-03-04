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
        vi v[3001];
        f(i,0,n){
                int x;
                cin >> x;
                v[x].pb(i+1);
        }
        int ans = 1;
        f(x,1,3001){
                int le = sz(v[x]);
                vi bui(3001,0);
                f(i,0,le)bui[v[x][i]] = 1;
                f(i,0,le){
                        f(j,i+1,le){
                                int co = 1;
                                int dis = v[x][j] - v[x][i];
                                int ind = v[x][j];
                                while(ind < 3001 and bui[ind]){
                                        co++;
                                        ind += dis;
                                }
                                ans = max(ans,co);
                        }
                }
        }
        cout << ans;
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
