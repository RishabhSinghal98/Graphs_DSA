#include<bits/stdc++.h>
using namespace std;

void dfs(int source,vector<int>&visited,vector<vector<int>>&graph)
{
	visited[source]=1; //marking the source in visited array to 1 i.e visited
	
	cout<<source<<"->"; //printing the nodes
	
	for(auto x:graph[source]) // traversing in the list/vecctor coonected with the vector i.e child 
	{
		if(visited[x]==0) //checking whether the child is visited or not
		{
			dfs(x,visited,graph); // recursively calling dfs again to go to the last node through the neighbour nodes 
		}
	}
	
}

void creategraph(int node1,int node2,vector<vector<int>>& graph)
{
    // creating graph ( pushing node2 at vector's node1 index)
	graph[node1].push_back(node2);
	//creating graph (pushing node1 at vector's node2 index)
	graph[node2].push_back(node1);
}
int main()
{
	
	int vertices=5;

	vector<vector<int>> graph(vertices); //created graph of size=no of vertices
	
	creategraph(0,1,graph);
	creategraph(0,2,graph);
	creategraph(1,2,graph);
	creategraph(2,0,graph);
	creategraph(2,3,graph);
	creategraph(3,3,graph);
	
	// creating an array to mark visited nodes initially witl all zeroes
	vector<int> visited(vertices,0);
	
	dfs(2,visited,graph); // 2 is the source node
	
	
	return 0;
	
}
