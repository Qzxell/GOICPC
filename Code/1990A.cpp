#include<bits/stdc++.h>
#define ln '\n'
#define ll long long
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
    for(int i = 0;i < n;i++){
        cin >> v[i] ;
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    v.pb(0);
    int c = 1;
    bool ans = 1;
    for(int i = 0;i < n;i++){
        if (v[i] == v[i+1]) {
            c ++;
        }else {
            if (c&1) {
                ans = 0;                
                break;
            }
            c= 1;
        } 
    }
    cout << (!ans ? "YES" : "NO") << ln;
    
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
