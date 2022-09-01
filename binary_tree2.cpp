//implementation of binary tree using queue
//printing of binary tree
#include<bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;
    TreeNode(T data)
    {
        this->data = data;
    }
    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};
string tobePrinted;

TreeNode<int> *takeInputLevelWise()
{
    queue<TreeNode<int> *> pendingNode; // taken a queue

    cout << "enter the root data " << endl;

    int rootdata; // taken root data from user

    cin >> rootdata;

    TreeNode<int> *root = new TreeNode<int>(rootdata); // new queue me root data element insert

    pendingNode.push(root); // push the data

    while (pendingNode.size() != 0)
    { // loop run until the queue is empty

        TreeNode<int> *currentNode = pendingNode.front(); // front data store in current data

        pendingNode.pop(); // pop front data

        cout << "Enter the number of children " << currentNode->data << endl; // taken total number of child
        int n;
        cin >> n; // child le liya element me
        for (int i = 1; i <= n; i++)
        {
            // saare child insert kr diya
            int currentchilddata;

            cout << i << " th child data" << currentNode->data << endl;

            cin >> currentchilddata;

            TreeNode<int> *childNode = new TreeNode<int>(currentchilddata);

            currentNode->children.push_back(childNode); //children me childnode ko dal do 

            pendingNode.push(childNode);  //childnode ko queue me dal do taki woo aage process kr sake 
            
        }
    }
    return root;
}

void dataTreePrint(TreeNode<int> *root)
{
    // string tobeprinted;
    // string tobePrinted;
    queue<TreeNode<int> *> pendingNode;  //queue 
    pendingNode.push(root);
    while (pendingNode.size() != 0)
    {
        TreeNode<int> *currentNode = pendingNode.front();
        pendingNode.pop();
        tobePrinted = to_string(currentNode->data)+" :";

        for (int i = 0; i < currentNode->children.size(); i++)
        {
            tobePrinted += to_string(currentNode->children[i]->data) + " ,";
            pendingNode.push(currentNode->children[i]);
        }
        if(tobePrinted[tobePrinted.length() - 1] == ',')
        {
            tobePrinted = tobePrinted.substr(0, tobePrinted.length() - 1);
        }
        cout << tobePrinted << endl;
    }
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    dataTreePrint(root);
}
// 1 2 2 3 2 4 5 2 6 7 0 0 0 0