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

ll res(vi v){
	ll ans = (1ll<<60);
        if(v.empty())return ans;
	ll sum = 0;
	int lo = v[0]+1;
	int le = sz(v);

	f(i,1,le){
		sum += v[i] - (lo);
		lo++;
	}
	ans = min(ans,sum);
	f(i,1,le){
		sum -= (v[i] - v[i-1]-1)*(le-i);
		sum += (v[i]-v[i-1]-1)*(i);
		ans = min(ans,sum);
	}
        return ans;
}
void so(int test){
	int n;
	cin >> n;
	string s;
	cin >> s;
	vi v;
	vi ga;
	f(i,0,n)if(s[i] == 'a')v.pb(i);
	f(i,0,n)if(s[i] == 'b')ga.pb(i);
	cout << min(res(v),res(ga))<<ln ;


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

