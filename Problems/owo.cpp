#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string wa = "What are you doing at the end of the world? Are you busy? Will you save us?";
string s1 = "What are you doing while sending \"";
string s2 = "\"? Are you busy? Will you send \"";
string s3 = "\"?";

const int MAX_N = 1e5 + 5;
const ll INF = 1e18;

vector<ll> len(MAX_N, -1);

void precompute() {
    len[0] = wa.size();
    for (int i = 1; i < MAX_N; ++i) {
        if (len[i-1] == -1) {
            len[i] = -1;
            continue;
        }
        ll current = 2 * len[i-1] + s1.size() + s2.size() + s3.size();
        len[i] = (current > INF) ? -1 : current;
    }
}

char query(int n, ll k) {
    while (true) {
        if (n == 0) {
            if (k <= wa.size()) return wa[k-1];
            else return '.';
        }
        if (k <= s1.size()) {
            return s1[k-1];
        }
        k -= s1.size();
        ll prev_len = len[n-1];
        if (prev_len == -1 || k <= prev_len) {
            n--;
            continue;
        }
        k -= prev_len;
        if (k <= s2.size()) {
            return s2[k-1];
        }
        k -= s2.size();
        if (prev_len == -1 || k <= prev_len) {
            n--;
            continue;
        }
        k -= prev_len;
        if (k <= s3.size()) {
            return s3[k-1];
        }
        return '.';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    precompute();
    int q;
    cin >> q;
    while (q--) {
        int n;
        ll k;
        cin >> n >> k;
        cout << query(n, k);
    }
    return 0;
}
