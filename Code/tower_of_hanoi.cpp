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

vii ans;
void rec(int n,int to,int inv){
        if(n==1){
                ans.pb({6-to-inv,to});
                return;
        }
        rec(n-1,inv,to);
        ans.pb({6-to-inv,to});
        rec(n-1,to,6-to-inv);
}
void so(int test){
        int n;	
        cin >> n;
        rec(n,3,2);
        cout << sz(ans) << ln;
        for(auto [a,b] :ans){
                cout << a << ' ' << b << ln;
        }
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
