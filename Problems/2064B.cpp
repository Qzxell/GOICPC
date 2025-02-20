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
	vi freq(n+1,0);
	f(i,0,n)cin >> v[i],freq[v[i]] += 1;
	bool yes = 1;
	f(i,1,n+1)if(freq[i] == 1)yes = 0; 
	if(yes){
		cout << 0 << ln;
		return;
	}
	ii ans ;
	bool fir = 1;
	int i = 0;
	while(i <n){
		int co = i;
		if(freq[v[i]] == 1){
			while(i+1 < n and freq[v[i+1]] == 1)i++;
			if(fir)ans = {co+1,i+1},fir = 0;
			else{
				if(i - co > ans.se - ans.fi){
					ans = {co+1,i+1};
				}
			}
		}

		i++;
	}
	cout << ans.fi << ' ' << ans.se << ln;

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
