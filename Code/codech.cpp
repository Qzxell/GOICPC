#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
        int tt;
        cin >> tt;
        while(tt--){
                int n;
                cin >> n;
		vector<int> v(n);
                vector<int> tab(n+1,0),ps(n+1,0);
                
                int mex = 0;
                for(int i = 0  ; i < n ; i++){
                        cin >> v[i];
                        tab[v[i]]++;
                        while(tab[mex])mex++;
                }
                ps[0] = (tab[0] == 0);
                for(int i = 1 ; i <= n ; i++){
                        ps[i] = ps[i-1] + (tab[i] == 0);
                }
                for(int i = 0 ; i <= mex;i++){
                        cout << tab[i] << ' ';
                }
                for(int i = mex+1 ; i <= n;i++){
                        cout << max(tab[i],ps[i-1]) << ' ';
                }
                cout << '\n';
        }
        return 0;
}

