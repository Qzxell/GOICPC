#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define vii vector<ii>
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v).size()

void so(int test){
	int n;
	cin >> n;
	string s;
	cin >> s;
	vi ans,ans_ ;
	forn(i,n)if(s[i] == '1')
		ans.push_back(i+1);
	else 
		ans_.push_back(i+1);
	if((sz(ans)&1) and sz(ans_) % 2 == 0){
		cout << -1 << '\n';
		return;
	}
	if(not(sz(ans)&1)){
		cout << sz(ans) << '\n';
		for(auto x : ans){
			cout << x << ' ';
		}
		cout << '\n';
		return;
	}
	cout << sz(ans_) << '\n';
	for(auto x : ans_){
		cout << x << ' ';
	}
	cout << '\n';
	return;
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
	cin >> tt;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

