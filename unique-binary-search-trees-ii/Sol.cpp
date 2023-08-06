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
    map<pair<int,int>,vector<TreeNode*>> mp;
    vector<TreeNode*> find(int l, int r) {
        if(l>r) return { NULL };
        if(mp.find({l,r})!=mp.end()) {
            return mp[{l,r}];
        }
        vector<TreeNode*> ans;
        for(int i=l; i<=r; i++) {
            vector<TreeNode*> lft = find(l,i-1);
            vector<TreeNode*> rgt = find(i+1,r);
            for(int ind=0; ind<lft.size(); ind++) {
                for(int r=0; r<rgt.size(); r++) { 
                    TreeNode* root = new TreeNode(i);
                    root->left = lft[ind];
                    root->right = rgt[r];
                    ans.push_back(root);
                }
            }
        }
        mp[{l,r}]=ans;
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return find(1,n);
    }
};