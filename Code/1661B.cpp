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

const int mod = 32768;
vi memo(mod+2,INT_MAX);

void so(int test){
	int x;
	cin >> x;
	cout << memo[x] << ' ';
			
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	cin >> tt;
	int test = 1;
	queue<int> qu;
	qu.push(0);
	memo[0] = 0;
	while(!qu.empty()){
		int num = qu.front();qu.pop();
		int prev1 = (num-1+mod)%mod;
		if(memo[prev1] > 1 + memo[num]){
			memo[prev1] = 1 + memo[num];
			qu.push(prev1);
		}
		if(num%2==0){
			int prev2 = num/2;
			int prev3 = (num+mod)/2;
			if(memo[prev2] > 1 + memo[num]){
				memo[prev2] = 1 + memo[num];
				qu.push(prev2);
			}
			if(memo[prev3] > 1 + memo[num]){
				memo[prev3] = 1 + memo[num];
				qu.push(prev3);
			}
		}
	}
	while (tt--){
		so(test++);
	}
	return 0;
}
