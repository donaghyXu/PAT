#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Student{
	int  id;
	int score[10];
	int rank;
	bool flag;
	int num, sum;
}stu[10010];

bool cmp(Student a, Student b) {
	if(a.sum != b.sum) return a.sum > b.sum;
	else if(a.num != b.num) return a.num > b.num;
	else return a.id < b.id;
}
int main() {
	int n, k, m, p[10];
	scanf("%d %d %d", &n, &k, &m);
	for(int i = 1; i <= k; i++) {
		scanf("%d", &p[i]);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= k; j++) {
			stu[i].score[j] = -1;
		}
		stu[i].id = i;
		stu[i].num = stu[i].sum = 0;	
		stu[i].flag = false;	
	}
	int tId, tP, tScore;
	for(int i = 0; i < m; i++) {
		scanf("%d %d %d", &tId, &tP, &tScore);
		if(tScore != -1) 	stu[tId].flag = true;
		if(stu[tId].score[tP] < tScore)
			stu[tId].score[tP] = tScore;
		if(tScore == -1 && stu[tId].score[tP] == -1) stu[tId].score[tP] = 0;
	}

	//总分及满分题个数	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= k; j++) {
			if(stu[i].score[j] >= 0) {
				stu[i].sum += stu[i].score[j];
			}		
			if(stu[i].score[j] == p[j])	stu[i].num++;
		}
	}
	sort(stu + 1, stu + n + 1, cmp);
	stu[1].rank = 1;
	for(int i = 2; i <= n; i++) {
		if(stu[i].sum != stu[i - 1].sum) {
			stu[i].rank = i;
		} else {
			stu[i].rank = stu[i - 1].rank;
		}
	}
	
	for(int i = 1; i <= n; i++) {
		if(stu[i].flag == true) {
			printf("%d %05d %d ", stu[i].rank, stu[i].id, stu[i].sum);
			for(int j = 1; j <= k; j++) {
				if(stu[i].score[j] == -1) printf("-");
				else printf("%d", stu[i].score[j]);
				if(j != k) printf(" ");
			}
			printf("\n");
		}		
	}
	return 0;
}
