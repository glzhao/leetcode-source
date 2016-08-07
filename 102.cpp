/*
 *102. Binary Tree Level Order Traversal
 *
 *Given a binary tree, return the level order traversal of its nodes'
 *values. (ie, from left to right, level by level).
 *
 *For example:
 *Given binary tree [3,9,20,null,null,15,7],
 *    3
 *   / \
 *  9  20
 *    /  \
 *   15   7
 *return its level order traversal as:
 *[
 * [3],
 * [9,20],
 * [15,7]
 *]
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        queue<TreeNode*> queue;
        vector<vector<int> > ret;
        vector<int> vet;
        
        if (root) {
            queue.push(root);
            queue.push(NULL);
        }

        while(!queue.empty()) {
            TreeNode *p = queue.front();
            queue.pop();

            if (p) {
                vet.push_back(p->val);

                if (p->left) {
                    queue.push(p->left);
                }

                if (p->right) {
                    queue.push(p->right);
                }
            } else {
                ret.push_back(vet);
                vet.resize(0);
                if (queue.size()) {
                    queue.push(NULL);
                }
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[])
{
    TreeNode t1(3);
    TreeNode t2(9);
    TreeNode t3(20);
    TreeNode t4(15);
    TreeNode t5(7);

    t3.left = &t4;
    t3.right = &t5;
    t1.left = &t2;
    t1.right = &t3;

    Solution *s = new Solution();
    vector<vector<int> > v = s->levelOrder(&t1);

    cout << v[0][0] << ","
        << v[1][0] << ","
        << v[1][1] << ","
        << v[2][0] << ","
        << v[2][1] << ","
        << endl;
    
    return 0;
}
