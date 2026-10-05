#include "QuestionBank.h"

int main()
{
    QuestionBank bank("三角形几何题库");

    TriangleQuestion q1(1, 3, 4, 5);
    TriangleQuestion q2(2, 2, 3, 4);
    TriangleQuestion q3(3, 1, 2, 3);

    bank.addQuestion(q1);
    bank.addQuestion(q2);
    bank.addQuestion(q3);

    bank.showAllQuestion();

    cout << "\n--------用户做题--------" << endl;
    bank.doQuestion(1, 6.0);
    bank.doQuestion(2, 2.90);
    bank.doQuestion(3, 99);

    bank.showScore();

    cout << "\n-------删除2号题目-------" << endl;
    bank.delQuestion(2);
    bank.showAllQuestion();

    return 0;
}