#include <stdexcept>
#include <iostream>

class Platformer
{
private:
    int pos;
public:
    Platformer(int n, int position)
    {
        throw std::logic_error("Waiting to be implemented");
    }

    void jumpLeft()
    {
        throw std::logic_error("Waiting to be implemented");
    }

    void jumpRight()
    {
        throw std::logic_error("Waiting to be implemented");
    }

    int position()
    {
        throw std::logic_error("Waiting to be implemented");
    }
};

#ifndef RunTests
int main()
{
    Platformer platformer(6, 3);
    std::cout << platformer.position() << std::endl; // should print 3

    platformer.jumpLeft();
    std::cout << platformer.position() << std::endl; // should print 1

    platformer.jumpRight();
    std::cout << platformer.position() << std::endl; // should print 4
}
#endif