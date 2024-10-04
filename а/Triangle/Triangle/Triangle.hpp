#include <iostream>
#include <string.h>
#include <math.h>

class Point
{
private:
   double x;
   double y;
public:
   Point(double x_ = 0, double y_ = 0)
   {
      x = x_;
      y = y_;
   }
   double GetX() { return x; };
   double GetY() { return y; };
   void SetX(double x_) { x = x_; };
   void SetY(double y_) { y = y_; };
   void ChangeCoor(double x_, double y_) { x = x_; y = y_;};
   void Print() { printf("(%f , %f)", x, y); }
};

class Triangle
{
private:
   Point vertex1;
   Point vertex2;
   Point vertex3;
   double side1;
   double side2;
   double side3;
public:
   Triangle();
   Triangle(Point v1_, Point v2_, Point v3_);
   Point GetVertex1() { return vertex1; };
   Point GetVertex2() { return vertex2; };
   Point GetVertex3() { return vertex3; };
   double GetSide1() { return side1; };
   double GetSide2() { return side2; };
   double GetSide3() { return side3; };
   double TriangleArea();
   void Move(double x_, double y_);
   bool PointInTriangle(Point& point_);
   bool InTriangle(Triangle& triangle_);
   bool operator>(Triangle& triangle_);
   bool operator<(Triangle& triangle_);
   bool operator==(Triangle& triangle_);
   bool operator!=(Triangle& triangle_);
   void Print() { vertex1.Print(); vertex2.Print(); vertex3.Print();}
};

void Work_Triangle(Triangle* triangle_);