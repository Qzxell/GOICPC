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
	int n;
	cin >> n;
	vector<string> v(n);
	vi tam(n,-1);//index = 1;

	forn(i,n)
		cin >> v[i];
	reverse(all(v));
	tam[0] = sz(v[0]);

	forsn(i,1,n){
		bool eq = 1;
		int lim = tam[i-1];
		int ind = - 1;
		while(ind + 1 < min(sz(v[i]),lim) && v[i][ind + 1] <= v[i-1][ind + 1]){
			ind++;
			if(v[i][ind] < v[i-1][ind])
				eq = 0;
		}
		tam[i] = ind + 1;
		if(!eq)
			tam[i] = sz(v[i]);
	}
	reverse(all(v));
	reverse(all(tam));
	int id = 0;
	for(auto s : v){
		int li = tam[id++];
		forn(i,li)
			cout << s[i];
		cout << '\n';
	}
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

