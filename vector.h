#include <vector>
#include <map>
#include <algorithm>
class TestVector
{
public:
	TestVector()
{
		std::vector<pair<int,int>> nodes;
		std::vector<pair<int,int>>::iterator itr;
		nodes.push_back(std::make_pair(3,3));
		nodes.push_back(std::make_pair(3,3));
		nodes.push_back(std::make_pair(3,3));
		
		
		itr = std::find(nodes.begin(),nodes.end(),std::make_pair(3,3));
		
		if (itr!=nodes.end())
		{
			std::cout<<"found !"<<endl;
		}
		
		for (int i=0;i<nodes.size();i++)
			cout<<nodes[i].first;
		
		testMap();
		
		
		
}
	
	void testMap()
	{
		std::map<int,int> nodes;
		std::map<int,int>::iterator itr;
		nodes.insert(std::make_pair(3,3));
		nodes.insert(std::make_pair(5,3));
		
		//itr=std::find(std::make_pair(5,3));
		
		if (itr!=nodes.end())
		{
			std::cout<<"Map found !"<<endl;
		}
	}
};