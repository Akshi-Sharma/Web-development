#include <string>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <cmath>
#include <iterator>
#include <fstream>

using namespace std;

void matchdiff(int array[], int length)
{
ofstream myfile;
    int diff;
int alistlength = 0;
		std::vector<int> array1;
		std::unordered_set<int> hashSet;
                for ( int h = 0 ; h < length; h++)
                {
                     hashSet.insert(array[h]);
                }
		for (int i = 0; i < length; i++)
		{
			for (int j = i + 1; j < length;j++)
			{
				diff = std::abs(array[j] - array[i]);

				if (hashSet.count(diff))
				{
					if (array[i] > array[j])
					{
						array1.push_back(diff);
						array1.push_back(array[i]);
						array1.push_back(array[j]);
                        alistlength  = alistlength +3;

					}
					else
					{
						array1.push_back(diff);
						array1.push_back(array[j]);
						array1.push_back(array[i]);
                        alistlength  = alistlength +3;
					}

				}

			}
		}
		
        if(alistlength == 0)
        {
         std::cout <<"There is no match"<< std::endl;   
        }
        else{
            myfile.open ("output.txt");
		for(int k = 0 ; k < alistlength; k++)
		{  
                   myfile << array1[k] << " ";
                   myfile << array1[++k] << " ";
                   myfile << array1[++k] << "\n";
                   
                   
		}
            myfile.close();
              for (int l = 0; l < alistlength; l++)
                {
                  std::cout <<array1[l];
		  std::cout << " "<<array1[++l];
		  std::cout <<" "<< array1[++l] << std::endl;
                }
        }
		
		
    
}

int main()
{
ifstream infile("input.txt");
int count = 0;
int a;
std::vector<int> arraylist;
while (infile >> a)
{
count++;
arraylist.push_back(a);
}
int arr[count];
for (int b = 0 ; b < arraylist.size() ; b++)
{
arr[b] = arraylist[b];
}

matchdiff (arr, count);
}