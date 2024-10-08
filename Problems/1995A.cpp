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
    int n,k;
    cin >> n >> k;
    vector<int> v(2*n+2,0);
    for(int i = 1;i <= n;i++){
        v[i] = i; 
        v[2*n-i] = i;
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    int i = 0;
    int ans =0 ;
    int cur =0;
    while(cur < k){
        cur += v[i];
        i++;
        ans++;
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
