#include<bits/stdc++.h>
#define ln '\n'
#define pb push_back
#define vii vector<pair<int,int>>  
#define vi vector<int>  
#define fi first
#define se second
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    while(true){
        cin >> a >> b;
        if (a == -1 and  b ==-1) {
            break;
        }
        if (a > b) {
            swap(a,b); 
        }
        if (a == 0) {
            cout << b;
            continue;
        }
        int esp = a+1;
        int ans = b/esp + (b%esp == 0 ? 0 : 1);
        cout << ans << ln;
    }
    return 0;
}

