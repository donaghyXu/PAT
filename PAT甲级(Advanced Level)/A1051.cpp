#include <cstdio>
#include <stack>
#include <queue>
using namespace std;
stack<int> s;
queue<int> q;
int main() {
	int m, n, k, num;
	scanf("%d %d %d", &m, &n, &k);
	for(int i = 0; i < k; i++) {
		for(int j = 1; j <= n; j++) {
			scanf("%d", &num);
			q.push(num);
		}
		bool flag = true;
		for(int j = 1; j <= n; j++) {
			if(s.size() < m) {
				s.push(j);
				while(s.empty() != true && q.empty() != true && s.top() == q.front()) {
					s.pop();
					q.pop();  
				}				
//				if(s1.top() != q1.front()) continue;
			} else {
				flag = false;
				break;
			}			
		}
		if(s.empty() == true && flag == true) printf("YES\n");
		else printf("NO\n");
		while(!q.empty()) {
			q.pop();
		}
		while(!s.empty()) {
			s.pop();
		}
	}
	return 0;
}
