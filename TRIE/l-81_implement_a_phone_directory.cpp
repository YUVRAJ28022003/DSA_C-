#include<iostream>
#include<vector>

using namespace std;


class TrieNode{
  public:
  char data;
  int count;
  bool isLeaf;
  TrieNode* children[26];
  
  
  TrieNode(char data){
      this->data = data;
      this->count =0;
      this->isLeaf = false;
      
      for(int i=0;i<26;i++)
      {
          this->children[i] = NULL;
      }
  }
 
};



   void insertNode(TrieNode* &root, string str)
    {
        if(str.length() == 0)
        {
            root->isLeaf = true;
            return;
        }
        
        int index = str[0] -'a';
        
        TrieNode * child;
        
        if(root->children[index] != NULL)
        {
          child = root->children[index];
            
        }
        else{
            // create new node
            child = new TrieNode(str[0]);
            root->count++;
            root->children[index] = child;
        }
     
        insertNode(child,str.substr(1));
    }
    
    
    void printSugesstion(TrieNode * curr,vector<string> &temp, string prefix)
    {
        if(curr->isLeaf)
        {
            temp.push_back(prefix);
        }
        
        
        for(char ch = 'a';ch <= 'z';ch++)
        {
            int index = ch-'a';
            TrieNode *next = curr->children[index];
            
            if(next!= NULL)
            {
                prefix.push_back(ch);
                printSugesstion(next,temp,prefix);
                prefix.pop_back();
            }
            
        }
    }
    
    
    vector<vector<string>> getSuggestion(TrieNode* root, string query)
    {
        string prefix = "";
        TrieNode *prev= root;
        vector<vector<string>> ans;
        
        for(int i=0;i<query.length();i++)
        {
            char lastch = query[i];
            prefix.push_back(lastch);
            
            int index = lastch - 'a';
            TrieNode* curr = prev->children[index];
            
            if(curr != NULL)
            {
                vector<string> temp;
                printSugesstion(curr,temp,prefix);
                ans.push_back(temp);
                temp.clear();
                prev = curr;
                
            }
            
            else{
                
                break;
            }
        }
        
        int remaining = query.size()-ans.size();
        for(int i=0;i<remaining;i++)
        {
            ans.push_back({"0"});
        }
        
        return ans;
    }
    
    

    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        TrieNode* root = new TrieNode('\0');
        for(int i=0;i<n;i++)
        {
            insertNode(root,contact[i]);
        }
        
        
        return getSuggestion(root,s);
        
        
    }




int main()
{
    // Contact list of the User
    string contacts[] = { "gforgeeks", "geeksquiz" };
 
    // Size of the Contact List
    int n = sizeof(contacts) / sizeof(string);
 
    string query = "gekk";
 
    // Note that the user will enter 'g' then 'e', so
    // first display all the strings with prefix as 'g'
    // and then all the strings with prefix as 'ge'
     vector<vector<string>>ans = displayContacts(n,contacts,query);

    return 0;
}