class MyCalendar {
public:
    
    vector<pair<int, int>> arr;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(int i = 0; i<arr.size(); i++){
            if((start>=arr[i].first && start<arr[i].second) || (end>arr[i].first && end<arr[i].second) || (start<=arr[i].first && end>=arr[i].second)) return false;
        }
        arr.emplace_back(make_pair(start, end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */