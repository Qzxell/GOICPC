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
	int m = *max_element(all(v));
	vi freq(m+1,0);
	f(i,0,n)freq[v[i]]++;
	vi freq_x(m+1,0); // cuantos elementos de A, son multiplos de x
	vi wasa(m+1,0); // dp: cual es el maximo divisor de i, que aparece en A al menos k veces

	// la idea principal es :
	// para un x, la respuesta es el maximo divisor tal que aparesca como minimo k veces
	f(i,1,m+1){
		for(int x = i ; x <= m; x+= i){
			freq_x[i] += freq[x];
		}
	}
	f(i,1,m+1){
		if(freq_x[i] < k)continue;
		for(int x = i ; x <= m; x+= i){
			wasa[x] = max(wasa[x],(int)i);
		}
	}
	f(i,0,n)cout << wasa[v[i]] << ln;
	
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
