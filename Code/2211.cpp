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

bool so(int test){//!! important :v
	//assert(false);
	int n,k;
	cin >> n >> k;
	vi a(n),b(n);
	set<int> pos[n+1];
	forn(i,n)
		cin >> a[i];
	forn(i,n){
		cin >> b[i];
		if(b[i] == -1)b[i]=0;
		pos[b[i]].insert(i);
	}
	vi con(n,-1);
	vi con_(n,-1);
	auto conec = [&](int x,int in)->bool{
		auto it = pos[a[x]].lower_bound(in);
		if(it == pos[a[x]].end() || *it >= in + k){
			auto it2 = pos[0].lower_bound(in);
			if(it2 == pos[0].end() || *it2 >= in + k)
				return 0;
			con[x] = *it2;
			con_[con[x]] = x;
			pos[0].erase(it2);
			return 1;
		}
		con[x] = *it;
		con_[con[x]] = x;
		pos[a[x]].erase(it);
		return  1;
	};
	forn(i,k) if(!conec(i,0))
		return 0;
	forsn(i,1,n-k ){
		// desconetamos atras :v
		int pun = con[i-1];
		pos[b[pun]].insert(pun);

		//conectamos lo desconectado
		auto it = pos[b[i-1]].find(i-1);
		if(it != pos[b[i-1]].end()){
			pos[b[i-1]].erase(it);
		}else{
			int ind1 = con_[i-1];
			if(!conec(ind1,i))
				return 0;
		}
		int ind1 = i + k -1;
		if(!conec(ind1,i))
			return 0;
	}
	return 1;
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
	cin >> tt;
        int test = 1;
        while(tt--) {
		cout << (so(test++)? "YES\n" : "NO\n");
	}
        return 0;
}

