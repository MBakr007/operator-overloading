/// Course:  CS213 - Programming II  - 2018
/// Title:   Assignment I - Task 1 - Problem 1
/// Program: CS213-2018-A1-T1-P1
/// Purpose: Skeleton code for the student to start working
/// Author:  Muhammad Bakr and Muhammad El-Taher
/// Date:    10 August 2018
/// Version: 1.0

#include <iostream>
#include <iomanip>
///#include <cassert>

using namespace std;

/// A structure to store a matrix
struct matrix
{
    int* data;       /// Pointer to 1-D array that will simulate matrix
    int row, col;
};

void createMatrix (int row, int col, int num[], matrix& mat);


/// Student #1 with the smallest ID (e.g., 20170080)
/// All these operations return a new matrix with the calculation result


matrix operator+  (matrix mat1, matrix mat2) /// Add if same dimensions
{
    matrix mat3;
    if (mat1.col == mat2.col && mat1.row == mat2.row )
    {
        int num[]={0};
        createMatrix(mat1.row , mat1.col , num , mat3);
        for (int i=0 ; i<mat1.col*mat1.row ; i++)
        {
            if(i%mat1.col==0)
                cout<<endl;
            mat3.data[i]= mat1.data[i]+mat2.data[i];
        }
    }
    return mat3 ;
}



matrix operator-  (matrix mat1, matrix mat2) /// Sub if same dimensions
{
    matrix mat3;
    if (mat1.col == mat2.col && mat1.row == mat2.row )
    {
        int num[]={0};
        createMatrix(mat1.row , mat1.col , num , mat3);
        for (int i=0 ; i<mat1.col*mat1.row ; i++)
        {
            if(i%mat1.col==0)
                cout<<endl;
            mat3.data[i]= mat1.data[i]+mat2.data[i];
        }
    }
    return mat3 ;
}



matrix operator*  (matrix mat1, matrix mat2) /// Multi if col1 == row2
{
    matrix mat3;
    if (mat1.col == mat2.row )
    {
        int num[]= {0};
        createMatrix(mat1.row , mat2.col , num , mat3);
        for(int i=0 ; i<mat1.row ; i++)
        {
            for(int j=0 ; j<mat2.col  ; j++)
            {
                int sum=0 ;
                for(int k=0 ; k< mat2.row ; k++)
                {
                    sum+=mat1.data[i*mat1.col+k]*mat2.data[k*mat2.col+j];
                }
                mat3.data[i*mat3.col+j]=sum;
            }
        }

    }
    return mat3;
}


matrix operator+  (matrix mat1, int scalar)  /// Add a scalar
{
    matrix mat2;
    for(int i=0 ; i<mat1.col*mat1.row ; i++)
    {
        mat2.data[i]= mat1.data[i]+scalar;
    }
    return mat2 ;
}



matrix operator-  (matrix mat1, int scalar)  /// Subtract a scalar
{
    matrix mat2;
    for(int i=0 ; i<mat1.col*mat1.row ; i++)
    {
        mat2.data[i]= mat1.data[i]-scalar;
    }
    return mat2 ;
}



matrix operator*  (matrix mat1, int scalar)  /// Multiple by scalar
{
    matrix mat2;
    for(int i=0 ; i<mat1.col*mat1.row ; i++)
    {
        mat2.data[i]= mat1.data[i]*scalar;
    }
    return mat2 ;
}








/// Student #2 with the middle ID (e.g., 20170082)
/// The last operator >> takes an istream and a matrix and return the
/// the same istream so it is possible to cascade input like
/// cin >> matrix1 >> matrix2 << endl;
matrix operator+= (matrix& mat1, matrix mat2) /// mat1 changes & return new matrix with the sum
{
    if (mat1.col==mat2.col && mat1.row==mat2.row)
    {
        for(int i=0 ; i<mat1.col*mat1.row ; i++)
        {
            mat1.data[i]+=mat2.data[i];

        }
    }
    return mat1 ;
}


matrix operator-= (matrix& mat1, matrix mat2) /// mat1 changes + return new matrix with difference
{
    if (mat1.col==mat2.col && mat1.row==mat2.row)
    {
        for(int i=0 ; i<mat1.col*mat1.row ; i++)
        {
            mat1.data[i]-=mat2.data[i];

        }
    }
    return mat1 ;
}




matrix operator+= (matrix& mat, int scalar)   /// change mat & return new matrix
{
    for(int i=0 ; i<mat.col*mat.row ; i++)
    {
        mat.data[i]+=scalar;
    }
    return mat ;
}


matrix operator-= (matrix& mat, int scalar)   /// change mat & return new matrix
{
    for(int i=0 ; i<mat.col*mat.row ; i++)
    {
        mat.data[i]-=scalar;
    }
    return mat ;
}


void   operator++ (matrix& mat)  	/// Add 1 to each element ++mat
{
    for(int i=0 ; i<mat.col*mat.row ; i++)
    {
        mat.data[i]++;
    }
}


void   operator-- (matrix& mat)  	/// Sub 1 from each element --mat
{
    for(int i=0 ; i<mat.col*mat.row ; i++)
    {
        mat.data[i]--;
    }
}



