// Using Merge Sort
class Solution {
public:
    void merge(vector<int> &arr,int s, int mid, int e){
        int n1 = mid-s+1; // calculating length of left subarray
        int n2 = e - mid;

        int leftArr[n1];
        int rightArr[n2];
        int i = 0, j  = 0;
        for( i = 0; i<n1; i++){
            leftArr[i] = arr[s+i];
        }
        for( j = 0; j<n2; j++){
            rightArr[j] = arr[mid+1+j];
        }
        i = 0, j= 0;

        int p = s;
        while(i<n1 && j<n2){
            if(leftArr[i] < rightArr[j]){
                arr[p++] = leftArr[i++];
            }
            else{
                arr[p++] = rightArr[j++];
            }
        }
        while(i<n1){
            arr[p++] = leftArr[i++];
        }
        while(j<n2){
            arr[p++] = rightArr[j++];
        }
    }
    void mergeSort(vector<int>&arr, int st, int end){
        int mid = st + (end-st)/2;

        if(st<end){
            mergeSort(arr,st,mid);
            mergeSort(arr,mid+1,end);
            merge(arr,st,mid,end);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int st = 0; 
        int end = nums.size()-1;
        mergeSort(nums,st,end);
        return nums;
    }
};

// 2nd Approach

// Using Heap Sort

class Solution {
public:
    void maxHeapify(vector<int>& nums, int n, int i){
        int largest = i;
        int left = (2 * i) + 1, right = (2 * i) + 2;
        if(left < n && nums[left] > nums[largest])
            largest = left;
        if(right < n && nums[right] > nums[largest])
            largest = right;
        if(largest != i){
            swap(nums[largest], nums[i]);
            maxHeapify(nums, n, largest);
        }
    }

    void heapSort(vector<int>& nums, int n){
        for(int i = n/2-1; i >= 0; i--)
            maxHeapify(nums, n, i);
        for(int i = n-1; i >= 0; i--){
            swap(nums[0], nums[i]);
            maxHeapify(nums, i, 0);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums, nums.size());
        return nums;
    }
};