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

string wa = "What are you doing at the end of the world? Are you busy? Will you save us?";
string s1 = "What are you doing while sending \"";
string s2 ="\"? Are you busy? Will you send \""  ;
string s3 = "\"?";

const int N = 1e5 + 2;
vector<ll> memo(N,-2);
ll ma = 1000000000000000001;

char rec(int n,ll ind){
        if(n == 0 ){
                if(ind <= sz(wa))return wa[ind-1];
                else return '*';
        }
        if(ind <= sz(s1)){
                return s1[ind-1];
        }
        ll ga = memo[n-1];
        ind -= sz(s1);
        if(ga  == -1 or (ga != -1 and ind <= ga)){
                char lo = rec(n -1, ind );
                return lo;
        }
        ind -= ga ;
        if(ind <= sz(s2)){
                return s2[ind-1];
        }
        ind -= sz(s2);
        if(ind <= ga){
                char lo = rec(n -1, ind);
                return lo;
        }
        ind -= ga;
        if(ind <= sz(s3)){
                return s3[ind-1];
        }
        return '*';
        

}
void so(int test){
        int n;
        ll k;
        cin >> n >> k;
        char ans = rec(n,k);
        if(ans=='*')cout << '.';
        else cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

        memo[0] = sz(wa);
        for (int i = 1; i < N; i++) {
                if (memo[i-1] == -1) {
                    memo[i] = -1;
                    continue;
                }
                ll cur = 2 * memo[i-1] + sz(s1) + sz(s2) +sz( s3);
                memo[i] = ((cur > ma) ? -1 : cur);
        }
	int tt = 1;
	cin >> tt;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}
