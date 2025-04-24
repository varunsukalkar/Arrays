/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

TreeNode * buildTree(vector<int> & preorder , int prestart , int preend ,
 vector<int> & inorder , int instart , int inend , map<int, int > & inmap){

 \tif(prestart>preend || instart >inend){
 \t\treturn nullptr;
 \t}

 \tTreeNode * root = new TreeNode( preorder[prestart]);

 \tint inroot = inmap[root->val];
 \tint numsleft = inroot-instart;

 \troot->left = buildTree(preorder , prestart+1 , prestart+ numsleft , inorder, instart , inroot-1 , inmap);

 \troot->right = buildTree(preorder , prestart+numsleft+1 , preend , inorder  , inroot+1 , inend , inmap);

 \treturn root;

}


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>inmap;

\tfor(int i = 0; i< inorder.size(); i++){
\t\tinmap[inorder[i]]=i;
\t}

\tTreeNode * root = buildTree(preorder , 0 , preorder.size()-1 , 
\t\tinorder ,0, inorder.size()-1 ,inmap );

\treturn root;

    }
};