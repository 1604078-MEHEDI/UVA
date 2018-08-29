#include<bits/stdc++.h>
using namespace std;
int main()
{
    while(1)
    {
        int n,a;
        cin >> n;
        if(n == 0)
        {
            return 0;
        }
        cin >> a;
        int ck = 0;
        vector<int> edge[201];
        for(int i = 0; i < a; i++)
        {
            int p,q;
            cin>>p>>q;
            if(i == 0)ck = p;
            edge[q].push_back(p);
            edge[p].push_back(q);
        }
        int color[201];
        int is = true;
        while(1)
        {
            for (int i = 0; i < 200; ++i)
            {
                color[i] = -1;
            }
            color[ck] = 1;
            queue<int>q;
            while(!q.empty())q.pop();
            q.push(ck);
            while(!q.empty())
            {
                int u = q.front();
                // cout<<u<<" //// ";
                q.pop();
//        if(edge[u][u] == 1)return false;
                //cout<<edge[u].size()<<endl;
                for(int i = 0; i < edge[u].size(); i++)
                {
                    int v = edge[u][i];
                    //cout<<color[v]<<" "<<color[u]<<" --> "<<u<<" "<<v<<endl;
                    if(v != u && color[v] == -1)
                    {
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                    else if(color[v] == color[u] && u != v)
                    {
                        is =  false;
                        break;
                    }
                }
            }
            break;
        }
        if((is))
        {
            cout<<"BICOLORABLE.\n";
        }
        else
        {
            cout<<"NOT BICOLORABLE.\n";
        }
    }
    return 0;
}
