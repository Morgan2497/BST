#include <iostream>
#define SPACE 10
using namespace std;

class TreeNode 
{
  public:
    int value;
    TreeNode * left;
    TreeNode * right;


  TreeNode() 
  {
    value = 0;
    left = nullptr;
    right = nullptr;
  }

  TreeNode(int v) 
  {
    value = v;
    left = nullptr;
    right = nullptr;
  }
};


class BST {
  public:
    TreeNode * root;

  BST() 
  {
    root = nullptr;
  }

  bool isTreeEmpty() 
  {
    if (root == nullptr) {return true;} 

    else {return false;}
  }

  void insertNode(TreeNode * new_node) 
  {
    if (root == nullptr) 
    {
      root = new_node;
      cout << "Value Inserted as root node!" << endl;
    } 
    else 
    {
      TreeNode * temp = root;
      while (temp != nullptr) 
      {
        if (new_node -> value == temp -> value) 
        {
          cout << "Value Already exist, insert another value!" << endl;
          return;
        }

        else if ((new_node -> value < temp -> value) && (temp -> left == nullptr)) 
        {
          temp -> left = new_node;
          cout << "Value Inserted to the left!" << endl;
          break;
        }

        else if (new_node -> value < temp -> value) 
        {
          temp = temp -> left;
        }

        else if ((new_node -> value > temp -> value) && (temp -> right == nullptr)) 
        {
          temp -> right = new_node;
          cout << "Value Inserted to the right!" << endl;
          break;
        }
        else 
        {
          temp = temp -> right;
        }
      }
    }
  }
  	TreeNode* insertRecursive(TreeNode *r, TreeNode *new_node)
	{
		if(r==nullptr)
		{
			r=new_node;
			cout <<"Insertion successful"<<endl;
			return r;
		}
	
		if(new_node->value < r->value)
		{
			r->left = insertRecursive(r->left,new_node);
		}
		else if (new_node->value > r->value)  
		{
			r->right = insertRecursive(r->right,new_node);
		}
	   else
	   {
	     	cout << "No duplicate values allowed!" << endl;
	     	return r; 
		}
		return r;
	}

  void print2D(TreeNode * r, int space) 
  {
    // 1. Base Case
    if (r == nullptr) return;

    space += SPACE; // Increase distance between levels   2
    print2D(r -> right, space); // Process right child first 3 
    cout << endl;

    for (int i = SPACE; i < space; i++) // 5 
      cout << " "; // 5.1  
    cout << r -> value << "\n"; // 6
    print2D(r -> left, space); // Process left child  7
  }

  /*
    Pre-order method.
    Node - Left - Right
    1. Access the data part of the current node.
    2. Traverse the left subtree by recursively calling the function.
    3. Traverse the right subtree by recursively calling the function.
  */
  void printPreorder(TreeNode * r) //(current node, Left, Right) 
  {
    if (r == nullptr) return;

    
    cout << r -> value << " ";
   
    printPreorder(r -> left);
    
    printPreorder(r -> right);
  }
  
  /*
    In-order method.
    Left - Node - Right
    1. Traverse the left subtree by recursively calling the function.
    2. Access the data part of the current node.
    3. Traverse the right subtree by recursively calling the function.
  */  
  void printInorder(TreeNode * r) //  (Left, current node, Right)
  {
    if (r == NULL)
      return;
    // Goes down all the way through the left leaf node always.
    printInorder(r -> left);
    
    cout << r -> value << " ";

    // Goes down all the way through the right leaf node always.
    printInorder(r -> right);
  }
  /*
    Post-order
    Left - Right - Node
    1. Traverse the left subtree by recursively calling the function.
    2. Traverse the right substree by recursively calling the function.
    3. Access the data part of the current node.
  */  
  void printPostorder(TreeNode * r)
  {
    if (r == nullptr)
      return;

    // first recur on left subtree 
    printPostorder(r -> left);

    // then recur on right subtree 
    printPostorder(r -> right);

    // now deal with the node 
    cout << r -> value << " ";
  }

  TreeNode * iterativeSearch(int v) 
  {
    if (root == nullptr) 
    {
      return root;
    }

    else 
    {
      TreeNode * temp = root;
      while (temp != nullptr) 
      {
        if (v == temp -> value) 
        {
          return temp;
        }

        else if (v < temp -> value) 
        {
          temp = temp -> left;
        }

        else 
        {
          temp = temp -> right;
        }
      }
      return nullptr;
    }
  }

  TreeNode * recursiveSearch(TreeNode * r, int val) 
  {
    // empty or couldn't find
    if(r == nullptr) return nullptr;

    // could be the root that's matching with the val
    // or while searching through it by recursively calling the function, we found it.
    else if(r->value == val) return r;

    // if the value we are looking for is smaller than the current node, goes left.
    else if(r->value > val) {return recursiveSearch(r->left,val);}
    // if the value we are looking for is larger than the current node, goes right.
    else {return recursiveSearch(r->right, val);}
  }

