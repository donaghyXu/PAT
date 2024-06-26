#include <cstdio>
struct Student{
	long long id;
	int examSeat;
}student[1010];
int main() {
	int n;
	scanf("%d", &n);
	long long id;
	int fSeat, examSeat;
	for(int i = 1; i <= n; i++) {
		scanf("%lld %d %d", &id, &fSeat, &examSeat);
		student[fSeat].id = id;
		student[fSeat].examSeat = examSeat;
	}
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		scanf("%d",&fSeat);
		printf("%lld %d\n", student[fSeat].id, student[fSeat].examSeat);
	}
	return 0;
}
