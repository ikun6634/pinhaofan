#include <iostream>
#include "shape.h"
#include "triangle.h"
#include "questionBank.h"
using namespace std;

int main()
{
    
    Triangle t1(3, 4, 5);
    if (t1.isLegal())
    {
        cout << "三角形t1：周长=" << t1.getPerimeter() << "，面积=" << t1.getArea() << endl;
    }

    
    QuestionBank bank;
    bank.addQuestion(Triangle(3, 4, 5));
    bank.addQuestion(Triangle(2, 2, 3));
    bank.addQuestion(Triangle(1, 2, 3));

    cout << "\n=====题库题目=====" << endl;
    bank.showAll();

    return 0;
}
