#include <cstdio>
//定义一个学生结构体，包含姓名，学号，成绩 
struct student {
	char name[15];
	char id[15];
	int score;
}stu[10005];

int main() {
	int n, max = 0, min = 0;
	scanf("%d", &n);
	//循环读入各个学生信息，比较成绩，把成绩最高的编号存到max，成绩最低的存到min 
	for(int i = 0; i < n; i++) {
		scanf("%s", stu[i].name);
		scanf("%s", stu[i].id);
		scanf("%d", &stu[i].score);
		if(stu[i].score > stu[max].score) max = i;
		if(stu[i].score < stu[min].score) min = i;
	}
	//输出最高和最低成绩的姓名和学号 
	printf("%s %s\n", stu[max].name, stu[max].id);
	printf("%s %s\n", stu[min].name, stu[min].id);
	return 0;
}
