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
	f(i,0,n)cin >> v[i];
	vi px0(n+1,0);
	vi px1(n+1,0);
	string s;
	cin >> s;
	int aux1,aux0;
	aux1 = aux0 = 0;
	f(i,0,n){
		px0[i+1] ^= px0[i]^( s[i] == '0' ? v[i] : 0);
		px1[i+1] ^= px1[i]^( s[i] == '1' ? v[i] : 0);
	}
	//--- queris ---
	int q;
	cin >> q;
	f(nn,0,q){
		int ty;
		cin >> ty;
		if(ty == 1){
			int l,r;
			cin >> l >> r;
			aux1 ^= (px1[r]^px1[l-1]);
			aux0 ^= (px0[r]^px0[l-1]);
		}else{
			int wa;
			cin >> wa;
			if(wa){
				cout << (px1[n]^aux1^aux0) << ' ';
			}else{
				cout << (px0[n]^aux0^aux1) << ' ';
			}
		}
	}
	cout << ln;
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
