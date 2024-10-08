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
    string a,b;
    while(true){
        cin >> a >> b;
        if (a == "*" and  b =="*") {
            break;
        }
        int c = 0;
        int le = a.size();
        int ans = 0;
        for (int i = 0; i < le; ++i) {
            if (a[i] != b[i]) {
                c++; 
            } 
            if (a[i] == b[i]  ) {
                if (c) {
                    ans++; 
                }
                c = 0;
            }
        }
        if (c) {
            ans++; 
        }

        cout << ans << ln;
    }
    return 0;
}

