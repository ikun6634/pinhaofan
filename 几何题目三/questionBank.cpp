#include "questionBank.h"
#include <iostream>
using namespace std;

QuestionBank::QuestionBank()
{
    count = 0;
}

void QuestionBank::addQuestion(Triangle t)
{
    if (count < 10)
    {
        ques[count] = t;
        count++;
    }
}

void QuestionBank::showAll()
{
    for (int i = 0; i < count; i++)
    {
        cout << "第" << i + 1 << "题：" << endl;
        if (ques[i].isLegal())
        {
            cout << "周长：" << ques[i].getPerimeter() << " 面积：" << ques[i].getArea() << endl;
        }
        else
        {
            cout << "无效三角形" << endl;
        }
    }
}
