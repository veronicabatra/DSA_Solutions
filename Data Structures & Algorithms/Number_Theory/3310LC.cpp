// 3345 Smallest Divisible Digit Product
class Solution {
public:
    int prod(int x){
        int ans=1;
        while(x>0){
            int last=x%10;
            ans*=last;
            x/=10;
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        int ans;
        while(true){
            int curr=prod(n);
            if(curr%t==0) return n;
            n++;
        }
        return -1;
    }
}; I