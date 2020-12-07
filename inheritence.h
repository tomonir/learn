class Father
{
protected :
	std::string property="1 K USD \n"; 
public:
	void getProperty()
	{
		std::cout<<property<<endl;
	}
};

class Son: protected Father
{
public:
	void getProperty()
	{
		std::cout<<property<<endl;
	}
};

class GrandSon: public Father
{
public:
	void getProperty()
	{
		std::cout<<property<<endl;
	}
};



class TestInheritence
{
public:
	TestInheritence()
{
		GrandSon gson;
		gson.getProperty();
}
};