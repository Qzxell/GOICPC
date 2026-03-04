#include<bits/stdc++.h>
#define ln '\n'
#define pb push_back
#define vii vector<pair<int,int>>  
#define vi vector<int>  
#define fi first
#define se second
using namespace std;

void so(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ind1 = -1;
    for(int i = 0;i < n-1 ;i++){
        if (s[i] == '1') {
            ind1 = i; 
        } 
    }
    if (s[n-1] == '0' and ind1 != -1 and n-1 - ind1 <= k) {
        swap(s[ind1],s[n-1]); 
        k -= (n-1-ind1);
    }
    int ind = -1;
    for(int i = 1;i < n - 1 ;i++){
        if (s[i] == '1') {
            ind = i; 
            break;
        } 
    }
    if (ind != -1 and ind <= k and s[0] =='0' ) {
        swap(s[0],s[ind]); 
    }
    int d=0,u=0;
    for(int i = 0;i < n;i++){
        if (i < n- 1 and s[i] =='1') {
            d++; 
        } 
        if (i > 0 and s[i] == '1') {
            u++;    
        }
    }
    cout << d*10 + u << ln;


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
