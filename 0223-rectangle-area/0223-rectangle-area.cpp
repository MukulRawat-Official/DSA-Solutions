bool f(int a , int  b, int  c){
  return c>=a && c<=b;
}
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
       int ans = abs(ax1 - ax2) * abs(ay2 - ay1) + abs(bx1 - bx2) * abs(by2 - by1);
        
        if ((f(ax1,ax2,bx1) || f(bx1,bx2,ax1)) && (f(by1,by2,ay1)|| f(ay1,ay2,by1)))
        {
        int cx1 = max(ax1,bx1) , cx2 = min(ax2,bx2);
        int cy1 = max(ay1,by1) , cy2 = min(ay2,by2);
        ans-= abs(cx1-cx2) * abs(cy1-cy2);
        }
        return ans;
    }
};