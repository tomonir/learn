#include <memory>
#include <thread>
class Ractangle
{
public:
	Ractangle(int w=0,int h=0)
	{
		width=w;
		height = h;
	}
	~Ractangle()
	{
		std::cout<<"Rect get deleted "<<this<<endl;
	}
	void setWidth(int w)
	{
		width = w;
	}
	int getWidth(void);
	
	
private:
	int width;
	int height;
};

int Ractangle::getWidth(void)
{
	return width;
}
void passUniquePointer(Ractangle *rec_ptr)
{
	rec_ptr->setWidth(100);
	std::cout<<rec_ptr->getWidth();
}


void passSharedPointer (shared_ptr<Ractangle> sh_ptr)
{
	std::cout<<"shraed cout"<<sh_ptr.use_count()<<endl;
}


class SmartPointer
{
public :
	SmartPointer(){}
	
	void testMe()
	{
		unique_ptr<Ractangle> rect_unique = make_unique<Ractangle>(5,3);
		passUniquePointer(rect_unique.get());
		
		//shared_ptr<Ractangle> rect_shared = make_shared<Ractangle>(5,3);
		
		//thread t1(passSharedPointer,rect_shared); thread t2(passSharedPointer,rect_shared); thread t3(passSharedPointer,rect_shared);
		//t1.join();t2.join();t2.join();
		
	}
};