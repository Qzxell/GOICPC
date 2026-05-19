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


string RGB = "RGB";

void so(int test){
	vii v(3);
	forn(i,3){
		cin >> v[i].fi;
		v[i].se = i;
	}
	sort(all(v));
	string ans = "";
	auto add = [&](int ind){ ans += RGB[v[ind].se]; v[ind].fi--;};
	while(v[0].fi + v[1].fi > v[2].fi) forn(i,2)add(i);

	int v1 = v[1].fi;
	int v0 = v[0].fi;
	forn(i,v1) add(2),add(1);
	forn(i,v0) add(2),add(0);
	if(v[2].fi > 0)
		add(2);
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

