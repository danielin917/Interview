/*BOOL MATRIX PROBLEM
 *http://www.practice.geeksforgeeks.org/problem-page.php?pid=478
 */

#include <iostream>
using namespace std;

struct my_bool{
    bool b;  
    my_bool():b(false){}
    ~my_bool(){}
};
void destroy_matrix(my_bool** matrix, int rows)
{
    for(int i = 0; i < rows; i++)
    {
        delete [] matrix[i];
    }
    delete [] matrix;
}
void kill_col(my_bool** matrix, int target_c, int rows)
{
    for(int i = 0; i < rows; i++)
    {
    
        matrix[i][target_c].b = true;
    }
}
void kill_row(my_bool** matrix, int target_r, int cols)
{
    for(int i = 0; i < cols; i++)
    {
        matrix[target_r][i].b = true;
    }
}
void update_matrix(my_bool**& matrix, int rows, int cols)
{
    my_bool* killed_rows = new my_bool[rows];
    my_bool* killed_cols = new my_bool[cols];
    my_bool** new_matrix = new my_bool*[rows];
    for(int i = 0; i < rows; i++)
    {
         new_matrix[i] = new my_bool[cols];
    } 
    for(int r = 0; r < rows; r++)
    {
        	     

        for(int c = 0; c< cols; c++)
        {
            if(matrix[r][c].b)
            {
                if(!killed_rows[r].b)
                {
                    kill_row(new_matrix, r, cols);
                    killed_rows[r].b = true;
                }
                if(!killed_cols[c].b)
                {
                    kill_col(new_matrix, c, rows);
                    killed_cols[c].b = true;
                }
            }
                
        }
    }
    delete [] killed_rows;
    delete [] killed_cols;
    destroy_matrix(matrix, rows);
    matrix = new_matrix;
}
void print_matrix(my_bool** matrix, int rows,int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(matrix[i][j].b)
                cout << 1 << " ";
            else
                cout << 0 << " ";
        }
    }
}
int main() {
	int num_tests;
	my_bool** matrix;
	cin >> num_tests;
	for(int i = 0; i < num_tests; i++)
	{
	    int rows, cols;
	    cin >> rows >> cols;
	    matrix = new my_bool*[rows]; 
	    for(int r = 0; r < rows; r++)
	    {
	        matrix[r] = new my_bool[cols];
	        for(int c = 0; c < cols; c++)
	        {
	           
	            int x;
	            cin >> x;
	            if(x == 1)
	                matrix[r][c].b = true;
	        }
	    }
	    update_matrix(matrix, rows, cols);
	    print_matrix(matrix, rows, cols);
	    cout << endl;
	    destroy_matrix(matrix, rows);
	}
	return 0;
}
