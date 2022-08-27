// binary search
class Solution {
public:
    int mySqrt(int x) {
        double left = 0;
        double right = x;
        double center = 0;
        while(true){
            center = (right-left)/2+left;
            if(center*center==x)
                break;
            else if(center*center>x) right = center;
            else left = center;
            if(floor(right)==floor(left))
                return floor(right);
        }
        return center;
    }
};

// newton method
class Solution {
public:
    int mySqrt(int x) {
        if(x<2) return x;
        double xk = x, delta=x;
        while(abs(delta)>=1){
            delta = 0.5*(xk-x/xk);
            xk -= delta;
        }
        return xk;
    }
};