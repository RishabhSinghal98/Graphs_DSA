#include<bits/stdc++.h>
using namespace std;

//Topological Sort can be implemented in DAG only i.e Directed Acyclic Graph

void topologicalsort(int source,vector<int>&visited,vector<vector<int>>&graph,stack<int>& auxilary)
{
	visited[source]=1; //marking the source in visited array to 1 i.e visited
	
	
	for(auto x:graph[source]) // traversing in the list/vecctor coonected with the vector i.e child 
	{
		if(visited[x]==0) //checking whether the child is visited or not
		{
		    // recuursively calling topologicl sort again to go to the last node through //the neighbour nodes
		    	topologicalsort(x,visited,graph,auxilary); 
		}
	}
	auxilary.push(source); // pushing the source on returing the reccursie function call i.e the last source
	
}

void creategraph(int node1,int node2,vector<vector<int>>& graph)
{
    // creating graph pushing node2 at vector node1 index
	graph[node1].push_back(node2);  //pushing only node 2 on node 1 as it is directed graph
	
}
int main()
{
	
	int vertices=6;

	vector<vector<int>> graph(vertices); //created graph of size=no of vertices
	
	creategraph(5,2,graph);
	creategraph(5,0,graph);
	creategraph(4,0,graph);
	creategraph(4,1,graph);
	creategraph(2,3,graph);
	creategraph(3,1,graph);
	
	// creating an array to mark visited nodes initally witl all zeroes
	vector<int> visited(vertices,0);
	
	stack<int> auxilary;
	vector<int> ans;  //for storing the topological sort vertices
	
	for(int i=0;i<vertices;i++)  //using a for loop as may the graph be disconnect so there will be more than 1 component
	{
		if(visited[i]==0)
		{
		   topologicalsort(i,visited,graph,auxilary); 
	    }
	}
	while(!auxilary.empty())
	{
		int top=auxilary.top();
		ans.push_back(top);
		auxilary.pop();
		
	}
	cout<<"Topological Sorted Answer is as "<<endl;
	for(auto x:ans)
	{
	    cout<<x<<" ";
	}
	
	
	return 0;
	
}
