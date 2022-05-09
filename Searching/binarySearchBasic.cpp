#incluude<bits/stdc++.h>
using namespace std;

// Binary search for non-decreasing array

int binarySearch(int arr[], int lo, int hi, int key) {
    
    while(lo<=hi) {

        int mid = lo + (hi - lo)/2;

        if(arr[mid]==key) {
            return mid;
        }
        else if(arr[mid]<key) {
            lo = mid+1;
        }
        else {
            hi = mid-1;
        }
    }

    return -1;
}

int binarySearchRecursion(int arr[], int lo, int hi, int key) {
    if(lo>hi) {
        return -1;
    }

    int mid = lo + (hi-lo)/2;

    if(arr[mid]==key) {
        return mid;
    }

    else if(arr[mid]<key) {
        return binarySearchRecursion(arr, mid+1, hi, key);
    }

    else {
        return binarySearchRecursion(arr, lo, mid-1, key);
    }
}

// when the array is non-increasing order

int binarySearch2(int arr[], int lo, int hi, int key) {

    while(lo<=hi) {
        int mid = lo + (hi-lo)/2;
        if(arr[mid]==key) {
            return mid;
        }
        else if(arr[mid]>key) {
            lo = mid+1;
        }
        else {
            hi = mid-1;
        }
    }

    return mid;
}

int binarySearch2Recursion(int arr[], int lo, int hi, int key) {
    if(lo>hi) {
        return -1;
    }
    int mid = lo + (hi-lo)/2;

    if(arr[mid]==key) {
        return mid;
    }

    else if(arr[mid]>key) {
        return binarySearch2Recursion(arr, mid+1, hi, key);
    }

    else {
        return binarySearch2Recursion(arr, lo, mid-1, key);
    }
}

// non-decreasing array

int lowerBound(int arr[], int lo, int hi, int key) {
    
}

int main() {

}