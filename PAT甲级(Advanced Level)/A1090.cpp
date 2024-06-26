#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 100010;
struct node{
	vector<int> child;
}Node[maxn];

int maxDepth = 0, num = 0;
void DFS(int root, int depth) {
	if(Node[root].child.size() == 0) {
		if(depth > maxDepth) {
			maxDepth = depth;
			num = 1;
		} else if(depth == maxDepth)
			num++;
		return;
	}
	for(int i = 0; i < Node[root].child.size(); i++) {
		DFS(Node[root].child[i], depth + 1);
	}
}
int main() {
	int n, root;
	double p, r;
	scanf("%d %lf %lf", &n, &p, &r);
	for(int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		if(temp != -1) 
			Node[temp].child.push_back(i);
	    else 
			root = i;		
	}
	DFS(root, 0);
	double res = p * pow((1 + r / 100), maxDepth);
	printf("%.2f %d", res, num);
	return 0;
}
