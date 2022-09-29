// determinite calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

void print(int n, vector<vector<int>> arr) {
    for (int x = 0; x < n; x++) {// for loop to output a given 2d vector
        for (int y = 0; y < n; y++) {
            cout << arr[x][y];
        }
        cout << endl;
    }
}
vector<vector<int>> create(int row, int col, int size, vector<vector<int>> arr, vector<vector<int>> arr1) {
    vector<int> temp;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((col != i) && (row != j)) {
                temp.push_back(arr[i][j]);

            }
        }
        if (col != i) {
            arr1.push_back(temp);
            temp.clear();
        }
        
    }
    return arr1;
}
int det(int size, vector<vector<int>>arr ) {
    if (size == 1)
        return arr[0][0];
    else if (size > 1) {
        vector <int> row;
        vector <vector <int>>arr1;
        int col = 0;
        int rows = 0;
        int temp = 0;
        int sum = 0;
        
        for (int i = 0; i < size; i++) {
            
            temp = (pow(-1,i))*arr[0][i] *det(size - 1, (create(rows, col, size, arr, arr1)));
            rows++;
            sum += temp;
            
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
    
    
    cout << "the matrix you entered is \n";
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
