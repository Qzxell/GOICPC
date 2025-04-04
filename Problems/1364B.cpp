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
        vi v(n);
        f(i,0,n)cin >> v[i];
        if(n == 2){
                cout << 2 << ln;
                cout << v[0] << ' ' << v[1] << ln;
                return;
        }
        vi ans ;
        ans.pb(v[0]);
        ans.pb(v[1]);
        int num = v[1];
        int dir = (v[0] < v[1] ? 1 : 0);
        f(i,2,n){
                if((v[i-1] < v[i]) == dir){
                        ans[sz(ans)-1] = v[i];
                }else{
                        ans.pb(v[i]);
                        dir ^= 1;
                }
        }
        cout << sz(ans) << ln;
        for(auto x :ans)cout << x << ' ';
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
