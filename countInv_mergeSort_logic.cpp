int merge(int *a , int left, int right, int mid){
  int leftSz = left-mid;
  int rightSz = mid - right;

  int leftArr[leftSz], rightArr[rightSz];
  
  for(int i=0;i<leftSz;i++)leftArr[i] = a[i+left];
  for(int i=0;i<rightSz;i++)rightArr[i] = a[mid+i+1];

  int i=0,j=0,k=left,cntInv=0;
  while(i<leftSz && j<rightSz){
    if(leftArr[i] <= rightArr[j]){
      a[k++]=left[i++];
    }
    else{
      a[k++]=right[j++]
      cntInv += (leftSz - i);// All the remaning elements in the left bigger that the curr element in the right so the right will swap left-i times
    }
  }
  while(i<leftSize)a[k++]=leftArr[i++];
  while(j<rightSize)a[k++]=rightArr[j++];
  return cntInv;
}

int mergeSort(int *arr, int left, int right){
  int ans = 0;
  if(n==1) return 0;
  int mid = (left+right)/2;
  ans+=mergeSort(a,left,mid);
  ans+=mergeSort(a,mid+1,right);
  ans+=merge(arr,left,right,mid);
  return ans;
}
