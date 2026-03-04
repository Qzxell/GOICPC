#include<bits/stdc++.h>
#define ln '\n'
#define pb push_back
#define vii vector<pair<int,int>>  
#define vi vector<int>  
#define fi first
#define se second
using namespace std;

void so(){
    int n,x,y;
    cin >> n >> x >> y;
    vi ans (n);
    for(int i = y-1;i < x;i++){
        ans[i] = 1; 
    }
    for(int i = y-1;i >= 0 ;i--){
        if ((y-1-i)&1) {
            ans[i] = -1; 
        }else ans[i]= 1;
    }
    for(int i = x-1 ;i < n;i++){
        if ((i-x+1)&1) {
            ans[i] = -1; 
        }else ans[i]= 1;
    }
    for(int i = 0;i < n;i++){
        cout << ans[i] << ' '; 
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
