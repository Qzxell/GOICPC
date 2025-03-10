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
	int n;
	cin >> n;
	string s;
	cin >> s;
	if(n&1){
		if(n<=3){
			cout << 1 << ln;
			return;
		}

		vector<vi> dp(n+3,vi(27,0));
		f(i,1,n+1){
			dp[i][s[i-1]-'a']++;
			f(j,0,27){
				dp[i+2][j] += dp[i][j];
			}
		}
		vi aux1(27),aux2(27),aux3(27),aux4(27);
		int ans = 2e9;
		f(i,1,n+1){
			aux1 = dp[i-1];
			aux2 = dp[i-2];
			if(i&1){
				f(j,0,27){
					aux4[j] = dp[n][j] - dp[i][j];
					aux3[j] = dp[n-1][j] - dp[i-1][j];
				}
			}else{
				f(j,0,27){
					aux4[j] = dp[n][j] - dp[i-1][j];
					aux3[j] = dp[n-1][j] - dp[i][j];
				}
			}
			f(j,0,27){
				aux2[j] += aux3[j];
				aux1[j] += aux4[j];
			}
			int wa = accumulate(all(aux1),0) - *max_element(all(aux1));
			wa += accumulate(all(aux2),0) - *max_element(all(aux2));
			ans = min(ans,wa);
		}
		cout << ans << ln;
		return;
	}
	vi freq1(27,0);
	vi freq2(27,0);
	for(int i = 0;i < n;i+=2){
		freq1[s[i] - 'a']++;
	}
	int ans = accumulate(all(freq1),0) - *max_element(all(freq1));
	for(int i = 1;i < n;i+=2){
		freq2[s[i] - 'a']++;
	}
	ans += accumulate(all(freq2),0) - *max_element(all(freq2));
	cout << ans << ln;

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
