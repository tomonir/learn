//============================================================================
// Name        : test.cpp
// Author      : Monir
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


#include "vehicle.h"



//################################################
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



class Test
{


public:
	void testDotProduct()
	{
		int m1,n1, m2,n2;
		m1= 2;
		n1 =3;
		m2= 3;
		n2 = 2;

		int** a= new int*[m1];
		int** b= new int*[m2];

		double** result =  new double*[m1];

		for (int i=0;i<m1;i++)
			a[i]= new int[n1];

		for (int i=0;i<m2;i++)
			b[i]= new int[n2];

		for (int i=0;i<m1;i++)
			result[i]= new double[n2];


		a[0][0] = 1;a[0][1] = 2;a[0][2] = 3;
		a[1][0] = 1;a[1][1] = 2;a[1][2] = 3;

		b[0][0] = 1;b[0][1] = 2;
		b[1][0] = 1;b[1][1] = 2;
		b[2][0] = 1;b[2][1] = 2;


		if ( doDotProduct(result,a,b,m1,n1,m2,n2))
		{
			for (int i=0;i<m1;i++)
			{
				for (int j=0;j<n2;j++)
					cout << result[i][j]<<" ";

				cout<<endl;

			}

		}

		delete[] *a;
		delete[] a;

	}

	void testDotProductWithStaticArray()
	{
		int m1,n1, m2,n2;
		m1= 2;
		n1 =3;
		m2= 3;
		n2 = 2;

		/*passiging normal array to the function*/

		int x[2][3] = {{1,2,3},
						{1,2,3}	};

		int y[3][2] = {{1,2},
					   {1,2},
						{1,2}};
		double xy[2][2];

		if ( doDotProduct((double**)xy,(int**)x,(int**)y,m1,n1,m2,n2))
		{
			for (int i=0;i<m1;i++)
			{
				for (int j=0;j<n2;j++)
					cout << xy[i][j]<<" ";

				cout<<endl;

			}
		}



	}


private:
	bool doDotProduct(double** result, int** p_a, int** p_b,int m1,int n1, int m2,int n2 )
	{

		if (n1 !=m2)
			return false;

		for (int row=0;row<m1;row++)
		{
			for (int target_col=0;target_col<n2;target_col++)
			{
				result[row][target_col]=0;
				for (int col=0;col<n1;col++)
				{
					result[row][target_col]+=p_a[row][col]*p_b[col][target_col];
				}
			}

		}

		return true;

	}


};


class Data
{
	Data(int x=0,int y=0,int r=0)
	{
		x=x;y=y;r=r;
	}
	int x;
	int y;
	int r;
};

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

int main() {


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


	std::cout<<"Successfull"<<endl;
	return 0;

//DOT PRODUCT
//========================================
	Test test;
	test.testDotProduct();
	//TODO SOLVE IT
	//test.testDotProductWithStaticArray();
//========================================


//LinkedList
//========================================

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

//========================================




}








