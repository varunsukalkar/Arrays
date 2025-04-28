class MyCalendarTwo {
     private: map<int,int>map1; 
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
         map1[start] ++;
        map1[end]--;
          int sum =0;
        for(auto it = map1.begin(); it!=map1.end();it++){
            sum+=it->second;
            if(sum>2){
                map1[start]--;
                map1[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */