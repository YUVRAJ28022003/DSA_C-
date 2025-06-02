#include<iostream>
using namespace std;


class trienode{
    public :
    char data;

    trienode* children[26];

    bool isterminal;// it will show the node is terminal node or not . terminal means end of node or not .


    trienode(char ch){
        data = ch;
        for(int i =0 ;i<26;i++){
            children[i] = NULL; 
        }
        isterminal = false;
    }
};

class trie{
    public:
    trienode* root;

    trie(){
        root = new trienode('\0');// null character
    }

    void insert(trienode* root,string word){
    //    base case
       if(word.length()== 0){
        root->isterminal = true;
        return ;
       }

    // assumption word will be in capital
    int index = word[0] - 'A';
    trienode* child;

    // present
    if(root ->children[index] != NULL){
        child = root->children[index];
    }else{
        // absent
        child = new trienode(word[0]);
        root->children[index] = child;
    }
    // recursion
    insert(child,word.substr(1));
    }

    void insertword(string word){
      insert(root,word);
    }
    
    bool search(trienode* root,string word){
    //   base case 
    if(word.length() == 0){
        return root->isterminal;
    }

    int index = word[0] - 'A';
    trienode* child;
    // present 
    if(root->children[index] != NULL){
        child = root->children[index];
    }else{
        // absent 
        return false;
    }
    // recursion
    return search(child, word.substr(1));
    }

    bool search(string word){
        return search(root,word);
    }

    void deletewordstring(trienode* root, string word){
        // base case
        if(word.length() == 0){
            return ;
        }

        int index = word[index] -'A';
        trienode* child ;

        // present 
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            // absent 

        }
        // recursion 
        deletewordstring(child,word.substr(1));
    }
    void deleteword(string word){
        return deletewordstring(root, word);
    }
};


int main (){
    trie *t = new trie();

    t->insertword("ABCD");
    cout<<"present or not : "<<t->search("ABCD")<<endl;
        t->deleteword("ABCD");
    cout<<"present or not : "<<t->search("ABCD")<<endl;
    t->insertword("XYZ");
    cout<<"present or not : "<<t->search("XYZQ")<<endl;
    t->insertword("KLMN");
    cout<<"present or not : "<<t->search("KLMN")<<endl;
    t->insertword("OPQR");
    cout<<"present or not : "<<t->search("OPQR")<<endl;
    
    return 0;
}