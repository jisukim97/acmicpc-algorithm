#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)

using namespace std;

typedef struct node{
	int key;
	node* left;
	node* right;
	node* parent;
}node;

void postorder(node* ptr) {
	if (ptr) {
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%d\n", ptr->key);
	}
}

int main() {

	int n; scanf("%d", &n);
	node* Root;
	Root = new node({ n,NULL,NULL, NULL }); //루트 노드 생성
	node * now = Root; //루트에서 생성 시작
	
	while (scanf("%d", &n) != EOF) { 
	
		if (now->key > n) {//왼쪽자식- 현재노드보다 작은 key값이면 왼쪽에 무조건 생성
			node * lnode = new node({ n, NULL, NULL, now });
			now->left = lnode;
			now = now->left;
		}
		else { //오른쪽자식
			while (now->parent&&now->parent->key < n) { //부모(의 부모의 부모..)의 오른쪽에 달아야 하는지 체크
				now = now->parent;
			}
			while (now->right && now->right->key < n) { //부모(의 부모의 부모..)가 왼쪽 노드가 다 차서 leaf의 오른쪽에 달아야 하는지 체크
				now = now->right;
			}
			if (!now->parent) now = Root; //parent로 더이상 올라갈 수 없으면 root의 오른쪽으로 이동

			node* rnode = new node({ n, NULL, NULL, now });
			now->right = rnode;
			now = now->right;
		}
	}

	postorder(Root);

	return 0;
}