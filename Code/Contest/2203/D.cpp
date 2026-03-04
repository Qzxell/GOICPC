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

const int N = 2e6 + 15;
int n,m;
int ft[N][2];
vi a;
int fre[N];

void clean(){
	forn(i,n+m+10) ft[i][0] = 0;
	forn(i,n+m+10) ft[i][1] = 0;
	forn(i,n+m+10)fre[i] = 0;
	a.clear();
	a.resize(n);
}

void so(int test){
	int x;
	cin >> n >> m;
	clean();
	forn(i,n)cin >> a[i];
	forn(i,m)cin >> x,fre[x]++;
	sort(all(a));
	a.erase(unique(all(a)),a.end());
	for(auto e : a){
		vi posi;
		for(int j = e; j < n+m + 1; j+=e){
			posi.push_back(j);
			ft[j][0]++;
			ft[j+1][0]--;
		}
		int prev = 1;
		for(auto u : posi){
			ft[prev][1]++;
			ft[u][1]--;
			prev = u + 1;
		}
		ft[prev][1]++;
		ft[n+m+10][1]--;
	}
	forsn(i, 1, n+m+10){
		ft[i][0] += ft[i-1][0];
		ft[i][1] += ft[i-1][1];
	}
	int am,al,bo;
	am = al = bo = 0;
	auto query = [&](int pos,int id)->int{
		return ft[pos][id];
	};
	forn(i,n+m+10){
		if(query(i,0) > 0 and query(i,1) > 0){
			am += (fre[i]);
			continue;
		}
		if(query(i,0) == sz(a)){
			al += fre[i];
			continue;
		}
		if(query(i,1) == sz(a)){
			bo += fre[i];
			continue;
		}
	}
	//cout << am << ' ' << al << ' ' << bo << '\n';
	if(am&1){
		al+=1;
		if(al > bo){
			cout << "Alice\n";
			return;
		}
		cout << "Bob\n";
		return;
	}else{
		bo+=1;
		if(bo > al){
			cout << "Bob\n";
			return;
		}
		cout << "Alice\n";
		return;
	}
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

