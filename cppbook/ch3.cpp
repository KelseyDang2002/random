#include <iostream>
using std::cout;
using std::endl;

void counter()
{
    cout << "\nCounting forward:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << i << " ";
    }

    cout << "\n\nCounting backward:\n";
    for (int i = 9; i >= 0; i--)
    {
        cout << i << " ";
    }

    cout << "\n\nCounting by fives:\n";
    for (int i = 0; i <= 50; i += 5)
    {
        cout << i << " ";
    }

    cout << "\n\nCounting with NULL statements:\n";
    int count = 0;
    for ( ; count < 10; )
    {
        cout << count << " ";
        count++;
    }

    cout << "\n\nCounting with nested for loops:\n";
    const int ROWS = 5;
    const int COLUMNS = 3;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            cout << "(" << i << "," << j << ")\t";
        }

        cout << endl;
    }
}

void string_example()
{
    cout;
}

int main()
{
    // counter();
    string_example();
    return 0;
}
