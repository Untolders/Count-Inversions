########################################################################################################  Question  ####################################################################################################################


Given an array of integers arr[]. Find the Inversion Count in the array.
Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum. 

Examples:

Input: arr[] = [2, 4, 1, 3, 5]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
Input: arr[] = [2, 3, 4, 5, 6]
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.
Input: arr[] = [10, 10, 10]
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104


########################################################################################################  Solution  ####################################################################################################################
  //{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count inversions in the array.
    void merge(int s , int p , int j , vector<int>&arr , int&ans){
        vector<int>arr1 ;
        vector<int>arr2 ; 
        
        for(int i = s ; i < p ; i ++) arr1.push_back(arr[i]) ;
        for(int i = p ; i <= j ; i ++) arr2.push_back(arr[i]) ;
        
        int n = arr1.size() ;
        int m = arr2.size() ;
        int i = 0 ; 
        j = 0 ; 
        
        while(i < n && j < m){
            if(arr2[j] < arr1[i]){ ans += (n - i) ; arr[s++] = arr2[j++] ; }
            else arr[s++] = arr1[i++] ;
        }
        while(i < n){
            arr[s++] = arr1[i++] ; 
        }
        while(j < m){
            arr[s++] = arr2[j++] ; 
        }
        
    }
    
    void mergeSort(int i , int j , int&ans , vector<int>&arr){
       if(i >= j) return ;
       int p = (i + j)/ 2 ;
       mergeSort(i , p , ans , arr) ;
       mergeSort(p + 1 , j , ans , arr) ;
       merge(i , p + 1 , j , arr , ans) ;
    }
    
    int inversionCount(vector<int> &arr) {
        int n = arr.size() ;
        int ans = 0 ;
        mergeSort(0 , n - 1 , ans , arr) ;
        return ans ;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
