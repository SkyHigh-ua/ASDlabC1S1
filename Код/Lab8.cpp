#include <iostream>
#include <iomanip>
#include <ctime>

void crmatrix(int **, int, int, int, int);
void colminlst(int **, int [], int, int, int);
void sort(int [], int);
void out(int [], int);

int main()
{
    const int row = 5, col = 8, rmax=99, rmin=10;
    int **matrix = new int *[row];
    int res[col];
    for (int i=0; i<row; i++)
    {
        matrix[i] = new int [col];
    }
    crmatrix(matrix, row, col, rmax, rmin);
    std::cout << "Згенерована матриця:" << std::endl;
    for (int i=0; i<row; i++)
    {
        std::cout << "|";
        for (int j=0; j<col; j++)
        {
            std::cout << std::setw(3) << matrix[i][j];
        }
        std::cout << std::setw(2) << "|" << std::endl;
    }
    colminlst(matrix, res, row, col, rmax);
    for (int i=0; i<row; i++)
    {
        delete [] matrix[i];
    }
    delete [] matrix;
    std::cout << "Знайдений масив = ";
    out(res, col);
    sort(res, col);
    std::cout << "Відсортований масив = ";
    out(res, col);
    return 0;
}

void crmatrix(int **mtrx, int row, int col, int rmax, int rmin)
{
    srand(time(NULL));
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            mtrx[i][j]= rand()%(rmax - rmin) + rmin;
        }
    }
}

void colminlst(int **mtrx, int lst[], int row, int col, int rmax)
{
    for (int i=0; i<col; i++)
    {
        int min = rmax;
        for (int j=0; j<row; j++)
        {
            if (mtrx[j][i] < min)
            {
                min = mtrx[j][i];
            }
        }
        lst[i] = min;
    }
}

void sort(int lst[], int len)
{
    for (int i = len / 2; i > 0; i /= 2) 
    {
        for (int j = i; j < len; j++) 
        {
            for (int k = j - i; k >= 0; k--) 
            {
                if (lst[k] > lst[k + i])
                {
                    lst[k + i] += lst[k];
                    lst[k] = lst[k + i] - lst[k];
                    lst[k + i] -= lst[k];
                }
            }
        }
    }
}

void out(int lst[], int len)
{
    std::cout << "[";
    for (int i=0; i<len; i++)
    {   
        std::cout << std::setw(3) << lst[i];
        if (i<len-1) std::cout << ",";
    }
    std::cout << std::setw(2) << "]" << std::endl;
}