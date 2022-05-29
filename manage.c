#include"manage.h"
#include"stu.h"
#include"list.h"

void login(){
	filetol();
	printf("\twelcome to student management system\n");

	printf("1.学生登录\t2.管理员登录\n");
	printf("请选择:");

	int ch = 0;
	scanf("%d",&ch);
	printf("log: ch=%d\n",ch);
	while(getchar()!=10);
	
	switch(ch){
		case 1:
			stu_login();
			break;
		case 2:
			admin_login();
			break;
		default:
			printf("invalid choice\n");
			break;
	}
	
	return;
}

void stu_login(){
	printf("please input your name:");
	char name[20];
	scanf("%s",name);

	struct node* p = list_find(name);
	if(p==NULL) {printf("no such student\n");return;}
	
	while(1){
		printf("\tSTUDENT SYSTEM\n");
		printf("-----------------------------\n");
		printf("1.show\n");
		printf("2.update\n");
		printf("3.quit\n");
		printf("-----------------------------\n");
		
		int ch = 0;
		printf("please choose:");
		scanf("%d",&ch);
		printf("log: ch=%d\n",ch);
		while(getchar()!=10);
		
		switch(ch){
			case 1:
				printf("%d %s %d %d %s %0.1f %0.2f\n",p->data.id,
					  p->data.name,p->data.age,p->data.classid,
					  p->data.sex,p->data.math,p->data.chinese);
				break;
			case 2:
				list_update(name);
				break;
			case 3:
				ltofile();
				exit(0);
				break;
			default:
				printf("invalid choice\n");
				break;
		}
	}

	return;
}

void admin_login(){
	printf("please input account and passwd:\n");
	char account[20];
	int  passwd;
	scanf("%s%d",account,&passwd);
	
	//if(account[0]=='a' && account[1]=='d' && account[2]=='m' &&
	   //account[3]=='i' && account[4]=='n' && passwd==123){
	if(strcmp(account,"admin")==0 && passwd==123){
	}else{
		printf("account or passwd error!\n");
		return;
	}

	while(1){
		printf("\tSTUDENT SYSTEM\n");
		printf("-----------------------------\n");
		printf("1.input\n");
		printf("2.show\n");
		printf("3.update\n");
		printf("4.delete\n");
		printf("5.find\n");
		printf("6.quit\n");
		printf("-----------------------------\n");
		
		int ch = 0;
		printf("please choose:");
		scanf("%d",&ch);
		printf("log: ch=%d\n",ch);
		while(getchar()!=10);
		
		switch(ch){
			case 1:
				stu_input();
				break;
			case 2:
				stu_show();
				break;
			case 3:
				stu_update();
				break;
			case 4:
				stu_delete();
				break;
			case 5:
				stu_find();
				break;
			case 6:
				ltofile();
				exit(0);
			default:
				printf("invalid choice\n");
				break;
		}
	}

}

void stu_input(){
	printf("please input student\n");
	printf("id name age classid sex math chinese\n");

	stu_t stu1;
	scanf("%d%s%d%d%s%f%f",&stu1.id,stu1.name,&stu1.age,&stu1.classid,
		  stu1.sex,&stu1.math,&stu1.chinese);

	list_add(stu1);
}

void stu_delete(){
	printf("please input student name:");

	char name[20]={0};
	scanf("%s",name);

	if(list_del(name)) printf("删除成功\n");
	else printf("无此学生，删除失败\n");

	return;
}

void stu_update(){
	printf("please input student name:");

	char name[20]={0};
	scanf("%s",name);

	int res = list_update(name);

	if(res==1)  printf("修改成功\n");
	else		printf("无此学生，修改失败\n");

	return;

}

void stu_find(){
	printf("please input student name:");

	char name[20]={0};
	scanf("%s",name);

	struct node* res = list_find(name);

	if(res)  printf("%d %s %d %d %s %0.1f %0.2f\n",res->data.id,res->data.name,
			       res->data.age,res->data.classid,res->data.sex,
			       res->data.math,res->data.chinese);
	else	 printf("无此学生，查找失败\n");

	return;

}

void stu_rank(){}

void stu_show(){
	list_show();
}
