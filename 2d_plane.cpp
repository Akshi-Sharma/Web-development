#include<iostream>
#include<fstream>
#include<string>
#include <limits>
#include <vector>
#include <cmath>

using namespace std;
float sort(int arr1[][2])
{
    float dmin = std::numeric_limits<int>::max();
    float d;
    for(int i = 0 ; i < 2 ; i++)
    {
        for (int j = i+1; j < 3 ; j++)
        {
            d =  (arr1[i][0] - arr1[j][0])*(arr1[i][0] - arr1[j][0]) + (arr1[i][1] - arr1[j][1])*(arr1[i][1] - arr1[j][1]);
            d = sqrt(d);
             if( d < dmin)
            {
                dmin = d;
            }
            
        }
        
    }
	
    return dmin;
    
}
float splitClosestDist(int splitArr[][2] , int len, float d)
{
    float dmin = d;
    float d1;
    for(int i = 0; i < len -1 ; i++)
    {
        for(int j = i+1; j<len ; j++)
        {
            d1 =  (splitArr[i][0] - splitArr[j][0])*(splitArr[i][0] - splitArr[j][0]) + (splitArr[i][1] - splitArr[j][1])*(splitArr[i][1] - splitArr[j][1]);
            d1 = sqrt(d1);
             if( d1 < dmin)
            {
                dmin = d1;
            }
        }
    }
    
    return dmin;
    
}


float findmindist(int arr[][2] , int len1)
{
    if (len1 <= 3)
    {
        return sort(arr);
    }
    
    int mid = len1/2;
    
    float l = findmindist(arr , mid);
    float R = findmindist(arr + mid , len1 - mid);
    
    float d = min(l , R);
    
    int splitArray[len1][2];
    int j=0;
    for(int i=0;i<len1;i++){
        if( abs(arr[i][0]- arr[mid][0])< d){
           
            splitArray[j][0]=arr[i][0];
            splitArray[j][1]=arr[i][1];
            
            j++;
		}
    float s = splitClosestDist(splitArray, j, d);
    return min(s, d);
}
}


int main()
{
    int a;
    ifstream infile("input.txt");
	ofstream myfile;
    int count = 0;
    int b = 0;
    int len;
    std::vector<int> arraylist;
    while (infile >> a)
      {
        count++;
        arraylist.push_back(a);
      }
     len = count/2;
    int array[len][2];
    for(int i = 0; i <len ; i++)
      {
          for (int j = 0 ; j <2 ; j ++)
          {
              array[i][j] = 0;
          }
      }
    for(int i = 0; i <len ; i++)
      {
          for (int j = 0 ; j <2 ; j ++)
          {
                  array[i][j] = arraylist[b];
                  b++;
              
          }
      }
      float min = findmindist(array , len);
	  myfile.open ("output.txt");
	  myfile << min ;
      printf("%f \n"  ,min);
      
}