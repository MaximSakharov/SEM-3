#include <iostream>

using namespace std;

class BinTree
{
private:
   struct Node
   {
      Node* parent;
      Node* left;
      Node* right;
      int data;

      Node() : parent(nullptr), left(nullptr), right(nullptr)
      { }

      Node(int value) : parent(nullptr), left(nullptr), right(nullptr), data(value)
      { }

   };
   Node* root;

   Node* CopySubTree(Node* root_)
   {
      if (root_ == nullptr)
         return nullptr;

      Node* newNode = new Node(root_->data);

      newNode->left = CopySubTree(root_->left);
      newNode->right = CopySubTree(root_->right);

      if (newNode->left) newNode->left->parent = newNode;
      if (newNode->right) newNode->right->parent = newNode;

      return newNode;
   }
public:
   BinTree()
   {
      root = nullptr;
   }
   BinTree(int* arr_, int size)
   {
      if (size == 0)
      {
         root = nullptr;
         return;
      }
      root = new Node(arr_[0]);

      Node* prev = root;
      Node* cur;

      for (int i = 1; i < size; ++i)
      {
         cur = new Node;
         if (prev->data <= arr_[i])
         {
            cur->data = arr_[i];
            cur->parent = prev;
            /*
            cur->left = nullptr;
            cur->right = nullptr;
            */
            prev->right = cur;
            prev = prev->right;
         }
         else
         {
            cur->data = arr_[i];
            cur->parent = prev;
            /*
            cur->left = nullptr;
            cur->right = nullptr;
            */
            prev->left = cur;
            prev = prev->left;
         }
      }
      prev->left = nullptr;
      prev->right = nullptr;
   }
   Node* GetRoot()
   {
      return root;
   }
   void Clear(Node* child_)
   {
      if (child_ == nullptr)
         return;

      Clear(child_->left);
      Clear(child_->right);

      delete child_;

   }
   ~BinTree()
   {
      Clear(root);
   }
   BinTree& operator=(const BinTree& other_)
   {
      if (this == &other_)
         return *this;

      root = CopySubTree(other_.root);

      return *this;
   }
   BinTree(const BinTree& other_)
   {
      root = CopySubTree(other_.root);
   }

   void Print(Node* root_)
   {
      if (!root_)
         return;

      Print(root_->left);
      Print(root_->right);

      cout << root_->data << " ";
   }

   //friend ostream& operator<< (ostream& out, BinTree& root_);

   //friend istream& operator >> (istream& out, BinTree& root_);
};

/*
ostream& operator<< (ostream& out, BinTree& root_)
{
   out << "( ";
   if (!root_.root)
   {
      out << ")";
      return out;
   }


}
*/