istream& operator>> (istream& in, matrix& mat) /// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
{
    /// and return istream to allow cascading input

    in>>mat.row>>mat.col;
    int *num = new int [mat.row*mat.col] ;
    for(int i=0 ; i<mat.row*mat.col ; i++)
    {
        in>>num[i];
    }
    createMatrix(mat.row , mat.col , num , mat);
    return in ;

}





///Student #3 with the biggest ID (e.g., 20170089)
ostream& operator<< (ostream& out, matrix mat)
/// Print matrix  as follows (2 x 3)			4	 6 	  8
/// and return ostream to cascade printing	9	12  	123
{
    for(int i=0 ; i<mat.col*mat.row ; i++)
    {
        if(i%mat.col==0)
            cout<<endl;
        out << mat.data[i] << " " ;
    }
    return out ;
}


bool   operator== (matrix mat1, matrix mat2)	/// True if identical
{
    int boolean=0;
    if (mat1.col==mat2.col && mat1.row==mat2.row)
    {
        for(int i=0 ; i<mat1.col*mat1.row ; i++)
        {
            if(mat1.data[i]==mat2.data[i])
                boolean++;
            else
                break;
        }
        if(boolean==mat1.col*mat1.row)
            return true ;
        else
            return false ;
    }
    else
        return false ;

}


bool   operator!= (matrix mat1, matrix mat2) 	/// True if not same
{
    int boolean=0;
    if (mat1.col==mat2.col && mat1.row==mat2.row)
    {
        for(int i=0 ; i<mat1.col*mat1.row ; i++)
        {
            if(mat1.data[i]==mat2.data[i])
                boolean++;
            else
                break;
        }
        if(boolean==mat1.col*mat1.row)
            return false ;
        else
            return true ;
    }
    else
        return true ;

}


bool   isSquare   (matrix mat)  /// True if square matrix
{
    if (mat.col==mat.row)
        return true ;
    else
        return false ;
}


matrix transpose(matrix mat)    /// Return new matrix with the transpose
{
    matrix mat1 ;
    int x=0 , num[]= {0} ;
    createMatrix(mat.col , mat.row , num , mat1);
    for (int i = 0; i < mat.row ; i++)
    {
        for (int j = i; j <= i+4 ; j+=mat.row)
        {
            mat1.data[j]=mat.data[x];
            x++;
        }
    }
    for(int i=0 ; i<mat1.col*mat1.row ; i++)
    {
        if(i%mat1.col==0)
            cout<<endl;
        cout<<mat1.data[i]<<" ";
    }
    return mat1 ;
}




bool   isSymetric (matrix mat)  /// True if square and symmetric
{
    if (mat.col==mat.row)
    {
        matrix mat1 ;
        int x=0 , num[]= {0} ;
        createMatrix(mat.col , mat.row , num , mat1);
        for (int i = 0; i < mat.row ; i++)
        {
            for (int j = i; j <= i+4 ; j+=mat.row)
            {
                mat1.data[j]=mat.data[x];
                x++;
            }
        }
        x = (mat1==mat);
        if(!x)
            return true ;
        else
            return false ;

    }

    else
        return false ;
}


bool   isIdentity (matrix mat)  /// True if square and identity
{
    int sum1=0 , sum2=0 ;
    if(mat.col==mat.row)
    {
        for(int i=0 ; i<mat.col*mat.row ; i+=(mat.col+1))
        {
            if(mat.data[i]==1)
                sum1++;
        }
        if(sum1==mat.col)
        {
            for(int j=0 ; j<mat.col*mat.row ; j++)
            {
                if(j%(mat.col+1)!=0)
                {
                    if(mat.data[j]==0)
                        sum2++;
                }
            }
            if(sum2==(mat.col*mat.row)-mat.col)
                return true ;
            else
                return false ;
        }
        else
            return false ;
    }
    else
        return false ;


}





int main()
{
    int data1 [] = {1,2,3,4,5,6,7,8};
    int data2 [] = {1,7,3,7,4,-5,3,-5,6};
    int data3 [] = {10,100,10,100,10,100,10,100};

    matrix mat1, mat2, mat3 ;
    createMatrix (4, 2, data1, mat1);
    createMatrix (3, 3, data2, mat2);
    createMatrix (4, 2, data3, mat3);

    cout << mat1 << endl;
    cout << mat2 << endl;
    cout << mat3 << endl;

    cout << (mat1 + mat3) << endl << endl;
    cout << (mat3 + mat3) << endl << endl;

    ++mat1;
    cout << mat1 << endl;

    mat1+= mat3 += mat3;
    cout << mat1 << endl;
    cout << mat2 << endl;
    cout << mat3 << endl;

    return 0;
}

///__________________________________________
/// Takes an array of data and stores in matrix according
/// to rows and columns
void createMatrix (int row, int col, int num[], matrix& mat)
{
    mat.row = row;
    mat.col = col;
    mat.data = new int [row * col];
    for (int i = 0; i < row * col; i++)
        mat.data [i] = num [i];
}
