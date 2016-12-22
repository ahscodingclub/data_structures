#include <iostream>

using namespace std;

class Enemy
{
public:
    virtual void attack()
    {

    }
};

class Ninja: public Enemy
{
public:
    void attack()
    {
        cout << "Ninja attack!" << endl;
    }
};

class Monster: public Enemy
{
    void attack()
    {
        cout << "Monster attack!" << endl;
    }
};

int main()
{
    Ninja n;
    Monster m;
    Enemy *e1 = &n;
    Enemy *e2 = &m;
    e1->attack();
    e2->attack();
    return 0;
}
