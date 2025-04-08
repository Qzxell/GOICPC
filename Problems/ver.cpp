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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n ;
	cin >> n;
	vector<string> v(n);
	f(i,0,n)cin >> v[i];
	bool yes = 1;
	f(i,0,n-1){
		f(j,0,n-1){
			if(v[i][j] == v[i+1][j+1] and v[i+1][j+1] == v[i+1][j] and v[i+1][j] == v[i][j+1])yes = 0;
		}
	}
	f(i,0,n){
		f(j,0,n-2){
			if(v[i][j] == v[i][j+1] and v[i][j+1] == v[i][j+2])yes = 0;
			if(v[j][i] == v[j][i+1] and v[j][i+1] == v[j][i+2])yes = 0;
		}
	}
	cout << yes<< ln;

	return 0;
}
