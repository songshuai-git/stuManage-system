#ifndef STU_H

#define STU_H
#include<stdio.h>
#include<string.h>

typedef struct student stu_t;
struct student{
	int id;
	char name[20];
	int age;
	int classid;
	char sex[10];
	float math;
	float chinese;
};

//stu_t stu1;

#endif