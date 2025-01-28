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
	string s;
	cin >> s;
	int n = sz(s);
	vi v(4,0);
	int in = 0, fi = 0;
	f(i,0,n){
		if(v[1] and v[2] and v[3])break;
		v[s[i] - '0']++;
		fi = i;
	}
	if(!(v[1] and v[2] and v[3])){
		cout << 0 << ln;
		return;
	}
	int ans = fi - in +1;
	while(in + 1 < n ){
		v[s[in++] - '0']--;
		while(fi + 1 < n and !(v[1] and v[2] and v[3])){
			v[s[++fi]-'0']++;
		}
		if(!(v[1] and v[2] and v[3]))break;
		ans = min(ans,fi - in + 1);
	}
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
