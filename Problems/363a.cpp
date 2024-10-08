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
     if (n < 100) {
            cout << 100 - n; 
     }else if (n < 200) {
            cout << 200 - n; 
     }else if (n < 300) {
            cout << 300 - n; 
     }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    tt = 1;
    while(tt--){
        so();
    }

    return 0;
}
