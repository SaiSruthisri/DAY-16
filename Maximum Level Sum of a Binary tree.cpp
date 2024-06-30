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
    int maxLevelSum(TreeNode* root) {
        int maxi=INT_MIN;
        int maxrow=0;
        queue<TreeNode*>q;
        if(root==nullptr)
        {
            return 0;
        }
        q.push(root);
        int row=0;

        while(!q.empty())
        {
            int size =q.size();
            int level =0;
            for(int i=0;i<size ;i++)
            {
                TreeNode* temp = q.front();
                level+=(temp->val);
                q.pop();
                if(temp->left !=NULL)q.push(temp->left);
                if(temp->right !=NULL)q.push(temp->right);

            }

            if(level>maxi)
            {
                maxi=level;
                maxrow=row;
            }
            row++;


        }
        return maxrow+1;

    }
};
