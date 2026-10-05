#include "TriangleQuestion.h"

TriangleQuestion::TriangleQuestion(int id, double x, double y, double z)
{
    qid = id;
    a = x;
    b = y;
    c = z;
    correctArea = calcArea();
    userAnswer = 0;
}

bool TriangleQuestion::isLegalTriangle()
{
    if (a > 0 && b > 0 && c > 0 && (a + b > c) && (a + c > b) && (b + c > a))
        return true;
    return false;
}

double TriangleQuestion::calcArea()
{
    if (!isLegalTriangle())
        return 0;
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void TriangleQuestion::setUserAns(double ans)
{
    userAnswer = ans;
}

int TriangleQuestion::getQid()
{
    return qid;
}

double TriangleQuestion::getCorrectAns()
{
    return correctArea;
}

void TriangleQuestion::showQuestion()
{
    cout << "【题目" << qid << "】三角形三边：" << a << " " << b << " " << c << endl;
    if (isLegalTriangle())
        cout << "请计算三角形面积：" << endl;
    else
        cout << "该三边无法构成三角形！" << endl;
}