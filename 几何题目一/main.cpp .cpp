#include <iostream>
#include "Triangle.h"


int main() {
    // ---- 1. 默认构造函数 ----
    std::cout << "========== 1. 默认构造函数 ==========" << std::endl;
    Triangle t1;
    t1.print();

    // ---- 2. 重载构造函数（合法参数）----
    std::cout << "\n========== 2. 重载构造函数（合法参数）==========" << std::endl;
    Triangle t2(3, 4, 5);
    t2.print();

    // ---- 3. 重载构造函数（非法参数）----
    std::cout << "\n========== 3. 重载构造函数（非法参数）==========" << std::endl;
    Triangle t3(1, 2, 5);  // 1 + 2 < 5，不能构成三角形
    t3.print();

    // ---- 4. 修改数据成员（合法性验证）----
    std::cout << "\n========== 4. 修改数据成员 ==========" << std::endl;
    Triangle t4(5, 5, 6);
    t4.print();

    if (t4.setSideA(100))  // 100、5、6 不能构成三角形
        std::cout << "修改成功" << std::endl;
    else
        std::cout << "修改失败：100、5、6 不能构成三角形，对象保持原值" << std::endl;

    if (t4.setSides(6, 8, 10))  // 合法修改
        std::cout << "修改成功：6、8、10" << std::endl;
    t4.print();

    // ---- 5. 获取数据成员 ----
    std::cout << "\n========== 5. 获取数据成员 ==========" << std::endl;
    std::cout << "t4 的三条边：a = " << t4.getA()
              << "，b = " << t4.getB()
              << "，c = " << t4.getC() << std::endl;

    // ---- 6. 扩展功能（题库演示）----
    std::cout << "\n========== 6. 扩展功能（题库演示）==========" << std::endl;
    t2.printQuestion();
    std::cout << "考生答案：周长 = 12，面积 = 6  --> "
              << (t2.checkAnswer(12, 6) ? "正确" : "错误") << std::endl;
    std::cout << "考生答案：周长 = 12，面积 = 8  --> "
              << (t2.checkAnswer(12, 8) ? "正确" : "错误") << std::endl;
    std::cout << "t4 是否为直角三角形：" << (t4.isRight() ? "是" : "否") << std::endl;
    std::cout << "t4 是否为等腰三角形：" << (t4.isIsosceles() ? "是" : "否") << std::endl;

    // ---- 7. 作用域与对象生命周期 ----
    std::cout << "\n========== 7. 作用域与对象生命周期 ==========" << std::endl;
    std::cout << "进入局部作用域" << std::endl;
    {
        Triangle temp(6, 6, 6);
        temp.print();
        std::cout << "即将离开局部作用域" << std::endl;
    }
    std::cout << "已离开局部作用域（temp 已析构）" << std::endl;

    std::cout << "\n========== main 即将结束，t1~t4 依次析构 ==========" << std::endl;
    return 0;
}
