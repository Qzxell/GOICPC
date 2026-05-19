#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define vi vector<int>
#define vl vector<ll>
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()

const int N = 1e7 + 8e5;
int pn[N];
vi primes;
vi tot;

void init(){
	for(int i = 2 ;i < N ;i ++){
		if(pn[i] == 0){
			pn[i] = i;
			primes.push_back(i);
		}
		for(auto p : primes){
			if(p > pn[i] or i*1ll*p > N)break;
			pn[i*p] = p;
		}
	}
	forsn(i,2,N){
		if(i/pn[i] == pn[i/pn[i]] && pn[i] != i/pn[i])
			tot.push_back(i);
	}
	//cout << sz(tot) << '\n';
}

void so(int test){
	int k;
	cin >> k;
	cout << tot[k-1] << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
	init();
	cin >> tt;
        while(tt--) so(test++);
        return 0;
}

