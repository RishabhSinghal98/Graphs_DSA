#include<bits/stdc++.h>
using namespace std;

//Topological Sort can be implemented in DAG only i.e Directed Acyclic Graph


void creategraph(int node1,int node2,vector<vector<int>>& graph)
{
    // creating graph pushing node2 at vector node1 index
	graph[node1].push_back(node2);
	
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
	

	
	vector<int> ans;  //for storing the topological sort vertices
	
	vector<int> indegree(vertices);// creating a vector for storing indegree
	
	queue<int> q; 
	
	for(int i=0;i<vertices;i++)
	{
	    for(auto x:graph[i])
	    {
	        indegree[x]++;
	    }
	}
	
	for(int i=0;i<vertices;i++)
	{ 
	    if(indegree[i]==0)
	    { 
	        q.push(i);  //pushing those vertices in queue whose indegree is 0
	    }
	}
	
	while(!q.empty())
	{
	    int current=q.front(); // taking top element of queue
	    ans.push_back(current); // pushing current in ans vector
	    q.pop();                // popping the top element from queue
	    
	    for(auto x:graph[current])  // traversing in graph i.e traversing on neighbours of current 
	    {
	        indegree[x]--;       // decreasing the indegree of neighbours  as we have from removed the element from queue 
	        if(indegree[x]==0)   // checking if indegree of neighbour is 0 then pushing it into queue
	        {
	            q.push(x);
	        }
	    }
	}
	
	
	
	cout<<"Topological Sorted Answer is as "<<endl;
	for(auto x:ans)
	{
	    cout<<x<<" ";
	}
	
	
	
	
	
	return 0;
	
}
