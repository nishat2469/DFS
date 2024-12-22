#include<bits/stdc++.h>
using namespace std;
vector<int>adj_list[100007];
int visited[100007];
int cost[100007];
int parent[100007];

void BFS(int s)
{
    visited[s]=1;
    cost[s]=0;
    parent[s]=s;

    stack<int>stk;
    stk.push(s);
    cout<<"Traversal Order: ";
    while(!stk.empty())
    {
        int top =stk.top();
        cout<<top<<" ";
        stk.pop();

        for(int i=0; i<adj_list[top].size(); i++)
        {
            int v=adj_list[top][i];

            if(visited[v]==0)
            {
                visited[v]=1;
                cost[v]=cost[top]+1;
                parent[v]=top;
                stk.push(v);
            }
        }
    }

}

int main()
{
    int nodes, edges;
    cin>>nodes>>edges;
    int u,v;
    for(int i=1; i<=edges; i++)
    {
        cin>>u>>v;
        adj_list[u].push_back(v);//for directed
        adj_list[v].push_back(u);//for undirected
    }

    int source, destination;
    cin>>source>>destination;

    BFS(source);

    cout<<endl;
    cout<<"Cost is: "<<cost[destination]<<endl;

/**Path Printing**/
    vector<int>path;//Here, path is the name of the vector container

    int now=destination;
    path.push_back(now);
    while(parent[now]!=now)
    {
        now=parent[now];
        path.push_back(now);
    }

    reverse(path.begin(), path.end());

    cout<<"Path is: ";
    for(int i=0; i<path.size(); i++)
    {
        cout<<path[i]<<"-->";
    }
    cout<<endl;

    return 0;

}




/* Sample Input: Here Nodes=7 edges=9  then, 9 edges pair.
Finally, source=1 and Destination = 7 (Indicating by last line)
7 9
1 2
2 4
1 3
2 5
3 5
3 6
3 7
5 7
6 7
1 7
*/
