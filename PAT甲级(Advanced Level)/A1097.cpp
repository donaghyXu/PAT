#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
const int table = 1000010;
struct Node{
	int data, address, next;
	int order;
}node[maxn];
bool isExist[table] = {0};

bool cmp(Node a, Node b) {
	return a.order < b.order;
}
int main() {
	int oriAddr, n, temp;
	for(int i = 0; i < maxn; i++) {
		node[i].order = 2 * maxn;
	}
	scanf("%d %d", &oriAddr, &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &temp);
		scanf("%d %d", &node[temp].data, &node[temp].next);
		node[temp].address = temp;
	}
	int p = oriAddr, validNum = 0, novalidNum = 0;
	while(p != -1) {
		if(!isExist[abs(node[p].data)]) {
			isExist[abs(node[p].data)] = true;
			node[p].order = validNum++;
		} else {
			node[p].order = maxn + novalidNum++;
		}
		p = node[p].next;
	}
	sort(node, node + maxn, cmp);
	int num = validNum + novalidNum;
	for(int i = 0; i < num; i++) {
		if(i != validNum - 1 && i != num - 1) {
			printf("%05d %d %05d\n", node[i].address, node[i].data, node[i + 1].address);
		} else {
			printf("%05d %d -1\n", node[i].address, node[i].data);
		}
	}
 	return 0;
}
