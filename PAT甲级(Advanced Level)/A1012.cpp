#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
struct Student{
	char id[7];
	int grade[4], res;
	int rank[4];
}stu[2010];
int now;
bool cmp(Student a, Student b) {
	return a.grade[now] > b.grade[now];
}

int main() {
	int n, m;
	char checkID[2010][7];
	char exam[4] = {'A', 'C', 'M', 'E'};
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%s %d %d %d", stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
		stu[i].grade[0] = round((stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]) / 3);
	} 
	
	for(now = 0; now < 4; now++) {
		sort(stu, stu + n, cmp);
		stu[0].rank[now] = 1;
		for(int i = 1; i < n; i++) {
			if(stu[i].grade[now] == stu[i - 1].grade[now]) {
				stu[i].rank[now] = stu[i - 1].rank[now];
			} else {
				stu[i].rank[now] = i + 1;
			}
		}
	}
	
	for(int i = 0; i < n; i++) {
		int min = 2010;
		for(int j = 0; j < 4; j++) {
			if(stu[i].rank[j] < min) {
				stu[i].res = j;
				min = stu[i].rank[j];
			}
		}
	}
	for(int i = 0; i < m; i++) {
		scanf("%s", checkID[i]);
	}
	
	for(int i = 0; i < m; i++) {
		bool flag = false;
		for(int j = 0; j < n; j++) {
//			printf("checkId:%s, stuid:%s\n", checkID[i], stu[j].id);
//			if(strcmp(checkID[i],stu[j].id) == 0) {
//				printf("true");
//			} else printf("false");
			if(strcmp(checkID[i],stu[j].id) == 0) {
				int k = stu[j].res;
				printf("%d %c\n", stu[j].rank[k], exam[k]);
				flag = true;
			}
		}
		if(flag == false) printf("N/A\n");
	}
	return 0;
}
