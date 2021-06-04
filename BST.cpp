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

	BSTnode* createNode(int value)
	{
		BSTnode* newNode = new BSTnode();
		newNode->left = newNode->right = NULL;
		newNode->data=value;
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

	int height_under_the_hood(BSTnode* node){
		if(node==NULL)
		{
			return -1;
		}
		return 1+max(this->height_under_the_hood(node->left),this->height_under_the_hood(node->right));
	}

	int height(int value)
	{
		BSTnode *Required_Node=this->Search_under_the_hood(value,this->root);
		if(Required_Node==NULL)
		{
			return -1;
		}
		return this->height_under_the_hood(Required_Node);
	}


	bool Search(int value)
	{
		if(this->Search_under_the_hood(value,this->root)!=NULL)
		{
			return true;
		}
		return false;
	}

	void Convert_BST_To_Sorted_Array_under_the_hood (vector<int>&nodes,BSTnode* CurrRoot)
	{
		if (CurrRoot == NULL)
		{
			return;
		}
		else
		{
			this->Convert_BST_To_Sorted_Array_under_the_hood(nodes,CurrRoot->left);
			nodes.push_back(CurrRoot->data);
			this->Convert_BST_To_Sorted_Array_under_the_hood(nodes,CurrRoot->right);
		}		
	}

	vector<int> Convert_BST_To_Sorted_Array()
	{
		vector<int>Sorted_Nodes;
		this->Convert_BST_To_Sorted_Array_under_the_hood(Sorted_Nodes,this->root);
		return Sorted_Nodes;
	}

	// BSTnode* Convert_SortedArray_To_BST(vector<int>&nodes,int start,int end)
	// {
	// 	if(start>end)
	// 	{
	// 		return NULL;
	// 	}
	// 	else
	// 	{
	// 		// get the index of middle item of sorted array
	// 		int Index_of_Mid_node=(start+end)/2;
	// 		// create the current root 
	// 		BSTnode *currRoot=this->createNode(nodes[Index_of_Mid_node]);
	// 		currRoot->left=Convert_SortedArray_To_BST(nodes,start,Index_of_Mid_node-1);
	// 		currRoot->right=Convert_SortedArray_To_BST(nodes,Index_of_Mid_node+1,end);
	// 		return currRoot;
	// 	}
	// }

	// void PreOrder(BSTnode *currRoot)
	// {
	// 	if(currRoot==NULL)
	// 	{
	// 		return;
	// 	}
	// 	else
	// 	{
	// 		cout<<currRoot->data<<endl;
	// 		PreOrder(currRoot->left);
	// 		PreOrder(currRoot->right);
	// 	}
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
	vector<int>SortedNodes=bst.Convert_BST_To_Sorted_Array();
	for(int i=0; i<SortedNodes.size();i++)
	{
		cout<<SortedNodes[i]<<" ";
	}
	cout<<endl;
	cout<<"Height of 10 is : "<<bst.height(12);
	return 0;
}