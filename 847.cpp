///http://shoshikkha.com/archives/796
//https://codingstrife.wordpress.com/2013/07/28/solution-uva847-pc110505-a-multiplication-game/
#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 100005
#define tc printf("Case %d: ", cs)
#define tcn printf("Case %d:\n", cs);
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);
#define dbg(x) cerr << #x << " = " << x << endl;
#define dbg2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define dbg3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;
#define dbg4(w,x, y, z) cerr << #w << " = " << w << ", " <<#x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;

map<int, bool> mp;

bool win(ll n, ll p, bool cur)
{
    for (int i = 2; i <= 9; i++) {
        if (p * i >= n) return cur;
        if (mp.find(p * i) != mp.end()) {
            if (mp[p * i]) return cur;
            continue;
        }
        mp[p * i] = win(n, p * i, (cur + 1) % 2) == cur;
        if (mp[p * i]) return cur;
    }
    return (cur + 1) % 2;
}

void solve(ll n)
{
    ll  lo;
    long double lg = logl(n) / logl(18);
    lo = floorl(lg);
    if (lg - lo < 0.00000000001) {
        cout << "Ollie wins.\n";
    }
    else if (n / powl(18.0, lo) > 9.0) {
        cout << "Ollie wins.\n";
    }
    else cout << "Stan wins.\n";
    return;
}

void go(ll n)
{
    int cnt = 0;
    while (n > 1) {
        cnt++;
        if (cnt & 1) n = (n + 8) / 9;
        else n = (n + 1) / 2;
    }
    if (cnt & 1)cout << "Stan wins.\n";
    else cout << "Ollie wins.\n";
    return;
}

int main()
{
    //FASTIO
    ///*
    //double start_time = clock();
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
//*/
    int T;
    //cin >> T;
    T = 1;
    for (int cs = 1; cs <= T; cs++) {
        ll n;
        while (scanf("%lld", &n) == 1) {
            // dbg(n);
            go(n);
            //solve(n);
            // cout << ((win(n, 1, 0)) ? ("Ollie wins.") : ("Stan wins.")) << '\n';
            //for(int i = 1; i <= 100; i++)
            //    dbg(mp[i]);
            // mp.clear();
        }
    }

    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
    return 0;
}
