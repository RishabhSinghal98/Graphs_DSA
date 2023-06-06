#include<bits/stdc++.h>
using namespace std;



bool iscyclic(int node,vector<int>& visited,vector<vector<int>>& graph,vector<int>& parent)
{
	visited[node]=1;
	parent[node]=-1;
	
	queue<int> q;
	q.push(node);
	
	while(!q.empty())
	{
		int current=q.front();
		q.pop();
		
		for(auto x:graph[current])
		{
			if(visited[x]==1 && x!=parent[current]) return true;
			
			else if(visited[x]==0)
			{
				q.push(x);
				visited[x]=1;
				parent[x]=current;
			}
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
	
// 	creategraph(1,0,graph);
// 	creategraph(0,2,graph);
// 	creategraph(2,1,graph);   //test input 1
// 	creategraph(0,3,graph);
// 	creategraph(3,4,graph);

    creategraph(0,1,graph);
	creategraph(1,2,graph);
	creategraph(2,3,graph);  //test input 2
	creategraph(3,4,graph);
	creategraph(4,0,graph);
	
	vector<int> visited(vertices); // creating an array to store status of visit
	
	vector<int> parent(vertices); // creating an array to store parents of nodes
	
	bool ans;
	for(int i=0;i<vertices;i++)
	{
		if(visited[i]==0) 
		{
			ans=iscyclic(i,visited,graph,parent);
		}
    }
	
	if(ans==true) cout<<"Cycle present"<<endl;
	else cout<<"Cycle Not Ppresent"<<endl;  
	   
	
	return 0;
	
}
