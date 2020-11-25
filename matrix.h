class Matrix
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



class MatrixTest
{
public:
	MatrixTest()
{
		Matrix matrix;
		matrix.testDotProduct();
}
	
};