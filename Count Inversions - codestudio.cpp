Problem Statement
Detailed explanation ( Input/output format, Notes, Constraints, Images )
Sample Input 1 :
3
3 2 1
Sample Output 1 :
3
Explanation Of Sample Output 1:
We have a total of 3 pairs which satisfy the condition of inversion. (3, 2), (2, 1) and (3, 1).
Sample Input 2 :
5
2 5 1 3 4
Sample Output 2 :
4
Explanation Of Sample Output 1:
We have a total of 4 pairs which satisfy the condition of inversion. (2, 1), (5, 1), (5, 3) and (5, 4).


////////////////////////////////////////////////////////////

#include <bits/stdc++.h> 
long long getInversions(long long *arr, int n){
    // Write your code here.
    if(n == 1){
        return 0 ; 
    }
    int count = 0 ; 
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i == j){
                continue ;
            }
            else if(i < j && arr[i] > arr[j]){
                count++ ; 
            }
        }
    }
    return count ; 
}
