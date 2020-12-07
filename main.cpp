#include <iostream>
using namespace std;
void merge(int A[],int si,int mid,int ei){
  int temp[ei-si];
  int i=si,j=mid+1,k=0;
  while(i <= mid && j <= ei){
    if(A[i]<A[mid+1]){
      temp[k++]=A[i++];
    }else{
      temp[k++]=A[j++];
    }
  }
  while(i<= mid){
    temp[k++]=A[i++];
  }
  while(j <= ei){
    temp[k++]=A[i++];
  }
  int m=0;
  for(int l=si;l<=ei;l++){
    A[l]=temp[m++];
  }  
}

void mergeSort(int A[],int si,int ei){
  if(si>=ei){
    return;
  }
  int mid = (si+ei)/2;
  mergeSort(A,si,mid);
  mergeSort(A,mid+1,ei);
  merge(A,si,mid,ei);
}
int main() {
  int n;
  cin>>n;
  int A[n];
  for(int i=0;i<n;i++){
    cin>>A[i];
  }
  mergeSort(A,0,n-1);
  for(int i=0;i<n;i++){
    cout<<A[i]<<" ";
  }
  cout<<endl;
  return 0;
}