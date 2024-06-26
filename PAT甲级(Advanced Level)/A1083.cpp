#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Student{
	char name[15], id[15];
	int grade;
}stu[100010];

bool cmp(Student a, Student b) {
	return a.grade > b.grade;
}
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].grade);
	}
	sort(stu + 1, stu + n + 1, cmp);
	int grade1, grade2;
	scanf("%d %d", &grade1, &grade2);
	int count = 0;
	for(int i = 1; i <= n; i++) {
		if(stu[i].grade >= grade1 && stu[i].grade <= grade2) {
			printf("%s %s\n", stu[i].name, stu[i].id);
			count++;
		}
	}
	if(count == 0) printf("NONE\n");
	return 0;
}
