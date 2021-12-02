#include <iostream>
#include <iomanip>

void crlst(char [], char []); // Створення 1 та 2 масиву 
void lstout(char [], int n = 0); // Вивід n-ого масиву
int interlst(char [], char [], char []); // Створення 3-ого масиву та знаходження його довжини
void finlst(char [], float, int); // Обробка 3-ого масиву
float arthmean(char [], int); // Знаходження середнього арифметичного

int main()
{
    char lst1[10], lst2[10], lst3[10];
    int len;
    float arthm;
    crlst(lst1, lst2);
    len = interlst(lst1, lst2, lst3);
    lstout(lst1, 1);
    lstout(lst2, 2);
    lstout(lst3, 3);
    std::cout << "Кількість спільних елементів: " << len << std::endl;
    arthm = arthmean(lst3, len);
    std::cout << "Середнє арифметичне: " << arthm << std::endl;
    finlst(lst3, arthm, len);
    lstout(lst3);
    return 0;
}

void crlst(char lst1[], char lst2[])
{
    for (int i=0; i<10; i++)
        {
            lst1[i]=i+59;
            lst2[i]=64-i;
        }
}

void lstout(char lst[], int n)
{
    if (n!=0) std::cout << "Масив №" << n << " = [";
    else std::cout << "Результат = [";
    for (int i=0; i<10; i++)
    {
        if (lst[i]!=0) std::cout << std::setw(2) << lst[i];
        if (lst[i+1]!=0 && i!=9) std::cout << ",";
    }
    std::cout << std::setw(2) << "]" << std::endl;
}

int interlst(char lst1[], char lst2[], char lst3[])
{
    int len = 0;
    for (int i = 0; i<10; i++)
    {
        int j = 0;
        do
        {
            if (lst1[i] == lst2[j])
            {
                lst3[len] = lst1[i];
                len++;
            }
        }
        while (lst1[i] != lst2[j] && ++j<10);
    }
    return len;
}

void finlst(char lst[], float arthm, int len)
{
    for (int i=0; i<len; i++)
    {
        if (lst[i]>arthm)
        {
            lst[i]=0;
        }
    }
}

float arthmean(char lst[], int len)
{
    float sum = 0, res;
    for (int i=0; i<len; i++)
    {
        sum += lst[i];
    }
    res = sum/len;
    return res;
}