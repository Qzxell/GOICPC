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

int a,b;
map<int,bool> vis;
map<int,bool> dp;

bool fu(int nu){
        if(nu == a)return dp[nu] = 1;
        if(nu < a )return 0;
        if(vis[nu])return dp[nu];
        vis[nu] = 1;
        bool ret = 0;
        if(nu%2 == 0){
                ret |= fu(nu/2);
        }
        if((nu-1)%10 ==0){
                ret |= fu(nu/10);
        }
        return dp[nu] = ret;
}
vi ans;
void rec(int nu){
        if(dp[nu]){
                ans.pb(nu);
        }
        if(nu%2 == 0 and dp[nu/2]){
                rec(nu/2);
                return;
        }
        if((nu-1)%10 ==0 and dp[nu/10]){
                rec(nu/10);
                return;
        }
}

void so(int test){
        cin >> a >> b;
        fu(b);
        if(!dp[b]){
                cout << "NO" << ln;
                return;
        }
        rec(b);
        cout << "YES" << ln;
        reverse(all(ans));
        cout << sz(ans) << ln;
        for(auto x : ans)cout << x << ' ' ;
        cout << ln;
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
