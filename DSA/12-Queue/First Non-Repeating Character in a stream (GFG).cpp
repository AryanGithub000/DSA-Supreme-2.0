//First non-repeating character in a stream
//GFG

class Solution {
	public:
		string FirstNonRepeating(string A){
		   string answer;
		   queue<char> q;
		   int freq[26]={0};
		   
		   for(int i=0;i<A.length();i++){
		       char ch=A[i];
		       freq[ch-'a']++; //mapping of each index to get freq
		       
		       q.push(ch);
		       
		       
		       //answer find out
		       while(!q.empty()){
		           char frontChar=q.front();
		           if(freq[frontChar-'a']>1){
		               //not answer
		               q.pop();
		           }
		           else{
		               //answer hai as =1 wala case
		               //yahi answer hai 
		               answer.push_back(frontChar);
		               break;
		           }
		       }
		       
		       if(q.empty()){
		           //no answer 
		           answer.push_back('#');
		       }
		   }
		   return answer;
		   
		}

};