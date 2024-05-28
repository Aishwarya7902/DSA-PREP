PROBLEM :https://www.geeksforgeeks.org/problems/flatten-bst-to-sorted-list--111950/1
VIDEO :https://www.youtube.com/watch?v=NzXtnzQTouk&list=PLpIkg8OmuX-IBcXsfITH5ql0Lqci1MYPM&index=11

/*
  TC:O(N^2)
  SC:O(N)
*/

class Solution
{
public:
    Node *flattenBST(Node *root)
    {
        // code here
        if(!root)return NULL;
        
        Node *headLeft=flattenBST(root->left);
        Node *headRight=flattenBST(root->right);
        
        root->left=NULL;
        root->right=headRight;
        
        if(!headLeft)return root;
        Node *temp=headLeft;
        while(temp->right){
            temp=temp->right;
        }
        
        temp->right=root;
        return headLeft;
        
    }
};
