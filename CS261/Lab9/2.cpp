#include <bits/stdc++.h>
using namespace std;
class FindMissingNumber {
    public:
        static int findMissing(int arr[], int n) {
            int sum=accumulate(arr,arr+n,0);
            int missing=(n*(n+1)/2)-sum;
            return missing;
    }
};
int main(){
   int arr[]={0,1,2,4,5};
   int n=arr.size();
   FindMissingNumber f;
   cout<<"Missing number= "<<f.findMissing(arr,n)<<endl;
}