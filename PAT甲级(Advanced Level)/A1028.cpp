#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Student{
	char id[7];
	char name[10];
	int grade;
}stu[100010];

bool cmp1(Student a, Student b) {
	return strcmp(a.id, b.id) < 0;
}
bool cmp2(Student a, Student b) {
	int s = strcmp(a.name, b.name);
	if(s != 0) return s < 0;
	else return strcmp(a.id, b.id) < 0;
}
bool cmp3(Student a, Student b) {
	if(a.grade != b.grade) return a.grade < b.grade;
	else return strcmp(a.id, b.id) < 0;
}
int main() {
	int n, c;
	scanf("%d %d", &n, &c);
	for(int i = 0; i < n; i++) {
		scanf("%s %s %d", stu[i].id, stu[i].name, &stu[i].grade);
	}
	if(c == 1) 	sort(stu, stu + n, cmp1);
	else if(c == 2) sort(stu, stu + n, cmp2);
	else if(c == 3) sort(stu, stu + n, cmp3);
	for(int i = 0; i < n; i++) {
		printf("%s %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
	}
	return 0;
}
