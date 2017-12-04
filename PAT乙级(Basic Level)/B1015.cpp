#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, l, h;
//ѧ���ṹ�� 
struct Student {
	char id[10];	//8λѧ�� 
	int dScore;	//�·� 
	int cScore;	//�ŷ� 
	int sum;	//�ܷ� 
	int level;	//��� 
}stu[100010];

//�ȽϹ��� 
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
		stu[i].sum = stu[i].dScore + stu[i].cScore; 	//�ܷ� 
		if(stu[i].dScore >= l && stu[i].cScore >= l) cnt++;	//ͳ�ƺϸ����� 
		//��ѧ������ 
		if(stu[i].dScore < l || stu[i].cScore < l) stu[i].level = 5;
		else if(stu[i].dScore >= h && stu[i].cScore >= h)	stu[i].level = 1;
		else if(stu[i].dScore >= h && stu[i].cScore < h)	stu[i].level = 2;
		else if(stu[i].dScore >= stu[i].cScore)		stu[i].level = 3;
		else stu[i].level = 4;
	} 
	sort(stu, stu + n, cmp);	//����
	printf("%d\n", cnt); 
	for(int i = 0; i < cnt; i++) {
		printf("%s %d %d\n", stu[i].id, stu[i].dScore, stu[i].cScore);
	}
	return 0;
} 
