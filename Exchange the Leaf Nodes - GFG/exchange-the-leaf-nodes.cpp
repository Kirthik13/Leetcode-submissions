// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++
/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    // void fn(Node* root,vector<Node*>&v)
    // {
    //     if(!root) return;
    //     if(!root->left and !root->right)
    //     {
    //         v.push_back(root);
    //         return;
    //     }
    //     fn(root->left,v);
    //     fn(root->right,v);
        
    // }
    // void dfs(Node* &root,vector<Node*>v,int &j)
    // {
    //     if(!root) return;
    //     if(!root->left and !root->right)
    //     {
    //         // if(j<v.size()){
    //         Node* t=v[j];
    //         root=t;
    //         j++;
    //         // }
    //         return;    
    //     }
    //     dfs(root->left,v,j);
    //     dfs(root->right,v,j);
        
    // }
   
    void dfs(Node* &root,Node* &v)
    {
        if(!root) return;
        if(!root->left and !root->right)
        {
            // if(j<v.size()){
            if(v){
            
            swap(v->data,root->data);
            v=NULL;
            }
            else{
                // f=1;
                v=root;
                
            }
            // j++;
            // }
            return;    
        }
        dfs(root->left,v);
        dfs(root->right,v);
        
    }
    void pairwiseSwap(Node *root)
    {
        // code here
        // vector<Node*>v;
        // queue<Node*>q;
        // fn(root,v);
        // // for(auto i:v)
        // // {
        // //     cout<<i->data<<" ";
        // // }
        // // cout<<endl;
        // for(int i=1;i<v.size();i+=2)
        // {
        //     swap(v[i],v[i-1]);
        // }
        // // for(auto i:v)
        // // {
        // //     cout<<i->data<<" ";
        // // }
        // // cout<<endl;
        
        // cout<<endl;
        //  q.push(root);
        //  int j{};
        
    Node* v=NULL;
         dfs(root,v);
        //  dfs(root,v,j);
       
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        obj.pairwiseSwap(root);
        printInorder(root);
        if (treeString.size() != 0)
            cout << "\n";
    }
    return 0;
}  // } Driver Code Ends