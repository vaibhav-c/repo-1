#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node * left;
    Node * right;
    Node(void):left{NULL},right{NULL}{};
    Node(int val):data{val},left{NULL},right{NULL}{};
};


class BST
{
public:
    BST(){};
    Node* add_node(Node *,int);
    int search_data(Node *,int);
    void display(Node*);
    void show_0_deg(Node *);
    void show_1_deg(Node *);
    void show_2_deg(Node *);
    int calc_0_deg(Node *);
    int calc_1_deg(Node *);
    int calc_2_deg(Node *);
    void show_h_height_node(Node*,int);
    int max_val(Node *);
    int min_val(Node *);
    int total_node(Node *);
    int height(Node *);
};

void BST::show_h_height_node(Node *root,int h)
{
    if(!root||h<0)
        return;
    if(!h)
    {
        cout<<root->data<<" ";
        return;
    }
    show_h_height_node(root->left,h-1);
    show_h_height_node(root->right,h-1);
}

int BST::calc_2_deg(Node *root)
{
    if(!root)
        return 0;
    int left_Count = calc_2_deg(root->left);
    int right_Count = calc_2_deg(root->right);
    if(root->left&&root->right)
        return 1+left_Count + right_Count;
    else
        return left_Count + right_Count;
}

int BST::calc_1_deg(Node *root)
{
    if(!root)
        return 0;
    if((root->left&&!root->right)||(!root->left&&root->right))
        return 1+calc_1_deg(root->left)+calc_1_deg(root->right);
    return calc_1_deg(root->left)+calc_1_deg(root->right);
}

int BST::calc_0_deg(Node *root)
{
    if(!root)
        return 0;
    if(!root->left&&!root->right)
        return 1;
    return calc_0_deg(root->left)+calc_0_deg(root->right);
}

void BST::show_0_deg(Node *root)
{
    if(!root)
        return;
    show_0_deg(root->left);
    if(!root->left&&!root->right)
        cout<<root->data<<" ";
    show_0_deg(root->right);
}

void BST::show_1_deg(Node *root)
{
    if(!root)
        return;
    show_1_deg(root->left);
    if((root->left&&!root->right)||(!root->left&&root->right))
        cout<<root->data<<" ";
    show_1_deg(root->right);
}

void BST::show_2_deg(Node *root)
{
    if(!root)
        return;
    show_2_deg(root->left);
    if(root->left&&root->right)
        cout<<root->data<<" ";
    show_2_deg(root->right);
}

int BST::min_val(Node *root)
{
    int minval = root->data;
    if(root->left)
        minval = min_val(root->left);
    return minval;
}

int BST::max_val(Node *root)
{
    int maxval = root->data;
    if(root->right)
        maxval = max_val(root->right);
    return maxval;
}

int BST::total_node(Node *root)
{
    if(!root)
        return 0;
    if(!root->left&&!root->right)
        return 1;
    else return 1+total_node(root->left)+total_node(root->right);
}

int BST::height(Node *root)
{
    if(!root)
        return 0;
    if(!root->left&&!root->right)
        return 1;
    else
    {
        int lheight = height(root->left);
        int rheight = height(root->right);
        if(lheight>rheight)
            return 1+lheight;
        else return 1+rheight;
    }
}

void BST::display(Node *root)
{
    if(!root)
        return;
    display(root->left);
    cout<<root->data<<" ";
    display(root->right);
}

int BST::search_data(Node *head,int data)
{
    if(!head)
        return 0;
    if(data==head->data)
        return 1;
    else return search_data(head->left,data)||search_data(head->right,data);
}

Node* BST::add_node(Node * root,int data)
{
    if(!root)
        root = new Node(data);
    else
    {
        if(data>=root->data)
            root->right = add_node(root->right,data);
        else root->left = add_node(root->left,data);
    }
    return root;
}

main()
{
    BST tree;
    Node * head =NULL;
    int op{0};
    while(op!=15)
    {
        cout<<"\n\nPrint 1 to add a node ";
        cout<<"\nPrint 2 to display tree ";
        cout<<"\nPrint 3 to calculate height ";
        cout<<"\nPrint 4 to search a data ";
        cout<<"\nPrint 5 to print maximum value ";
        cout<<"\nPrint 6 to print minimum value ";
        cout<<"\nPrint 7 to print 0 degree nodes ";
        cout<<"\nPrint 8 to print 1 degree nodes ";
        cout<<"\nPrint 9 to print 2 degree nodes ";
        cout<<"\nPrint 10 to calculate 0 degree nodes ";
        cout<<"\nPrint 11 to calculate 1 degree nodes ";
        cout<<"\nPrint 12 to calculate 2 degree nodes ";
        cout<<"\nPrint 13 to calculate total nodes ";
        cout<<"\nPrint 14 to print nodes at a height ";
        cout<<"\nPrint 15 to quit ";
        cin>>op;
        switch(op)
        {
        case 1:
            {
                cout<<"\nEnter data you want to add ";
                int data;
                cin>>data;
                head = tree.add_node(head,data);
                break;
            }
        case 2:
            {
                cout<<"\nTree: ";
                tree.display(head);
                break;
            }
        case 3:
            {
                cout<<"\nHeight of the tree: "<<tree.height(head);
                break;
            }
        case 4:
            {
                cout<<"\nEnter data you want to search ";
                int data;
                cin>>data;
                if(tree.search_data(head,data))
                    cout<<"\nNumber found";
                else cout<<"\nNumber not found";
                break;
            }
        case 5:
            {
                if(!head)
                    cout<<"\nNo available tree";
                else
                cout<<"\nMaximum value in tree: "<<tree.max_val(head);
                break;
            }
        case 6:
            {
                if(!head)
                    cout<<"\nNo available tree";
                else
                cout<<"\nMinimum value in tree: "<<tree.min_val(head);
                break;
            }
        case 7:
            {
                if(!tree.calc_0_deg(head))
                cout<<"\nNo nodes available";
                else
                {
                    cout<<"\n0 degree nodes: ";
                    tree.show_0_deg(head);
                }
                break;
            }
        case 8:
            {
                if(!tree.calc_1_deg(head))
                cout<<"\nNo nodes available";
                else
                {
                    cout<<"\n1 degree nodes: ";
                    tree.show_1_deg(head);
                }
                break;
            }
        case 9:
            {
                if(!tree.calc_2_deg(head))
                cout<<"\nNo nodes available";
                else
                {
                    cout<<"\n2 degree nodes: ";
                    tree.show_2_deg(head);
                }
                break;
            }
        case 10:
            {
                cout<<"\nNumber of 0 degrees node: "<<tree.calc_0_deg(head);
                break;
            }
        case 11:
            {
                cout<<"\nNumber of 1 degrees node: "<<tree.calc_1_deg(head);
                break;
            }
        case 12:
            {
                cout<<"\nNumber of 2 degrees node: "<<tree.calc_2_deg(head);
                break;
            }
        case 13:
            {
                cout<<"\nTotal nodes in tree: "<<tree.total_node(head);
                break;
            }
        case 14:
            {
                cout<<"\nEnter height you want to see ";
                int data;
                cin>>data;
                if(data<0||data>=tree.height(head))
                    cout<<"\nInvalid input";
                else
                {
                    cout<<"\nNodes at "<<data<<" height: ";
                    tree.show_h_height_node(head,data);
                }
                break;
            }
        case 15:
            {
                cout<<"\nThank you";
                exit(0);
            }
        default:
            {
                cout<<"\nInvalid option chosen ";
                break;
            }
        }
    }
}
