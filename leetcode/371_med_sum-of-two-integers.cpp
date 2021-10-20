class Solution {
public:
    int getSum(int a, int b) {
        int xoor;
        int carry ;
        while(b){
            xoor = a^b;
            carry =(uint32_t) (a & b)<< 1;
            a = xoor;
            b= carry;
        }
    return a;
        
    }
};