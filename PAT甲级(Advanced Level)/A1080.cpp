#include <cstdio>
#include <algorithm>
using namespace std;
struct Person{
	int GE, GI, id;
	int choice[5];
	int rank;
}per[40010];

struct School{
	int quota;
	int stuNum;
	int stuID[40010];
	int lastAdminId;
}sch[110];

bool cmp(Person a, Person b) {
	int sum1 = a.GE + a.GI;
	int sum2 = b.GE + b.GI;
	if(sum1 != sum2) return sum1 > sum2;
	else return a.GE > b.GE;
}

bool cmpId(int a, int b) {
	return per[a].id < per[b].id;
}
int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < m; i++) {
		scanf("%d", &sch[i].quota);
		sch[i].lastAdminId = -1;
		sch[i].stuNum = 0;
	}
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &per[i].GE, &per[i].GI);
		for(int j = 0; j < k; j++) {
			scanf("%d", &per[i].choice[j]);
		}
		per[i].id = i;
	}
	
	sort(per, per + n, cmp);
	per[0].rank = 1;
	for(int i = 1; i < n; i++) {
		if((per[i].GE + per[i].GI) == (per[i - 1].GE + per[i - 1].GI) && per[i].GE == per[i - 1].GE) {
			per[i].rank = per[i - 1].rank;
		} else {
			per[i].rank = i + 1;
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < k; j++) {
			int aaa = per[i].choice[j];
			int num = sch[aaa].stuNum;
			int last = sch[aaa].lastAdminId;
			if(num < sch[aaa].quota || (last != -1 && per[i].rank == per[last].rank)) {
				sch[aaa].stuID[num] = i;
				sch[aaa].lastAdminId = i;
				sch[aaa].stuNum++;
				break;
			}
		}
	}
	for(int i = 0; i < m; i++) {
		if(sch[i].stuNum > 0) {
			sort(sch[i].stuID, sch[i].stuID + sch[i].stuNum, cmpId);
			for(int j = 0; j < sch[i].stuNum; j++) {
				printf("%d", per[sch[i].stuID[j]].id);
				if(j != sch[i].stuNum - 1) printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
