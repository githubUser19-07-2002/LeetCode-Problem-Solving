//Problem Link
https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/?envType=daily-question&envId=2025-04-04

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
    TreeNode *ans = NULL;
    int getMaxDepth(TreeNode* root){
        if(!root){
            return 0;
        }
        return 1+max(getMaxDepth(root->left),getMaxDepth(root->right));
    }
    int countOfNodes(TreeNode* root,int depth,int maxDepth){
        if(!root){
            return 0;
        }
        if(depth == maxDepth){
            return 1;
        }
        return countOfNodes(root->left,depth+1,maxDepth) + countOfNodes(root->right,depth+1, maxDepth);
    }
    int getLca(TreeNode* root,int depth = 1,int maxDepth = 1,int count = 0){
        if(!root){
            return 0;
        }
        int current = (depth == maxDepth);
        int countLeft = getLca(root->left,depth+1,maxDepth,count);
        int countRight = getLca(root->right,depth+1,maxDepth,count);

        if(current+countLeft+countRight == count && ans == NULL){
            ans = root;
        }
        return countLeft+countRight+current;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root->left && !root->right){
            return root;
        }
        int depth = getMaxDepth(root);
        int count = countOfNodes(root,1,depth);
        getLca(root,1,depth,count);
        return ans;
        }
};