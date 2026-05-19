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

void so(int test){
	int n;
	cin >>n;
	string siu;
	cin >> siu;
	int co = 0;
	char uwu = 'd';
	vi gru;
	forn(i,n){
		if(siu[i] == uwu){
			co++;
		}else{
			if(co > 0)
				gru.push_back(co);
			co = 1;
		}
		uwu = siu[i];
	}
	if(co > 0)
		gru.push_back(co);
	for(;;){

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

