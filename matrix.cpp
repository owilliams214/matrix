#include <iostream>
#include <ctime>
//#include <iomanip>
using namespace std;

const int n = 10;
void createMatrix(double matrix[n][n]) ;
void printMatrix(double matrix[n][n], bool isRowWise);
void addMatrix(double matrix1[n][n], int matrix2[n][n], int matrix[n][n]);
void transposeMatrix(double matrix[n][n], int transpose[n][n]);
void transposeMatrix(double matrix[n][n]);
void multMatrix(double matrix1[n][n], int matrix2[n][n],  int matrix[n][n], bool isRowWise);
void swapColumn(double matrix[n][n], int column1, int column2);
void swapRow(double matrix[n][n], int row1, int row2);
int findSmallest (double matrix[n][n],  int *row, int *column);
int findLargest (double matrix[n][n],  int *row, int *column);
bool findValue (double matrix[n][n], double value, int *row, int *column);
void valueMultRow(double matrix[n][n], double value, int row);
void addRows (double matrix[n][n],  int row1, int row2);
void valueMultColumn(double matrix[n][n], double value, int column);
void addColumns (double matrix[n][n],  int column1, int column2);
int main(){


	double a[n][n], number ;
	int choice, row, column;
	bool isA = 0;
	do{


		cout << "What do you want to do? Enter 0 to quit: ";
		cin >> choice;

		switch (choice){
		case 1: createMatrix(a);
			isA = 1;
			break;
		case 2: if (isA) printMatrix(a, 1);
				else cout << "a has not been created" << endl;
			break;
		case 3: cout << "Sorry.  Three was not completed. " << endl;
			break;
		case 4: cout << "Sorry.  Four was not completed. " << endl;
			break;
		case 5: if (isA){cout << "Enter the row followed by the column: ";
			cin >> row >> column;
			cout << "The value at row " << row << " column " << column << " is " << a[row][column];
				}
				else cout << "a has not been created" << endl;
				
			break;
		case 6: if (isA) {
				
				cout << "What is the value you would like the find? ";
				cin >> number;

				bool isPresent = findValue(a,number,&row,&column);

				if (isPresent){ cout << "The value is present at row " << row << " column " << column << "." << endl;}
				else{ cout << "The value is not present in the matrix" << endl;}
				}
				else cout << "a has not been created" << endl;
					break;

		case 7: if (isA){
						cout << "What value would you like to multiply by? " ;
						cin >> number;
						cout << "What row would you like to multiply? ";
						cin >> row;
						valueMultRow(a, number, row);
					
				}

				else cout << "a has not been created" << endl;
					break;

		case 8: if (isA){
			cout << "What two rows would you like to add? ";
			int row2;
			cin >> row >> row2;
			addRows(a,row,row2);
				}
				else cout << "a has not been created" << endl;
					break;

case 9: if (isA){
						cout << "What value would you like to multiply by? " ;
						cin >> number;
						cout << "What column would you like to multiply? ";
						cin >>column;
						valueMultColumn(a, number, column);
					
				}

				else cout << "a has not been created" << endl;
					break;

		case 10: if (isA){
			cout << "What two columns would you like to add? ";
			int column2;
			cin >> column >> column2;
			addColumns(a,column,column2);
				}
				else cout << "a has not been created" << endl;
					break;



case 11: if (isA){
		double low = findSmallest(a, &row, &column);

		cout << "The smallest number is " << low << " located at " << row << " " << column << "." << endl;
				}
				else cout << "a has not been created" << endl;
					break;
case 12: if (isA){
		double high = findLargest(a, &row, &column);

		cout << "The biggest number is " << high << " located at " << row << " " << column << "." << endl;
				}
				else cout << "a has not been created" << endl;
					break;
		

		case 13: if (isA){
			transposeMatrix(a);
				 }
				 else cout << "a has not been created" << endl;
					break;
case 14: if (isA){
	cout << "What two rows would you like to swap? ";
			int row2;
			cin >> row >> row2;
			swapRow(a,row,row2);
				 }
				 else cout << "a has not been created" << endl;
					break;

					case 15: if (isA){
	cout << "What two columns would you like to swap? ";
			int column2;
			cin >> column >> column2;
			swapColumn(a,column,column2);
				 }
				 else cout << "a has not been created" << endl;
					break;
		}
	}while (choice != 0);


	system("pause");
	return 0;
}


