/*
 *104. Maximum Depth of Binary Tree
 *Given a binary tree, find its maximum depth.
 *The maximum depth is the number of nodes along the longest path from the root
 *node down to the farthest leaf node.
 */

#include <iostream>
#include <queue>

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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> queue;
        int depth = 0;
        
        if (root) {
            queue.push(root);
            queue.push(NULL);
        } else {
            return 0;
        }

        while(!queue.empty()) {
            TreeNode *p = queue.front();
            queue.pop();

            if (p) {
                if (p->left) {
                    queue.push(p->left);
                }

                if (p->right) {
                    queue.push(p->right);
                }
            } else {
                depth++;
                if (queue.size()) {
                    queue.push(NULL);
                }
            }
        }

        return depth;
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
	cout << s->maxDepth(&t5) << endl;
    
    return 0;
}
