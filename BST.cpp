#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

class BSTnode
{
public:
	int data;
	BSTnode* left;
	BSTnode* right;
	BSTnode()//to initialize the left and right of any BSTnode to points to null
	{
		this->left = NULL;
		this->right = NULL;
	}
};

class BST
{
private:
	int length;
	BSTnode* root;
	
	void insert_under_the_hood(BSTnode* currRoot, int value)
	{
		BSTnode* node = this->createNode();
		node->data = value;
		if (this->isEmpty())
		{
			node->left = node->right = NULL;
			this->root = node;//as this inserted node will be the root of the tree
		}
		else
		{
			if (value <= currRoot->data)
			{
				if (currRoot->left == NULL)// if tree has only the root node and we will insert at left sub-tree
				{
					currRoot->left = node;
				}
				else// there are already nodes in left sub-tree
				{
					this->insert_under_the_hood(currRoot->left, value);
				}
			}
			else
			{
				if (currRoot->right == NULL)// if tree has only the root node and we will insert at left sub-tree
				{
					currRoot->right = node;
				}
				else// there are already nodes in left sub-tree
				{
					this->insert_under_the_hood(currRoot->right, value);
				}
			}
		}
		this->length++;
	}

	void InOrderTraversal_UnderTheHood(BSTnode* currRoot)
	{
		if (currRoot == NULL)
		{
			return;
		}
		else
		{
			this->InOrderTraversal_UnderTheHood(currRoot->left);
			cout << currRoot->data << endl;
			this->InOrderTraversal_UnderTheHood(currRoot->right);
		}

	}

	// BSTnode* Convert_Sorted_Array_to_BST_Under_The_Hood(BSTnode* currRoot,vector<int>&nodes,int start,int end)
	// {
	// 	if(start>end)
	// 	{
	// 		return NULL;
	// 	}
	// 	else
	// 	{
	// 		int midNode=(start+end)/2;
	// 		currRoot->left=this->Convert_Sorted_Array_to_BST_Under_The_Hood()
	// 	}
	// }

	BSTnode* Search_under_the_hood(int value,BSTnode* currRoot)
	{
		if(currRoot!=NULL)
		{
			if(value==currRoot->data)
			{
				return currRoot;
			}
			else if(value<currRoot->data)
			{
				return this->Search_under_the_hood(value,currRoot->left);
			}
			else if(value>currRoot->data)
			{
				return this->Search_under_the_hood(value,currRoot->right);
			}
		}
		else
		{
			return NULL;
		}
		
	}

public:
	BST()
	{
		this->length = 0;
		this->root = NULL;
	}

	bool isEmpty()
	{
		return this->root == NULL;
	}

	BSTnode* createNode()
	{
		BSTnode* newNode = new BSTnode();
		newNode->left = newNode->right = NULL;
		return newNode;
	}

	void insert(int value)
	{
		this->insert_under_the_hood(this->root, value);
	}

	void InOrderTraversal()
	{
		this->InOrderTraversal_UnderTheHood(this->root);
	}

	int height(BSTnode* node){
		if(node==NULL)
		{
			return -1;
		}
	}

	BSTnode* Search(int value)
	{
		return this->Search_under_the_hood(value,this->root);
	}

	// void Convert_Sorted_Array_to_BST(vector<int>&nodes)
	// {
	// 	this->root=
	// 	this->Convert_Sorted_Array_to_BST_Under_The_Hood(root,nodes,0,nodes.size()-1);
	// }

};

int main()
{
	BST bst;
	bst.insert(10);
	bst.insert(7);
	bst.insert(12);
	bst.insert(5);
	bst.insert(8);
	bst.InOrderTraversal();
	return 0;
}