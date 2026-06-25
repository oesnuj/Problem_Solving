class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourAngle = minutes * 0.5 +  hour * 30;
        double minuteAngle = minutes * 6;
        double result = abs(hourAngle - minuteAngle);
        return min(result, 360 - result);
    }
};