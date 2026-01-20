#include<bits/stdc++.h>

using namespace std;

#define ii pair<int,int>


void so(){
	int n,m,k,co = 0;
	cin >> n >> m >> k;
	vector<string> ma(n);
	vector<vector<bool>> vis(n,vector<bool>(m,0));
	vector<int> led(n*m,-1);

        string ret;
	for(int i = 0; i < n ; i++){
                cin >> ma[i];
                for(auto x : ma[i])co += (x == 'R');
                if(i&1)reverse(ma[i].begin(),ma[i].end());
                ret += ma[i];
        }

	int cd = co/k;
	int so = co % k;
        int li = cd + ( so > 0 );
        int acu = 0,pap = 0,ind = 0;
        for(auto x : ret){
                led[ind] = pap;
                if(x == 'R')acu++;
                if(acu == li && pap < k - 1){
                        pap++;
                        acu = 0;
                        so--;
                        li = cd + ( so > 0);
                }
                ind++;
        }
        for(int i = m; i < n*m ; i += 2*m){
                reverse(led.begin() + i , led.begin()+i+m);
        }

	for(int i = 0; i < n ; i++){
		for(int j = 0; j < m ; j++){
                        int x = led[i*m+j];
                        assert(x != -1);
			if(x < 26){
				cout << (char)('a' + x);
				continue;
			}
			if( x< 52){
				cout << (char)('A' + x - 26);
				continue;
			}
			cout << x-52 ;
		}
		cout << '\n';
	}
}

int main(){
	int tt;
	cin >> tt;
	while(tt--){
		so();
	}
	return 0;
}
