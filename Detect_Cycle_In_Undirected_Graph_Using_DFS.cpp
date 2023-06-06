#include<bits/stdc++.h>
using namespace std;



bool iscyclic(int node,vector<int>& visited,vector<vector<int>>& graph,int parent)
{
	visited[node]=1;  //marking the node as visited
	
	for(auto x:graph[node]) //traversing in the neighbour of node
	{
		if(visited[x]==0)
		{
			bool ans=iscyclic(x,visited,graph,node);  //calling the fucntion recurssively if neighbour not visited where parent==node and node==x
			if(ans==true) return true;
		}
		else if(x!=parent)
		{
			return true;
		}
	}
	
	
	return false;
	
	
}


void creategraph(int node1,int node2,vector<vector<int>>& graph)
{
    // creating graph pushing node2 at vector node1 index
	graph[node1].push_back(node2);
	
	//creating graph pushing node2 at vector node1 index
	graph[node2].push_back(node1);
	
}
int main()
{
	
	int vertices=5;

	vector<vector<int>> graph(vertices); //created graph of size=no of vertices
	
	creategraph(1,0,graph);
	creategraph(0,2,graph);
	creategraph(2,1,graph);
	creategraph(0,3,graph);
	creategraph(3,4,graph);
	
	vector<int> visited(vertices,0); // creating an array to store status of visit
	
	bool ans;
	for(int i=0;i<vertices;i++)
	{
		if(visited[i]==0) 
		{
			ans=iscyclic(i,visited,graph,-1);
		}
    }
	
	if(ans==true) cout<<"Cycle present"<<endl;
	else cout<<"Cycle Not Present"<<endl;  
	   
	
	return 0;
	
}
