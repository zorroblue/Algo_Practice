typedef struct node
{
    int data;
    struct node *left,*right;
}node;

//A function to return a dynamically allocated node 
node *gen_node(int x)
{
    node *newnode=(node *)malloc(sizeof(node));
    newnode->data=x;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

//A function to implement standard BST insert without recursion ,returns the root of the tree
node *insert_without_recursion(node *root,int x)
{
    if(root==NULL)
    {
       node *newnode= gen_node(x);
        root=newnode;
        return root;
    }
    else // the tree is not empty
    {
        node *p=root;
        while(p!=NULL)
        {
            if(p->data==x)
                return root; //the tree already has the root
            else if(p->data>x)
                p=p->left;
            else
                p=p->right;
        }
        //now p is at the right place and is null
        p=gen_node(x);
        p->data=x;
        p->left=NULL;
        p->right=NULL;
        return root;
    }
}

