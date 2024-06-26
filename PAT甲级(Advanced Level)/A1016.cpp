#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int tt[24];
struct Record{
	char name[25];
	int m, dd, hh, mm;
	char state[10];
}record[1010];

bool cmp(Record a, Record b){
	if(strcmp(a.name,b.name) != 0) return strcmp(a.name,b.name) < 0;
	else if(a.m != b.m) return a.m < b.m;
	else if(a.dd != b.dd) return a.dd < b.dd;
	else if(a.hh != b.hh) return a.hh < b.hh;
	else return a.mm < b.mm;
}
void getTimeAndMoney(int start, int end, int& min, int& money) {
	while(record[start].dd < record[end].dd || record[start].hh < record[end].hh
	|| record[start].mm < record[end].mm) {
		min++;
		money += tt[record[start].hh];
		record[start].mm++;
		if(record[start].mm >= 60) {
			record[start].mm = 0;
			record[start].hh++;
		} 
		if(record[start].hh >= 24) {
			record[start].hh = 0;
			record[start].dd++;
		}
	}
}
int main() {
	int n;
	for(int i = 0; i < 24; i++) {
		scanf("%d", &tt[i]);
	}
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s %d:%d:%d:%d %s",record[i].name, &record[i].m, &record[i].dd,
		&record[i].hh, &record[i].mm, record[i].state);
	}
	sort(record, record + n, cmp);
	
	int start = 0, end, next;
	while(start < n) {
		int needPrint = 0;
		next = start;
		while(next < n && strcmp(record[start].name,record[next].name) == 0) {
			if(needPrint == 0 && strcmp(record[next].state,"on-line") == 0) {
				needPrint = 1;
			} else if(needPrint == 1 && strcmp(record[next].state,"off-line") == 0) {
				needPrint = 2;
			}
			next++;
		}
		if(needPrint < 2) {
			start = next;
			continue;
		} 
		int charge = 0;
		printf("%s %02d\n", record[start].name, record[start].m);
		while(start < next) {
			while(start < next - 1 && !(strcmp(record[start].state, "on-line") == 0 && 
			strcmp(record[start + 1].state, "off-line") == 0)) {
				start++;
			}
			end = start + 1;
			if(end == next) {
				start = next;
				break;
			}
			printf("%02d:%02d:%02d ", record[start].dd, record[start].hh, record[start].mm);
			printf("%02d:%02d:%02d ", record[end].dd, record[end].hh, record[end].mm);
			int min = 0, money = 0;
			getTimeAndMoney(start, end, min, money);
			//printf("money1:%.2f ", money);
			//printf("money2:%.2f\n", money / 100.0);
			charge = charge + money;
			printf("%d $%.2f\n", min, money / 100.0);			
			start = end + 1;
		}
		printf("Total amount: $%.2f\n", charge / 100.0);
	}
	return 0;
}
