#ifndef TRIANGLEQUESTION_H
#define TRIANGLEQUESTION_H

#include <iostream>
#include <cmath>
using namespace std;

class TriangleQuestion
{
private:
    int qid;
    double a, b, c;
    double correctArea;
    double userAnswer;
public:
    TriangleQuestion(int id = 0, double x = 3, double y = 4, double z = 5);
    bool isLegalTriangle();
    double calcArea();
    void setUserAns(double ans);
    int getQid();
    double getCorrectAns();
    void showQuestion();
};

#endif