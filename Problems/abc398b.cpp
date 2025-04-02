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
	vi wa;	
	vi fr(14,0);
	f(i,0,7){
		int x;
		cin >> x;
		if(fr[x] == 0)wa.pb(x);
		fr[x]++;
	}
	int le = sz(wa);
	f(i,0,14){
		f(j,0,14){
			if(i == j)continue;
			if(fr[i] >= 2 and fr[j] >= 3){
				cout << "Yes";
				return;
			}
		}
	}
	cout << "No";
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
