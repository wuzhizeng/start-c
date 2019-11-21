#include"stdio.h"
#include"stdlib.h"
#define M 1000
#define N 30
#define M1 10

typedef struct{
  int weight;
  int parent;
  int lchild;
  int rchild;
}HNodeType;

typedef struct{
  int bit[M1];
  int start;
}HCodeType;

void Crehfm(HNodeType h[],int n){
  int i,j,x1,x2,m1,m2;
  for(i=0;i<2*n-1;i++){
    h[i].weight=0;
    h[i].parent=-1;
    h[i].lchild=-1;
    h[i].rchild=-1;
  }
  printf("input:");
  for(i=0;i<n;i++)
    scanf("%d",&h[i].weight);

  for(i=0;i<n-1;i++){
    m1=m2=M;
    x1=x2=0;
    for(j=0;j<n+i;j++){
      if(h[j].parent==-1 && h[j].weight<m1){
        m2=m1;
        x2=x1;
        m1=h[j].weight;
        x1=j;
      }
      else if(h[j].parent==-1 && h[j].weight<m2){
        m2=h[j].weight;
        x2=j;
      }
    }

    h[x1].parent=n+i;
    h[x2].parent=n+i;
    h[n+i].weight=h[x1].weight+h[x2].weight;
    h[n+i].lchild=x1;
    h[n+i].rchild=x2;
  }
}

void HfmCode(int n){
  HNodeType h[N];
  HCodeType hc[N],cd;
  int i,j,c,p;
  Crehfm(h,n);
  for(i=0;i<n;i++){
    cd.start=n-1;
    c=i;
    p=h[c].parent;
    while (p!=-1) {
      if(h[p].lchild==c)
        cd.bit[cd.start]=0;
      else
        cd.bit[cd.start]=1;

      cd.start--;
      c=p;
      p=h[c].parent;
    }
    for(j=cd.start+1;j<n;j++)
      hc[i].bit[j]=cd.bit[j];
    hc[i].start=cd.start;
  }
  for(i=0;i<n;i++){
    printf("%d:",h[i].weight);
    for(j=hc[i].start+1;j<n;j++)
      printf("%d",hc[i].bit[j]);
    printf("\n");
  }
}

int main(int argc, char const *argv[]) {
  int n;
  printf("请输入哈夫曼树的叶子个数:");
  scanf("%d",&n);
  HfmCode(n);
  return 0;
}
