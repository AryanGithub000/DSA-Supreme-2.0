class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
        }

    int maxVowels(string s, int k) {
        int n=s.length();
        int count=0;
        
        //count first substring of k length
        for(int i=0;i<k;i++){
            if(isVowel(s[i])) count++;
        }

        int ans=count; //variable to save max counter
        for(int i=k;i<n;i++){
            if(isVowel(s[i-k])) count--; //remove the first elt.
            if(isVowel(s[i])) count++; //add curr elt in it
            ans=max(ans,count);
        }

        return ans;
    }
};
