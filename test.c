#include<stdio.h>
#include<string.h>
#include"stu.h"
#include"list.h"

#if 0
struct stu2
{
	int a;
	char b;
};

struct stu1
{
	//int z;
	float x;//4
//struct II y;//8
	double y;
	struct stu2 z;
};//12  单个最大类型
#endif

int main(){
	//scanf("%d",&stu1.id);	
	//printf("%d\n",stu1.id);

	#if 0
	char name[20] = "hello";
	name[0] = 'n';
    
	char* str = "hello";
	//str[0] = 'n';
	printf("%s,%c\n",name,str[0]);
	#endif
	
	#if 0
	head = (struct node*)malloc(sizeof(struct node));
	memset(head,0,sizeof(struct node));
	
	char name[20] = "hello";
	double a = 3.14;
	struct stu1 s1;

	printf("%d,%d\n",sizeof(double),20*sizeof(char));
	printf("%d,%d\n",sizeof(a),sizeof(name));
	printf("%d\n",strlen(name));
	printf("%d,%d\n",sizeof(stu_t),sizeof(head->data));
	printf("%d,%d\n",sizeof(struct stu1),sizeof(s1));
	printf("%d,%d\n",sizeof(double),sizeof(float));
	printf("%d\n",sizeof(struct stu2));
	#endif
	
	char d = 'y';	
	char b = 'z';
	char const *p = &d;
	//p = &b;
	*p = 'u'; //×

	printf("%c\n",*p);
	return 0;
}
