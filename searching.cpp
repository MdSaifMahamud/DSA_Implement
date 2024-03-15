#include<bits/stdc++.h>
using namespace std;
int linearSearch(int a[],int n, int key){
    for(int i=0;i<n;i++){
        if(a[i]==key){
            return i;
        }
    }
    return -1;
}
int binSrc(int a[],int n,int key){
    int high=n-1;
    int low=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==key){
            return mid;
        }else if(a[mid]>key){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return -1;
}
int recursiveBinSrc(int a[],int low,int high,int key){
    if(abs(low-high)==1){
        if(a[low]==key){
            return low;
        }
        if(a[high]==key){
            return high;
        }
        return -1;
    }
    int mid=(low+high)/2;
    if(a[mid]==key){
        return mid;
    }else if(a[mid]>key){
        recursiveBinSrc(a,low,mid,key);
    }else{
        recursiveBinSrc(a,mid,high,key);
    }
}
int firstOccurance(int a[],int n,int key){
    int low=0,high=n-1,ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==key){
            ans=mid;
            high=mid-1;
        }else if(a[mid]>key){
            high=mid-1;
        }else{
            low=low+1;
        }
    }
    return ans;
}
int lastOccurance(int a[],int n,int key){
    int high=n-1,low=0,ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==key){
            ans=mid;
            low=mid+1;
        }else if(a[mid]>key){
            high=mid-1;
        }else{
            low=low+1;
        }
    }
    return ans;
}
int main()
{
    int n,k;
    cin >> n >> k;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    // cout<<linearSearch(a,n,k)<<endl;
    // cout<<binSrc(a,n,k)<<endl;
    // cout<<recursiveBinSrc(a,0,n-1,k)<<endl;
    // cout<<firstOccurance(a,n,k)<<endl;
    // cout<<lastOccurance(a,n,k)<<endl;
    return 0;
}