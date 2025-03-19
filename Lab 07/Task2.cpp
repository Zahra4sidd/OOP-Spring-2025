#include <iostream>
#include <cmath>
using namespace std;

class Shape{
    protected:
    int positionX;
    int positionY;
    string color;
    public:
    Shape(int x,int y,string c):
    positionX(x),positionY(y),color(c){}
    virtual void draw() = 0;
    virtual float calcArea() = 0;
    virtual float calcPerimeter() = 0;
};
class Circle : public Shape{
    private:
    float radius;
    public:
    Circle(int x,int y,string c,float radius):
    Shape(x,y,c),radius(radius){}
    void draw() override{
        cout<<"Drawing a "<<color<<" circle at "<<"("<<positionX<<","<<positionY<<")"<<endl;
    }
    float calcArea() override{
        return M_PI * radius * radius;
    }
    float calcPerimeter() override{
        return 2 * M_PI * radius;
    }
};
class Rectangle : public Shape{
    private:
    float width;
    float height;
    public:
    Rectangle(int x,int y,string c,float w,float h):
    Shape(x,y,c),width(w),height(h){}
    void draw() override{
        cout<<"Drawing a "<<color<<" rectangle at "<<"("<<positionX<<","<<positionY<<")"<<endl;
    }
    float calcArea() override{
        return width * height;
    }
    float calcPerimeter() override{
        return 2 * (height + width);
    }
};
class Triangle : public Shape{
    private:
    float base,height,side1,side2,side3;
    public:
    Triangle(int x,int y,string c,float b,float h,float s1,float s2,float s3):
    Shape(x,y,c),base(b),height(h),side1(s1),side2(s2),side3(s3){}
    void draw() override{
        cout<<"Drawing a "<<color<<" triangle at "<<"("<<positionX<<","<<positionY<<")"<<endl;
    }
    float calcArea() override{
        return 0.5 * base * height;
    }
    float calcPerimeter() override{
        return side1 + side2 + side3;
    }
};
int main()
{
    Circle circle(0,0,"red",5);
    Rectangle rectangle(10,10,"blue",4,6);
    Triangle triangle(20,20,"green",3,4,5,6,4);
    circle.draw();
    cout << "Circle Area: " << circle.calcArea() << "\n";
    cout << "Circle Perimeter: " << circle.calcPerimeter() << "\n";

    rectangle.draw();
    cout << "Rectangle Area: " << rectangle.calcArea() << "\n";
    cout << "Rectangle Perimeter: " << rectangle.calcPerimeter() << "\n";

    triangle.draw();
    cout << "Triangle Area: " << triangle.calcArea() << "\n";
    cout << "Triangle Perimeter: " << triangle.calcPerimeter() << "\n";
    //Another Approach
    /*Shape* shapes[] = {&circle,&rectangle,&triangle};
    for(int i=0;i<3;i++){
        shapes[i]->draw();
        cout<<"Area: "<<shapes[i]->calcArea()<<endl;
        cout<<"Perimeter: "<<shapes[i]->calcPerimeter()<<endl;
        cout<<"--------------------------------"<<endl;
    }*/
}
