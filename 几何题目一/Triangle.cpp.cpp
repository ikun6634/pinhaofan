#include "Triangle.h"

#include <algorithm>
#include <cmath>
#include <iostream>


namespace {
    const double EPS = 1e-6;  // 浮点数比较允许的误差
}

// ==================== 构造与析构 ====================

// 默认构造函数：初始化为 3、4、5（必须保证是合法三角形）
Triangle::Triangle() : a(3), b(4), c(5) {
    std::cout << "[构造] 默认构造函数：初始化为 (3, 4, 5)" << std::endl;
}

// 重载构造函数：先赋默认值，再尝试写入参数；参数非法则保留默认值
Triangle::Triangle(double x, double y, double z) : a(3), b(4), c(5) {
    if (setSides(x, y, z)) {
        std::cout << "[构造] 重载构造函数：(" << a << ", " << b << ", " << c << ")" << std::endl;
    } else {
        std::cerr << "[构造] 参数 (" << x << ", " << y << ", " << z
                  << ") 不能构成三角形，对象使用默认值 (3, 4, 5)" << std::endl;
    }
}

Triangle::~Triangle() {
    std::cout << "[析构] Triangle(" << a << ", " << b << ", " << c << ") 被销毁" << std::endl;
}

// ==================== 合法性验证 ====================

bool Triangle::isValid(double x, double y, double z) {
    if (x <= 0 || y <= 0 || z <= 0) return false;      // 边长必须为正数
    return (x + y > z) && (x + z > y) && (y + z > x);  // 任意两边之和大于第三边
}

bool Triangle::isValid() const {
    return isValid(a, b, c);
}

// ==================== 修改数据成员 ====================

bool Triangle::setSides(double x, double y, double z) {
    if (!isValid(x, y, z)) return false;
    a = x; b = y; c = z;
    return true;
}

bool Triangle::setSideA(double x) {
    if (!isValid(x, b, c)) return false;
    a = x;
    return true;
}

bool Triangle::setSideB(double y) {
    if (!isValid(a, y, c)) return false;
    b = y;
    return true;
}

bool Triangle::setSideC(double z) {
    if (!isValid(a, b, z)) return false;
    c = z;
    return true;
}

// ==================== 获取数据成员 ====================

double Triangle::getA() const { return a; }
double Triangle::getB() const { return b; }
double Triangle::getC() const { return c; }

// ==================== 输出 ====================

void Triangle::print() const {
    std::cout << "三边长：a = " << a << "，b = " << b << "，c = " << c
              << "；周长 = " << perimeter()
              << "，面积 = " << area()
              << "，类型：" << typeName() << std::endl;
}

// ==================== 扩展功能 ====================

double Triangle::perimeter() const {
    return a + b + c;
}

double Triangle::area() const {
    double s = perimeter() / 2.0;                // 半周长
    double v = s * (s - a) * (s - b) * (s - c);  // 海伦公式
    if (v < 0) v = 0;                            // 防止浮点误差产生微小负数
    return std::sqrt(v);
}

bool Triangle::isEquilateral() const {
    return nearlyEqual(a, b) && nearlyEqual(b, c);
}

bool Triangle::isIsosceles() const {  // 等边也视为等腰
    return nearlyEqual(a, b) || nearlyEqual(b, c) || nearlyEqual(a, c);
}

bool Triangle::isRight() const {
    double x, y, z;
    sortSides(x, y, z);
    return nearlyEqual(x * x + y * y, z * z);  // 勾股定理
}

std::string Triangle::typeName() const {
    double x, y, z;
    sortSides(x, y, z);
    bool equ = nearlyEqual(x, y) && nearlyEqual(y, z);
    bool iso = nearlyEqual(x, y) || nearlyEqual(y, z);
    bool rt  = nearlyEqual(x * x + y * y, z * z);

    if (equ) return "等边三角形";
    if (iso && rt) return "等腰直角三角形";
    if (iso) return "等腰三角形";
    if (rt) return "直角三角形";
    return "一般三角形";
}

// ==================== 题库功能 ====================

void Triangle::printQuestion() const {
    std::cout << "【题目】已知三角形的三条边长分别为 " << a << "、" << b << "、" << c
              << "，求它的周长和面积。" << std::endl;
}

bool Triangle::checkAnswer(double per, double areaVal) const {
    return nearlyEqual(per, perimeter()) && nearlyEqual(areaVal, area());
}

// ==================== 私有辅助函数 ====================

bool Triangle::nearlyEqual(double p, double q) {
    double diff  = std::fabs(p - q);
    double scale = std::max(1.0, std::max(std::fabs(p), std::fabs(q)));
    return diff <= EPS * scale;
}

void Triangle::sortSides(double& x, double& y, double& z) const {
    double s[3] = { a, b, c };
    std::sort(s, s + 3);
    x = s[0];
    y = s[1];
    z = s[2];
}
