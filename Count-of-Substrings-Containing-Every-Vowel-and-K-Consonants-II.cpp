class Solution {
public:
   long long c(string word, int k ){
    long long int cnt = 0;
    int j = 0;
    int i = 0;
    map<char,int>m;
    int cont=0;
    while(j<word.size()){
        if(word[j]=='a' || word[j]=='e' || word[j]=='i'|| word[j]=='o'|| word[j]=='u'){
          m[word[j]]++;
        
    }
    else{
        cont++;
    }
    while(m.size()==5 && cont>=k){
        cnt+=word.size()-j;
        if(m.find(word[i])!=m.end()){
            m[word[i]]--;
            if(m[word[i]]==0){
                m.erase(word[i]);
            }

        }
        else{
            cont--;
        }
        i++;

    }
    j++;
   }
return cnt;
   }
    long long countOfSubstrings(string word, int k) {
      return c(word,k)-c(word,k+1);
    }
};