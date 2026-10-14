class Solution {
public:
    string maxSumOfSquares(int n, int sum) {
        if(sum>n*9) return "";
        if(n==1) return to_string(sum);

        int nine=sum/9;
        int rem=sum%9;

        string num="";
        for(int i=1;i<=nine;i++){
            num+="9";
        }
        if(num.size()<n){
             string add=to_string(rem);
             num+=add;
        }
        
        int more=n-nine-1;

        for(int i=1;i<=more;i++) num+="0";
        return num;

    }
};