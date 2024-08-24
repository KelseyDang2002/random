#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

void inventory_2();
void inventory_3();
void high_scores();

int main()
{
    // inventory_2();
    // inventory_3();
    high_scores();
    return 0;
}

void inventory_2()
{
    vector<string> inventory;

    inventory.push_back("sword");
    inventory.push_back("armor");
    inventory.push_back("shield");

    cout << "You have " << inventory.size() << " items.\n";
    cout << "\nYour items:\n";
    for (unsigned int i = 0; i < inventory.size(); i++)
    {
        cout << inventory[i] << endl;
    }

    cout << "\nYou trade your sword for a battle axe.";
    inventory[0] = "battle axe";
    cout << "\nYour items:\n";
    for (unsigned int i = 0; i < inventory.size(); i++)
    {
        cout << inventory[i] << endl;
    }

    cout << "\nThe item name '" << inventory[0] << "' has";
    cout << inventory[0].size() << " letters in it.\n";

    cout << "\nYour shield is destroyed in a fierce battle.";
    inventory.pop_back();
    cout << "\nYour items:\n";
    for (unsigned int i = 0; i < inventory.size(); i++)
    {
        cout << inventory[i] << endl;
    }

    cout << "\nYou were robbed of all of your possessions by a thief.";
    inventory.clear();
    if (inventory.empty())
    {
        cout << "\nYou have nothing.";
    }
    else
    {
        cout << "\nYou have at least one item.\n";
    }
}

void inventory_3()
{
    vector<string> inventory;
    inventory.push_back("sword");
    inventory.push_back("armor");
    inventory.push_back("shield");

    vector<string>::iterator myIterator; // declare iterator
    vector<string>::const_iterator iter; // declare const iterator

    cout << "\nYour items:\n";
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        cout << *iter << endl;
    }

    cout << "\nYou trade your sword for a battle axe.";
    myIterator = inventory.begin(); // first element
    *myIterator = "battle axe";
    
    cout << "\nYour items:\n";
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        cout << *iter << endl;
    }

    cout << "\nThe item name '" << *myIterator << "' has ";
    cout << (*myIterator).size() << " letters in it.\n";

    cout << "\nThe item name '" << *myIterator << "' has ";
    cout << myIterator->size() << " letters in it.\n";

    cout << "\nYou recover a crossbow form a slain enemy.";
    inventory.insert(inventory.begin(), "crossbow");

    cout << "\nYour items:\n";
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        cout << *iter << endl;
    }

    cout << "\nYour armor is destroyed in a fierce battle.";
    inventory.erase((inventory.begin() + 2)); // armor is at index 2 from the beginning of the vector

    cout << "\nYour items:\n";
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        cout << *iter << endl;
    }
}

void high_scores()
{
    vector<int>::const_iterator iter;
}
