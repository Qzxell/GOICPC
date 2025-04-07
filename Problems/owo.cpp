#include <bits/stdc++.h>
using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>  ;
using vi = vector<int>  ;
#define ln  '\n'
#define ll long long
#define pb push_back
#define fi first
#define se second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define f(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)

string wa = "What are you doing at the end of the world? Are you busy? Will you save us?";
string s1 = "What are you doing while sending \"";
string s2 = "\"? Are you busy? Will you send \"";
string s3 = "\"?";


int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int nn = 2;
        char wasa = ((nn&1)? 'a' : 'm');
        //vector<string> com = rec(nn-1,wasa,mi,mi);
        int len = (1<<nn);
        int mi = len/2;
        vector<string> aux(mi,string(mi,' '));
        //vector<string> lost = (nn-1,ga,l,r);
        vector<string> lost(mi,string(mi, '-'));
        lost[0] = "01";
        vector<string> ret(len,string(len,' '));

        auto ful = [&](int ind_x,int ind_y){
                f(i,0,mi){
                        f(j,0,mi){
                                ret[ind_x + i][ind_y +j] = lost[i][j];
                        }
                }
        };
        auto rotate = [&](){
                f(i,0,mi){
                        f(j,0,mi){
                                aux[mi-j-1][i] = lost[i][j];
                        }
                }
                swap(aux,lost);
        };
        ful(0,0);
        rotate();
        ful(mi,0);
        rotate();
        ful(mi,mi);
        rotate();
        ful(0,mi);
        f(i,0,len){
                f(j,0,len){
                        cout<< ret[i][j] ;
                }
                cout << ln;
        }
        return 0;
}
