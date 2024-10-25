#include <iostream>
#include <string.h>
#include <math.h>

enum ORIENT { LEFT, RIGHT, AHEAD, BEHIND, BETWEEN };

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
   Point operator+(const Point& point_) const { return Point(x + point_.x, y + point_.y); }
   Point operator-(const Point& point_) const { return Point(x - point_.x, y - point_.y); }
   void operator+=(const Point& point_) { x += point_.x; y += point_.y; }
   void operator-=(const Point& point_) { x -= point_.x; y -= point_.y; }
   double VectorLength() const;

   double Length() const { return sqrt(x * x + y * y); }
   
   bool PointInTriangle(Triangle& triangle_);



};


class Triangle
{
private:
   char* name;
   static int count;
   Point vertex1;
   Point vertex2;
   Point vertex3;
   double side1;
   double side2;
   double side3;
public:
   //Triangle();
   Triangle(Point v1_ = (0, 0), Point v2_ = (0, 0), Point v3_ = (0, 0));
   ~Triangle() { delete[] name; }
   Triangle(const Triangle& other_);
   Point GetVertex1() const { return vertex1; };
   Point GetVertex2() const { return vertex2; };
   Point GetVertex3() const { return vertex3; };
   double GetSide1() { return side1; };
   double GetSide2() { return side2; };
   double GetSide3() { return side3; };
   const char* GetName() { return name; };
   void IncreaseCount() { ++count; }
   double TriangleArea();
   void Move(double x_, double y_);
   
   bool InTriangle(Triangle& triangle_);
   Triangle& operator=(const Triangle& other_);
   bool operator>(Triangle& triangle_);
   bool operator<(Triangle& triangle_);
   bool operator==(Triangle& triangle_);
   bool operator!=(Triangle& triangle_);
   void Print() { printf("%s ", name); vertex1.Print(); vertex2.Print(); vertex3.Print(); }

   static Triangle* CreateTriangleArray(int size) 
   {
      int save_count = count;

      Triangle* triangles = new Triangle[size];

      count = save_count;

      return triangles;
   }

   /*
Функция ORIENT классифицирует положение точки current_p относительно отрезка, заданного точками beg_p и end_p.
Она использует векторный подход для определения следующего:

- LEFT: точка слева от отрезка.
- RIGHT: точка справа от отрезка.
- BEHIND: точка находится за началом отрезка.
- AHEAD: точка находится перед концом отрезка.
- BETWEEN: точка находится между beg_p и end_p.
*/
   ORIENT Classify(Point current_p, Point& beg_p, Point& end_p) const
   {
      Point pO = current_p;
      Point a = end_p - beg_p;   // вектор от beg_p до end_p
      Point b = pO - beg_p;      // вектор от beg_p до current_p
      double sa = a.GetX() * b.GetY() - b.GetX() * a.GetY();   // Вычисляется знак площади параллелограмма (векторное произведение)
      if (sa > 0.0) return LEFT;    // current_p слева от отрезка (beg_p, end_p)
      if (sa < 0.0) return RIGHT;   // current_p справа от отрезка (beg_p, end_p)
      if ((a.GetX() * b.GetX() < 0.0) || (a.GetY() * b.GetY() < 0.0)) return BEHIND; // Если b выходит за пределы a, возвращается BEHIND (точка за началом отрезка).
      if (a.Length() < b.Length()) return AHEAD;                                     // Если b находится дальше конца отрезка, будет возвращен AHEAD.
      return BETWEEN;                                                                // В противном случае точка находится между beg_p и end_p(BETWEEN).
   }
};


void Work_Triangle(Triangle* triangle_);