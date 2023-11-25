#include <iostream>
#include <cstdlib>
using namespace std;

// Binary Search Tree Node
class BinarySearchTree
{
    private:
        // Tree node definition
        struct tree_node {
            tree_node* left;
            tree_node* right;
            int data;
        };

    public:
        // Root of the tree
        tree_node* root;

        // Constructor
        BinarySearchTree() {
            root = nullptr;
        }

        // Destructor
        bool isEmpty() const { return root == NULL; }
        
        // Functions to insert data
        void print_inorder();

        // Functions to traverse tree
        void inorder(tree_node*);

        // Functions to traverse tree
        void print_preorder();

        // Functions to traverse tree
        void preorder(tree_node*);

        // Functions to traverse tree
        void print_postorder();

        // Functions to traverse tree
        void postorder(tree_node*);

        // Functions to insert data
        void insert(int);

        // Functions to remove data
        tree_node* remove(int d, tree_node* node) {

            // Base case
            if (node == nullptr)
                return nullptr;

            // Recursive case
            else if (d < node->data)
            {
                node->left = remove(d, node->left);
                return node;
            }

            // Recursive case
            else if (d > node->data)
            {
                node->right = remove(d, node->right);
                return node;
            }

            // Base case
            else if (d == node->data)
            {
                // Case 1: No child
                if (node->left == nullptr && node->right == nullptr)
                {
                    delete node;
                    return nullptr;
                }

                // Case 2: One child
                else if (node->left == nullptr || node->right == nullptr)
                {
                    // If left child is empty, return right child
                    tree_node* temp;
                    if (node->left == nullptr)
                        temp = node->right;
                    else
                        temp = node->left;
                    delete node;
                    return temp;
                }

                // Case 3: 2 children
                else
                {
                    // Find the minimum value in the right subtree
                    tree_node* temp = node->right;
                    while (temp->left != nullptr)
                        temp = temp->left;
                    node->data = temp->data;
                    node->right = remove(temp->data, node->right);
                    return node;
                }
            }
        }
};

// Function to insert data
void BinarySearchTree::insert(int d) {

    // Create a new tree node
	tree_node* t = new tree_node;
	tree_node* parent = root;
	t->data = d;
	t->left = nullptr;
	t->right = nullptr;

    // If the tree is empty, make the new node the root
	if (root == nullptr) {
		root = t;
		return;
	}

	// Smaller elements should go to the left, whereas larger  elements should go to the right
	else {
		
        tree_node* curr;
        curr = root;

        // Find the parent of the new node
        while (curr) {
            parent = curr;
            if (t->data > curr->data) curr = curr->right;
            else curr = curr->left;
        }

        // Insert the new node
        if (t->data < parent->data) parent->left = t;
        else parent->right = t;

	}
}


// Function to print inorder traversal
void BinarySearchTree::print_inorder() {
	inorder(root);
	cout << endl;
}

// Function to print inorder traversal
void BinarySearchTree::inorder(tree_node* p) {
	if (p != nullptr) 
	{
		inorder(p->left);
		cout << p->data << "\t";
		inorder(p->right);
	}
}

// Function to print preorder traversal
void BinarySearchTree::print_preorder() {
	preorder(root);
	cout << endl;
}

// Function to print preorder traversal
void BinarySearchTree::preorder(tree_node* p) {
	// Write your code here



}


// Function to print postorder traversal
void BinarySearchTree::print_postorder() {
	postorder(root);
	cout << endl;
}


// Function to print postorder traversal
void BinarySearchTree::postorder(tree_node* p) {
    // Write your code here

	


}

// Function to insert data
void insertIntoTree(BinarySearchTree* b) {

    // Ask the user how many elements they want to insert
	cout << "How many elements do you want to insert?" << endl;
	int n;
	cin >> n;
	int val;

    // Insert the elements
	for (int i = 0; i < n; i++)
	{
		cout << "Enter element # " << i << ":" << "\t";
		cin >> val;
		b->insert(val);
	}
}

// Main function
int main()
{
    // Create a new binary search tree
	BinarySearchTree b;

	while (true) {

		int menuOption = 0;

        // Display the menu
		while (menuOption > 6 || menuOption < 1) //This loop can exit program
		{
			cout << "\t*****************************************" << endl;
			cout << "\t* Select Option:\t\t\t*" << endl;
			cout << "\t*\t1. Insert New Data\t\t*" << endl;
			cout << "\t*\t2. In-Order Traversal\t\t*" << endl;
			cout << "\t*\t3. Pre-Order Traversal\t\t*" << endl;
			cout << "\t*\t4. Post-Order Traversal\t\t*" << endl;
			cout << "\t*\t5. Delete an item\t\t*" << endl;
			cout << "\t*\t6. Exit\t\t\t\t*" << endl;
			cout << "\t*****************************************" << endl;

			cout << "> ";
			cin >> menuOption;

			if (menuOption == 6) {
				return 0; //Exiting
			}


			switch (menuOption)
			{
				case 1:
				{
					insertIntoTree(&b);
					break;
				}
				case 2:
				{
					b.print_inorder();
					break;
				}
				case 3:
				{
					b.print_preorder();
					break;
				}
				case 4:
				{
					b.print_postorder();
					break;
				}
				case 5:
				{
					cout << "Enter element to remove:" << endl;
					int elem;
					cin >> elem;
					b.remove(elem, b.root);
				}
			}
		}

	}


    // Exit the program
	getchar();
}
