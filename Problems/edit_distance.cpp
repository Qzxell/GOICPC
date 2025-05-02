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
        string s1,s2;
        cin >> s1 >> s2;
        int l1 = sz(s1),l2 = sz(s2);
        vector<vi> dp(l1+1,vi(l2+1,0));
        f(i,1,l1+1){
                f(j,1,l2+1){
                        if(s1[i-1] == s2[j-1]){
                                dp[i][j] = dp[i-1][j-1] + 1;
                        }else{
                                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                        }
                }
        }
        cout << max(l1,l2) - dp[l1][l2] << ln;
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
