#include<bits/stdc++.h>
using namespace std;

void so(){
    int n,q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;
    
    vector<vector<int>> pa(n+1,vector<int>(27,0));
    vector<vector<int>> pb(n+1,vector<int>(27,0));

    for(int i = 1 ; i <= n ; i++){
        pa[i][a[i-1] - 'a'] =  1 ;
        pb[i][b[i-1] - 'a'] =  1 ;
        for(int j = 0 ; j < 27 ; j++){
            pa[i][j] += pa[i-1][j]; 
            pb[i][j] += pb[i-1][j]; 
        }
    }

    while (q--){
        int l,r;
        cin >> l >> r;
        int t = r - l + 1;
        int inter  = 0;
        for(int i = 0 ; i < 27 ; i++){
            int aa = pa[r][ i] - pa[l-1][ i] ;
            int bb = pb[r][ i] - pb[l-1][ i] ;
            inter += min(aa,bb);
        }
        cout << t - inter << '\n';

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
