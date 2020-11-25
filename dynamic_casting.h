class Entity
{
public:
	virtual shhowName(){};
};


class Wheel: public Entity
{
	
};

class Light: public Entity
{
	
};


class TestdynamicCast{
public:
	TestdynamicCast()
{
		Entity* e1 = new  Wheel();
		Entity* e2 = new  Light();
		Wheel* curr_wheel1 = dynamic_cast<Wheel*> (e1);
		Wheel* curr_wheel2 = dynamic_cast<Wheel*> (e2);
		if (curr_wheel2==nullptr)
		{
			cout<<"to Wheel from Light conversion NOK"<<endl;
		}
}
};
