class Node
{
public:
	Node(int x=0){
		value =x;
		next_node= NULL;
		parent_node = NULL;
	}


	~Node()
	{
		cout<<"Node destrucitor called"<<endl;

	}
	int value;
	Node* next_node;
	Node* parent_node;

};






class LinkedList
{


public:
	LinkedList()
	{
		root = new Node();
	}

	void push(int value)
	{

		root->value = value;
		root->next_node = new Node();
		root->next_node->parent_node = root;
		root = root->next_node;
	}


	bool pop(Node& out_node)
	{
		if (root->parent_node == NULL)
			return false;
		out_node.value = root->parent_node->value;

		root->parent_node->value = 0;
		delete root->next_node;

		root = root->parent_node;

		return true;
	}
	

private:
	Node* root;
};


class TestLinkList
{
	public:
	
	TestLinkList()
	{
		LinkedList mylist;
		mylist.push(5);
		mylist.push(10);
		mylist.push(8);

		Node tempNode;

		if (mylist.pop(tempNode))
			cout<< tempNode.value<<endl;
		if (mylist.pop(tempNode))
			cout<< tempNode.value<<endl;
		if (mylist.pop(tempNode))
			cout<< tempNode.value<<endl;
		mylist.push(8);
		if (mylist.pop(tempNode))
			cout<< tempNode.value<<endl;
		if (mylist.pop(tempNode))
			cout<< tempNode.value<<endl;
		if (mylist.pop(tempNode))
			cout<< tempNode.value<<endl;
		if (mylist.pop(tempNode))
			cout<< tempNode.value<<endl;
	}
};