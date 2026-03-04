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
	f(i,0,n){
		cin >> v[i];
		freq[v[i]]++;
	}
	bool yes = 1;
	f(i,1,n){
		if(freq[i] == 0)continue;
		if(freq[i] == 1){
			yes = 0;
			break;
		}
		freq[i+1] += freq[i] - 2;
	}
	if(freq[n] &1)yes = 0;
	cout << (yes ? "Yes" : "No") << ln;
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
