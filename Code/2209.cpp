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
#define pb push_back
#define imp(v) {for(auto x:v)cout<<x<<' ';cout<<'\n';}


void so(int test){
	vii v;
	forn(i,3){
		int x;
		cin >> x;
		v.pb({x,i});
	}
	string ans;
	string s = "RGB";
	sort(rall(v));
	forn(i,min(v[0].fi,v[1].fi)){
		ans +=s[v[0].se] ;
		ans +=s[v[1].se] ;
	}
	v[0].fi -= v[1].fi;
	forn(i,min(v[0].fi,v[2].fi)){
		ans +=s[v[0].se] ;
		ans +=s[v[2].se] ;
	}
	if(v[0].fi >= v[2].fi){
		int sob = v[0].fi - v[2].fi;
		if(sob > 0){
			ans += s[v[0].se];
		}
	}else{
		int sob = v[2].fi - v[0].fi;
		ans = s[v[2].se] + ans;
		sob--;
		if(sob > 0 && ans.back() != s[v[2].se]){
			ans+= s[v[2].se];
		}
	}
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

