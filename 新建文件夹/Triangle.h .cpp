#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>

// 题目1：三角形题目类（简单几何图形题库系统）
// 数据成员：三条边长（私有，体现访问控制与封装）
// 基本操作：合法性验证、初始化（构造函数）、修改、获取、输出
// 扩展操作：求周长/面积、判断类型、生成题目与判卷
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