void createMatrix(double matrix[n][n]){

	int a, b = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{

			a = rand ();
			while (b == 0){b = rand ();}

			matrix[i][j] = (double) a / (double) b;
			
		}
	}
}
void printMatrix(double matrix[n][n], bool isRowWise){
	
	if (isRowWise)
	for (int i = 0; i < n; i++){

		for (int j = 0; j < n; j++){
			cout  << matrix[i][j] << " ";
		}
		cout << endl;
		
	}

	else
	for (int i = 0; i < n; i++){

		for (int j = 0; j < n; j++){
			cout << matrix[j][i] << " ";
		}
		cout << endl;
		
	}
	cout << endl << endl;

}
void addMatrix(double matrix1[n][n], int matrix2[n][n],  int matrix[n][n]){
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = matrix1[i][j] + matrix2[i][j];
			
		}
	}
}

void transposeMatrix(double matrix[n][n], double transpose[n][n])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			transpose[i][j] = matrix[j][i];
			
		}
	}
}

void transposeMatrix(double matrix[n][n])
{

	
	int temp;

	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;			
		}
	}

	
}

void multMatrix(double matrix1[n][n], int matrix2[n][n],  int matrix[n][n], bool isRowWise){
// for knowing purposes, to multiply a matrix:

	/*
		matrix1[a][b] and matrix2[m][n]

		b must be equal to m and the dimensions of the new array will be a * n;
	*/



	for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)
        {
            matrix[i][j]=0;
		}
	}


	if (isRowWise){
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
			matrix[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}

	}

	else
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
			matrix[i][j] += matrix1[i][k] * matrix2[j][k];
			}
		}
	}



}






bool findValue (double matrix[n][n], double value, int *row, int *column)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == value)
			{
				*row = i;
				*column = j;
				return 1;
			}
		}
	}

	return 0;
}

void valueMultRow(double matrix[n][n], double value, int row)
{
	for (int i = 0; i < n; i++)
	{
		matrix[row][i] *= value;
	}
}

void addRows (double matrix[n][n],  int row1, int row2)
{
	for (int i = 0; i < n; i++)
	{
		matrix[row2][i] += matrix[row1][i];
	}
}

void valueMultColumn(double matrix[n][n], double value, int column)
{
	for (int i = 0; i < n; i++)
	{
		matrix[i][column] *= value;
	}
}

void addColumns (double matrix[n][n],  int column1, int column2)
{
	for (int i = 0; i < n; i++)
	{
		matrix[i][column2] += matrix[i][column1];
	}
}

int findSmallest (double matrix[n][n],  int *row, int *column)
{

	double smallest = 100000;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] < smallest)
			{
				*row = i;
				*column = j;
				smallest = matrix[i][j];
			}
		}
	}

	return smallest;
}

int findLargest (double matrix[n][n],  int *row, int *column)
{

	double largest = -1000000;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] > largest)
			{
				*row = i;
				*column = j;
				largest = matrix[i][j];
			}
		}
	}

	return largest;
}

void swapRow(double matrix[n][n], int row1, int row2)
{

	
	double temp;

	for (int i = 0; i < n; i++)
	{
		
			temp = matrix[row1][i];
			matrix[row1][i] = matrix[row2][i];
			matrix[row2][i] = temp;			
		
	}

	
}

void swapColumn(double matrix[n][n], int column1, int column2)
{

	
	double temp;

	for (int i = 0; i < n; i++)
	{
		
			temp = matrix[i][column1];
			matrix[i][column1] = matrix[i][column2];
			matrix[i][column2] = temp;			
		
	}

	
}