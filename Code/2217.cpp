#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define vi vector<int>
#define vl vector<ll>
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()

void so(int test){
	int n,k;
	cin >> n >> k;
	vi v(n+1);
	vi ind(k);
	forsn(i,1,n+1)
		cin >> v[i];
	forn(i,k)
		cin >> ind[i];
	int ti = v[ind[0]];
	int l,r;
	bool ok = 0;
	int gru1 = 0,gru2 = 0;
	forsn(i,1,n+1){
		if(v[i] == ti){
			if(!ok){
				ok = 1;
				l = r = i;
			}else
				r = i;
		}else{
			if(ok){
				ok = 0;
				int pun = lower_bound(all(ind),l) - ind.begin();
				int pri = 1<<30;
				if(pun < k)
					pri = ind[pun];
				if(pri <= r)
					gru2++;
				gru1++;
			}
		}
	}
	if(ok){
		int pun = lower_bound(all(ind),l) - ind.begin();
		int pri = 1<<30;
		if(pun < k)
			pri = ind[pun];
		if(pri <= r)
			gru2++;
		gru1++;
	}
	gru1 -= gru2;
	cout << gru2 + 1 + gru1  << '\n';

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

