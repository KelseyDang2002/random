#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::endl;
using std::cin;

void do_while_loop()
{
    char again;
    do
    {
        cout << "\n**Game**";
        cout << "\nPlay again? (y/n): ";
        cin >> again;
    } while (again == 'y');

    cout << "\nOkay. Bye.";
}

void counter()
{
    int count = 0;
    while (true)
    {
        count += 1;
        // end loop if greater than 10
        if (count > 10)
        {
            break;
        }
        // skip number 5
        if (count == 5)
        {
            continue;
        }

        cout << count << endl;
    }
}

void die_roller()
{
    srand(static_cast<unsigned int>(time(0)));
    int randomNumber = rand(); // generate random number
    int die = (randomNumber % 6) + 1; // random number betwwen 1 and 6
    cout << "You rolled a " << die << endl;
}

void number_guesser()
{
    srand(static_cast<unsigned int>(time(0)));

    int secretNumber = rand() % 100 + 1; // random number between 1 and 100
    int tries = 0;
    int guess;

    do
    {
        cout << "Enter a guess: ";
        cin >> guess;
        ++tries;

        if (guess > secretNumber)
        {
            cout << "Too high.\n\n";
        }
        else if (guess < secretNumber)
        {
            cout << "Too low.\n\n";
        }
        else
        {
            cout << "Correct. You got it in " << tries << " guesses.\n";
        }
    } while (guess != secretNumber);
}

int main()
{
    // do_while_loop();
    // counter();
    // die_roller();
    number_guesser();
    return 0;
}
