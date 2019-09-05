
#include <bits/stdc++.h>


using namespace std;

// Node Declaration
struct node
{
    int user_id;
    int recharge;
    struct node *left;
    struct node *right;
}*root;

// Class Declaration
class Tree
{
    public:
        int height(node *);
        int diff(node *);
        node *RR_rot(node *);
        node *LL_rot(node *);
        node *LR_rot(node *);
        node *RL_rot(node *);
        node* balance(node *);
        node* insert_node(node* ,int , int* );
        Tree()
        {
            root = nullptr;
        }
};

 //Height of Tree

int Tree::height(node *temp)
{
    int h = 0;
    if (temp != nullptr)
    {
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}


 //Difference in height
 
int Tree::diff(node *temp)
{
    int l_height = height (temp->left);
    int r_height = height (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}


 // Right- Right Rotation

node *Tree::RR_rot(node *parent)
{
    node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

 // Left- Left Rotation
 
node *Tree::LL_rot(node *parent)
{
    node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}


 //Left - Right Rotation
 
node *Tree::LR_rot(node *parent)
{
    node *temp;
    temp = parent->left;
    parent->left = RR_rot (temp);
    return LL_rot (parent);
}


 // Right- Left Rotation
 
node *Tree::RL_rot(node *parent)
{
    node *temp;
    temp = parent->right;
    parent->right = LL_rot (temp);
    return RR_rot (parent);
}


// Balancing AVL Tree

node *Tree::balance(node *temp)
{
    int bal_factor = diff (temp);
    if (bal_factor > 1)
    {
        if (diff (temp->left) > 0)
            temp = LL_rot (temp);
        else
            temp = LR_rot (temp);
    }
    else if (bal_factor < -1)
    {
        if (diff (temp->right) > 0)
            temp = RL_rot (temp);
        else
            temp = RR_rot (temp);
    }
    return temp;
}


// Insert Element into the tree
 
node* Tree::insert_node(node* root,int uid, int* rech)
{
    if (root == nullptr)
    {
        root = new node;
        root->user_id = uid;
        root->recharge = *rech;
        root->left = nullptr;
        root->right = nullptr;
        return root;
    }
    else if (uid < root->user_id)
    {
        root->left = insert_node(root->left, uid, rech);
        root = balance (root);
    }
    else if (uid > root->user_id)
    {
        root->right = insert_node(root->right, uid, rech);
        root = balance (root);
    }
    else{
        root->recharge+=*rech;
        *rech=root->recharge;
        return root;
    }
    return root;
}

int main()
{
    Tree avl;
	int n;
	cin>>n;
	int q;
	cin>>q;
	int maxi=-1;
	int id=-1;
	while(q--){
		int x;
		cin>>x;
		if(x==1){
			int uid;
			int recharge;
			cin>>uid>>recharge;
			root=avl.insert_node(root,uid,&recharge);
			if(recharge>maxi){
				maxi=recharge;
				id=uid;
			}
		}
		else{
			if(id==-1)
				cout<<"No data available.\n";
			else
				cout<<id<<"\n";
		}
	}
    return 0;
}


