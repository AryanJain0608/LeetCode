class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long lcm = (long long)divisor1 / 
                        gcd(divisor1, divisor2) * divisor2;

        long long low = 1, high = 1e10;

        while (low < high) {

            long long mid = low + (high - low) / 2;

            long long a = mid - mid / divisor1;
            long long b = mid - mid / divisor2;
            long long c = mid - mid / lcm;

            if (a >= uniqueCnt1 &&
                b >= uniqueCnt2 &&
                c >= (long long)uniqueCnt1 + uniqueCnt2) {

                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return (int)low;
    }
};