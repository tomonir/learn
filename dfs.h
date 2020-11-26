#include <vector>
#include <algorithm>


class TestDFS
{
	
	
	
	
public:
	TestDFS()
{
		startNode_i=0;
		startNode_j=0;
		
		endNode_i=2;
		endNode_j=2;
		
		num_row=3;
		num_col=3;
}
	
	void searchPath(std::vector<pair<int,int>> current_path,int current_node_i,int current_node_j)
	{
		if ((current_node_i==endNode_i)&&
				(current_node_j==endNode_j)	)
		{
			std::cout<<"["<<startNode_i<<" "<<startNode_j<<"] ";
			for (int i=0;i<current_path.size();i++)
				std::cout<<"["<<current_path[i].first<<" "<<current_path[i].second<<"] ";
			std::cout<<endl;
			return;
		}
		std::vector<pair<int,int>>::iterator itr; 
		
		//left
		int node_i = current_node_i;
		int node_j = current_node_j-1;
		if (node_j>-1)
		{
			itr = std::find(current_path.begin(),current_path.end(),std::make_pair(node_i,node_j));
			if ((itr==current_path.end()))//not visited
			{
				current_path.push_back(std::make_pair(node_i,node_j));
				searchPath(current_path,node_i,node_j);
			}
		}
		
		//down
		node_i = current_node_i+1;
		node_j = current_node_j;
		if (node_i<num_row)
		{
			
			itr = std::find(current_path.begin(),current_path.end(),std::make_pair(node_i,node_j));
			if ( (itr==current_path.end()))//not visited
			{
				//cout<<"down";
				current_path.push_back(std::make_pair(node_i,node_j));
				searchPath(current_path,node_i,node_j);
			}
		}
		
		//right

		node_i = current_node_i;
		node_j = current_node_j+1;
		if (node_j<num_col)
		{
			itr = std::find(current_path.begin(),current_path.end(),std::make_pair(node_i,node_j));
			if ( (itr==current_path.end()))//not visited
			{
				current_path.push_back(std::make_pair(node_i,node_j));
				searchPath(current_path,node_i,node_j);
			}
		}
		
		//up

		node_i = current_node_i-1;
		node_j = current_node_j;
		if (node_i>-1)
		{
			itr = std::find(current_path.begin(),current_path.end(),std::make_pair(node_i,node_j));
			if ((itr==current_path.end()))//not visited
			{
				current_path.push_back(std::make_pair(node_i,node_j));
				searchPath(current_path,node_i,node_j);
			}
		}
		
		return;
		
	}
	
private:
	int startNode_i;
	int startNode_j;
	
	int endNode_i;
	int endNode_j;
	
	int num_row;
	int num_col;
	
	
	
};


class TestDSFClass
{
public:
	TestDSFClass()
{
		TestDFS testDsf;
		std::vector<pair<int,int>> current_path;
		cout<<"all paths from [0,0] to [2,2]"<<endl;
		testDsf.searchPath(current_path,0,0);
}
};