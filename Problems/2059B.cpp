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
	vi v(n);
	f(i,0,n)cin >> v[i];
        int ind = 0;
        int ans = 1;
        int dis = n - k;
        f(i,1,k+1){
                if(i&1){
                        int c = 0;
                        for(;c <= dis;c++){
                                if(v[ind + c+1] != ans){
                                        cout << ans << ln;
                                        return;
                                }
                        }
                        ind++;
                }else{
                        int c = 1;
                        for(;c <= dis;c++){
                                if(v[ind + c] == ans+1){
                                        break;
                                }else{
                                        cout << ans + 1 << ln;
                                        return;
                                }
                        }
                        ind++;
                        ans++;
                }
        }
        cout << ans <<ln;
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
