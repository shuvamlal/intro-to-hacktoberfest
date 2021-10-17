# include <iostream>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void waveSort(int arr[], int n){

    for(int i = 1; i < n; i += 2){

        if(arr[i] > arr[i - 1])
            swap(&arr[i], &arr[ i - 1]);

        if((arr[i] > arr[i + 1])  && (i <= n - 2))
            swap(&arr[i], &arr[i + 1]);

    }

    return;

}

int main(){

    int arr[] = {1, 3, 4, 7, 5, 6, 2};

    waveSort(arr, (sizeof(arr) / sizeof(arr[0])));

    for(auto i : arr)
        cout << i << " ";
    cout << endl;

    return 0;

}