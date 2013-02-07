#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void insertion_sort(int* array, int n)
{
    int i,j,key;
    for (i=0;i<n;i++)
    {
        key=array[i];
        j=i-1;
        while (j>=0 && array[j]>key)
        {
            array[j+1]=array[j];
            j=j-1;
        }
        array[j+1]=key;
    }
}

int main()
{
    int c = 0, n=10000;
    int numbers[10000];
    string line;
    fstream myfile;
    myfile.open("data10k.txt");
    while(myfile.good())
    {
        getline(myfile,line);
        stringstream(line)>>numbers[c];
        c++;
    }

    insertion_sort(numbers,n);

    for(c = 0; c<n; c++)
    {
        cout<<numbers[c]<<endl;
    }
    myfile.close();

    return 0;
}
