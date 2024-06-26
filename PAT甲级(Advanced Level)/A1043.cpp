#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1005;
//int pre[maxn];
struct node{
	int data;
	node* lchild;
	node* rchild;
};

//node* create(int preL, int preR, bool flag) {
//	if(preL > preR) return NULL;
//	node* root = new node;
//	root->data = pre[preL];
//	int k;
//	for(k = preL + 1; k <= preR; k++) {
//		if(flag == true) {
//			if(pre[k] >= pre[preL]) break;
//		} else {
//			if(pre[k] < pre[preL]) break;
//		}		
//	}
//	root->lchild = create(preL + 1, k - 1, flag);
//	root->rchild = create(k, preR, flag);
////	printf("%d ",root->data);
//	return root;
//}
//
//bool isBSTorMirrBST(int l, int r) {
//	node* root = new node;
//	root->data = pre[l];
//	int k;
//	for(k = l + 1; k <= r; k++) {
//		if(pre[k] >= pre[l]) break;
//	}
//}

void insert(node* &root, int data) {
	if(root == NULL) {
		root = new node;
		root->data = data;
		root->lchild = root->rchild = NULL;
		return;
	}
	if(data >= root->data) insert(root->rchild, data);
	else insert(root->lchild, data);
}
int num = 0;
void postOrder(node* root, bool flag, int n) {
	if(root == NULL) return;
	if(flag == true) {
		postOrder(root->lchild, flag, n);
		postOrder(root->rchild, flag, n);
	} else {
		postOrder(root->rchild, flag, n);
		postOrder(root->lchild, flag, n);
	}	
	printf("%d", root->data);
	num++;
	if(num < n) printf(" ");
}
void preOrder(node* root, vector<int> &vi) {
	if(root == NULL) return;
	vi.push_back(root->data);
	preOrder(root->lchild, vi);
	preOrder(root->rchild, vi);
}
void preOrderMirr(node* root, vector<int> &vi) {
	if(root == NULL) return;
	vi.push_back(root->data);
	preOrderMirr(root->rchild, vi);
	preOrderMirr(root->lchild, vi);
}
int main() {
	int n, temp;
	scanf("%d", &n);
	node* root = NULL;
	vector<int> origin, pre, preM;
	for(int i = 0; i < n; i++) {
		scanf("%d", &temp);
		origin.push_back(temp);
		insert(root, temp);
	}
	preOrder(root, pre);
	preOrderMirr(root, preM);
	bool flag;
	if(origin == pre) {
		flag = true;
		printf("YES\n");
		postOrder(root, flag, n);
	} else if(origin == preM) {
		flag = false;
		printf("YES\n");
		postOrder(root, flag, n);
	} else {
		printf("NO\n");
	}
//	node* root = create(0, n - 1);
//	postOrder(root);
	return 0;
}
