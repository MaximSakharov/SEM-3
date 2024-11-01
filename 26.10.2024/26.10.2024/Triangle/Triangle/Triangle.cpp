#pragma warning (disable: 4996)

#include "Triangle.hpp"
#include "functions.hpp"
#include <math.h>

const double epsilon = 1e-9;

double Point::VectorLength() const
{
   return Pythag(*this, Point());
}

static int amount = 0;

/*
Triangle::Triangle()
   : vertex1(0, 0), vertex2(0, 0), vertex3(0, 0), side1(0), side2(0), side3(0)
{
   name = new char[100];
   strcpy(name, "Triangle");
   
   sprintf(name, "Triangle %d ", count);

   count++;
}
*/

Triangle::Triangle(Point v1_, Point v2_, Point v3_)
   : vertex1(v1_), vertex2(v2_), vertex3(v3_)
{
   side1 = Pythag(vertex1, vertex2);
   side2 = Pythag(vertex2, vertex3);
   side3 = Pythag(vertex1, vertex3);

   // Check triangle inequality
   if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
      throw 1;
   }

   name = new char[100];
   sprintf(name, "Triangle %d", count);

   ++count;
}

Triangle::Triangle(const Triangle& other_)
   :vertex1(other_.vertex1), vertex2(other_.vertex2), vertex3(other_.vertex3), side1(other_.side1), side2(other_.side2), side3(other_.side3)
{
   /*
   if (other_.name) {
      name = new char[strlen(other_.name) + 1];
      strcpy(name, other_.name);
   }
   else {
      name = nullptr;
   }
   */
}

double Triangle::TriangleArea() 
{
   if (side1 <= 0 || side2 <= 0 || side3 <= 0)
      return 0;

   if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1)
      return 0;

   double s = (side1 + side2 + side3) / 2;

   // Площадь по формуле Герона
   double area = sqrt(s * (s - side1) * (s - side2) * (s - side3));

   return area;
}

Triangle& Triangle::operator=(const Triangle& other_) 
{
   if (this != &other_) 
   {
      //delete[] name;

      vertex1 = other_.vertex1;
      vertex2 = other_.vertex2;
      vertex3 = other_.vertex3;
      side1 = other_.side1;
      side2 = other_.side2;
      side3 = other_.side3;
      /*
      if (other_.name) {
         name = new char[strlen(other_.name) + 1];
         strcpy(name, other_.name);
      }
      else 
         name = nullptr;
      */
   }
   return *this;
}

bool Triangle::operator>(Triangle& triangle_)
{
   return TriangleArea() > triangle_.TriangleArea();
}

bool Triangle::operator<(Triangle& triangle_)
{
   return TriangleArea() < triangle_.TriangleArea();
}

bool Triangle::operator==(Triangle& triangle_)
{
   return TriangleArea() == triangle_.TriangleArea();
}

bool Triangle::operator!=(Triangle& triangle_)
{
   return TriangleArea() != triangle_.TriangleArea();
}

void Triangle::Move(double x_, double y_)
{
   vertex1.SetX(vertex1.GetX() + x_);
   vertex1.SetY(vertex1.GetY() + y_);
   vertex2.SetX(vertex2.GetX() + x_);
   vertex2.SetY(vertex2.GetY() + y_);
   vertex3.SetX(vertex3.GetX() + x_);
   vertex3.SetY(vertex3.GetY() + y_);
}

bool Triangle::IsTriangle()
{
   return (side1 + side2 > side3 || side1 + side3 > side2 || side2 + side3 > side1);
}

double TriangleArea2(const Point& point1_, const Point& point2_, const Point& point3_)
{
   double sub_side1 = Pythag(point1_, point2_);
   double sub_side2 = Pythag(point2_, point3_);
   double sub_side3 = Pythag(point3_, point1_);

   double s = (sub_side1 + sub_side2 + sub_side3) / 2;

   // Площадь по формуле Герона
   double area = sqrt(s * (s - sub_side1) * (s - sub_side2) * (s - sub_side3));

   return area;
}

bool Point::PointInTriangle(Triangle& triangle_)
{
   //2
   /*
   double total_area = triangle_.TriangleArea();
   double area1 = TriangleArea2(triangle_.GetVertex1(), triangle_.GetVertex2(), *this);
   double area2 = TriangleArea2(triangle_.GetVertex2(), triangle_.GetVertex3(), *this);
   double area3 = TriangleArea2(triangle_.GetVertex3(), triangle_.GetVertex1(), *this);

   return fabs(total_area - (area1 + area2 + area3)) < epsilon;
   */

   //1
   double param1 = ((triangle_.GetVertex1().GetX() - x) * (triangle_.GetVertex2().GetY() - triangle_.GetVertex1().GetY()) - (triangle_.GetVertex2().GetX() - triangle_.GetVertex1().GetX()) * (triangle_.GetVertex1().GetY() - y));
   double param2 = ((triangle_.GetVertex2().GetX() - x) * (triangle_.GetVertex3().GetY() - triangle_.GetVertex2().GetY()) - (triangle_.GetVertex3().GetX() - triangle_.GetVertex2().GetX()) * (triangle_.GetVertex2().GetY() - y));
   double param3 = ((triangle_.GetVertex3().GetX() - x) * (triangle_.GetVertex1().GetY() - triangle_.GetVertex3().GetY()) - (triangle_.GetVertex1().GetX() - triangle_.GetVertex3().GetX()) * (triangle_.GetVertex3().GetY() - y));

   if ((param1 == 0 || param2 == 0 || param3 == 0) || (param1 > 0 && param2 > 0 && param3 > 0) || (param1 < 0 && param2 < 0 && param3 < 0))
      return 1;
   else
      return 0;
   
}

