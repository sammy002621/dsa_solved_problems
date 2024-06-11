#include<iostream>
#include<vector>
using namespace std;

// brute force solution

vector<int> peakElements(vector<int> nums,int n){
    vector<int> v1;

    for(int i=0;i<n;i++){
        if(i==0){
            for(int j=i+1;j<n;j++){
                if(nums[i]>nums[j]){
                    if(j==n-1){
                        v1.emplace_back(nums[i]);
                    }else{
                        continue;
                    }
                }else{
                    break;
                }
            }
        }

        
        if(i>=1&&i<=n-2){
            bool flag=true;
            //the left side loop
            for(int k=0;k<i;k++){
                if(nums[i]>nums[k]){
                    continue;
                }else{
                    flag=false;
                    break;
                }
            }


            for(int z=i+1;z<n;z++){
                if(nums[i]>nums[z]){
                     continue;
                }else{
                    flag=false;
                    break;
                }
            }
             if(flag){
       v1.emplace_back(nums[i]);
             }
            
        }


        if(i==n-1){
            for(int j=n-2;j>=0;j--){
                if(nums[i]>nums[j]){
                    if(j==0){
                        v1.emplace_back(nums[i]);
                    }else{
                        continue;
                    }
                }else{
                    break;
                }
            }
        }




        
    }

    return v1;
}


int peakElement2(vector<int>nums,int n){
    int left,right,mid;
    left=0;
    right=n-1;

    while(left<=right){
  mid=left+(right-left)/2;
 if((mid==0 || nums[mid]>nums[mid-1])&&(nums[mid]>nums[mid+1]||mid==n-1)){
   return mid;
 }

 if(mid>0&&nums[mid]<nums[mid+1]&&nums[mid]>nums[mid-1]){
 left=mid+1;
 }

 if(mid>0&&nums[mid]>nums[mid+1]&&nums[mid]<nums[mid-1]){
    right=mid-1;
 }

    }

    return -1;



}


int main(){

    vector<int> numbers={1,2,3,8};
    int peakNumber=peakElement2(numbers,numbers.size());
    // int n=peakNumbers.size();

    cout<<" the peak element that was found is : "<<peakNumber;


    return 0;

}