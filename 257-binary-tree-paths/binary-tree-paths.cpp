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
    void dfs(TreeNode* root, vector<int> &path, vector<string> &result){
        if(root == nullptr){
            return;
        }
        path.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr){
            string currpath;
            for(int i = 0; i<path.size(); i++){
                if(i>0){
                    currpath += "->";
                }
                currpath += to_string(path[i]);
            }
            result.push_back(currpath);
        }
        dfs(root->left, path, result);
        dfs(root->right, path, result);

        path.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int>path;
        dfs(root,path, result);

        return result;

    }
};