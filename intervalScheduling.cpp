struct Interval{
  int start;
  int end;
}

bool cmp(const Interval& a, const Interval& b) {
    return a.end < b.end;
}

int solve(vector<Interval>intervals){
  sort(intervals.begin(), intervals.end(),cmp);
  int cnt = 0;
  int lastEndTime = -1;
  for(auto interval:intervals){
    if(interval.start >= lastEndTime){
      cnt++;
      lastEndTime = interval.end;
    }
  }
  return cnt;
}
