#include <bits/stdc++.h>

#define f first
#define s second
#define sz size
#define pb push_back
#define mp make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define SQ(a) (a)*(a)
#define INF 1000000000
#define endl '\n'

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

class Node {
  public:
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
    int getValue();
    void setValue(int v);
    void setLeft(Node* n);
    Node* getLeft();
    void setRight(Node* n);
    Node* getRight();

  private:
    int data;
    Node* left;
    Node* right;
};

void Node::setValue(int v){
  data = v;
}

int Node::getValue(){
  return data;
}

void Node::setRight(Node* n){
  right = n;
}

Node* Node::getRight(){
  return right;
}

void Node::setLeft(Node* n){
  left = n;
}

Node* Node::getLeft(){
  return left;
}


class BSTree{
  public:
    BSTree(){
      root = NULL;
    }
    void insert(int value);
    void preorderPrint();
    void inorderPrint();
    void postorderPrint();
    void destroy();
  private:
    Node* root;
    void insert(Node* root, int value);
    void preorderPrint(Node* root);
    void inorderPrint(Node* root);
    void postorderPrint(Node* root);
    void destroy(Node* root);
    Node* getRoot();
    void setRoot(Node* newRoot);
};

void BSTree::insert(int value){
  insert(root, value);
}

void BSTree::insert(Node* root, int value){
  Node* newNode = new Node(value);
  if(this->getRoot() == NULL){
    this->setRoot(newNode);
  }else{
    Node* current = root;
    Node* prev = NULL;
    while(current != NULL){
      prev = current;
      if(value == current->getValue()){
        delete newNode;
        return;
      }
      if(value > current->getValue()){
        current = current->getRight();
      }else{
        current = current->getLeft();
      }
    }

    if(value > prev->getValue()){
      prev->setRight(newNode);
    }else{
      prev->setLeft(newNode);
    }
  }
}

void BSTree::preorderPrint(){
  cout << "Pre.:";
  preorderPrint(root);
  cout << endl;
}

void BSTree::preorderPrint(Node* root){
  if(root == NULL) return;
  cout << " " << root->getValue();
  preorderPrint(root->getLeft());
  preorderPrint(root->getRight());
}


void BSTree::inorderPrint(){
  cout << "In..:";
  inorderPrint(root);
  cout << endl;
}

void BSTree::inorderPrint(Node* root){
  if(root == NULL) return;
  inorderPrint(root->getLeft());
  cout << " " << root->getValue();
  inorderPrint(root->getRight());
}

void BSTree::postorderPrint(){
  cout << "Post:";
  postorderPrint(root);
  cout << endl;
}

void BSTree::postorderPrint(Node* root){
  if(root == NULL) return;
  postorderPrint(root->getLeft());
  postorderPrint(root->getRight());
  cout << " " << root->getValue();
}


Node* BSTree::getRoot(){
  return root;
}
void BSTree::setRoot(Node* newRoot){
  root = newRoot;
}

void BSTree::destroy(Node* root){
  if(root != NULL){
    destroy(root->getLeft());
    destroy(root->getRight());
    delete root;
  }
}

void BSTree::destroy(){
  destroy(root);
  root = NULL;
}


int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(0);
  BSTree tree = BSTree();
  int n, tmp, aux;
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> tmp;
    for(int j = 0; j < tmp; j++){
      cin >> aux;
      tree.insert(aux);
    }
    cout << "Case " << i << ":" << endl;
    tree.preorderPrint();
    tree.inorderPrint();
    tree.postorderPrint();
    tree.destroy();
    cout << endl;
  }
  return 0;
}
