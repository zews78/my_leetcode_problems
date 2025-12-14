class Solution {
public:
    string reverseWords(string s) {
    int n=s.size();
    reverse(s.begin(), s.end());
    int i=0;
    int j=0;
    int curr =0;
    while(j<n){
        if(s[curr]==' '){
            curr++; j++;
        }else{
            while(j<n && s[j]!=' '){
                j++;
            }

            int word_len = j-curr;
            reverse_word(s, curr, j-1);
            cout<<i<<curr<<j<<endl;
            while(word_len){
                s[i]=s[curr];
                if(i!=curr) s[curr]=' ';
                i++; curr++;
                word_len--;
            }
            s[i]=' ';
            i++;

            curr= i;
            j=i;
        }


    }

    s.resize(i-1);

    return s;
    }


    void reverse_word(string &s, int st, int end){
        while(st<end){
            swap(s[st], s[end]);
            st++; end--;
        }
    }
};



