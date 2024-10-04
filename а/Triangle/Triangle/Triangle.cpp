#pragma warning (disable: 4996)

#include "Triangle.hpp"
#include "functions.hpp"

static int count = 0;

Triangle::Triangle()
   : vertex1(0, 0), vertex2(0, 0), vertex3(0, 0)
{

}

Triangle::Triangle(Point v1_, Point v2_, Point v3_)
   : vertex1(v1_), vertex2(v2_), vertex3(v3_)
{
   side1 = Pythag(vertex1, vertex2); // Расстояние между первой и второй вершиной
   side2 = Pythag(vertex2, vertex3); // Расстояние между второй и третьей вершиной
   side3 = Pythag(vertex1, vertex3); // Расстояние между первой и третьей вершиной
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

bool Triangle::PointInTriangle(Point& point_)
{
   double param1 = ((vertex1.GetX() - point_.GetX()) * (vertex2.GetY() - vertex1.GetY()) - (vertex2.GetX() - vertex1.GetX()) * (vertex1.GetY() - point_.GetY()));
   double param2 = ((vertex2.GetX() - point_.GetX()) * (vertex3.GetY() - vertex2.GetY()) - (vertex3.GetX() - vertex2.GetX()) * (vertex2.GetY() - point_.GetY()));
   double param3 = ((vertex3.GetX() - point_.GetX()) * (vertex1.GetY() - vertex3.GetY()) - (vertex1.GetX() - vertex3.GetX()) * (vertex3.GetY() - point_.GetY()));

   if ((param1 == 0 || param2 == 0 || param3 == 0) || (param1 > 0 && param2 > 0 && param3 > 0) || (param1 < 0 && param2 < 0 && param3 < 0))
      return 1;
   else
      return 0;
}

bool Triangle::InTriangle(Triangle& triangle_)
{
   if (PointInTriangle(triangle_.vertex1) == 1 && PointInTriangle(triangle_.vertex2) == 1 && PointInTriangle(triangle_.vertex3) == 1)
      return 1;
   else
      return 0;
}

void DeleteTriangle(Triangle* triangle_, int k)
{
   for (int i = k - 1; i < count; ++i)
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

	while (variant != 8)
	{
		Print_Menu();

		variant = get_variant(8);

		switch (variant)
		{
		case 1:
         for (int i = 0; i < count; ++i)
         {
            printf("%d ", i + 1);
            triangle_[i].Print();
            printf("\n");
         }
			break;
		case 2:
         printf("Insert points: ");
         scanf("%lf %lf", &x, &y);
         p1.ChangeCoor(x, y);
         scanf("%lf %lf", &x, &y);
         p2.ChangeCoor(x, y); 
         scanf("%lf %lf", &x, &y);
         p3.ChangeCoor(x, y);
         triangle_[count] = Triangle(p1, p2, p3);
         ++count;
         printf("\n");
			break;
		case 3:
         printf("Insert number of triangle: ");
         scanf("%d", &num1);
         printf("Insert move by x and y: ");
         scanf("%lf %lf", &x, &y);
         triangle_[num1 - 1].Move(x, y);
         printf("\n");
			break;
		case 4:
         printf("Insert number of triangle: ");
         scanf("%d", &num1);
         printf("%lf", triangle_[num1 - 1].TriangleArea());
         printf("\n");
			break;
		case 5:
         printf("Insert number of first triangle: ");
         scanf("%d",&num1);
         printf("Insert number of second triangle: ");
         scanf("%d", &num2);
         if (triangle_[num1 - 1] > triangle_[num2 - 1])
            printf("Triangle number %d > Triangle number %d", num1, num2);
         else
            printf("Triangle number %d <= Triangle number %d", num1, num2);
         printf("\n");
			break;
		case 6:
         printf("Insert number of first triangle: ");
         scanf("%d", &num1);
         printf("Insert number of second triangle: ");
         scanf("%d", &num2);
         if (triangle_[num1 - 1].InTriangle(triangle_[num2 - 1]))
            printf("Triangle number %d contains Triangle number %d", num1, num2);
         else
            printf("Triangle number %d does not contains Triangle number %d", num1, num2);
         printf("\n");
			break;
      case 7:
         printf("Insert number of triangle to delete: ");
         scanf("%d", &num1);
         DeleteTriangle(triangle_, num1);
         --count;
         printf("\n");
         break;
		}
		if (variant != 8)
			system("pause");
	}
}