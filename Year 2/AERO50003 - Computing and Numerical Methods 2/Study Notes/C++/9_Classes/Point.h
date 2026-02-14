#include <iostream>
using namespace std;

class Point
{
public:
    void setPoint(int x, int y);
    void printPoint();
    
private:
    int xPos;
    int yPos;
};

void Point::setPoint(int x, int y)
{
    xPos = x;
    yPos = y;
}

void Point::printPoint()
{
    cout << " x = " << xPos << endl;
    cout << " y = " << yPos << endl;
}