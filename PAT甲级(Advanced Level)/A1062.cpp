#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Student{
	char id[10];
	int de, cai, sum;
	int flag;
}stu[100010];
bool cmp(Student a,Student b) {
	if(a.flag != b.flag) return a.flag < b.flag;
	else if(a.sum != b.sum) return a.sum > b.sum;
	else if(a.de != b.de) return a.de > b.de;
	else return strcmp(a.id, b.id) < 0;
}
int main() {
	int n, l, h;
	scanf("%d %d %d", &n, &l, &h);
	int count = n;
	for(int i = 0; i < n; i++) {
		scanf("%s %d %d", stu[i].id, &stu[i].de, &stu[i].cai);
		stu[i].sum = stu[i].de + stu[i].cai;
		if(stu[i].de < l || stu[i].cai < l)	{
			stu[i].flag = 5;
			count--;
		} else if(stu[i].de >= h && stu[i].cai >= h) stu[i].flag = 1;
		else if(stu[i].de >= h && stu[i].cai < h) stu[i].flag = 2;
		else if(stu[i].de >= stu[i].cai) stu[i].flag = 3;
		else  stu[i].flag = 4;
	}
	sort(stu, stu + n, cmp);
	printf("%d\n", count);
	for(int i = 0; i < n; i++) {
		if(stu[i].flag != 5) 
			printf("%s %d %d\n", stu[i].id, stu[i].de, stu[i].cai);
	}
	return 0;
}
