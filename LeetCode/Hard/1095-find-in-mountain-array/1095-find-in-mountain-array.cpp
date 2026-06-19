/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        
        int peak = findPeak(mountainArr, n);
        
        int leftResult = searchAscending(mountainArr, 0, peak, target);
        if (leftResult != -1) {
            return leftResult;  
        }
        return searchDescending(mountainArr, peak + 1, n - 1, target);
    }
    
private:
    int findPeak(MountainArray &arr, int n) {
        int left = 0;
        int right = n - 2;

        while(left < right){
            int mid = (left + right)/2;
            if(arr.get(mid) > arr.get(mid+1)) {
                right = mid;  
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
    
    int searchAscending(MountainArray &arr, int left, int right, int target) {
        while(left <= right){
            int mid = (left + right) / 2;
            if(arr.get(mid) < target){
                left = mid + 1;
            }
            else if(arr.get(mid) > target){
                right = mid - 1;
            }
            else{
                return mid; 
            }
        }
        return -1;
    }
    
    int searchDescending(MountainArray &arr, int left, int right, int target) {
        while(left <= right){
            int mid = (left + right) / 2;
            if(arr.get(mid) < target) {
                right = mid - 1;
            }
            else if(arr.get(mid) > target) {
                left = mid + 1;
            }
            else{
                return mid; 
            }
        }
        return -1;
    }
};