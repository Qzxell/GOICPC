#include<bits/stdc++.h>
#define ln '\n'
#define pb push_back
#define vii vector<pair<int,int>>  
#define vi vector<int>  
#define fi first
#define se second
using namespace std;

map<int,int> frec;

void so(){
    int n,k,d;
    frec.clear();
    cin >> n >> k >> d;
    vi v(n);
    for(int i = 0 ; i < n ; i++){
        cin >> v[i] ;
    }
    int cnt = 0;
    for(int i = 0 ; i < d ; i++){
        if (frec[v[i]] == 0) {
            cnt++; 
        }
        frec[v[i]]++; 
    }
    int ans = cnt;
    for(int i = d ; i < n ; i++){
        if (frec[v[i]] == 0) {
            cnt++; 
        } 
        frec[v[i]]++;
        if (frec[v[i-d]] == 1) {
            cnt--; 
        }
        frec[v[i-d]]--;
        ans = min(ans,cnt);
    }
    cout << ans << ln;


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
