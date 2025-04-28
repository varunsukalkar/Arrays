class MyCalendar {
    private: map<int,int>map1; 
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        map1[start] ++;
        map1[end]--;
        int sum =0;
        for(auto it = map1.begin(); it!=map1.end();it++){
            sum+=it->second;
            if(sum>1){
                map1[start]--;
                map1[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */