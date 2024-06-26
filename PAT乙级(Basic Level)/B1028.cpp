#include <cstdio>
struct Person {
	char name[6];
	int yy, mm, dd;
}oldest, youngest, left, right, temp;
void init() {
	left.yy = youngest.yy = 1814;
	right.yy = oldest.yy = 2014;
	left.mm = right.mm = oldest.mm = youngest.mm = 9;
	left.dd = right.dd = oldest.dd = youngest.dd = 6;
}
bool cmpLess(Person temp1,Person temp2) {
	if(temp1.yy != temp2.yy) return temp1.yy <= temp2.yy;
	else if(temp1.mm != temp2.mm) return temp1.mm <= temp2.mm;
	else return temp1.dd <= temp2.dd;
}

bool cmpMore(Person temp1,Person temp2) {
	if(temp1.yy != temp2.yy) return temp1.yy >= temp2.yy;
	else if(temp1.mm != temp2.mm) return temp1.mm >= temp2.mm;
	else return temp1.dd >= temp2.dd;
}
int main() {
	init();
	int n, count = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s %d/%d/%d", temp.name, &temp.yy, &temp.mm, &temp.dd);
		if(cmpLess(temp,right) && cmpMore(temp,left)) {
			count++;
			if(cmpLess(temp,oldest)) oldest = temp;
			if(cmpMore(temp,youngest)) youngest = temp;
		}
	}
	if(count == 0) printf("0\n");
	else printf("%d %s %s\n", count, oldest.name, youngest.name);
	return 0;
}
