// Homework20.03.2024 2d dinamic arrays.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;


int** addStrk(int** ar, int width, int heigth);
int** DelStrk(int** ar, int width, int heigth);
int** addStolbets(int** ar, int width, int heigth);
int** DelStolbets(int** ar, int width, int heigth);
int main()
{
    unsigned int width = 8;
    unsigned int heigth = 7;

    int** ar = new int* [heigth];
    cout << "Array:\n\n";
    for (int y = 0; y < heigth; y++)
    {
        cout << "\t\t";
        ar[y] = new int[width];
        for (int x = 0; x < width; x++)
        {
            ar[y][x] = rand() % 100;
            cout << ar[y][x] << "\t";
        }
        cout << "\n\n";
    }

    int** arAddStrk = addStrk(ar, width, heigth);
    cout << "Array with added string to the end:\n\n";
    for (int y = 0; y < heigth + 1; y++) 
    {
        cout << "\t\t";
        for (int x = 0; x < width; x++) 
        {
            cout << arAddStrk[y][x] << "\t";
        }
        cout << "\n\n";
    }
    
    int** arDelStrk = DelStrk(ar, width, heigth + 1);
    cout << "Array with deleted string to the end:\n\n";
    for (int y = 0; y < heigth; y++)
    {
        cout << "\t\t";
        for (int x = 0; x < width; x++)
        {
            cout << arDelStrk[y][x] << "\t";
        }
        cout << "\n\n";
    }
    
    int** arAddStolbets = addStolbets(ar, width, heigth);
    cout << "Array with added stolbets to the end:\n\n";
    for (int y = 0; y < heigth; y++)
    {
        cout << "\t\t";
        for (int x = 0; x < width + 1; x++)
        {
            cout << arAddStolbets[y][x] << "\t";
        }
        cout << "\n\n";
    }
    
    int** arDelStolbets = DelStolbets(ar, width +1, heigth);
    cout << "Array with deleted stolbets to the end:\n\n";
    for (int y = 0; y < heigth; y++)
    {
        cout << "\t\t";
        for (int x = 0; x < width; x++)
        {
            cout << arDelStolbets[y][x] << "\t";
        }
        cout << "\n\n";
    }
    
    
    for (int y = 0; y < heigth; y++) 
    {
        delete[] ar[y];
    }
    delete[] ar;
    ar = nullptr;
    
    for (int y = 0; y < heigth ; y++) 
    {
        delete[] arAddStrk[y];
    }
    delete[] arAddStrk;
    arAddStrk = nullptr;
    
    for (int y = 0; y < heigth; y++)
    {
        delete[] arDelStrk[y];
    }
    delete[] arDelStrk;
    arDelStrk = nullptr;
    
    for (int y = 0; y < heigth; y++)
    {
        delete[] arAddStolbets[y];
    }
    delete[] arAddStolbets;
    arAddStolbets = nullptr;

    for (int y = 0; y < heigth; y++)
    {
        delete[] arDelStolbets[y];
    }
    delete[] arDelStolbets;
    arDelStolbets = nullptr;
}


int** addStrk(int** ar, int width, int heigth)
{
    int** arAddStrk = new int* [heigth + 1];
    for (int y = 0; y < heigth; y++)
    {
        arAddStrk[y] = new int[width];
        for (int x = 0; x < width; x++)
        {
            arAddStrk[y][x] = ar[y][x];
        }
    }
    arAddStrk[heigth] = new int[width] {};
    return arAddStrk;
}
int** DelStrk(int** arAddStrk, int width, int heigth)
{
    int** arDelStrk = new int* [heigth];
    for (int y = 0; y < heigth - 1; y++)
    {
        arDelStrk[y] = new int[width];
        for (int x = 0; x < width; x++)
        {
            arDelStrk[y][x] = arAddStrk[y][x];
        }
    }
    arDelStrk[heigth - 1] = new int[width];
    return arDelStrk;
}

int** addStolbets(int** arDelStrk, int width, int heigth)
{
    int** arAddStolbets = new int* [heigth];
    for (int y = 0; y < heigth; y++)
    {
        arAddStolbets[y] = new int[width + 1];
        for (int x = 0; x < width; x++)
        {
            arAddStolbets[y][x] = arDelStrk[y][x];
        }
        arAddStolbets[y][width] = 0;
    }
    
    return arAddStolbets;
}

int** DelStolbets(int** ar, int width, int heigth)
{
    int** arDelStolbets = new int* [heigth];
    for (int y = 0; y < heigth; y++)
    {
        arDelStolbets[y] = new int[width -1];
        for (int x = 0; x < width - 1; x++)
        {
            arDelStolbets[y][x] = ar[y][x];
        }
    }
    return arDelStolbets;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
