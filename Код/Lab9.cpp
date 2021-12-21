#include <iostream>
#include <iomanip>
#include <ctime>

void crmatrix(double **, int, double, double); // створення матриці обходом по стовпцях
int find(double **, int, double, int *); // пошук місцезнаходження елементу Х
double arthm(double **, int); // пошук середньоарифметичного елементів під побічною діагоналлю
void out(double **, int); // вивід матриці

int main()
{
    int len, row, col;
    double X, arthmean, num, step = 1;
    std::cout << "Введіть n = ";
    std::cin >> len;
    srand(time(NULL));
    num = rand()%10 + -5;
    std::cout << "Згенероване початкове число = " << num << std::endl;
    std::cout << "Введіть X = ";
    std::cin >> X;
    double **matrix = new double *[len];
    for (int i=0; i<len; i++)
    {
        matrix[i] = new double [len];
    }
    crmatrix(matrix, len, num, step);
    out(matrix, len);
    row = find(matrix, len, X, &col);
    if (row == 0) 
    {
        std::cout << "Елемент X відсутній на побічній діагоналі" << std::endl;
        return 0;
    }
    else std::cout << "Месцезнаходження елементу X - " << row << " рядок, " << col << " стовпець" << std::endl;
    arthmean = arthm(matrix, len);
    std::cout << "Середньоарифметичне елементів під побічною діагоналлю = " << arthmean << std::endl;
    if (arthmean == X) std::cout << "Елемент X рівний середньоарифметичному" << std::endl;
    else if (arthmean > X) std::cout << "Елемент X менший за середньоарифметичне" << std::endl;
    else std::cout << "Елемент X більший за середньоарифметичне" << std::endl;
    for (int i=0; i<len; i++)
    {
        delete [] matrix[i];
    }
    delete [] matrix;
    return 0;
}

void crmatrix(double **mtrx, int len, double num, double step)
{
    int k;
    mtrx[0][0] = num;
    for (int i=0; i<len; i+=2)
    {
        mtrx[0][i] = num + step*i*len;
        for (int j=1; j<len; j++)
        {
            mtrx[j][i]= mtrx[j-1][i] + step;
        }
        k = i + 1;
        if (k < len)
        {
            mtrx[len-1][k] = num + step*k*len;
            for (int j=len-2; j>=0; j--)
            {
                mtrx[j][k]= mtrx[j+1][k] + step;
            }
        }
    }
}

int find(double **mtrx, int len, double X, int *col)
{
    int j = 0;
    for (int i = len - 1; i>=0; i--)
    {
        if ( mtrx[i][j] == X )
        {
            *col = j + 1;
            return i + 1;
        }
        j++;
    }
    return 0;
}

double arthm(double **mtrx, int len)
{
    int j = 1;
    double res = mtrx[0][0];
    for (int i = len - 1; i>0; i--)
    {
        res += mtrx[i][j];
        j++;
    }
    res /= len;
    return res;
}

void out(double **mtrx, int len)
{
    std::cout << "Згенерована матриця:" << std::endl;
    for (int i=0; i<len; i++)
    {
        std::cout << "|";
        for (int j=0; j<len; j++)
        {
            std::cout << std::setw(3) << mtrx[i][j];
        }
        std::cout << std::setw(2) << "|" << std::endl;
    }
}