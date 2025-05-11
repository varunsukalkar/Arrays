class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        typedef pair<int,int> p ;
        vector<int>vec(n); // next smallest to right;
        vector<int>vec2(n); // next smallest to left
        stack<p>s;
        for(int i = n-1 ; i>=0; i--){
              if(s.size()==0){
                vec[i]=n;
              }
              else if(s.size()>0 && s.top().first<heights[i]){
                vec[i]=s.top().second;
              }
              else if(s.size()> 0 && s.top().first>=heights[i]){
                while(s.size()>0 && s.top().first>=heights[i]){
                    s.pop();
                }
                if(s.size()==0){
                    vec[i]=n;

                }
                else{
                    vec[i]=s.top().second;
                }
              }
            s.push({heights[i],i});

        }
       // reverse(vec.begin(),vec.end());
        stack<p>s1;
        for(int i = 0 ; i<n; i++ ){
            if(s1.size()==0){
                vec2[i]=-1;

            }
            else if(s1.size()>0 && s1.top().first<heights[i]){
                 vec2[i]=s1.top().second;
            }
           else if(s1.size()>0 && s1.top().first>=heights[i]){
            while(s1.size()>0 && s1.top().first>=heights[i]){
                s1.pop();
            }
            if(s1.size() ==0){
                vec2[i]=-1;
            }
            else{
                vec2[i]=s1.top().second;
            }
            
            
            
            
            
                      }

          s1.push({heights[i],i});
        }
        
       heights.push_back(0);

           vector<int>width(n);
           for(int i = 0 ; i< n; i++){
            width[i]= vec[i]-vec2[i]-1;
           }

           int maxrec = 0;

           for(int i = 0 ;i< n; i++){
            maxrec=max(maxrec,width[i]* heights[i]);
           }

            return maxrec;
    }
};