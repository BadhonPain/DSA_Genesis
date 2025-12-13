#include<iostream>
using namespace std;
int main()
{
    int arr[]= {1,8,6,2,5,4,8,3,7};
    int size = 9;
    int mx =0, smx =0;
     int idx1 = -1, idx2 = -1;
    if (arr[0]>arr[1])
    {
        mx= arr[0];
        idx1 = 0;
        smx = arr[1];
        idx2 =1;
    }
    else 
    {
        mx= arr[1];
        idx1 = 1;
        smx = arr[0];
        idx2 = 0;
    }
   
    for (int i = 0; i < size; i++)
    {
        if (arr[i]> mx)
        {
            smx = mx;
            
            mx = arr[i];
        }
        else if (arr[i]<mx && arr[i]>smx)
        {
            smx = arr[i];
        }
        
        
    }
    
}