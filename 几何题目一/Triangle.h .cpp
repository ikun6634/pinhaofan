#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
using namespace std;

class Triangle
{
//私有成员，封装数据
private:
    double a, b, c;
    // 校验三边是否能构成三角形
    bool isValid(double x, double y, double z);

public:
    // 默认构造函数
    Triangle();
    // 重载构造函数
    Triangle(double x, double y, double z);

    // set 修改边长
    void setA(double x);
    void setB(double y);
    void setC(double z);

    // get 获取边长
    double getA();
    double getB();
    double getC();

    // 获取周长
    double getPerimeter();
    // 获取面积 海伦公式
    double getArea();
    // 判断三角形类型
    void showType();
    // 输出三角形全部信息
    void showInfo();
};

#endif
