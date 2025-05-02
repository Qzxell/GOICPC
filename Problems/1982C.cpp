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

const int N = 1e5 + 5;
int n,l,r;	
int a[N];
ll ps[N];
vi dp(N,-1);

int rec(int pos){
        if(pos >= n )return 0;
        if(dp[pos] != -1)return dp[pos];
        if(l <= a[pos] and a[pos] <= r){
                return dp[pos] = 1 + rec(pos+1);
        }
        if(a[pos] > r)return dp[pos] = rec(pos+1);

        int ret = rec(pos+1);
        int value = a[pos];
        int lo = pos,lf = n-1,mid;
        while(lo < lf){
                mid = (lo+lf)/2;
                if(ps[mid+1] - ps[pos] >= l)lf = mid;
                else lo = mid+1;
        }
        if(ps[lo+1] - ps[pos] >= l and ps[lo+1] - ps[pos] <= r)ret = max(ret,1 + rec(lo + 1));
        return dp[pos] = ret;
}


void so(int test){
        cin >> n >> l >> r;
        f(i,0,n)cin >> a[i];
        f(i,1,n+1)ps[i] = ps[i-1] + a[i-1];
        int ans = rec(0);
        cout << ans << ln;
        f(i,0,n+2)dp[i] = -1;
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
