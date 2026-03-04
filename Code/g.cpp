#include<bits/stdc++.h>
#define ln '\n'
#define ll long long
#define pb push_back
#define vii vector<pair<int,int>>  
#define vi vector<int>  
#define fi first
#define se second
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int co = 1;
    while(true){
        int a,b,c;
        cin >> a >> b >> c;
        if (a == -1) {
            break; 
        }
        if (co == 73) {
            cout << a <<' ' << b << c;
        }
        co++;
    }
    cout << co;
    return 0;
}
