#include "Triangle.h"

int main()
{
    //测试1：默认构造对象
    Triangle t1;
    cout<<"====对象t1(默认构造)===="<<endl;
    t1.showInfo();

    //测试2：重载构造，合法三边 5,5,6
    cout<<"\n====对象t2(5,5,6)===="<<endl;
    Triangle t2(5,5,6);
    t2.showInfo();

    //测试3：传入非法三边，比如1,2,3不能构成三角形
    cout<<"\n====对象t3(1,2,3)非法输入===="<<endl;
    Triangle t3(1,2,3);
    t3.showInfo();

    //测试set修改成员
    cout<<"\n====测试修改t1的边长===="<<endl;
    t1.setA(6);
    t1.setB(8);
    t1.setC(10);
    t1.showInfo();

    return 0;
}
