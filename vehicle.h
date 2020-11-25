class Vehicle
{
	public:

		friend std::ostream& operator<<(std::ostream& os, Vehicle& v);
		Vehicle(std::string id = "567",int total_light=5);
		Vehicle(Vehicle& source);
		Vehicle& operator=(Vehicle& source);
		Vehicle(Vehicle&& source);

		~Vehicle();

		void insertLight(std::string light_name);

	private:
		std::string id;
		int total_lights;
		int used_count;
		string *_leights;
};


Vehicle::Vehicle(std::string id,int total_light)
{
this->id = id;
this->total_lights = total_light;
this->used_count = 0;
this->_leights = new string[total_light];
}


Vehicle::~Vehicle()
{
	std::cout<<" desconstructor called" <<endl;
	delete[] _leights;
}


Vehicle::Vehicle(Vehicle& source)
{
	std::cout<<" copy constructor called" <<endl;

	this->id = source.id;
	this->total_lights = source.total_lights;
    this->used_count   = source.used_count;
    this->_leights = new string[source.total_lights];

    for (int i=0;i<source.used_count;i++)
    	this->_leights[i]=source._leights[i];
	//copy(source._leights,source._leights+this->total_lights,this->_leights);

}

Vehicle&Vehicle::operator=(Vehicle& source)
{
	std::cout<<" assign constructor called" <<endl;

	this->id = source.id;
	this->total_lights = source.total_lights;
	this->used_count = source.used_count;
	this->_leights = new string[source.total_lights];

    for (int i=0;i<source.used_count;i++)
    	this->_leights[i]=source._leights[i];

	//copy(source._leights,source._leights+this->total_lights,this->_leights);

}

Vehicle::Vehicle(Vehicle&& source)
{
	std::cout<<" Move constructor called" <<endl;
	this->id = source.id;
	this->total_lights = source.total_lights;
    this->used_count   = source.used_count;
    this->_leights = source._leights;
    
    source._leights= nullptr;
    		
}

void Vehicle::insertLight(std::string light_name)
{


	if (this->used_count > this->total_lights -1)
	{
		std::cout<<" full" <<endl;
	}
	else
	{
		//std::cout<<" fillout" <<endl;
		_leights[this->used_count] =light_name;
		this->used_count+=1;
	}
}

std::ostream& operator<<(std::ostream& os, Vehicle& v)
{
	std::string output="";
	for (int i=0;i<v.used_count;i++)
		output += " |" + v._leights[i];

	return os<< output <<endl;
}

Vehicle passVehicle(const Vehicle&& v)
{
	cout<<"passed do nothing"<<endl;
	
}



class TestCopyConstructor{
public:
	TestCopyConstructor()
{
			Vehicle v1;

			v1.insertLight("left");
			//v1.insertLight("right");
			//v1.insertLight("up");
			//v1.insertLight("left");
			//v1.insertLight("right");
			//v1.insertLight("up");


			Vehicle v2 ;

			v2 = v1; //assignment operator will be called

			//copy constructor will be called twice
			//passVehicle(v2);

			//v2=takeVehicle();

			//cout<< v2;

			int total_size = 6;
			//dynamic memory acclocation;

			Vehicle *vehicles = new  Vehicle[total_size];
			delete[] vehicles;
}
};

