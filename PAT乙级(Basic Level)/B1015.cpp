#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, l, h;
//学生结构体 
struct Student {
	char id[10];	//8位学号 
	int dScore;	//德分 
	int cScore;	//才分 
	int sum;	//总分 
	int level;	//类别 
}stu[100010];

//比较规则 
bool cmp(Student s1, Student s2) {
	if(s1.level != s2.level) return s1.level < s2.level;
	else if(s1.sum != s2.sum) return s1.sum > s2.sum;
	else if(s1.dScore != s2.dScore) return s1.dScore > s2.dScore;
	else return strcmp(s1.id, s2.id) < 0;
	
}

int main() {
	int cnt = 0;
	scanf("%d %d %d", &n, &l, &h);
	for(int i = 0; i < n; i++) {
		scanf("%s %d %d", stu[i].id, &stu[i].dScore, &stu[i].cScore);
		stu[i].sum = stu[i].dScore + stu[i].cScore; 	//总分 
		if(stu[i].dScore >= l && stu[i].cScore >= l) cnt++;	//统计合格人数 
		//给学生分类 
		if(stu[i].dScore < l || stu[i].cScore < l) stu[i].level = 5;
		else if(stu[i].dScore >= h && stu[i].cScore >= h)	stu[i].level = 1;
		else if(stu[i].dScore >= h && stu[i].cScore < h)	stu[i].level = 2;
		else if(stu[i].dScore >= stu[i].cScore)		stu[i].level = 3;
		else stu[i].level = 4;
	} 
	sort(stu, stu + n, cmp);	//排序
	printf("%d\n", cnt); 
	for(int i = 0; i < cnt; i++) {
		printf("%s %d %d\n", stu[i].id, stu[i].dScore, stu[i].cScore);
	}
	return 0;
} 
