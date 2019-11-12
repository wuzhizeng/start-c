#include"stdio.h"
#include"stdlib.h"
#define M 100

typedef char DataType;
typedef struct Node{
  DataType data;
  int ltag,rtag;
  struct Node *LChild,*RChild;
}Bitree;

Bitree *Create_Tree();//递归创建二叉树
void creatree(Bitree **BT,char *str);//非递归创建二叉树
void InOrder(Bitree *root);//中序递归遍历
void InOrder1(Bitree *t);//中序非递归遍历
void inorder_Thread(Bitree *p);//将二叉树线索化,利用递归算法
void InOrderTraverse_Thr(Bitree *T);//线索二叉树的中序遍历输出
void Visit(Bitree *a);//输出二叉树的 data 域

Bitree *Create_Tree(){
  Bitree *t;
  DataType c;
  c=getchar();
  if(c=='.') t=NULL;
  else{
        t=(Bitree*)malloc(sizeof(Bitree));
        t->data=c;
        t->LChild=Create_Tree();
        t->RChild=Create_Tree();
    }
  return t;
}

void creatree(Bitree **BT,char *str){
  Bitree *stack[M],*p;
  int top=-1,k,j=0;
  char ch;
  *BT=NULL;
  ch=str[j];
  while (ch!='\0')
  {
    switch(ch)
    {
      case '(':
        top++;
        stack[top]=p;
        k=1;  //k=1为左结点
        break;
      case ')':
        top--;
        break;
      case ',':
        k=2;   //k=2为右结点
        break;
      default:
        p=(Bitree *)malloc(sizeof(Bitree));
        p->data=ch;
        p->LChild=p->RChild=NULL;
        if (*BT==NULL)
          *BT=p;
        else
        {
          switch(k)
          {
            case 1:stack[top]->LChild=p;
            break;
            case 2:stack[top]->RChild=p;
            break;
          }
        }
    }
    ch=str[++j];
  }
}

void InOrder(Bitree *root){
  if(root!=NULL){
    InOrder(root->LChild);
    printf("%c ",root->data);
    InOrder(root->RChild);
  }
}

void InOrder1(Bitree *t){
  int i=0;
  Bitree *p,*s[M];
  p=t;
  do{
    while(p!=NULL){
      s[i++]=p;
      p=p->LChild;
    }
    if(i>0){
      p=s[--i];
      printf("%c ",p->data);
      p=p->RChild;
    }
  }while(i>0||p!=NULL);
}

Bitree *pre=NULL;

void inorder_Thread(Bitree *p){
  if(p!=NULL){
    inorder_Thread(p->LChild);

    if(p->LChild==NULL){
      p->ltag=1;
      p->LChild=pre;
    }
    if(pre!=NULL && pre->RChild==NULL){
      pre->RChild=p;
	  pre->rtag=1;
    }
    pre=p;
    inorder_Thread(p->RChild);
  }
}

void InOrderTraverse_Thr(Bitree *T){
  Bitree *p;
  p=T->LChild;
  while(p!=T){
    while(p->ltag==0){
      p=p->LChild;
    }
    Visit(p);
    while(p->rtag==1 && p->RChild!=T){
      p=p->RChild;
      Visit(p);
    }
      p=p->RChild;//这里的 p->data 是等于 T 的
  }
  Visit(p);//输出二叉树的根
  p=p->RChild;//指向根结点的右孩子,即遍历右子树,也能让 p!=T 条件符合
  while(p!=T){
    while(p->ltag==0){
      p=p->LChild;
    }
    Visit(p);
    while(p->rtag==1 && p->RChild!=T){
      p=p->RChild;
      Visit(p);
    }
    p=p->RChild;
  }
}

void Visit(Bitree *a){
  printf("%c ",a->data);
}

int main(int argc, char const *argv[]) {
  Bitree *b;
  char *s="A(B(D,E(H,I)),C(F,G))";
  creatree(&b,s);
  InOrder(b);
  printf("\n");
  inorder_Thread(b);
  InOrderTraverse_Thr(b);
  printf("\n");
  return 0;
}
