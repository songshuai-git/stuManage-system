#ifndef LIST_H

#define LIST_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stu.h"

struct node{
	struct student data;
	struct node* next;
};

struct node* head;
//static struct node* head; //编译 链接均能通过，但运行时若其他文件用到了head会出现段错误

struct node* list_find(char*);
void list_add(struct student data);
int list_del(char*);
int list_update(char*);
void list_rand();
void list_show();
int ltofile();
int filetol();

#endif 
