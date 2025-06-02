// IS BINARY TREE A HEAP  ?


// Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
// Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.

// Input:
//       5
//     /  \
//    2    3

// Output: 1
// Explanation: The given tree follows max-heap property since 5,
// is root and it is greater than both its children.


int countNodes(struct Node* tree){
        if(tree == NULL){
            return 0;
        }
        
        int ans = 1+countNodes(tree->left)+ countNodes(tree->right);
        return ans;
    }
    
    bool iscbt(struct Node* tree,int i ,int cnt){
        if(tree == NULL)
         return true;
         
        if(i >= cnt)
         return false;
        else{
            bool left = iscbt(tree->left , 2*i+1 , cnt);
            bool right = iscbt(tree->right , 2*i+2 , cnt);
            return (left && right);
        }
    }
    
    bool ismaxorder(struct Node* tree){
        if(tree->left == NULL && tree->right == NULL)
          return true;
          
        if(tree->right == NULL){
            return ( tree->data > tree->left->data );
        }else{
            bool left = ismaxorder(tree->left);
            bool right = ismaxorder(tree->right);
            
            if(left && right && (tree->data > tree->left->data)  && (tree->data > tree->right->data)){
                return true;
            }
            return  false;
        }
    }
  
    bool isHeap(struct Node* tree) {
        int index = 0;
        int totalcount= countNodes(tree);
        if(iscbt(tree , index , totalcount) && ismaxorder(tree)){
            return true;
        }else{
            return false;
        }
    }