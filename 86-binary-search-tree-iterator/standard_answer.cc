/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 * Example of iterate a tree:
 * BSTIterator iterator = BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
 
 
 


class BSTIterator {
public:
    stack<TreeNode*> stk;
    
    /*
    * @param root: The root of binary tree.
    */BSTIterator(TreeNode * root) {
        // do intialization if necessary
        while (root != NULL) {
            stk.push(root);
            root = root->left;
            
        }
    }

    /*
     * @return: True if there has next node, or false
     */
    bool hasNext() {
        // write your code here
        return !stk.empty();
    }

    /*
     * @return: return next node
     */
    TreeNode * next() {
        // write your code here
        TreeNode* curt = stk.top();
        TreeNode* node = curt;
        if (node->right == NULL) {
            node = stk.top();
            stk.pop();
            while (!stk.empty() && stk.top()->right == node) {
                node = stk.top();
                stk.pop();
            }
        } else {
            node = node->right;
            while (node != NULL) {
                stk.push(node);
                node = node->left;
            }
        }
        return curt;
    }
};
