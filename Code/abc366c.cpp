#include <bits/stdc++.h>

using namespace std;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define ln '\n'
#define ll long long
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>  
#define vi vector<int>  
#define fi first
#define se second


void so(){
    int q;
    cin >> q;
    set<int> s;
    vi freq(1e6+2,0);
    for(int i =0 ; i < q ; i++){
        int u;
        int x;
        cin >> u;
        if (u != 3) {
            cin >> x; 
        }
        if (u == 1) {
            if(freq[x] == 0 ) s.insert(x) ;
            freq[x]++;
        }
        if (u == 2) {
            if (freq[x] == 1) {
                s.erase(x) ;
            }    
            freq[x] --;
        }
        if (u == 3) {
            cout << (int)s.size() << ln;
        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    while (tt--){
        so();
    }
    return 0;
}
