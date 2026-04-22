// Online C++ compiler to run C++ program online
#include <iostream>
#include <list>
#include <vector>
using namespace std;
int main() {
    // Write C++ code here
    int k=3;
   int arr[8] = {-2,-3,-4,-5,6,7,8,9};
   int n=8;
   int i=0;
   int j=0;
   vector<int>ans;
   list<int>l;
   while(j<n){
       if(arr[j]<0){
          l.push_back(arr[j]);
       }
       if((j-i+1)<k){
           j++;
       }
       else if((j-i+1)==k){
           if(l.empty()){
               ans.push_back(0);
               i++;
               j++;
           }
           else{
          ans.push_back(l.front());
          if(arr[i]==l.front()){
              l.pop_front();
             
          }
           i++;
             j++;
        }
          
           
       }
       
   }
   for(int i=0;i<ans.size();i++){
           cout<<ans[i]<<" ";
       }
   
   

    return 0;
}