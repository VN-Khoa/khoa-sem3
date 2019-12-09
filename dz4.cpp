#include <bits/stdc++.h>
#define maxn 100000
#define fi first
#define se second

using namespace std;

int n,m,q,del[maxn];
pair<int,int> deg[maxn];
vector<int> g[maxn];
priority_queue<pair<int,int> > all;

int main()
{
    cout<<"Enter the number of vertices:"<<endl;
    cin>>n;
    cout<<"Enter the number of edges:"<<endl;
    cin>>m;
    cout<<"Enter edges:"<<endl;
    for (int i=1,u,v;i<=m;i++)
    {
        cin>>u>>v;//1 edge u v
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout<<"Enter the number of edges with 2 vertices to be deleted:"<<endl;
    cin>>q;
    cout<<"Enter edges:"<<endl;
    for (int i=1,u,v;i<=q;i++)
    {
        cin>>u>>v; //enter the edges
        del[u]=1;
        del[v]=1;
    }
    for (int i=1;i<=n;i++)
    {
        if (del[i]) continue;
        int num=0;
        for (auto x : g[i]) if (!del[x]) num++;
        deg[i] = make_pair(num,i);
    }
    for (int i=1;i<=n;i++)
    {
        if (del[i]) continue;
        all.push(deg[i]);
    }
    cout<<"Result:"<<endl;
    while (!all.empty()) 
    {
        auto x = all.top();
        cout<<x.fi<<" "<<x.se<<endl;
        all.pop();
    }
}
