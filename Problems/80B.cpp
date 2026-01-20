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
#define sz(v) (int)(v).size()

void so(int test){
        string s;
        cin >> s;
        string h,m;
        h = s.substr(0, 2);
        m = s.substr(3, 2);
        int ho = stoi(h);
        int mi = stoi(m);
        ho %= 12;
        double ans_h = (ho ?30*ho:0 ) + (double)mi/2.0;
        double ans_mi = 6*mi;
        cout << ans_h << ' ' << ans_mi << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


