#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>


class Triangle {
public:
    Triangle();                              // (3) 默认构造函数
    Triangle(double x, double y, double z);  // (4) 重载构造函数
    ~Triangle();                             // 析构函数（用于观察对象生命周期）

    // ---- 合法性验证 ----
    static bool isValid(double x, double y, double z);
    bool isValid() const;

    // ---- 修改数据成员（带验证，失败返回 false，对象保持原状）----
    bool setSides(double x, double y, double z);
    bool setSideA(double x);
    bool setSideB(double y);
    bool setSideC(double z);

    // ---- 获取数据成员 ----
    double getA() const;
    double getB() const;
    double getC() const;

    // ---- 输出 ----
    void print() const;

    // ---- 扩展功能 ----
    double perimeter() const;      // 周长
    double area() const;           // 面积（海伦公式）
    bool isEquilateral() const;    // 是否等边
    bool isIsosceles() const;      // 是否等腰
    bool isRight() const;          // 是否直角
    std::string typeName() const;  // 类型名称

    // ---- 题库功能 ----
    void printQuestion() const;                          // 输出题目
    bool checkAnswer(double per, double areaVal) const;  // 判卷

private:
    double a, b, c;  // 三条边长

    void sortSides(double& x, double& y, double& z) const; // 三边升序排列
    static bool nearlyEqual(double p, double q);           // 浮点数近似比较
};

#endif // TRIANGLE_H
