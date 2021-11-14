#include <iostream>

int bin(int);

int main()
{
    int num, res;
    std::cout << "Введіть натуральне число десяткової системи = ";
    std::cin >> num;
    res = bin(num);
    std::cout << "Число " << num << " в двійковій системі числення: " << res << std::endl;
    return 0;
}

int bin(int num)
{
    int bit, binum = 0;
    if (num > 1) 
    {
        binum = bin(num / 2);
    }
    bit = num % 2;
    binum *= 10;
    binum += bit;
    return binum;
}