#include<bits/stdc++.h>
#define all(c) (c).begin(), (c).end()
#define ln '\n'
#define ll long long
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>  
#define vi vector<int>  
#define fi first
#define se second
using namespace std;

void so(){
    string s ;
    cin >> s;
    int le = (int) s.size() - 1;
    while(s[le] == '0'){
        le--;
    }
    if (s[le] == '.') {
        le--; 
    }
    for(int i = 0; i <= le ; i++){
        cout << s[i];
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

