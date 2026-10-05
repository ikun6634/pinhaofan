#ifndef QUESTIONBANK_H
#define QUESTIONBANK_H

#include "TriangleQuestion.h"
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class QuestionBank
{
private:
    string bankName;
    int questionCount;
    vector<TriangleQuestion> qList;
    vector<double> scoreList;
    double avgScore;
public:
    QuestionBank(string name = "几何题库");
    void addQuestion(TriangleQuestion q);
    bool delQuestion(int id);
    void showAllQuestion();
    void doQuestion(int qid, double userInput);
    void calcAvg();
    void showScore();
};

#endif