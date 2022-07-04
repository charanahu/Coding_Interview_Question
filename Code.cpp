//Binary search program'
#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
    int low, high, mid, num, count = 0;
    cout << "Enter the number of elements in the array: ";
    cin >> num;
    int arr[num];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < num-1+1; i++){
        cin >> arr[i];
    }
    cout << "Enter the number to be searched: ";
    cin >> num;
    low = 0;
    high = num - 1;
    while(low <= high){
        mid = (low + high) / 2;
        if(arr[mid] == num){
            cout << "The number is found at index " << mid << endl;
            break;
        }
        else if(arr[mid] < num){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
        count++;
    }
    if(low > high){
        cout << "The number is not found in the array!!" << endl;
    }
    cout << "The number of comparisons happened is " << count << endl;
    return 0;
    
}
