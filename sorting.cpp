#include<bits/stdc++.h>
using namespace std;
void print(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int max_element(int a[],int n){
    int mx=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>mx){
            mx=a[i];
        }
    }
    return mx;
}
void copy(int a[],int b[],int low,int high){
    for(int i=low,j=0;i<=high;i++,j++){
        a[i]=b[j];
    }
    return ;
}
void sort(int a[],int low,int mid,int high){
    int cur1=low,cur2=mid+1;
    int b[high-low+1];
    int i=0;
    while(cur1<=mid &&  cur2<=high){
        if(a[cur1]==a[cur2]){
            b[i++]=a[cur1++];
        }else if(a[cur1]<a[cur2]){
            b[i++]=a[cur1++];
        }else{
            b[i++]=a[cur2++];
        }
    }
    while(cur1<=mid){
        b[i++]=a[cur1++];
    }
    while(cur2<=high){
        b[i++]=a[cur2++];
    }
    copy(a,b,low,high);
}
void sortSingleRadix(int a[],int n,int exp){
    int cnt[10]={0};
    int out[n];
    for(int i=0;i<n;i++){
        cnt[(a[i]/exp)%10]++;
    }
    for(int i=1;i<10;i++){
        cnt[i]=cnt[i-1]+cnt[i];
    }
    for(int i=n-1;i>=0;i--){
        out[(cnt[(a[i]/exp)%10])-1] = a[i];
        cnt[(a[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++){
        a[i]=out[i];
    }
}
/*Sorting Function*/
void bouble_sort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
}
void insertion_sort(int a[],int n){
    for(int i=1;i<n;i++){
        int key=a[i],j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
void selection_sort(int a[],int n){
    for(int i=0;i+1<n;i++){
        int key=a[i],idx=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<key){
                idx=j;
                key=a[j];
            }
        }
        if(idx!=i){
            swap(a[i],a[idx]);
        }
    }
}
void counting_sort(int a[],int n){
    int k=max_element(a,n);
    int b[k+1]={0},c[n];
    for(int i=0;i<n;i++){
        b[a[i]]++;
    }
    for(int i=1;i<=k;i++){
        b[i]=b[i-1]+b[i];
    }
    for(int i=n-1;i>=0;i--){
        b[a[i]]--;
        c[b[a[i]]]=a[i];
    }
    for(int i=0;i<n;i++){
        a[i]=c[i];
    }
}
void mer_sort(int a[],int n,int low,int high){
    if(low==high){
        return ;
    }
    int mid=(low+high)/2;
    mer_sort(a,n,low,mid);
    mer_sort(a,n,mid+1,high);
    sort(a,low,mid,high);
}
void merge_sort(int a[],int n){
    mer_sort(a,n,0,n-1);
}
void radix_sort(int a[],int n){
    int mx=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>mx){
            mx=a[i];
        }
    }
    for(int i=1;mx/i>0;i*=10){
        sortSingleRadix(a,n,i);
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    // merge_sort(a,n);
    // bouble_sort(a,n);
    // insertion_sort(a,n);
    // selection_sort(a,n);
    // counting_sort(a,n);
    radix_sort(a,n);
    print(a,n);
    return 0;
}