//
//  main.cpp
//  binarySearch
//
//  Created by Евгений Киримов on 16.08.2018.
//  Copyright © 2018 Евгений Киримов. All rights reserved.
//

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int binarySearch(vector<int> &vec, int key, int left, int right);
void quickSort(vector<int> &vec, int left, int right);

int main(int argc, const char * argv[]) {
    
    int size;
    vector<int> vec1;
    
    cout << "Enter to upper limit: ";
    cin >> size;
    
    for(int i=0; i < size; i++){
        vec1.push_back(rand()%100);
    }
    for(int i=0; i < vec1.size(); i++){
        cout << vec1[i];
        cout << " ";
    }
    cout << endl;
    
    quickSort(vec1, 0, vec1.size()-1); //using quickSort
    int searchResult = binarySearch(vec1, 12, 0, vec1.size()-1); //using binarySearch
    
    //print sorted arr
    for(int i=0; i < vec1.size(); i++){
        cout << vec1[i];
        cout << " ";
    }
    cout << endl;
    cout << "Search result: " << searchResult << endl;
    
    return 0;
}

int binarySearch(vector<int> &vec, int key, int left, int right){
    int mid = (left+right)/2;
    int midValue = vec[mid];
    
    if(left >= right)
        return -1;
    
    if(key == midValue)
        return mid;
    
    else if(key < midValue){
        return binarySearch(vec, key, left, mid);
    }
    else {
        return binarySearch(vec, key, mid+1, right);
    }
}


void quickSort(vector<int> &vec1, int left, int right){
    int i = left;
    int j = right;
    int p = vec1[(left+right)/2];
    
    while(i<=j){
        while(vec1[i]<p){
            i++;
        }
        
        while(vec1[j]>p){
            j--;
        }
        
        if(i<=j){
            int temp = vec1[i];
            vec1[i] = vec1[j];
            vec1[j] = temp;
            i++;
            j--;
        }
    }
    if(j>left) quickSort(vec1, left, j);
    if(i<right) quickSort(vec1, i, right);
}

