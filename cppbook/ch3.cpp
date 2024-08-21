#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

void counter();
void string_example();
void inventory();
void tic_tac_toe();

int main()
{
    // counter();
    // string_example();
    inventory();
    // tic_tac_toe();
    return 0;
}

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
    string word1 = "Game";
    string word2("Over");
    string word3(3, '!');

    string phrase = word1 + " " + word2 + word3;
    cout << "The phrase is: " << phrase << "\n\n";

    cout << "The phrase has " << phrase.size() << " characters in it.\n\n";

    cout << "The character at position 0 is: " << phrase[0] << "\n\n";

    cout << "Changing the character at position 4 and 5.\n";
    phrase[4] = 'J';
    phrase[5] = 'o';
    cout << "The phrase is now: " << phrase << "\n\n";

    for (unsigned int i = 0; i < phrase.size(); i++)
    {
        cout << "Character at position " << i << " is: " << phrase[i] << endl;
    }

    cout << "\nThe sequence 'Jover' begins at location ";
    cout << phrase.find("Jover") << endl;

    if (phrase.find("Over") == string::npos)
    {
        cout << "'Over' is not in the phrase.\n\n";
    }

    phrase.erase(4, 5);
    cout << "The phrase is now: " << phrase << endl;

    phrase.erase(4);
    cout << "The phrase is now: " << phrase << endl;

    phrase.erase();
    cout << "The phrase is now: " << phrase << endl;

    if (phrase.empty())
    {
        cout << "The phrase is no more.\n";
    }
}

void inventory()
{
    cout;
}

void tic_tac_toe()
{
    cout;
}


