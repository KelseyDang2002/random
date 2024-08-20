#include <iostream>
using std::cout;
using std::endl;

void game_stats_3() 
{
    const int ALIEN_POINTS = 150;
    int aliensKilled = 10;
    int score = aliensKilled * ALIEN_POINTS;
    cout << "Score: " << score << endl;

    enum difficulty {NOVICE, EASY, NORMAL, HARD, UNBEATABLE};
    difficulty myDifficulty = NORMAL;

    enum shipCost {FIGHTER_COST = 25, BOMBER_COST, CRUISER_COST = 50};
    shipCost myShipCost = BOMBER_COST;
    cout << "\nTo upgrade ship to a Cruiser will cost "
    << (CRUISER_COST - myShipCost) << " Resource points.\n";
}

int main()
{
    game_stats_3();
    return 0;
}
