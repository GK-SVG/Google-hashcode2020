#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;
int  main()
{
    int totalBooks,totalLib,totalDays;
    int count=0;
    fstream file;
    string filename;
    cin>>filename;
    file.open(filename);
    file>>totalBooks;
    file>>totalLib;
    file>>totalDays;

    int *totallibout;
    totallibout=new int[totalLib];


                         //***For storing books Score***
    int *booksScore;
    booksScore= new int[totalBooks];
    for(int i=0;i<totalBooks;i++)
    {
        file>>booksScore[i];
    }

                      //***creating 2d array for storing book Score index in libraries***
    int **booksINlib;
    booksINlib=new int*[totalLib];
    for (int l = 0; l <totalBooks ; ++l)
    {
        booksINlib[l]= new int[totalBooks];
    }
    for (int m = 0; m <totalLib ; ++m)
    {
        for (int i = 0; i <totalBooks ; ++i)
        {
          booksINlib[m][i]=-1;
        }
    }

                     //******For storing parameters of libraries******
                     //***creating 2d array for parameter***
    int **parameters;
    parameters= new int*[totalLib];
    for (int j = 0; j <3 ; ++j)
    {
       parameters[j]= new int[3];
    }
                      //***entering parameters of libraries***
                      //***parameters are => 'totalbooks in library','totalsigning day of library',
                      //***               => 'totalshipping book of library/per day'
    for (int k = 0; k <totalLib ; ++k)
    {
        for (int i = 0; i < 3; ++i)
        {
           file>>parameters[k][i];
        }

                        //***Assigning books to library***
        if (k==count)
        {
            for (int j = 0; j < parameters[k][0]; ++j)
            {
                file >> booksINlib[k][j];
            }
            count++;
        }
    }

    int count1=0,totaldays4issue;
    for (int m = 0; m < totalLib; ++m)
    {
        totalDays-=parameters[m][1];
        totaldays4issue= totalDays;
        if(totalDays>0)
        {
            while(parameters[m][0]>0 && totaldays4issue>0)
            {
                parameters[m][0]-=parameters[m][2];
                totaldays4issue--;
                if(parameters[m][0]>=0)
                    count1+=parameters[m][2];
                else
                    {
                      parameters[m][2]+=parameters[m][0];
                      count1+=parameters[m][2];     
                    }
                    
                
            }
            totallibout[m]=count1;
            count1=0;
        }
    }

    //cout<<endl;
    cout<<totalLib<<endl;
    for (int n = 0; n <totalLib; ++n)
    {
        cout<<n<<" "<<totallibout[n]<<endl;
        for (int i = 0; i < totallibout[n]; ++i)
        {
          if(booksINlib[n][i]==-1)
              continue;
          else
              cout<<booksINlib[n][i]<<" ";
        }
        cout<<endl;
    }
    delete[] booksINlib;
    delete[] parameters;
    delete[] totallibout;
    delete[] booksScore;
    return 0;
}