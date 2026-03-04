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
        ll l,r;	
        cin >> l >> r;
        if(l == r){
                cout << 0 << ln;
                return;
        }
        ll ans = 0;
        int ind = 0;
        f(i,0,63)if((r>>i)&1)ind = i;
        while(((l>>ind)&1) == ((r>>ind)&1))ind--;
        cout << (1ll<<(ind+1))-1;
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
