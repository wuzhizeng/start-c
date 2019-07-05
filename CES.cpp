#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 15
#define M 100
int a,n,m;

struct namepass{
  char name[N];
  char pass[N];
}np[M];

struct CES{
  int number;
  char name[N];//名字
	char sex[N];//性别
	char address[N];//地址
	char relation[N];//关系
	char tel[N];//电话
}ces[M];

void readfile();
void password();
void amendpassword();
void save1();
void main1();
void help();
void refresh();
void add();
void amend();
void deletes();
void search();
void show();
void save();


int main(){
  printf("\n\n\t*开始时,有账号和密码登陆,请在文件夹先打开 reme.txt 文件!*\n\n");
  password();
  return 0;
}

void readfile(){
	FILE*fp;
	int i=0;
	if((fp=fopen("password.txt","r"))==NULL){
		printf("文件打开错误!");
		system("pause");
		exit(0);
	}
	while(fscanf(fp,"%s %s",np[i].name,np[i].pass)==2){
		i++;
    a=i;
	}
	fclose(fp);
}

void password(){
  readfile();
  int num=0;
  char na[N];
  char pa[N];
  printf("\t第一次登陆时,用户名和密码是你的手机号.\n\n");
  while(1){
    printf("\t|请输入你的用户名.               |\n");
    printf("\t *用户名:");
    scanf("%s", na);
    printf("\n\t ----------------------------- \n");
    printf("\t ------------------------------- \n");
    printf("\t|请输入你的密码.                 |\n");
    printf("\t *密码:");
    scanf("%s", pa);
    printf("\t ------------------------------- \n");
    for(int i=0;i<a;i++){
      if(strcmp(na,np[i].name)==0 && strcmp(pa,np[i].pass)==0){
        printf("密码正确.\n");
        printf("欢迎使用通讯录管理系统.\n");
        system("pause");

        main1();

      }
      else{
        printf("对不起!系统没有你的手机号信息!\n");
        printf("请重新输入.\n\n");
        num++;
        if(num==3){
          system("pause");
          printf(" 对不起!你已输入3次错误!\n");
          printf(" 再见!\n");
          exit(0);
        }
         system("pause");
         break;
      }
    }
  }
}

void amendpassword(){
  readfile();
  int b=1,c;
  char name1[N];
  char passw1[N];
  char passw2[N];
  char passw3[N];
  printf("请输入原来的密码.\n");
  scanf("%s",passw1);
  for(int i=0;i<a;i++){
    if(strcmp(passw1,np[i].pass)==0){
      c=i;
      printf("请输入新的用户名:\n");
      scanf("%s",name1);

      while(1){
        while(1){
          printf("请输入新的密码:\n");
          scanf("%s",passw2);
          if(strcmp(passw2,passw1)==0){
            printf("新密码和旧密码不能相同!\n");
          }
          else{
            break;
          }
        }
        printf("请再次确认新密码:\n");
        scanf("%s",passw3);
        if(strcmp(passw2,passw3)==0){
          strcpy(np[c].pass,passw2);
          strcpy(np[c].name,name1);
          printf("密码修改成功\1 退出系统后重新登陆.\n");
          save1();
          break;
        }
        else{
          printf("密码不一样.请重新输入.\n");
          break;
        }
      }
    }
    else{
      if(b!=3){
        printf("密码错误!请重新输入.\n" );
        b++;
      }
      else{
        printf("输入3次密码错误!\n");
        printf("再见!\n");
        exit(0);
      }
    }
    system("pause");
  }
}

void save1(){
  int i;
	FILE*fp;
	fp=fopen("password.txt","w");
	for(i=0;i<a;i++){
		fprintf(fp,"%s %s\n",np[i].name,np[i].pass);
	}
	fclose(fp);
}

void main1() {
  while (1) {
		int num;
	  printf("\n\n\t\t          通讯录管理系统         \n\n" );
	  printf("\t\t ***********功能 菜单********* \n" );
	  printf("\t\t -----------        ----------- \n");
	  printf("\t\t|******************************|\n");
	  printf("\t\t|     1.系统说明.              |\n");
	  printf("\t\t|     2.增加通讯人信息.        |\n");
	  printf("\t\t|     3.修改通讯人信息.        |\n");
	  printf("\t\t|     4.删除通讯人信息.        |\n");
	  printf("\t\t|     5.查找通讯人信息.        |\n");
	  printf("\t\t|     6.展示全部通讯人.        |\n");
    printf("\t\t|     7.密码修改.              |\n");
	  printf("\t\t|     8.退出系统.              |\n");
	  printf("\t\t|******************************|\n");
	  printf("\t\t -----------     ------------- \n");
	  printf("提示:请正确输入数字!!\n请选择功能编号:");
    scanf("%d",&num );
	  switch (num) {
	    case 1: help();break;
	    case 2: add();break;
	    case 3: amend();break;
	    case 4: deletes();break;
	    case 5: search();break;
	    case 6: show();break;
      case 7: amendpassword();break;
	    case 8: exit(0);
	    default:printf("请在 1~7 中选择.\n");
	  }
  }
  system("pause");
}

