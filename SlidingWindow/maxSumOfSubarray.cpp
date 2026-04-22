// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    // Write C++ code here
   int arr[7] = {2,3,4,5,6,7,8};
   
   int sum=0;
   int i=0;
   int j=0;
   int maxsum=0;
   int k=3;
   while(j<7){
       sum+=arr[j];
       if((j-i+1)<k){
           j++;
       }
       else if((j-i+1)==k){
           maxsum= max(maxsum,sum);
           sum-=arr[i];
           i++;
           j++;
       }
   }
   cout<<maxsum;

    return 0;
}