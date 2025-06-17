class Solution {
public:
unordered_map<string ,int>map;
vector<vector<string>>ans;
string b ;
      

      void dfs(string word , vector<string>  & seq){
        if(word==b){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return ;
        }
        int steps = map[word];
        for(int i = 0 ; i<word.size(); i++){
            char original  = word[i];
            
            for(char ch = 'a' ; ch<='z'; ch++){
                word[i]=ch;
                if(map.find(word)!=map.end()&&
                    map[word]+1==steps){
                        seq.push_back(word);
                        dfs(word,seq);
                        seq.pop_back();
                }
            }
            word[i]= original;
        }
      }

















    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        b = beginWord;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        map[beginWord]=1;
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            string word = it.first;

            int steps =it.second;
            if(word==endWord){
                break;
            } 
            for(int i  =0 ; i<word.size(); i++){
                char original = word[i];
                for(char ch = 'a' ; ch<='z'; ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,steps+1});
                        map[word]=steps+1;

                    }

                }
                word[i]=original;

            }
        }
        if(map.find(endWord)!=map.end()){
            vector<string>seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
        }
        return ans;

    }
};