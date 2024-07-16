#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/
    void topView(Node * root) 
    {
        if (!root)
            return;
        map<int,int> Top_View_Check_Point;
        queue<pair<Node*,int>> Q;
        Q.push(make_pair(root,0));

        while (!Q.empty())
        {
            Node* current = Q.front().first;
            int Distane = Q.front().second;
            Q.pop();
            if (Top_View_Check_Point.find(Distane) == Top_View_Check_Point.end())
            {
                Top_View_Check_Point[Distane] = current->data;
            }
            if (current->left)
                Q.push({current->left,Distane-1});
            if (current->right)
                Q.push({current->right,Distane+1});
        }

        for (map<int,int>::iterator itr = Top_View_Check_Point.begin(); itr != Top_View_Check_Point.end(); ++itr)
            cout << itr->second << " ";
    }

}; //End of Solution

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    myTree.topView(root);

    return 0;
}
