#include<bits/stdc++.h>
#define ln '\n'
#define pb push_back
#define vii vector<pair<int,int>>  
#define vi vector<int>  
#define fi first
#define se second
using namespace std;

void so(){
    int n;
    cin >> n;
    vi v(n);
    vector<bool> vis(n,0);

    for(int i = 0;i < n;i++){
        cin >> v[i] ;
    }
    int gc = 0;
    for(int i = 0;i <n;i++){
        int ma = 0;
        int ind = 0;
        for(int j = 0;j < n;j++){
            if (vis[j]) {
                continue; 
            } 
            if (gcd(v[j],gc) > ma) {
                ind = j;
                ma = gcd(v[j] , gc);
            }
        } 
        gc = ma;
        vis[ind] = 1;
        cout << v[ind] << ' ';
    }
    cout << ln;



}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        so();
    }

    return 0;
}
