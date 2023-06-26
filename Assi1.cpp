#include<iostream>
#include<queue>
using namespace std;
class node{
public:
int data;
node* left;
node* right;
node(int data){
this->data=data;
this->left=NULL;
this->right=NULL;
}
};
node* buildTree(node* root){
int data;

cout<<"Enter the value"<<" ";
cin>>data;
root=new node(data);
if(data==-1){
return NULL;
}
cout<<"enter the value for the left node of "<< data <<endl;
root->left = buildTree(root->left);
cout<<"enter the value for the right node of "<< data <<endl;
root->right = buildTree(root->right);
return root;
}
void levelOredertravarsal(node* root){
queue<node*>q;
q.push(root);
q.push(NULL);
while(!q.empty()){
// node* temp= q.front;
node* temp= q.fornt;
if(temp==NULL){
cout<<endl;
if(!q.empty()){
q.push(NULL);
}
}
else{
cout<<temp->data<<" ";
if(temp->left){
q.push(temp->left);
}
if(temp->right){
q.push(temp->right);
}
}
}

}
void inorder(node* root){
if(root==NULL){
return;
}
inorder(root->left);
cout<<root->data<<" ";
inorder(root->right);
}
void preorder(node* root){
if(root==NULL){
return;
}
cout<<root->data<<" ";
preorder(root->left);
preorder(root->right);
}
void postorder(node* root){
if(root==NULL){
return;
}
postorder(root->left);
postorder(root->right);
cout<<root->data<<" ";
}
int main(){
node* root=NULL;
root=buildTree(root);
int n=0;
while(n<5){
int option;
cout<<endl;
cout<<endl;
cout<<"Which travasal method want to apply ??: "<<endl;
cout<<" 1.leval order travarasal"<<endl;
cout<<" 2.Inorder travarsal"<<endl;
cout<<" 3.Preorder travarsal"<<endl;
cout<<" 4.postorder travarsal"<<endl;

cin>>option;
switch (option)
{
case 1:
levelOredertravarsal( root);
break;
case 2:
cout<<"The Inorder travarsal is : "<<endl;
inorder(root);
break;
case 3:
cout<<"The preorder travarsal is : "<<endl;
preorder(root);
break;
case 4:
cout<<"The postorder travarsal is : "<<endl;
postorder(root);
break;
}}
return 0;
}