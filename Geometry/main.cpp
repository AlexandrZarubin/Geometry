#include<iostream>
using namespace std;
class Shape
{
public:
    virtual void get_Properties() const = 0;//размер
    virtual double get_area() const = 0;//площадь
    virtual double get_perimeter() const = 0;//перимитр
    virtual void draw() const = 0;//прорисовка
    virtual ~Shape() = 0;
};
Shape::~Shape() {};



//Прямоугольник
class Rectangle : public Shape 
{
private:
    int width, height;
public:
    Rectangle(int w=10, int h=5) : width(w), height(h) {}
    ~Rectangle()override {} 

    void get_Properties() const override 
    {
        cout << " ширина = " << width << ", длина = " << height << endl;
    }

    double get_area() const override 
    {
        return width * height;
    }

    double get_perimeter() const override 
    {
        return 2 * (width + height);
    }

    void draw() const override 
    {
        for (int i = 0; i < height; i++) 
        {
            for (int j = 0; j < width; j++) 
            {
               cout << "* ";
            }
            cout << endl;
        }
    }
};
//Квадрат
class Square : public Rectangle
{
private:
    int size;
public:
    Square(int Square = 7) : Rectangle (Square, Square){}
    ~Square()override {} 
};
//Круг
class Circle :public Shape
{
	double radius;
public:
	Circle(double radius=5):radius(radius){}
    ~Circle()override {}
    void get_Properties() const override 
    {
        cout << "диаметр круга = " << radius*2 << endl;
    }

    double get_area() const override 
    {
        return 3.14 * radius * radius;
    }

    double get_perimeter() const override 
    {
        return 2 * 3.14 * radius;
    }

    void draw() const override 
    {

        for (int i = -radius; i <= radius; i++)
        {
            for (int j = -radius; j <= radius; j++)
            {
                //(x-x0)^2+(y-y0)^2<=r^2
                //x^2+y^2=r^2
                //if (i * i + j * j <= radius * radius)
                if (sqrt(i * i + j * j) <= radius * 1.05)
                {
                    cout << "* ";
                }
                else 
                {
                    cout << "  ";
                }
            }
           cout << endl;
        }
    }
};
//треугольник
class Triangle : public Shape 
{
private:
    int a, b, c; // Стороны треугольника
public:
    Triangle(int a, int b, int c) : a(a), b(b), c(c) {}
    Triangle():a(3),b(4),c(5){}
    ~Triangle()override{}
    void get_Properties() const override 
    {
        cout << "стороны треуголника = " << a << ", " << b << ", " << c << endl;
    }

    double get_area() const override 
    {
        double s = ((double)a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double get_perimeter() const override 
    {
        return a + b + c;
    }

    void draw() const override 
    {
        int height = 2*get_area()/a;
        for (int i = 1; i <= height; i++) 
        {
            for (int j = 0; j < height - i; j++) 
            {
               cout << "  ";
            }
            for (int j = 0; j < 2 * i - 1; j++) 
            {
                cout << "* ";
            }
            cout << endl;
        }
    }
};

void main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    const int SIZE = 4;
    Shape** shapes=new Shape*[SIZE];
    int arr[SIZE]{};
    //Square square;
   // Rectangle rectangle;
    bool flag = true;
    int i = 0;
    do
    {
        flag = true;
        int Key = rand() % 4;
        for (int j = 0; j < i; j++)
        {
            if (Key == arr[j]) { flag = false; break; }
        }
        if (flag)
        {
            arr[i]=Key;
            switch (Key)
            {
            case 0:
            //shapes=&square;
                 shapes[i] = new Square();
                 break;

            case 1:
            //shapes =&rectangle;
                shapes[i] = new Rectangle();
                break;
             case 2:
                shapes[i] = new Circle();
                 break;
            case 3:
                shapes[i] = new Triangle();
                break;
            }

            i++;
        }
    } while (i<SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Площадь: " << shapes[i]->get_area() << endl;
        cout << "Периметр: " << shapes[i]->get_perimeter() << endl;
        shapes[i]->get_Properties();
        shapes[i]->draw();
    }
    for (int i = 0; i < SIZE; i++)delete shapes[i];
    delete[]shapes;
    


}