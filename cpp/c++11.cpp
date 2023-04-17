#include<iostream>
#include<vector>
#include<algorithm>
#include<thread>
using namespace std;
void func1()
{
    cout<<"func1"<<endl;
}
void func2(int l1,int l2)
{
    int n=l1+l2;
    cout<<n<<" func2"<<endl;
}
int main()
{
//    thread t1(func1); // 当创建这个线程的时候 就已经启动了
//    t1.join(); // join 会阻塞主进程 直到该线程 执行结束
//    thread t2(func2,1,2); // 如果函数有参数，加到后面即可
//    t2.join();

    // 创建100个线程，并等待结束
    //c++11 thread
    vector<thread> ls;
    for(int i=0;i<100;i++)
    {
        ls.emplace_back(thread(func2,i,0));
    }
    for(int i=0;i<100;i++)
    {
        ls[i].join();
    }

    //detach 分离线程
    //joinable() 检查该线程 是否

}