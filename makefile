stuManage: main.o manage.o list.o
	gcc main.o manage.o list.o -o stuManage -g
main.o: main.c stu.h list.h manage.h 
	gcc -c main.c -o main.o -g
manage.o:manage.c stu.h list.h
	gcc -c manage.c -o manage.o -g
list.o:list.c stu.h list.h
	gcc -c list.c -o list.o -g
clean:
	rm stuManage main.o manage.o list.o