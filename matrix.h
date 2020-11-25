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


	void testSpiralMatrix()
	{

		int R=4;int C=4;
		int M[R][C]= {
				{1, 2, 3 ,4},
				{5, 6, 7, 8},
				{9, 10, 11, 12},
				{14,15,16,17},
		};


		if (C!=R)
			return;

		int max = C;
		for (int r=0;r<R; r++)
		{
			//left
			for (int c=r;c<max;c++)
				cout<< M[r][c]<<endl;

			//down
			for (int r_d=r+1;r_d<max;r_d++)
				cout<< M[r_d][max-1]<<endl;


			//left
			for (int c_l=max-2;c_l>=r;c_l--)
				cout<< M[max-1][c_l]<<endl;

			//up
			for (int r_u=max-2;r_u>r;r_u--)
				cout<< M[r_u][r]<<endl;

			max = max-1;
		}

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
		//matrix.testDotProduct();
		matrix.testSpiralMatrix();
}
	
};
