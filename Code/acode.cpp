#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)

#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define vii vector<ii>
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v).size()

bool ok = true;

void so(int test){
        string s;
        cin >> s;
        if(s == "0"){
                ok = false;
                return;
        }
        vl dp(sz(s)+2,0);
        dp[0] = 1;
        forsn(i,1,sz(s)+1){
                if(s[i-1] != '0') dp[i] += dp[i-1];
                if(i-2 >= 0 and stoi(s.substr(i-2,2)) <= 26 and stoi(s.substr(i-2,2)) >= 10)dp[i] += dp[i-2];
        }
        cout << dp[sz(s)] << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(ok) so(test++);
        return 0;
}
