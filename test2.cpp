#include <iostream>

using namespace std;

template<typename T>
class Singleton1
{
    public: 

    static Singleton1& getInstance()
    {
        static Singleton1 instance;
        return instance;
    }

    T& getObj()
    {
        return obj;
    }

    void setObj(const T& val)
    {
        obj = val;
    }

    void setObj(T&& val)
    {
        obj = std::move(val);
    }

    private:
    Singleton1(){}; //默认构造函数只能在类内初始化唯一的局部静态变量使用，类外不能使用
    Singleton1(const Singleton1&) = delete;  //编译器会为我们合成一个拷贝构造函数，必须禁止它
    T obj;
};

int main()
{
    Singleton1<int>::getInstance().setObj(1);
    cout << Singleton1<int>::getInstance().getObj() << endl;
    return 0;
}