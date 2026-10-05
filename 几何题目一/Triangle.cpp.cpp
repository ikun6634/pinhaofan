#include "Triangle.h"
#include <cmath>

//校验三边：边长>0，任意两边之和大于第三边
bool Triangle::isValid(double x, double y, double z)
{
    if(x <= 0 || y <=0 || z <= 0)
        return false;
    if( (x+y>z) && (x+z>y) && (y+z>x) )
        return true;
    return false;
}

//默认构造，初始化为合法3,4,5直角三角形
Triangle::Triangle()
{
    a = 3;
    b = 4;
    c = 5;
}

//重载构造函数，如果传入三边非法，重置为3,4,5
Triangle::Triangle(double x, double y, double z)
{
    if(isValid(x,y,z))
    {
        a = x;
        b = y;
        c = z;
    }
    else
    {
        cout<<"输入三边不合法！自动设置为3 4 5"<<endl;
        a = 3;
        b = 4;
        c = 5;
    }
}

void Triangle::setA(double x)
{
    //修改后要校验整体合法性
    if(isValid(x,b,c))
        a = x;
    else
        cout<<"修改a之后三边不合法，修改失败"<<endl;
}

void Triangle::setB(double y)
{
    if(isValid(a,y,c))
        b = y;
    else
        cout<<"修改b之后三边不合法，修改失败"<<endl;
}

void Triangle::setC(double z)
{
    if(isValid(a,b,z))
        c = z;
    else
        cout<<"修改c之后三边不合法，修改失败"<<endl;
}

double Triangle::getA(){ return a; }
double Triangle::getB(){ return b; }
double Triangle::getC(){ return c; }

//周长
double Triangle::getPerimeter()
{
    return a + b + c;
}

//海伦公式求面积
double Triangle::getArea()
{
    double p = (a+b+c)/2.0;
    return sqrt( p*(p-a)*(p-b)*(p-c) );
}

//判断三角形类型
void Triangle::showType()
{
    if(a==b && b==c)
        cout<<"这是等边三角形"<<endl;
    else if(a==b || b==c || a==c)
        cout<<"这是等腰三角形"<<endl;
    else
        cout<<"普通不等边三角形"<<endl;
}

void Triangle::showInfo()
{
    cout<<"边长a="<<a<<" b="<<b<<" c="<<c<<endl;
    cout<<"周长:"<<getPerimeter()<<endl;
    cout<<"面积:"<<getArea()<<endl;
    showType();
}
