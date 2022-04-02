#include "assignment/binary_search_tree.hpp"

namespace assignment {

  BinarySearchTree::~BinarySearchTree() {
    BinarySearchTree::Clear();
  }

  void BinarySearchTree::Insert(int key, int value) {
    if (root_!=nullptr){
      insert(key,value,root_);
    } else {
      root_= new Node(key,value);
    }
  }

  bool BinarySearchTree::Remove(int key) {
    if(root_!=nullptr){
      return remove(key,root_);
    }
    return false;
  }

  void BinarySearchTree::Clear() {
    if(root_!= nullptr) {
      clear(root_);
      root_= nullptr;
    }
  }

  std::optional<int> BinarySearchTree::Find(int key) const {
Node* node = find(key,root_);
if(node != nullptr){
  return node->value;
}
return std::nullopt;
  }

  bool BinarySearchTree::Contains(int key) const {
    return find(key,root_) != nullptr;
  }

  bool BinarySearchTree::IsEmpty() const {
    if(root_== nullptr){
      return true;
    }
    return false;
  }

  std::optional<int> BinarySearchTree::FindMin() const {
    if (root_!= nullptr){
      return find_min(root_)->key;
    }
    return std::nullopt;
  }

  std::optional<int> BinarySearchTree::FindMax() const {
    if(root_!= nullptr){
      return find_max(root_)->key;
    }
    return std::nullopt;

  }

  Node* BinarySearchTree::root() const {
    return root_;
  }

  // вспомогательные методы

  void BinarySearchTree::insert(int key, int value, Node*& node) {
    if (node== nullptr){
      node= new Node(key,value);
      node->left= nullptr;
      node->right= nullptr;
    }else {
      if (key < node->key) {
        insert(key, value, node->left);
      }
      if (key == node->key) {
        node->value = value;
      }
      if (key > node->key) {
        insert(key, value, node->right);
      }
    }
  }

  bool BinarySearchTree::remove(int key, Node*& node) {
    if(key<node->key){
      return remove(key,node->left);
    }
    if(key==node->key){
      if(node->left== nullptr && node->right== nullptr){
        node= nullptr;
        return true;
      } if(node->left!= nullptr && node->right== nullptr){
        node=node->left;
        node->left= nullptr;
        return true;
      }if(node->left== nullptr && node->right!= nullptr){
        node=node->right;
        node->right= nullptr;
        return true;
      }if(node->left!= nullptr && node->right!= nullptr){
        Node* newNode = find_min((node->right));
        int key = newNode->key;
        int value = newNode->value;
        remove(newNode->key,root_);
        node->key=key;
        node->value=value;
        return true;
      }
    }
    if(key>node->key){
      return remove(key,node->right);
    }
    if (node== nullptr){
      return false;
    }
  }

  void BinarySearchTree::clear(Node* node) {
    if(node== nullptr){
      return;
    }
    clear(node->left);
    clear(node->right);
    delete node;
  }

  Node* BinarySearchTree::find(int key, Node* node) const {
    if(node== nullptr){
      return nullptr;
    }
      if (key < node->key) {
        return find(key, node->left);
      }
      if (key > node->key) {
        return find(key, node->right);
      }

    return node;
  }

  Node* BinarySearchTree::find_min(Node* node) const {
    if(node->left== nullptr){
      return node;
    }
    if(node== nullptr) {
      return nullptr;
    }
    return find_min(node->left);
  }

  Node* BinarySearchTree::find_max(Node* node) const {
    if(node->right== nullptr){
      return node;
    }
    if(node== nullptr) {
      return nullptr;
    }
    return find_max(node->right);
  }

}  // namespace assignment