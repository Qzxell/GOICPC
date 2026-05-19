#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()

void so(int test){
	int n,m;
	cin >> n >> m;
	string s;
	cin >> s;

	int gru[n], in[n + 2] , fin[n + 2];

	int co = 1;

	gru[0] = co;


	forsn(i,1,n){
		if(s[i] >= s[i-1])
			gru[i] = gru[i-1];
		else 
			gru[i] = ++co;
	}
	forn(i,n+2) in[i] = -1;
	forn(i,n){
		if(in[gru[i]] == -1) in[gru[i]] = i;
		fin[gru[i]] = i;
	}

	set<pair<int,int>> seg;
	forn(i,m){
		int l,r;
		cin >> l >> r;
		l--;r--;
		if(gru[l] == gru[r]){
			seg.insert({-1,-1});
		}
		else {
			if( l - 1 >= 0 && s[l-1] == '0')
				l = in[gru[l-1]];
			if( r + 1 < n && s[r+1] == '1')
				r = fin[gru[r+1]];
			seg.insert({l,r});
		}
	}
	cout << seg.size() << '\n';
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

