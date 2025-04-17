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
        vector<vi> ma(n,vi(n));
        vector<vi> ps(n+1,vi(n+1));

        f(i,0,n) f(j,0,n)cin >> ma[i][j];

        f(i,0,n+1)
                ps[i][0] = 0;

        f(i,1,n+1) f(j,1,n+1){
                ps[i][j] = ma[i-1][j-1] + ps[i][j-1];
        }
        auto kadane = [&](int l, int r){
                int ret = -1e9;
                int last = 0;
                for(int i = 0;i < n ; i++){
                        int cur = ps[i+1][r] - ps[i+1][l-1];
                        if(last < 0){
                                ret = max(ret,cur);
                                last = cur;
                        }else{
                                last += cur;
                                ret = max(ret,last);
                        }
                }
                return ret;
        };

        int ans = -1e9;
        f(i,1,n+1) f(j,i+1,n+1){
                ans = max(ans,kadane(i,j));
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
