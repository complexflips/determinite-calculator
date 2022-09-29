// determinite calculator.cpp 
// coded by Aubreye Freeman
// this program is coded in order to find the determinate of a matrix 

#include <iostream>
#include <vector>
using namespace std;

void print(int n, vector<vector<int>> arr) {//print function
    for (int x = 0; x < n; x++) {// for loop to output a given 2d vector
        for (int y = 0; y < n; y++) {
            cout << arr[x][y];
        }
        cout << endl;
    }
}
// function that creates a 2d vector (arr1) with values from a previous 2d vector (arr) with a size of (n-1.n-1)
vector<vector<int>> create(int row, int col, int size, vector<vector<int>> arr, vector<vector<int>> arr1) {
    vector<int> temp;// temporary 1d vector                                                                                       
    for (int i = 0; i < size; i++) {//for loop to enter values into the new vector
        for (int j = 0; j < size; j++) {
            if ((col != i) && (row != j)) {//leave out a certian row and column determined in det function
                temp.push_back(arr[i][j]);//enter values into the temporary 1d vector in order to form a row

            }
        }
        if (col != i) {
            arr1.push_back(temp);//insert the temp vector into the arr1 2d vector
            temp.clear();// clear the temp vector to reuse for next row
        }
        
    }
    return arr1;
}
int det(int size, vector<vector<int>>arr ) {
    if (size == 1)//base condition
        return arr[0][0];//the determinite of a 1X1 matrix is the value in that matrix
    else if (size > 1) {//recursive condition
        vector <vector <int>>arr1;//a 2d vector that will be made smaller
        int col = 0;//what column will be removed in the smaller matrix
        int rows = 0;//what row will be removed in the smaller matrix
        int temp = 0;//temporary int variable
        int sum = 0;//value that holds the sum of determinates 
        
        for (int i = 0; i < size; i++) {//loop used to sum 
            
            temp = (pow(-1,i))*arr[0][i] *det(size - 1, (create(rows, col, size, arr, arr1)));//formula for determinate
            //(-1^i) alternating sign
            //arr[0][i] multiply by the value in row 1 and column n
            //det() find the determinate of a matrix size n-1Xn-1 where row 0 and column n are removed when compaired to base matrix
            rows++;//do not use the next row in calculating the determinite of n-1Xn-1 matrix
            sum += temp;//add the value stored in the temporary integer to sum
            
        }
        return sum; 
    }
    else
        return 0;
}


int main()
{
    int n = 0;
    

    cout << "what size of square matrix would you like to compute \n";
    cin >> n;
    
    vector <int> row(n,0);//initialize a row
    vector <vector <int>>arr(n, row);//initialize the 2d vector
    
    for (int i = 0; i< n; i++) {// for loop to fill in the 2d vector
        for (int j=0; j <n; j++) {
            cout << "enter value for (" << i+1 << " , " << j+1 <<")" << endl;
            cin >> arr[i][j];
        }
    }
    
    
    cout << "the matrix you entered is \n";//print the first 2d vector
    print(n, arr);//call print

    cout << "the determinate of that matrix is " << det(n,arr);//call determinate function

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
