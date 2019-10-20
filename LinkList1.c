#include"stdlib.h"
#include"stdio.h"

typedef char ElemType;
typedef struct  Node{
  ElemType data;
  struct Node* next;
}*LinkList;

//函数的定义
LinkList Init();//单链表的初始化
void Create_Tail(LinkList L);//头插法建表
void nizhi(LinkList L);//单链表的逆置
void get_hao(LinkList L,int i);//按号查找
void get_zhi(LinkList L,ElemType i);//按值查找
int ListLength(LinkList L);//单链表的长度
void InsList(LinkList L,int i,ElemType e);//单链表的插入
void DelList(LinkList L,int i,ElemType *e);//单链表的删除
void output(LinkList L);

LinkList Init(){
  LinkList L;
  L=(LinkList)malloc(sizeof(LinkList));
  L->next=NULL;
  return L;
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
  printf("建表成功!\n");
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
  printf("逆置成功!逆置后为:");
  output(L);
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
      printf("查找成功!\n");
      return;;
    }
  }
  printf("查找失败!\n");
}

int ListLength(LinkList L){
  int j=0;
  while(L->next!=NULL){
    j++;
    L=L->next;
  }
  return j;
}

void InsList(LinkList L,int i,ElemType e){
  LinkList p,s;
  int k=0;
  if(i<=0)printf("NULL\n");
  p=L;
  while(p!=NULL && k<i-1){
    p=p->next;
    k=k+1;
  }
  if(p==NULL) printf("插入位置不合理!!!\n");
  s=(LinkList)malloc(sizeof(LinkList));
  s->data=e;
  s->next=p->next;
  p->next=s;
  printf("插入成功\n");
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
  while(L->next!=NULL){
    L=L->next;
    printf("%c ",L->data);
  }
   printf("\n");
}

int main(){

  int create,c;
  LinkList L=Init();
  ElemType a;

//先建表,避免出现求长度函数的错误
  printf("尾插法建表.\n");
  printf("请输入单链表的元素,*结束.\n");
  Create_Tail(L);

  while (1) {
    printf("*********************************\n");
    printf("*        单链表功能              *\n");
    printf("*1-表的逆置       2-按号查找     *\n");
    printf("*3-按值查找       4-表的长度     *\n");
    printf("*5-表的插入       6-表的删除     *\n");
    printf("*7-表的输出       0-退出         *\n");
    printf("*********************************\n");
    printf("请在0~7中输入选项\n");
    scanf("%d",&create);
    switch (create) {
      case 1:
        nizhi(L);
        break;
      case 2:
        printf("请输入你要查找的号码: ");
        scanf("\n%d",&c);
        get_hao(L,c);
        break;
      case 3:
        printf("请输入你要查找的值: ");
        scanf("\n%c",&a);
        get_zhi(L,a);
        break;
      case 4:
        printf("单链表的长度=%d\n",ListLength(L));
        break;
      case 5:
        printf("请分别输入你要插入在那个号码位置和元素: ");
        scanf("\n%d %c",&c,&a);
        InsList(L,c,a);
        break;
      case 6:
        printf("请输入你要删除的那个号码位置: ");
        scanf("\n%d",&c);
        DelList(L,c,&a);
        printf("删除元素为%c\n",a);
        break;
      case 7:
        output(L);
        break;
      case 0:
        exit(0);
      default:
        printf("请在0~7选择.\n");
    }
  }
  return 0;
}

// case 1:
//   printf("请输入单链表的元素,*结束.\n");
//   Create_Tail(L);
//   break;
// case 2:
//   printf("请输入单链表的元素,*结束.\n");
//   Create_Head(L);
//   break;

// while (1) {
//   printf("*********************************\n");
//   printf("*1-头插法建表     2-尾插法建表   *\n");
//   printf("*提示:输入单链表的元素时,*为结束 *\n");
//   printf("*********************************\n");
//   printf("请1 2中选择你建表的方法: ");
//   scanf("%d",&create);
//   if(create==1){
//     Create_Head(L);
//     break;
//   }
//   if(create==2){
//     Create_Tail(L);
//     break;
//   }
//   else printf("输入非法!请重新输入!\n");
// }

// void Create_Head(LinkList L);//尾插法建表
// void Create_Head(LinkList L){
//   LinkList s;
//   ElemType c;
//   while(1){
//     c=getchar();
//     if(c!='*'){
//       s=(LinkList)malloc(sizeof(LinkList));
//       s->data=c;
//       s->next=L->next;
//       L->next=s;
//     }
//     else
//     	break;
//   }
//   printf("建表成功!\n");
// }
