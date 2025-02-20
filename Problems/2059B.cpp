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
	int ans = 0;
	int expain = n - k;
	int in = 0;
	int pro = 1;
	bool yes = 0;
	set<int> ans<D-v><D-d
	while(in < n){
		if(pro){
			for(int i = in; i <= min(n-1,in+expain);i++){
				int nex = (i+1 == n ? 0 : v[i+1]);
				if(nex != 1 + ans){
					ans++;
					yes = 1;
					break;
				}
			}
		}else{
			for(int i = in; i <= min(n-1,in+expain);i++){
				if(v[i] == i - in + ans + 1){
					ans = v[i];
					break;
				}else if(i - in == 0){
					ans = i - in + ans + 1;
					yes = 1;
					break;
				}
			}
			
		}
		if(yes)break;
		pro ^= 1;
		in++;
	}
	if(!yes) ans ++;
	cout << ans << ln;

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
