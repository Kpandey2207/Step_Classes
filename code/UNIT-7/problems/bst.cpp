#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:

    // Insert Node
    TreeNode* insert(TreeNode* root, int val) {
        if (root == NULL)
            return new TreeNode(val);

        if (val < root->data)
            root->left = insert(root->left, val);
        else if (val > root->data)
            root->right = insert(root->right, val);

        return root;
    }

    //BFS Traversal
    vector<int> bfs(TreeNode* root){
        vector<int> result;
        if(root==NULL)
        return result;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            result.push_back(curr->data);
            if(curr->left)
            q.push(curr->left);
            if(curr->right)
            q.push(curr->right);
        }
        return result;
    }

    //DFS Traversal = Preorder traversal using stack
    vector<int>dfs(TreeNode* root){
        vector<int> result;
        if(root==NULL)
        return result;
        
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty()){
            TreeNode* curr=s.top();
            s.pop();
            result.push_back(curr->data);
            if(curr->right)
            s.push(curr->right);
            if(curr->left)
            s.push(curr->left);
        }
        return result;
    }

    //Inorder Traversal using stack
    vector<int>inorderStack(TreeNode* root){
        vector<int> result;
        if(root==NULL)
        return result;

        stack<TreeNode*>s;
        TreeNode* curr=root;

        while(curr || !s.empty()){
            while(curr){
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();
            s.pop();
            result.push_back(curr->data);
            curr=curr->right;
        }
        return result;
    }

    //Inorder Traversal using Recursion
    void inorderRec(TreeNode* root, vector<int>& result){
        if(root==NULL)
        return;

        inorderRec(root->left,result);
        result.push_back(root->data);
        inorderRec(root->right,result);
    }

    //Preorder Traversal using Recursion
    void preorderRec(TreeNode* root, vector<int>& result){
        if(root==NULL)
        return;

        result.push_back(root->data);
        preorderRec(root->left,result);
        preorderRec(root->right,result);
    }

    //Postorder Traversal using stack
    vector<int> postorder(TreeNode* root){
        vector<int> result;
        if(root==NULL)
        return result;

        stack<TreeNode*>s;
        s.push(root);

        while(!s.empty()){
            TreeNode* curr=s.top();
            s.pop();
            result.push_back(curr->data);
            if(curr->left)
            s.push(curr->left);
            if(curr->right)
            s.push(curr->right);
        }
        reverse(result.begin(),result.end());
        return result;
    }
    
    //Postorder Traversal using Recursion
    void postorderRec(TreeNode* root, vector<int>& result){ 
        if(root==NULL)
        return;

        postorderRec(root->left,result);
        postorderRec(root->right,result);
        result.push_back(root->data);
    }

    //Search in BST
    bool search(TreeNode* root, int key){
        if(root==NULL)
        return false;

        if(root->data==key)
        return true;
        else if(key<root->data)
        return search(root->left, key);
        else
        return search(root->right, key);
    }

    

};

int main() {

    BST bst;
    TreeNode* root = nullptr;

    int n;
    cout<<"Enter number of nodes : ";
    cin>>n;
    vector<int>values(n);
    cout<<"Enter values : ";  
    for(auto &x : values)
        cin>>x;

    for (int x : values)
        root = bst.insert(root, x);
    
    
    
    return 0;
}