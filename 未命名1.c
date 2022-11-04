#include <stdio.h>
//1.
//struct Stu
//{
//	
//	char name[20];
//	short age;
//	char tel[20];
//	char sex[5];	
//}s1,s2,s3;

//2.
typedef struct Stu
{
	char name[20];
	short age;
	char tel[20];
	char sex[5];
		
}Stu;

typedef struct Inf
{
	Stu s;
	int num;
	char adr[30];
	char *sec;
}Inf;

int main()
{	
	//struct Stu s1;
	char region[30] = "Gulouqu\n";
	Inf i1 = {{"Zhangsan",20,"12345","male"}, 6, "Fuzhou, China", region};
	printf("%s\n", i1.s.name);
	printf("%d\n", i1.s.age);
	printf("%s\n", i1.sec);
	return 0;
}
