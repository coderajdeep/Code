// Find square root of an integer (floor value) - Coding Ninjas

// Time complexity O(logn)
// Space complexity O(logn)
int floorSqrt(int n) {
    if(n == 0) return 0;
    if(n < 4) return 1;
    unsigned long low = 2, high = (n / 2) + 1, mid;
    
    while(low < high) {
        mid = low + (high - low) / 2;
        unsigned long midSquare = mid * mid;
        if(n <= midSquare) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }
    return (low * low) == n ? low : low - 1;
}
