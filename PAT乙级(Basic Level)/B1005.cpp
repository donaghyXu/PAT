#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1000;
int hashTable[N] = {0}; 	//ɢ�б�������0����δ��֤��-1��������
//��֤3n+1���� 
void valid(int n) {
	while(n != 1) {
		if(n % 2 == 0) {
			n = n / 2;
			hashTable[n] = -1;	//�������ǵ�����Ϊ-1 
		} else {
			n = (3 * n + 1) / 2;
			hashTable[n] = -1;
		}
	}
}

//���Ӵ�С���� 
bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int n, cnt = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		if(hashTable[temp] == 0) hashTable[temp] = temp;	//���δ����֤���Ͱ����������Լ�	 
		valid(temp);	//������֤ 
	} 
	sort(hashTable, hashTable + N, cmp);	//û�����ǵ����������������ǵľ���-1��δ��֤�ľ���0 
	
	for(int i = 0; i < n; i++) {
		if(hashTable[i] > 0) cnt++;	//ͳ���ж��ٸ��ؼ��� 
	}
	
	for(int i = 0; i < cnt; i++) {
		if(hashTable[i]) printf("%d", hashTable[i]);
		if(i != cnt - 1) printf(" ");
	}
	return 0;
} 