bool Triangle::InTriangle(Triangle& triangle_)
{
   //1
   if (triangle_.vertex1.PointInTriangle(*this) == 1 && triangle_.vertex2.PointInTriangle(*this) == 1 && triangle_.vertex3.PointInTriangle(*this) == 1)
      return 1;
   else
      return 0;
   
   //3
   /*
   ORIENT or1 = Classify(triangle_.GetVertex1(), vertex1, vertex2);
   ORIENT or2 = Classify(triangle_.GetVertex2(), vertex2, vertex3);
   ORIENT or3 = Classify(triangle_.GetVertex3(), vertex3, vertex1);
   if ((or1 == RIGHT || or1 == BETWEEN)
      && (or2 == RIGHT || or2 == BETWEEN)
      && (or3 == RIGHT || or3 == BETWEEN)) return true;
   else return false;
   */
   
   //2
   //return (PointInTriangle(triangle_.vertex1) && PointInTriangle(triangle_.vertex2) && PointInTriangle(triangle_.vertex3));

}

void DeleteTriangle(Triangle* triangle_, int k)
{
   for (int i = k - 1; i < amount; ++i)
      triangle_[i] = triangle_[i + 1];
}
   
void Work_Triangle(Triangle* triangle_)
{
	int variant = 0;

   Point p1;
   Point p2;
   Point p3;

   double x = 0;
   double y = 0;

   int num1 = 0;
   int num2 = 0;

   Triangle new_triangle;

	while (variant != 8)
	{
		Print_Menu();

		variant = get_variant(8);

		switch (variant)
		{
		case 1:
         for (int i = 0; i < amount; ++i)
         {
            printf("%d ", i + 1);
            triangle_[i].Print();
            printf("\n");
         }
			break;
		case 2:
         try
         {
            printf("Insert points: ");
            scanf_s("%lf %lf", &x, &y);
            p1.ChangeCoor(x, y);
            scanf_s("%lf %lf", &x, &y);
            p2.ChangeCoor(x, y);
            scanf_s("%lf %lf", &x, &y);
            p3.ChangeCoor(x, y);
            //new_triangle = Triangle(p1, p2, p3);

            triangle_[amount] = Triangle(p1, p2, p3);
            ++amount;
            printf("\n");
         }
         catch (const int)
         {
            printf("It's not a triangle!\n");
         }
         break;
		case 3:
         printf("Insert number of triangle: ");
         scanf_s("%d", &num1);
         printf("Insert move by x and y: ");
         scanf_s("%lf %lf", &x, &y);
         triangle_[num1 - 1].Move(x, y);
         printf("\n");
         
			break;
		case 4:
         printf("Insert number of triangle: ");
         scanf_s("%d", &num1);
         printf("%lf", triangle_[num1 - 1].TriangleArea());
         printf("\n");
			break;
		case 5:
         printf("Insert number of first triangle: ");
         scanf_s("%d",&num1);
         printf("Insert number of second triangle: ");
         scanf_s("%d", &num2);
         if (triangle_[num1 - 1] > triangle_[num2 - 1])
            printf("%s > %s", triangle_[num1 - 1].GetName(), triangle_[num2 - 1].GetName());
         else
            printf("%s <= %s", triangle_[num1 - 1].GetName(), triangle_[num2 - 1].GetName());
         printf("\n");
			break;
		case 6:
         printf("Insert number of first triangle: ");
         scanf_s("%d", &num1);
         printf("Insert number of second triangle: ");
         scanf_s("%d", &num2);
         if (triangle_[num1 - 1].InTriangle(triangle_[num2 - 1]))
            printf("%s contains %s", triangle_[num1 - 1].GetName(), triangle_[num2 - 1].GetName());
         else
            printf("%s does not contains %s", triangle_[num1 - 1].GetName(), triangle_[num2 - 1].GetName());
         printf("\n");
			break;
      case 7:
         printf("Insert number of triangle to delete: ");
         scanf_s("%d", &num1);
         DeleteTriangle(triangle_, num1);
         --amount;
         printf("\n");
         break;
		}
		if (variant != 8)
			system("pause");
	}
}
