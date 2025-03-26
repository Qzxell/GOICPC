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
	int n,q;
	cin >> n >> q;
	vi freq(n+1,1);
	vi wh(n+1,0);
	f(i,1,n+1)wh[i] = i;

	int ans = 0;
	while(q--){
		int ty,a,b;
		cin >> ty;
		if(ty == 1){
			cin >>a>> b;
			int cur = wh[a];
			wh[a] = b;
			if(freq[cur] > 1 and freq[cur] -1 <= 1)ans--;
			freq[cur]--;
			if(freq[b] <= 1 and freq[b]+1>1 )ans++;
			freq[b]++;
		}else{
			cout << ans << ln;
		}
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
