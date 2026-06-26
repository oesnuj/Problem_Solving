class Solution {
public:
    double angleClock(int hour, int minutes) {
        // 시간당 30° + 분당 0.5°
        double hourAngle = (hour % 12) * 30 + minutes * 0.5;
         // 분당 6°
        double minuteAngle = minutes * 6;
        double diff = fabs(hourAngle - minuteAngle);
        return min(diff, 360 - diff);
    }
};