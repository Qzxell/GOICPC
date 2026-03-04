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
        string s;
        cin >> s;
        vi ps(n+1,0);
        vi ans(n,-1);
        vi ind;
        f(i,1,n+1){
                if(s[i-1] == '1')ind.pb(i-1);
                ps[i] = ps[i-1] + (s[i-1] == '1');
        }
        f(i,0,n){
                if(i+k > n)break;
                if(ps[i+k] - ps[i] == k){
                        cout << "NO" << ln;
                        return;
                }
        }
        int num = 1;
        f(i,0,sz(ind))ans[ind[i]] = num++;
        f(i,0,n)if(ans[i] == -1)ans[i] = num++;
        cout << "YES"<< ln;
        f(i,0,n)cout << ans[i] <<  ' ';
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


