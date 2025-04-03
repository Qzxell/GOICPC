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

	while (true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		if(n >= 101){
			cout << "f91(" << n ;
			cout << ") = ";
			cout << n - 10 << ln;
			continue;
		}else{
			cout << "f91(" << n ;
			cout << ") = ";
			cout << 91 << ln;
		}

	}
	return 0;
}
