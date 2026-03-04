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

const int N = 1e6 + 2;
const int inf = 1e9;
vi dp(N,inf);

void so(int test){
        int n;
        cin >> n;
        queue<ii> qu;
        qu.push({n,0});

        int ans = 1e9;
        while(!qu.empty()){
                auto [num, steps] = qu.front();qu.pop();
                string num_str = to_string(num);
                if(num == 0){
                        ans = min(ans,steps);
                        continue;
                }
                for(char x : num_str)if(x!='0'){
                        int digit = x - '0';
                        if(dp[num-digit] > steps+1){
                                qu.push({num-digit,steps+1});
                                dp[num-digit] = steps + 1;
                        }
                }
        }
        cout << ans << ln;

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
