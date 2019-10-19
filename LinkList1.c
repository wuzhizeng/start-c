#include"stdio.h"
#include"stdlib.h"

typedef char ElemType;
typedef struct Node{
  ElemType data;
  struct Nade *next;
}*LinkList;

//函数的定义
LinkList Init();//单链表的初始化
void Create_Head(LinkList L);//尾插法建表
void Create_Tail(LinkList L);//头插法建表
void nizhi(LinkList L);//单链表的逆置
void get_hao(LinkList L,int i);//按号查找
void get_zhi(LinkList L,ElemType i);//按值查找
int ListLength(LinkList L);//单链表的长度
void InsList(LinkList L,int i,ElemType e);//单链表的插入
void DelList(LinkList L,int i,ElemType *e);//单链表的删除
void output(LinkList L);

//函数原型
LinkList Init(){
  LinkList L;
  L=(LinkList)malloc(sizeof(LinkList));
  L->next=NULL;
  return L;
}

void Create_Head(LinkList L){
  LinkList s;
  ElemType c;
  while(1){
    c=getchar();
    if(c!='*'){
      s=(LinkList)malloc(sizeof(LinkList));
      s->data=c;
      s->next=L->next;
      L->next=s;
    }
    else break;
  }
}

void Create_Tail(LinkList L){
  LinkList s;
  ElemType c;
  while(1){
    c=getchar();
    if(c!='*'){
      s=(LinkList)malloc(sizeof(LinkList));
      s->data=c;
      L->next=s;
      L=s;
    }
    else{
      L->next=NULL;
      break;
    }
  }
}

void nizhi(LinkList L){
  LinkList p,f,b;
  p=L->next;
  b=NULL;
  while(p!=NULL){
    f=p->next;
    p->next=b;
    b=p;
    p=f;
  }
  L->next=b;
}

void get_hao(LinkList L,int i){
  int j;
  LinkList p;
  if(i<=0) printf("NULL!!!\n");

  p=L;j=0;
  while(p->next!=NULL && j<i){
    p=p->next;
    j++;
  }
  if(i==j) printf("查找成功!!!\n");
  else printf("查找失败!!!\n");
}

void get_zhi(LinkList L,ElemType i){
  LinkList p;
  p=L->next;
  while(p!=NULL){
    if(p->data!=i){
      p=p->next;
    }
    else{
      printf("查找成功\n");
      break;
    }
  }
}

int ListLength(LinkList L){
  LinkList p;
  int j=0;
  p=L->next;
  while(p!=NULL){
    p=p->next;
    j++;
  }
  return j;
}

void InsList(LinkList L,int i,ElemType e){
  LinkList p,s;
  int k=0;
  if(i<=0)printf("NULL\n");
  p=L;
  while(p!=NULL && k<i){
    p=p->next;
    k=k+1;
  }
  if(p==NULL) printf("插入位置不合理!!!\n");
  s=(LinkList)malloc(sizeof(LinkList));
  s->data=e;
  s->next=p->next;
  p->next=s;
}

void DelList(LinkList L,int i,ElemType *e){
  LinkList p,r;
  int k=0;
  p=L;
  while(p->next!=NULL && k<i-1){
    p=p->next;
    k++;
  }
  if(p->next==NULL)printf("插入位置不合理!!!\n");
  r=p->next;
  p->next=r->next;
  *e=r->data;
  free(r);
}

void output(LinkList L){
  while(L){
    printf("%c ",L->data);
    L=L->next;
  }
   printf("\n");
}

int main(){
  int create,c;
  LinkList L=Init();
  ElemType a;
  while (1) {
    printf("********************************\n");
    printf("*1-尾插法建表     2-头插法建表   *\n");
    printf("*3-表的逆置       4-按号查找     *\n");
    printf("*5-按值查找       6-表的长度     *\n");
    printf("*7-表的插入       8-表的删除     *\n");
    printf("*9-表的输出       0-退出         *\n");
    printf("********************************\n");
    printf("请在0~9中输入选项\n");
    scanf("%d",&create);
    switch (create) {
      case 1:
        printf("请输入单链表的元素,*结束.\n");
        Create_Tail(L);
        break;
      case 2:
        printf("请输入单链表的元素,*结束.\n");
        Create_Head(L);
        break;
      case 3:
        nizhi(L);
        break;
      case 4:
        printf("请输入你要查找的号码: ");
        scanf("%d",&c);
        get_hao(L,c);
        break;
      case 5:
        printf("请输入你要查找的值: ");
        scanf("%c",&a);
        get_zhi(L,a);
        break;
      case 6:
        printf("单链表的长度=%d\n",ListLength(L));
        break;
      case 7:
        printf("请分别输入你要插入在那个号码位置和元素: ");
        scanf("%d\n%c",&c,&a);
        InsList(L,c,a);
        break;
      case 8:
        printf("请输入你要删除的那个号码位置: ");
        scanf("%d",&c);
        DelList(L,c,&a);
        printf("删除元素为%c\n",a);
        break;
      case 9:
        output(L);
        break;
      case 0:
        exit(0);
      default:
        printf("请在0~9选择.\n");
    }
  }
  return 0;
}
