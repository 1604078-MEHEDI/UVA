/// Topic: Sqrt Decomposition
#include<bits/stdc++.h>
using namespace std;
#define sz 550

struct data
{
    int v, idx;
};

data piece[sz][sz];
int a[sz*sz];

bool cmp(data a, data b)
{
    return a.v < b.v;
}

int query(int l, int r, int v)
{
    static int cnt, lp, rp, m, tl, tr;

    cnt = 0;
    tl = l;
    tr = r;

    while(l%sz && l <= r)
    {
        if(a[l] < v) cnt++;
        l++;
    }

    while((r+1)%sz && l <+ r)
    {
        if(a[r] < v) cnt++;
        r--;
    }
    if(l > r) return cnt;
    lp = l/sz;
    rp = r/sz;
    v--;
    while(lp <= rp)
    {
        l = 0;
        r = sz - 1;
        while(l < r)
        {
            m = (l + r + 1) >> 1;
            if(piece[lp][m].v <= v) l = m;
            else r = m - 1;
        }
        if(piece[lp][l].v > v) l--;
        cnt += l + 1;
        lp++;
    }
    return cnt;
}

int main()
{
  //  freopen("in.txt", "r", stdin);
    int n,m,u;
    while(scanf("%d %d %d", &n, &m,&u) == 3)
    {
        for(int i = 0, j = (n - 1)/sz; i < sz; i++)
        {

            piece[j][i].v = 2147483647;
            piece[j][i].idx = -1;
        }
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            piece[i/sz][i%sz].v = a[i];
            piece[i/sz][i%sz].idx = i;
        }

        for(int i = (n - 1)/sz; i >= 0; i--)
            sort(piece[i], piece[i]+ sz, cmp);
        int i;
        while(m--)
        {
            int l,r,v,p;
            scanf("%d %d %d %d", &l, &r, &v, &p);
            l--, r--, p--;
            int x = query(l,r,v);
            int y = (int)((long long)x*u/(r - l + 1));
            x = p/sz;

            for( i = 0; piece[x][i].idx != p; i++);
            for( i;  i <sz; i++)
            {
                piece[x][i].v = piece[x][i+1].v;
                piece[x][i].idx = piece[x][i+1].idx;
            }

            for( i = sz - 2; i >= 0 && piece[x][i].v > y; i--)
            {
                piece[x][i+1].v = piece[x][i].v;
                piece[x][i+1].idx = piece[x][i].idx;
            }
            piece[x][i+1].v = y;
            piece[x][i+1].idx = p;
            a[p] = y;
        }
        for( i = 0; i < n; i++)
            printf("%d\n", a[i]);
    }
    return 0;
}
