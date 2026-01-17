class Solution {
  public:
  
  bool recursionFunc ( string &s, int ptr1, int ptr2) {
      
      if( ptr1 >= ptr2 ) return true;
      
     
        if ( s[ptr1] != s[ptr2] ){
          return false;
      }
        
      
      return recursionFunc ( s, ptr1+1, ptr2-1 );
  }
  
    bool isPalindrome(string& s) {
        
        int n = s.size();
        int ptr1 = 0;
        int ptr2 = n-1;
        
        return recursionFunc(s, ptr1, ptr2);
    }
};
