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

bool fu(ll n){
	while(n > 0){
		if(n%10 == 7)return true;
		n/=10;
	}
	return false;
}

void so(int test){
	int n;
	cin >> n;
	int ans = ((n%10) - 7 + 10 ) % 10;
	forn(i,10)
		if(fu(n-i))
			ans =min(ans,i);

	string s = to_string(n);

	forn(i,sz(s)-1) {
		string uwu = s.substr(i+1,n-i-1);
		int sob = stoi(uwu);
		int va = ('7' - s[i] + 10) % 10 ;
		ans = min(ans,va + (sob < va) );
	}
	ans = min(ans,7);
	cout << ans << '\n';
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