void help(){
	printf("\n欢迎输入系统说明.\n");
  printf("可以跟随系统提示操作.\n");
  printf("初始用户名为你的手机号.\n");
}
void refresh(){
	FILE*fp;
	int i=0;
	if((fp=fopen("cespeople.txt","r"))==NULL){
		printf("打开文件失败!");
		system("pause");
		exit(0);
	}
	while(fscanf(fp,"%d %s %s %s %s %s",&ces[i].number,ces[i].name,ces[i].sex,ces[i].address,ces[i].relation,ces[i].tel)==6){
		i++;
	}
	fclose(fp);
	n=i;
}

void add(){
  refresh();
  int i=n,j,flag;
  printf("请输入您所要增加的新人数:\n" );
  scanf("%d",&m);
  do{
		flag=1;
		while (flag) {
			flag=0;
      printf("请输入第 %d 新人员的编号:\n", i+1);
			scanf("%d",&ces[i].number);
			for(j=0;j<i;j++){
				if(ces[i].number==ces[j].number){
					printf("编号已有!请重新输入\n");
					flag=1;
					break;
				}
			}
		}
    printf("请输入第 %d 新人员的名字:\n", i+1);
    scanf("%s",ces[i].name);
		printf("请输入第 %d 新人员的性别:\n", i+1);
    scanf("%s",ces[i].sex);
    printf("请输入第 %d 新人员的地址:\n", i+1);
    scanf("%s",ces[i].address);
    printf("请输入第 %d 新人员的关系:\n", i+1);
    scanf("%s",ces[i].relation);
    printf("请输入第 %d 新人员的电话:\n", i+1);
    scanf("%s",ces[i].tel);
    i++;

  }while(i<n+m);
  n+=m;
  save();
  printf("增加成功.\n\n" );
}
void amend(){
  refresh();
  int i,item,num=n,nu,l=0;
  char s3[N];
  printf("请输入你需要修改的人员编号:\n" );
  scanf("%d",&nu);
  for(i=0;i<n;i++){
    if(ces[i].number==nu){
      num=i;
    }
  }
  if(num==n){
    printf("没有这个人员!\n");
    return;
  }

  printf("\t ----------------- \n");
  printf("\t|1.修改编号.       |\n");
  printf("\t|2.修改名字.       |\n");
  printf("\t|3.修改性别.       |\n");
  printf("\t|4.修改地址.       |\n");
  printf("\t|5.修改关系.       |\n");
  printf("\t|6.修改电话.       |\n");
  printf("\t|7.退出菜单.       |\n");
  printf("\t ----------------- \n");
  while (1) {

    printf("请选择菜单的功能编号:\n" );
    scanf("%d",&item);
    switch (item) {
      case 1:
        while(1){
          if(l==1){
            break;
          }
          printf("请输入新的编号:\n");
          scanf("%d",&nu);
          for(int k=0;k<n;k++){
            if(ces[k].number==nu){
              printf("编号已有.请重新输入新的编号.\n");
              break;
            }
            else{
              ces[num].number=nu;
              l=1;
              break;
            }
          }

        }
        save();
        printf("修改成功!\n");
        break;
      case 2:
        printf("请输入新的名字:\n");
        scanf("%s", s3);
        strcpy(ces[num].name,s3);
        save();
        printf("修改成功!\n");
        break;
      case 3:
        printf("请输入新的性别:\n");
        scanf("%s", s3);
        strcpy(ces[num].sex,s3);
        save();
        printf("修改成功!\n");
        break;
      case 4:
        printf("请输入新的地址:\n");
        scanf("%s", s3);
        strcpy(ces[num].address,s3);
        save();
        printf("修改成功!\n");
        break;
      case 5:
        printf("请输入新的关系:\n");
        scanf("%s", s3);
        strcpy(ces[num].relation,s3);
        save();
        printf("修改成功!\n");
        break;
      case 6:
        printf("请输入新的电话号码:\n");
        scanf("%s", s3);
        strcpy(ces[num].tel,s3);
        save();
        printf("修改成功!\n");
        break;
      case 7:return;
      default:printf("请在1~7选择.\n");
    }
  }
}
void deletes(){
  refresh();
	int i,j,flag=0;
	char s[N];
	printf("请输入你想要删除的人员名字:\n");
	scanf("%s",s);
	for(i=0;i<n;i++){
		if(strcmp(ces[i].name,s)==0){
			flag=1;
			for(j=i;j<n-1;j++){
				ces[j]=ces[j+1];
			}
		}
	}
	if(flag==0){
		printf("%s 不存在!\n",s);
	}
	if(flag==1){
		printf("删除成功!\n");
		n--;
	}
  save();
}
void search(){
  refresh();
	int i,item,flag,num;
	char s[N];
	while (1) {
		printf(" ------------------ \n");
    printf("|1.按编号查询.      |\n");
		printf("|2.按名字查询.      |\n");
		printf("|3.按性别查询.      |\n");
		printf("|4.按关系查询.      |\n");
		printf("|5.退出菜单.        |\n");
		printf(" ------------------ \n");

		printf("请输入你想要的功能编号:");
		scanf("%d",&item);
		flag=0;
		switch (item) {
      case 1:
        	printf("请输入你想要的人员编号:\n");
          scanf("%d",&num);
  				for(i=0;i<n;i++){
  					if(ces[i].number==num){
  						flag=1;
  						printf("编号\t\t名字\t\t性别\t\t地址\t\t关系\t\t手机号\n");
  						printf("******************************************\n");
  						printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",ces[i].number,ces[i].name,ces[i].sex,ces[i].address,ces[i].relation,ces[i].tel);
  					}
  				}
  				if(flag==0){
  					printf("没有这个编号!\n");
  				}
  				break;
			case 2:
				printf("请输入你想要的人员名字:\n");
				scanf("%s",s);
				for(i=0;i<n;i++){
					if(strcmp(ces[i].name,s)==0){
						flag=1;
						printf("编号\t\t名字\t\t性别\t\t地址\t\t关系\t\t手机号\n");
						printf("******************************************\n");
						printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",ces[i].number,ces[i].name,ces[i].sex,ces[i].address,ces[i].relation,ces[i].tel);
					}
				}
				if(flag==0){
					printf("没有这个名字!\n");
				}
				break;
			case 3:
				printf("请输入你想要查找的人员性别:\n");
				scanf("%s",s);
				for(i=0;i<n;i++){
					if(strcmp(ces[i].sex,s)==0){
						flag=1;
						printf("编号\t\t名字\t\t性别\t\t地址\t\t关系\t\t手机号\n");
						printf("*****************************************\n");
						printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",ces[i].number,ces[i].name,ces[i].sex,ces[i].address,ces[i].relation,ces[i].tel);
					}
				}
				if(flag==0){
					printf("没有这个性别!\n");
				}
				break;
			case 4:
				printf("请输入你想要查找的人员关系:\n");
				scanf("%s",s);
				for(i=0;i<n;i++){
					if(strcmp(ces[i].relation,s)==0){
						flag=1;
            printf("编号\t\t名字\t\t性别\t\t地址\t\t关系\t\t手机号\n");
            printf("*****************************************\n");
            printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",ces[i].number,ces[i].name,ces[i].sex,ces[i].address,ces[i].relation,ces[i].tel);
					}
				}
				if(flag==0){
					printf("没有这样的关系!\n");
				}
				break;
			case 5:return;
			default:printf("请在 1~5 中选择!\n");
		}
	}

}
void show(){
  refresh();
	int i,j;
  struct CES _;
  for(i=0;i<n;i++){
    for(j=i;j<n;j++){
      if(ces[i].number>ces[j].number){
        _=ces[i];
        ces[i]=ces[j];
        ces[j]=_;
      }
    }
  }
	printf("输出全部通讯人的信息,如下:\n");
	printf("编号\t\t名字\t\t性别\t\t地址\t\t关系\t\t手机号\n");
	printf("*****************************************\n");
	for(i=0;i<n;i++){
		printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",ces[i].number,ces[i].name,ces[i].sex,ces[i].address,ces[i].relation,ces[i].tel);
	}
  save();
}
void save(){
  int i;
	FILE*fp;
	fp=fopen("cespeople.txt","w");
	for(i=0;i<n;i++){
		fprintf(fp,"%d %s %s %s %s %s\n",ces[i].number,ces[i].name,ces[i].sex,ces[i].address,ces[i].relation,ces[i].tel);
	}
	fclose(fp);
}
