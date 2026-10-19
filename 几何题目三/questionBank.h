#ifndef QUESTIONBANK_H
#define QUESTIONBANK_H
#include "triangle.h"

class QuestionBank
{
private:
    Triangle ques[10];
    int count;
public:
    QuestionBank();
    void addQuestion(Triangle t);
    void showAll();
};

#endif

