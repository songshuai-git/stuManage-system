#include"list.h"

void list_add(stu_t data){
	struct node* new = (struct node*)malloc(sizeof(struct node));
	memset(new,0,sizeof(struct node));
	
	new->data = data;	//构造类型，可以用“=”直接赋值(深拷贝，系统自动实现)

	struct node* current = head;
	while(current->next!=NULL) current = current->next;

	current->next = new;
	new->next = NULL;
}

int list_del(char* name){
	struct node* current = head;
	for(;current->next!=NULL;current=current->next){
		if( strcmp(current->next->data.name,name)==0 ){
			/*free(current->next);
			current->next = current->next->next;*/ //不能先free掉

			struct node* t = current->next;
			current->next = t->next;
			free(t);

			return 1;
		}
	}
	return 0;
}

int list_update(char* name){
	struct node* res = list_find(name);
	if(!res) return 0;

	printf("please input new data:\n");
	printf("id name age classid sex math chinese\n");
	scanf("%d%s%d%d%s%f%f",	\
		 //? 优先级	
		 &res->data.id,res->data.name,&res->data.age,&res->data.classid, \
		 res->data.sex,&res->data.math,&res->data.chinese);
	return 1;
}

struct node* list_find(char* name){
	struct node* current = head->next;
	for(;current!=NULL;current = current->next){
		if( strcmp(current->data.name,name)==0 )return current;
		
	}
	return current;
}

void list_rand();

void list_show(){
	struct node* current = head->next;

	for(;current!=NULL;current = current->next){
		printf("%d %s %d %d %s %0.1f %0.2f\n",current->data.id,current->data.name,
			  current->data.age,current->data.classid,current->data.sex,
			  current->data.math,current->data.chinese);
	}
}

int ltofile(){
	FILE* fp = fopen("stuDB.bin","wb");
	if(fp==NULL){ 
		printf("log:文件打开失败\n");
		return 1;
	}

	struct node* current = head->next;
	for(;current!=NULL;current=current->next){
		//fwrite(&current->data,sizeof(current->data),1,fp); //！没有优先级出问题
		fwrite(&current->data,sizeof(stu_t),1,fp);
	}
	
	fclose(fp);
	return 0;
}

int filetol(){
	FILE* fp = fopen("stuDB.bin","rb");
	if(fp==NULL) return 1;

	stu_t temp;
	while(fread(&temp,sizeof(stu_t),1,fp)) list_add(temp);
	
	fclose(fp);
	return 0;
}
#if 0
int main(){
	head = (struct node*)malloc(sizeof(struct node));
	memset(head,0,sizeof(struct node));

	list_add(1);
	list_add(2);
	list_add(3);
	/*
	struct node* res = list_find(4);
	if(res==NULL) printf("no find\n");
	else printf("%d\n",res->data);
	list_show();
	*/
	//list_update(4);
	list_del(2);
	list_show();
	return 0;
}
#endif
