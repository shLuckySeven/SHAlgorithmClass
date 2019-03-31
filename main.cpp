//
//  main.cpp
//  AlgorithmDemo
//
//  Created by shuhuan on 2019/3/30.
//  Copyright © 2019年 gsh. All rights reserved.
//

#include <iostream>
#include "SelectSort.cpp"
#include "SortTestHelper.h"

using namespace std;
/*
 冒泡算法
 */

/*
 查找数组中重复的数字(时间复杂度O(N))
 */
int findRepeatNum(){
    int i;
    int temp =0;
    int a[5] ={2,4,1,3,2};
    int count[5] ={0};
    for (i =0; i<5; i++) {
        temp =a[i];
        if (count[temp - 1] == 1) {
            NSLog(@"重复的数为：%d",temp);
            return temp;
        }else{
            count[temp - 1]++;
        }
    }
    return 0;
}

template <typename T> //模版函数(泛型)
/*
 选择排序
 **/
void selectionSort ( T arr[] , int n ){
    
    //  10, 39, 8, 7, 6, 5, 4, 3, 2, 1
    //先取出最小的值 然后交换
    
    for ( int i  = 0 ;  i < n ; i ++ ){
        
        int minIndex = i;
        
        for ( int j = i + 1 ; j < n ; j ++ ){
            
            if( arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        
        swap( arr[i] , arr[minIndex] );  //交换函数
    }
}

/*
 插入排序
 **/
template <typename T> //模版函数(泛型)
void insertSort (T arr[] , int n ){
    
    //  10, 39, 8, 7, 6, 5, 4, 3, 2, 1
    //取出第二个值，和第一个值交换，
    //取出第三个值，和第二个值交换，和第一个值交换
    
    for ( int i = 1 ; i < n ; i ++ ){
        
        for( int j = i ; j > 0  ; j -- ){
            if( arr[j] < arr[j-1]){
                swap( arr[j] , arr[j-1] );
            }else{
                break;
            }
            
        }
        
    }
}

/*
 插入排序优化
 **/
template <typename T> //模版函数(泛型)
void insertOptimizeSort (T arr[] , int n ){
    
    //  10, 39, 8, 7, 6, 5, 4, 3, 2, 1
    //取出第二个值，拷贝一份，然后和第一个值比较，如果大把第一个值移
    //取出第三个值，拷贝一份，然后和第二个值比较，如果大把第二个值移，然后和第一个值比较

    
    for ( int i = 1 ; i < n ; i ++ ){
        
        T e = arr[i];
        int j;
        for(j = i ; j > 0  ; j -- ){
            
            if( arr[j-1] >e){
                
                arr[j] = arr[j-1];
            }else{
                break;
            }
            
        }
        arr[j] = e;
    }
}



int main(int argc, const char * argv[]) {
   
    int arr[10] =  {10,39, 8, 7, 6, 5, 4, 3, 2, 1};

    insertSort(arr, 10);
    
    for( int i = 0 ; i < 10 ; i ++ ){
        cout<< arr[i] <<endl;
    }
    
    int n  =  10;
    SortTestHelper::testSor("Selcetion sotr", selectionSort , arr, n);
    
    
    return 0;
}
