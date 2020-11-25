class Distance
{
public:
	int distance_cm;
};


class Point
{
public:
	int x;
	int y;
	int viewing_angle;

};
class Sensor
{
public:

	void SetPosition(int x, int y,int anagle)
	{
		position.x = x;
		position.y = y;
		position.viewing_angle = anagle;
	}

	Point position;
	int id;

	Distance _distance;
};

class Feature
{
public:
	int x;
	int y;
};

class Circle
{
public:
	Circle ()
	{
		this->x =0;
		this->y =0;
		this->r =0;
	}

	void SetCordinate(int x,int y,int r)
	{
		this->x =x;
		this->y =y;
		this->r =r;
	}

	int x;
	int y;
	int r;
};


#define TOTAL_SENSORS 4
class Measurments
{
public:

	 Measurments();
	~Measurments();


	void setMeasurment(int sensor_id, int distance_cm);
	Feature* getFeature();

private:
	void SetSensorsPosition();
	Sensor _sensors[TOTAL_SENSORS];
	Feature _features [TOTAL_SENSORS];

};

void Measurments::SetSensorsPosition()
{
	_sensors[0].SetPosition(230,50,60);
	_sensors[1].SetPosition(280,50,60);
	_sensors[2].SetPosition(320,50,60);
	_sensors[3].SetPosition(370,50,60);
}
 Measurments::Measurments()
{
	SetSensorsPosition();
}

Measurments::~Measurments()
{

}
void Measurments::setMeasurment(int sensor_id, int distance_cm)
{
	this->_sensors[sensor_id]._distance.distance_cm = distance_cm;
}



Feature* Measurments::getFeature()
{

	Circle c1,c2,c3;
	c1.r = 0;c2.r = 0;c3.r = 0;
	for (int sensor_id=0;sensor_id<TOTAL_SENSORS;sensor_id++)
	{
		if (this->_sensors[sensor_id]._distance.distance_cm>0)
		{
			c1.SetCordinate(this->_sensors[sensor_id].position.x,this->_sensors[sensor_id].position.y,this->_sensors[sensor_id]._distance.distance_cm);
			for (int sensor_id_j=0;sensor_id_j<TOTAL_SENSORS;sensor_id_j++)
			{
				if (this->_sensors[sensor_id_j]._distance.distance_cm<1)
				{
					break;
				}else
				{
					if (c2.r >0)
					{
						c3.SetCordinate(this->_sensors[sensor_id_j].position.x,this->_sensors[sensor_id_j].position.y,this->_sensors[sensor_id_j]._distance.distance_cm);
					}
					else
					{
						c2.SetCordinate(this->_sensors[sensor_id_j].position.x,this->_sensors[sensor_id_j].position.y,this->_sensors[sensor_id_j]._distance.distance_cm);
					}

				}
			}
		}
	}

}





class TestTriaalteration
{
public:
	TestTriaalteration()
{
		//TODO: Test it
}
};
