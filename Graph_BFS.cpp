#include<bits/stdc++.h>
using namespace std;

void bfs(int source,vector<int>visited,vector<vector<int>> graph)
{
	queue<int> q;
	q.push(source);
	visited[source]=1;
	while(!q.empty())
	{
		int current=q.front();
		q.pop();
		cout<<current;
		for(auto x:graph[current])
		{
			if(visited[x]==0)
			{
				q.push(x);
				visited[x]=1;
			}
		}
	}
	
}


int main()
{
    int edges,vertices,u,v;
    cout<<"Enter Total edges"<<endl;
	cin>>edges;
	cout<<"Enter Total Vertices"<<endl;
	cin>>vertices;
	
	vector<vector<int>> graph(vertices+1);
	
	for(int i=0;i<edges;i++)
	{
		cout<<"Enter vertice"<<endl;
		cin>>u;
		cout<<"Enter vertice"<<endl;
		cin>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	vector<int> visited(vertices,0);
	bfs(1,visited,graph);
	
	
    return 0;
	
}
