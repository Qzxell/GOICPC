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
	vi v(4);
	f(i,0,4)cin >> v[i];
	sort(all(v));
	if(v[0] == v[2] and v[2] != v[3]){
		cout << "Yes";
		return;
	}
	if(v[1] == v[3] and v[0] != v[1]){
		cout << "Yes";
		return;
	}
	if(v[0] == v[1] and v[2] == v[3] and v[1] != v[2]){
		cout << "Yes";
		return;
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
