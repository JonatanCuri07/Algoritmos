#include <iostream>
using namespace std;

template <typename T>
T divide(T array[], int start, int end) {
    int left;
    int right;
    T pivot;
    T temp;

    pivot = array[start];
    left = start;
    right = end;

    while (left < right) {
        while (array[right] > pivot) {
            right--;
        }

        while ((left < right) && (array[left] <= pivot)) {
            left++;
        }

        if (left < right) {
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }
    }

    temp = array[right];
    array[right] = array[start];
    array[start] = temp;

    return right;
}

template <typename T>
void quicksort(T arr[], int start, int end)
{
    T temp;

    if (start < end) {
        temp = divide(arr, start, end);

        quicksort(arr, start, temp - 1);

        quicksort(arr, temp + 1, end);

    }
}

template <typename T>
void show(T baraja[],int t)
{
    for (int i = 0; i < t; i++)
    {
        cout<<baraja[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int baraja[] = {10,4,12,6,23,13,2,5};
    int t = sizeof(baraja)/sizeof(int);
    show(baraja,t);
    quicksort(baraja,0,t-1);
    show(baraja,t);
    

}