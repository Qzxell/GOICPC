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
	vector<int> v;
	int ind_m = -1;
	int sac = 1;
	int ans = 0;
	forn(i,n + n){
		string op;
		int nu;
		cin >> op;
		if(op == "add"){
			cin >> nu;
			v.push_back(nu);
		}else{
			int ind_c = sz(v) - 1;
			if(ind_c == ind_m){
				v.pop_back();
				ind_m--;
				sac++;
			}else if(v.back() == sac){
				v.pop_back();
				sac++;
			}else{
				ans++;
				sac++;
				ind_m = sz(v) - 1;
			}
		}
	}
	cout << ans << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