  int height(TreeNode * r) 
  {
    if (r == nullptr)
      return -1;
    else 
    {
      // Keep calling the function recursively until it reaches out to nullptr on left side
      int lheight = height(r -> left);

      // Keep calling the function recursively until it reaches out to nullptr on right side
      int rheight = height(r -> right);

      /* use the larger one */
      if (lheight > rheight) {return (lheight + 1);}
      else {return (rheight + 1);}
    }
  }

  /* Print nodes at a given level */
  void printGivenLevel(TreeNode * r, int level) 
  {
    if (r == nullptr) return;

    else if (level == 0) {cout << r -> value << " ";}

    else // level > 0  
    {
      printGivenLevel(r -> left, level - 1);
      printGivenLevel(r -> right, level - 1);
    }
  }

  void printLevelOrderBFS(TreeNode * r) 
  {
    int h = height(r);
    for (int i = 0; i <= h; i++) {printGivenLevel(r, i);}
  }

  TreeNode * minValueNode(TreeNode * node) 
  {
    TreeNode * current = node;
    /* loop down to find the leftmost leaf */
    while (current -> left != nullptr) 
    {
      current = current -> left;
    }
    return current;
  }
  /*

      // base case 
    if (r == nullptr) {
      return nullptr;
    }

    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    else if (v < r -> value) { r -> left = deleteNode(r -> left, v);}

    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (v > r -> value) {r -> right = deleteNode(r -> right, v);}
    // if key is same as root's key, then This is the node to be deleted 
    else 
    {
      // node with only one child or no child 
      if (r -> left == nullptr) 
      {
        TreeNode * temp = r -> right;
        delete r;
        return temp;
      } 

      else if (r -> right == nullptr) 
      {
        TreeNode * temp = r -> left;
        delete r;
        return temp;
      }

      else 
      {
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        TreeNode * temp = minValueNode(r -> right);
        // Copy the inorder successor's content to this node 
        r -> value = temp -> value;
        // Delete the inorder successor 
        r -> right = deleteNode(r -> right, temp -> value);
        //deleteNode(r->right, temp->value); 
      }
    }
    return r;
  }

    The difference between r = r->right and r->right = r->right 
    r = r->right is we are moving the current location to the right of the curr node
    r->right = r->right is we are saving the data into the curr node of right address.  
  */
  TreeNode * deleteNode(TreeNode * r, int v) 
  {
    // Base case
    if (r == nullptr) return r;
    // If the value to be deleted is less than the current node, goes left.
    else if(v < r->value) { r->left = deleteNode(r->left, v);}

    // If the value to be delted is greater than the current node, goes right.
    else if(v > r->value) { r->right = deleteNode(r->right,v);}

    // After the two "else if" statements, if we are here in "else" part,
    // that means we've got the matching node so we proceed to delete the node.
    else
    {
    // 1. Case where a node has no child (Deleting a leaf node).
        if(r->left == nullptr && r->right == nullptr)
        {
            cout << "Value => " << r->value << " has been successfully deleted!" << endl;
            delete r;
            r = nullptr;
            return r; 
        }

    // 2. Case where a node has one child, but root's left is nullptr.
        else if(r->left == nullptr)
        {
            TreeNode* temp = r;
            r = r->right;
            cout << "Value => " << temp->value << " has been successfully deleted!" << endl;
            delete temp;
            return r;
         }

        // 3. Case where a node has one child, but root's right is nullptr.
        else if(r->right == nullptr)
        {
            TreeNode* temp = r;
            r = r->left;
            cout << "Value => " << temp->value << " has been successfully deleted!" << endl;
            delete temp;
            return r;
        }

        // 4. Case where a node has two children. Find the smallest node in the right subtree to replace.
        else
        {
            TreeNode* temp = minValueNode(r->right);
            r->value = temp->value;
            r->right = deleteNode(r->right, temp->value);
        }
    }
  }
};
int main() {
  BST obj;
  int option, val;
  int treeHeight = 0;

  do {
    cout << "What operation do you want to perform? " <<
      " Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Node" << endl;
    cout << "2. Search Node" << endl;
    cout << "3. Delete Node" << endl;
    cout << "4. Print/Traversal BST values" << endl;
    cout << "5. Height of Tree" << endl;
    cout << "6. Clear Screen" << endl;
    cout << "0. Exit Program" << endl;

    cin >> option;
    //Node n1;
    TreeNode * new_node = new TreeNode();

    switch (option) {
    case 0:
      break;
    case 1:
      	  cout <<"INSERT"<<endl;
	      cout <<"Enter VALUE of TREE NODE to INSERT in BST: ";
	      cin >> val;
	      new_node->value = val;

          cout << "Choose 1 for Iterative Insert or 2 for Recursive Insert: ";
          int sel;
          cin >> sel;

          if(sel == 1)
          {
            obj.insertNode(new_node);
          }
          else
          {
            obj.root = obj.insertRecursive(obj.root,new_node);
          }
          
	      cout<<endl;
    	  break;
      
    case 2:
      cout << "SEARCH" << endl;
      cout << "Enter VALUE of TREE NODE to SEARCH in BST: ";
      cin >> val;

      sel;
      cout << "Choose 1 for Iterative Search or 2 for Recursive Search: ";
      cin >> sel;

      if (sel == 1) {new_node = obj.iterativeSearch(val);}
      
      else {new_node = obj.recursiveSearch(obj.root, val);}
      
      if (new_node != nullptr) { cout << "Value found" << endl;} 
      else { cout << "Value NOT found" << endl;}
      break;

    case 3:
      cout << "DELETE" << endl;
      cout << "Enter VALUE of TREE NODE to DELETE in BST: ";
      cin >> val;
      new_node = obj.iterativeSearch(val);

      if (new_node != nullptr) 
      {
        obj.deleteNode(obj.root, val);
        cout << "Value Deleted" << endl;
      } 
      else 
      {
        cout << "Value NOT found" << endl;
      }
      break;

    case 4:
      cout << "PRINT 2D FUNCTION OPERATING . . .  " << endl;
      obj.print2D(obj.root, 5);
      cout << endl;
      cout << "Print Level Order BFS: \n";
      obj.printLevelOrderBFS(obj.root);
      cout << endl;
      //	      cout <<"PRE-ORDER: ";
      //	      obj.printPreorder(obj.root);
      //	      cout<<endl;
      //	      cout <<"IN-ORDER: ";
      //	      obj.printInorder(obj.root);
      //	      cout<<endl;
      //	      cout <<"POST-ORDER: ";
      //	      obj.printPostorder(obj.root);
      break;

    
    case 5:
      cout << "TREE HEIGHT" << endl;
      treeHeight = obj.height(obj.root);
      cout << "Height: " << treeHeight << endl;
      break;

    case 6:
      system("cls");
      break;

    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);


  return 0;
}
/*
int main() 
{
  BST obj;
  int option, val;

  do {
    cout << "What operation do you want to perform? " <<
      " Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Node" << endl;
    cout << "2. Search Node" << endl;
    cout << "3. Delete Node" << endl;
    cout << "4. Print/Traversal BST values" << endl;
    cout << "5. Height of Tree" << endl;
    cout << "6. Clear Screen" << endl;
    cout << "0. Exit Program" << endl;

    cin >> option;
    //Node n1;
    TreeNode * new_node = new TreeNode();

    switch (option) {
    case 0:
      break;
    case 1:
      	cout <<"INSERT"<<endl;
	      cout <<"Enter VALUE of TREE NODE to INSERT in BST: ";
	      cin >> val;
	      new_node->value = val;
	      obj.root= obj.insertRecursive(obj.root,new_node);
	      //obj.insertNode(new_node);
	      cout<<endl;
    		break;
      
    case 2:
      cout << "SEARCH" << endl;
      cout << "Enter VALUE of TREE NODE to SEARCH in BST: ";
      cin >> val;
      //new_node = obj.iterativeSearch(val);
      new_node = obj.recursiveSearch(obj.root, val);
      if (new_node != NULL) {
        cout << "Value found" << endl;
      } else {
        cout << "Value NOT found" << endl;
      }
      break;
    case 3:
      cout << "DELETE" << endl;
      cout << "Enter VALUE of TREE NODE to DELETE in BST: ";
      cin >> val;
      new_node = obj.iterativeSearch(val);
      if (new_node != NULL) {
        obj.deleteNode(obj.root, val);
        cout << "Value Deleted" << endl;
      } else {
        cout << "Value NOT found" << endl;
      }
      break;
    case 4:
      cout << "PRINT 2D: " << endl;
      obj.print2D(obj.root, 5);
      cout << endl;
      cout << "Print Level Order BFS: \n";
      obj.printLevelOrderBFS(obj.root);
      cout << endl;
      //	      cout <<"PRE-ORDER: ";
      //	      obj.printPreorder(obj.root);
      //	      cout<<endl;
      //	      cout <<"IN-ORDER: ";
      //	      obj.printInorder(obj.root);
      //	      cout<<endl;
      //	      cout <<"POST-ORDER: ";
      //	      obj.printPostorder(obj.root);
      break;
    case 5:
      cout << "TREE HEIGHT" << endl;
      cout << "Height : " << obj.height(obj.root) << endl;
      break;
    case 6:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}
*/
