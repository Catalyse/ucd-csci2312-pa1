//
// Created by Ivo Georgiev on 8/25/15.
//

#include "Point.h"
#include <iomanip>
#include <cmath>
#include <iostream>

using namespace std;

double CalculateArea(Point &A, Point &B, Point &C);
double GetSemiPerimeter(double &A, double &B, double &C);
double GetPointDistance(Point A, Point B);

int main(void)
{
    int setX, setY, setZ;

    //The next section will initialize all three points via the constructor.
    cout << "Welcome to the 3d Triangle Area Calculation program." << endl;
    cout << "Please enter 3 coordinates for Point A, each followed by enter. E.G. 1 (Enter), 2 (Enter), etc.." << endl;
    cin >> setX;
    cin >> setY;
    cin >> setZ;
    Point *A = new Point(setX, setY, setZ);

    cout << "Please enter 3 coordinates for Point B, each followed by enter. E.G. 1 (Enter), 2 (Enter), etc.." << endl;
    cin >> setX;
    cin >> setY;
    cin >> setZ;
    Point *B = new Point(setX, setY, setZ);

    cout << "Please enter 3 coordinates for Point C, each followed by enter. E.G. 1 (Enter), 2 (Enter), etc.." << endl;
    cin >> setX;
    cin >> setY;
    cin >> setZ;
    Point *C = new Point(setX, setY, setZ);

    double area = CalculateArea(*A, *B, *C);

    cout << fixed << setprecision(2);
    cout << "The area of your traiangle is: " << area << endl;
    return 0;
}

//The functions below are used to calculate area based on herons method(Hero's method)

double GetPointDistance(Point A, Point B) //This function is used to get the side length between two points
{
    double distance = sqrt(pow((A.getX() - B.getX()),2) + pow((A.getY() - B.getY()),2) + pow((A.getZ() - B.getZ()),2));
    return distance;
}

double GetSemiPerimeter(double &A, double &B, double &C) //Gets the SemiPerimeter used in herons formula based on side lengths
{
    double s = (A+B+C)/2;
    return s;
}

double CalculateArea(Point &A, Point &B, Point &C) //Herons formula.
{
    double sideA = GetPointDistance(B, C);
    double sideB = GetPointDistance(A, C);
    double sideC = GetPointDistance(A, B);
    double s = GetSemiPerimeter(sideA,sideB,sideC);
    double area = sqrt(s*(s - sideA)*(s - sideB)*(s - sideC));
    return area;
}