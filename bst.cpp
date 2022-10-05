#include<iostream>
using namespace std;

struct bstnode{
    int data;
    bstnode *left;
    bstnode *right;
};

// function to create a new node in heap
bstnode *create(int val)
{
    bstnode *newNode = new bstnode();
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// function to insert data in BST, return address of root node
bstnode *Insert(bstnode *root, int val)
{
    if(root == NULL) // empty tree
        root = create(val);
    
    else if(val <= root->data)
        root->left = Insert(root->left, val);
    
    else
        root->right = Insert(root->right, val);

    return root;
}

// function to display all values in a binary search tree
void display(bstnode *root)
{
    if(root!=NULL)
    {
        display(root->left);
        cout<<root->data<<" ";
        display(root->right);
    }
}

void search(bstnode *root, int val)
{
    if(root==NULL)
        cout<<"Element not found";

    else if(root->data == val)
        cout<<"Element is found";

    else if(val <= root->data)
        search(root->left, val);
        
    else
        search(root->right, val);
}


int main()
{
    bstnode *root = NULL;

    root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
    display(root);
    cout<<endl;
    int num;
	cout<<"Enter number be searched\n";
	cin>>num;
	search(root, num);

}