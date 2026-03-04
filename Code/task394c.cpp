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
	int le = sz(s);
	int i = 0;
	int c = 0;
	while(i < le){
		if(s[i] == 'W')c++;
		else if(s[i] == 'A'){
			for(int k = i ;k >= i-c;k--)s[k] = 'C';
			s[i-c] = 'A';
			c = 0;
		}else c = 0;
		i++;
	}
	cout << s ;
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
