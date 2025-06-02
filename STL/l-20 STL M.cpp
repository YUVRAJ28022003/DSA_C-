#include <iostream>
#include <map>
using namespace std;

int main() 
{
  map <int,string> m;
  m[1] = "i ";
  m[2] = "love ";
  m[3] = "you ";
  m[10] = "yuvraj ";
  m[13] = "roy ";
    for(auto i :m)
     cout<<i.first<<" " <<i.second<<endl;
    cout<<endl;
    m.erase(13);
    for(auto i :m)
     cout<<i.first<<" " <<i.second<<endl;
     
    return 0;
}

