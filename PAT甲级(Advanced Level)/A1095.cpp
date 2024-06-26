#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
struct Record{
	char plateNum[10];
	int hh, mm, ss;
	bool status;
}record[10010], valid[10010];

struct Query{
	int hh, mm, ss;
	int num;
}query[80010];

bool cmp(Record a, Record b) {
	int s = strcmp(a.plateNum, b.plateNum);
	if(s != 0) return s < 0;
	else if(a.hh != b.hh) return a.hh < b.hh;
	else if(a.mm != b.mm) return a.mm < b.mm;
	else return a.ss < b.ss;
}

int timeTos(int hh, int mm, int ss) {
	return hh * 3600 + mm * 60 + ss;
}

bool cmpByTime(Record a, Record b) {
	if(a.hh != b.hh) return a.hh < b.hh;
	else if(a.mm != b.mm) return a.mm < b.mm;
	else return a.ss < b.ss;
}
int main() { 
	int n, k;
	map<string, int> parkTime;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++) {
		scanf("%s %d:%d:%d", record[i].plateNum, &record[i].hh, &record[i].mm, &record[i].ss);
		char strStatus[4];
		scanf("%s", strStatus);
		if(strcmp(strStatus, "in") == 0) record[i].status = true;
		else if(strcmp(strStatus, "out") == 0)	record[i].status = false;
	}
	
	sort(record, record + n, cmp);
	int count = 0, maxTime = -1;
	int i = 0;
	while(i < n) {
		if(strcmp(record[i].plateNum, record[i + 1].plateNum) == 0 && 
		record[i].status == true && record[i + 1].status == false) {
			valid[count++] = record[i];
			valid[count++] = record[i + 1];
			if(parkTime.count(record[i].plateNum) == 0) parkTime[record[i].plateNum] = 0;
			int time = timeTos(record[i + 1].hh, record[i + 1].mm, record[i + 1].ss)
			- timeTos(record[i].hh, record[i].mm, record[i].ss);
			parkTime[record[i].plateNum] += time;
			if(parkTime[record[i].plateNum] > maxTime) maxTime = parkTime[record[i].plateNum];
			i += 2;
		} else i++;
	}
//	for(int i = 0; i < count; i++) {
//		printf("Test:%s %d:%d:%d\n", valid[i].plateNum,valid[i].hh,valid[i].mm,valid[i].ss);
//	}
//	printf("count:%d\n", count);
	
    /*for(int i = 0; i < k; i++) {
		scanf("%d:%d:%d", &query[i].hh, &query[i].mm, &query[i].ss);
		query[i].num = 0;
		for(int j = 0; j < count; j += 2) {
			int queryTime = timeTos(query[i].hh, query[i].mm, query[i].ss);
			int time1 = timeTos(valid[j].hh, valid[j].mm, valid[j].ss);
			int time2 = timeTos(valid[j + 1].hh, valid[j + 1].mm, valid[j + 1].ss);
			if(queryTime >= time1 && queryTime < time2) {
				query[i].num++;
//				printf("%d %02d:%02d:%02d %02d:%02d:%02d\n", queryTime, valid[j].hh, valid[j].mm, valid[j].ss,
//				valid[j + 1].hh, valid[j + 1].mm, valid[j + 1].ss);
			}
		}
	}
	for(int i = 0; i < k; i++) {
		printf("%d\n", query[i].num);
	}*/
	
	sort(valid, valid + count, cmpByTime);
	int now = 0, numCar = 0, hh, mm, ss;
	for(int i = 0; i < k; i++) {
		scanf("%d:%d:%d", &hh, &mm, &ss);
		int times = timeTos(hh, mm, ss);
		while(now < count && timeTos(valid[now].hh, valid[now].mm, valid[now].ss) <= times) {
			if(valid[now].status == true) numCar++;
			else numCar--;
			now++;
		}
		printf("%d\n", numCar);
	}
	
	map<string, int>::iterator it;
	for(it = parkTime.begin(); it != parkTime.end(); it++) {
		if(it->second == maxTime)
			printf("%s ", it->first.c_str());
	}
	printf("%02d:%02d:%02d\n", maxTime / 3600, maxTime % 3600 / 60, maxTime % 60);
	return 0;
}
