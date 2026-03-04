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

vector<ll> num(32,0);
void so(int test){
        ll n;
        cin >> n;
        int pos = lower_bound(all(num),n) - num.begin();
        cout << pos*2 + 3 << ln;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

        num[0] = 1;
        for(int i = 1 ; i <= 31;i++){
                num[i] = 2*num[i-1] + 1;
        }
	int tt = 1;
	cin >> tt;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}
