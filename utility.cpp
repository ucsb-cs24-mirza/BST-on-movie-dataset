#include "utility.h"
using namespace std;

double min(double arr[], int size){
    double min= arr[0];
    for(int i=0;i<size;i++){
        if (arr[i]<min){
            min=arr[i];
        }
    }
    return min;
}

double max(double arr[], int size){
    double max= arr[0];
    for(int i=0;i<size;i++){
        if (arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

double median(double arr[], int size){
    int mid = size/2;
    if (size%2==0){
        return (arr[mid]+arr[mid+1])/2;
    }else{
        return arr[mid];
    }
}


