#include<iostream>
#include<fstream>
#include<string>
#include <limits>
#include <vector>
#include <cmath>

using namespace std;
void mindist(int arr[][2] , int len1)
{
    ofstream myfile;
    float dmin = std::numeric_limits<int>::max();
    int index1;
    int index2;
    float d;
    for(int i = 0 ; i < len1 - 1 ; i ++)
    {
        for (int j = i +1 ; j < len1; j++)
        {
          d =  (arr[i][0] - arr[j][0])*(arr[i][0] - arr[j][0]) + (arr[i][1] - arr[j][1])*(arr[i][1] - arr[j][1]);
            d = sqrt(d);
            
            if( d < dmin)
            {
                dmin = d;
                index1 = i;
                index2 = j;
            }
            
        }
    }
          std::cout <<index1;
		  std::cout << " "<<index2;
		  std::cout <<" "<< dmin << std::endl;
		  
		  myfile.open ("output.txt");
		  {
		       myfile << index1 << " ";
                   myfile << index2 << " ";
                   myfile << dmin << "\n";
		  }
    
    
}


int main()
{
    int a;
    ifstream infile("input.txt");
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
      mindist(array , len);
      
}
