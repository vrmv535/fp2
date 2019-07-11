#include <stdio.h>
#include <stdlib.h>

int leaves;
int least;
int maxHeight;
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

void preorder(struct node *root,int height){
	if(root == NULL){
		return;
	}
	if(root->left == NULL && root->right ==NULL){
		leaves++;
	}
	if(root->data < least){
		least = root->data;
	}
	if(maxHeight < height){
		maxHeight = height;
	}
	printf("%d\t",root->data);
	preorder(root->left,height+1);
	preorder(root->right,height+1);
}

void postorder(struct node *root,int height)
{
	if(root ==NULL){
		return;
	}
	if(root->left == NULL && root->right ==NULL){
		leaves++;
	}
	if(root->data < least){
		least = root->data;
	}
	if(maxHeight < height){
		maxHeight = height;
	}
	postorder(root->left,height+1);
	postorder(root->right,height+1);
	printf("%d\t",root->data);
}

void inorder(struct node *root,int height)
{
	if(root==NULL)
	{
		return;
	}
	if(root->left == NULL && root->right ==NULL){
		leaves++;
	}
	if(root->data < least){
		least = root->data;
	}
	if(maxHeight < height){
		maxHeight = height;
	}
	inorder(root->left,height+1);
	printf("%d\t",root->data);
	inorder(root->right,height+1);

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
		leaves = 0;
		least = 99999;
		maxHeight = -1;
		if(ch==1){
			printf("Enter the element to insert\n");
			scanf("%d",&elem);
			insert(&root,elem);
		}
		if(ch==2){
			preorder(root,0);
			printf("\nThere are %d leaves\n",leaves);
			printf("The least element is %d\n",least);
			printf("Height of tree is %d\n",maxHeight);
		}
		if(ch==3){
			postorder(root,0);
			printf("\nThere are %d leaves\n",leaves);
			printf("The least element is %d\n",least);
			printf("Height of tree is %d\n",maxHeight);
		}
		if(ch==4){
			inorder(root,0);
			printf("\nThere are %d leaves\n",leaves);
			printf("The least element is %d\n",least);
			printf("Height of tree is %d\n",maxHeight);
		}
		
		if(ch==5){
			break;
		}
	}

}
