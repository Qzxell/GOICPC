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
        int n,k;
        cin >> n >> k;
        int lo = 0;
        int lf = 2e5;
        vi v(n);
        f(i,0,n)cin >> v[i];

        vector<int> vis(lf+1,0);
        auto can = [&](int x) -> bool {
                int cnt = 0;
                int mex = 0;
                for (int i = 0; i < n; i++) {
                        if(v[i] < x) vis[v[i]] = 1;
                        while (vis[mex]) mex++;
                        if (mex >= x) {
                                cnt++;
                                f(j,0,x+1)vis[j] = 0;
                                mex = 0;
                        }
                }
                                f(j,0,x+1)vis[j] = 0;
                return cnt >= k;
        };
        int mid ;
        while(lo < lf){
                mid = (lo+lf+1)/2;
                if(can(mid)){
                        lo = mid;
                }else{
                        lf = mid-1;
                }
        }
        cout << lo  << ln;
                
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
