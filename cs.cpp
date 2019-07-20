#include<iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  int m[n];
  string na[n];
  string xue[n];
  for(int i=0;i<n;i++){
    cin>>na[i]>>xue[i]>>m[i];
  }
  int max=m[0],min=m[0],a=0,b=0;
  for(int i=0;i<n;i++){
    if(max<m[i]){
      a=i;
      max=m[i];
    }
    if(min>m[i]){
      b=i;
      min=m[i];
    }
  }
  cout<<na[a]<<" "<<xue[a]<<endl
    <<na[b]<<" "<<xue[b]<<endl;
  return 0;
}
