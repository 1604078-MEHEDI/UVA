///https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1620
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

#define dbg1(x) cerr << #x << " = " << x << endl;
#define dbg2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define dbg3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;
#define dbg4(w,x, y, z) cerr << #w << " = " << w << ", " <<#x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;

const int N = 1e6 + 6;
const int M = 1e3 + 4;
int n, name_of_node, cnt;
int res[N];
int node[N][27];
int fail[N];
int path[N];
int end_node[N];
char txt[1000006], pat[M];
void init()
{
    name_of_node = 0;
    cnt = 0;
    memset(path, 0, sizeof path);
    memset(fail, 0, sizeof fail);
    memset(res, 0, sizeof res);
    memset(node, -1, sizeof node);
}

void Insert(char s[], int pos)
{
    int now = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (node[now][s[i] - 'a'] == -1) {
            node[now][s[i] - 'a'] = ++name_of_node;
        }
        now = node[now][s[i] - 'a'];
    }
    end_node[pos] = now;
}

void failure()
{
    queue<int> Q;
    for (int i = 0; i < 26; i++) {
        if (~node[0][i])
            Q.push(node[0][i]);
        else node[0][i] = 0;
    }

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int i = 0; i < 26;  i++) {
            int v = node[u][i];
            if (~v) {
                Q.push(v);
                fail[v] = node[fail[u]][i];
                path[++cnt] = v;
            }
            else {
                node[u][i] = node[fail[u]][i];
            }
        }

    }
    return;
}

void aho_corasick(char s[])
{
    int now = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        now = node[now][s[i] - 'a'];
        res[now]++;
    }
    for (int i = cnt; i >= 1; i--) {
        res[fail[path[i]]] += res[path[i]];
    }
}


int main()
{
    FASTIO
    ///*
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
//*/
    int T;
    scanf("%d", &T);
    //T = 1;
    for (int cs = 1; cs <= T; cs++) {
        init();
        scanf("%s", txt);
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s", pat);
            Insert(pat, i);
        }
        failure();
        aho_corasick(txt);

        //printf("Case %d:\n", cs);
        for (int i = 0; i < n; i++) {
            //printf("%d\n", res[end_node[i]]);
            int x = res[end_node[i]];
            if (x > 0) printf("y\n");
            else printf("n\n");
        }
    }
    return 0;
}
