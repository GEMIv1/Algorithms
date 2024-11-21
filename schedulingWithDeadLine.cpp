struct Job{
  int sratTime;
  int deadLine;
}

void solve(vector<Job> arr, int n){
  sort(arr.begin(), arr.end(), cmp);
  vector<int> ans(n);
  vector<int> slot(n,false);
  for(int i=0;i<n;i++){
    for(int j=min(n,arr[i].deadLine)-1;j>=0;j--){
      if(!slot[j]){
        ans[j] = i;
        slot[j] = true;
        break;
      }
    }
  }
  for(int i=0;i<n;i++){
    if(slot[i]){
      cout<<arr[ans[i]]<<" ";
    }
  }
  
}
