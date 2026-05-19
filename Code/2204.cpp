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

int su(int nu){
	int ret = 0;
	while(nu > 0){
		ret += nu%10;
		nu /= 10;
	}
	return ret;
}
const int N = 2000005;
vector<vi> dp(N);
vi vis(N,0);

vi fun(int nu){
	if(vis[nu])return dp[nu];
	vi ret(10,0);
	if(nu < 10){
		vis[nu] = 1;
		ret[nu]++;
		return dp[nu] = ret;
	}
	vis[nu] = 1;
	int aux = nu;
	while(nu > 0){
		ret[nu%10]++;
		nu /= 10;
	}
	vi rec = fun(su(aux));
	forn(i,10)
		ret[i] += rec[i];
	return dp[aux] = ret;
}

string sol(int nu){
	string ret = to_string(nu);
	if(nu < 10)
		return ret;
	string uwu = sol(su(nu));
	return ret + uwu;
}

void so(int test){
	string s;
	cin >> s;
	vi fre(10,0);
	int n = sz(s);
	ll su = 0;
	forn(i,n){
		fre[s[i] - '0']++;
		su += s[i]-'0';
	}
	forsn(i,1,9*n + 2){
		vi fr = dp[i];
		bool ok = 1;
		ll sob = 0;
		forn(j,10){
			if(fr[j] > fre[j])
				ok = 0;
			sob += (fre[j] - fr[j])*j;
		}
		if(!ok)continue;
		if(sob != i)continue;
		for(int k = 9 ; k >= 0 ; k--){
			forn(j,fre[k]-fr[k])
				cout << k;
		}
		cout << sol(i);
		cout << '\n';
		return;
	}
	cout << s << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
	forsn(i,1,N)
		fun(i);
	cin >> tt;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

