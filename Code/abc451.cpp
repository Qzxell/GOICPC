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


int dis[3002][3002];
int p[3002];

int fat(int nod){
	if(p[nod] == nod)return nod;
	return p[nod] = fat(p[nod]);
}
bool join(int a,int b){
	a = fat(a);
	b = fat(b);
	if(a == b)return true;
	p[b] = a;
	return false;
}

void so(int test){
	int n;
	cin >> n;
	iota(p,p+n,0);

	forn(i,n-1)
		forsn(j,i+1,n)
			cin >> dis[i][j];
	vi T[n+1];

	auto get = [&](int x, int y){
		if(x > y)
			swap(x,y);
		return dis[x][y];
	};
	forsn(i,1,n) {
		forsn(j,1,n)if(i!=j){
			if(dis[1][i] + get(i,j)  == dis[1][j]){
				T[i].push_back(j);
			}
		}
	}
	forn(i,n){
		int lon = sz(T[i]);
		for(auto a : T[i])
		for(auto b : T[i]){
			if(a == b)continue;
			if(get(a,i) + get(b,i) != get(a,b)){
				cout << "No\n";
				return;
			}
		}
	}
	cout << "Yes\n";
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
	//cin >> tt;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

