#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *right;
	struct node *left;
};

void insert(struct node **root,int elem)
{
	struct node *tmp;
	tmp = (struct node*)malloc(sizeof(struct node));
	tmp->data=elem;

	if(*root==NULL)
	{
		*root=tmp;
		return;
	}else{
		struct node *ptmp;
		ptmp=*root;
		while(1)
		{
			printf("Data is %d\n",ptmp->data);
			if(ptmp->data > tmp->data)
			{
				if(ptmp->left==NULL)
				{
					printf("Inserting at left\n");
					ptmp->left=tmp;
					break;
				}
				else
				{
					printf("Going to left of %d\n",ptmp->data);
					ptmp=ptmp->left;
				}
			}
			else
			{
				if(ptmp->right==NULL)
				{
					printf("Inserting at right of %d\n",ptmp->data);
					ptmp->right=tmp;
					break;
				}
				else
				{
					printf("Going to right of %d\n",ptmp->data);
					ptmp=ptmp->right;
				}
			}
		}
	
	}
	printf("%d is the root\n",(*root)->data);
}

void preorder(struct node *root){
	if(root == NULL){
		return;
	}
	printf("%d\t",root->data);
	preorder(root->left);
	preorder(root->right);
}

void postorder(struct node *root)
{
	if(root ==NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d\t",root->data);
}

void inorder(struct node *root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	printf("%d\t",root->data);
	inorder(root->right);

}
void main(){
	int i;
	struct node *root;
	root=NULL;

	int ch,elem;
	ch=0;
	while(ch!=5){
		printf("1.Insert\n2.preorder\n 3.Postorder\n4.Inorder\n5.Exit\n");
		scanf("%d",&ch);
		if(ch==1){
			printf("Enter the element to insert\n");
			scanf("%d",&elem);
			insert(&root,elem);
		}
		if(ch==2){
			preorder(root);
		}
		if(ch==3){
			postorder(root);
		}
		if(ch==4){
			inorder(root);
		}
		
		if(ch==5){
			break;
		}
	}

}
