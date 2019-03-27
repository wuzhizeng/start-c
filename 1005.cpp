// 将变量的引用作为函数形参，实现2个int型数据交换。
// 输入
// 输入2个int型整数。
// 输出
// 输出2个整数交换前后的值。
// 样例输入
// 88 66
// 样例输出
// 88 66
// 66 88
#include"iostream"
using namespace std;
void exchange(int,int);
main(){
  int n,m;
  cin>>n>>m;
  cout<<n<<" "<<m<<endl;
  exchange(n,m);
}
void exchange(int a,int b){
  // int _;
  // _=a;a=b;b=_;
  cout<<b<<" "<<a<<endl;
}
