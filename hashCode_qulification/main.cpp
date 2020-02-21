#include <iostream>
#include <cstdlib>
using namespace std;
int *booksINlib;
int  main()
{
    int totalBooks,totalLib,totalDays;
    int count=0;
    //booksOFlib obj1;
    cout<<"Enter total books "<<endl;
    cin>>totalBooks;
    cout<<"Enter total Lib "<<endl;
    cin>>totalLib;
    cout<<"Enter total Days "<<endl;
    cin>>totalDays;

                         //***For storing books Score***
    int *booksScore;
    booksScore= new int[totalBooks];
    cout<<"Enter Books Score"<<endl;
    for(int i=0;i<totalBooks;i++)
    {
        cin>>booksScore[i];
    }

                      //***for storing total library***
    int *lib;
    lib= new int[totalLib];
    for(int i=0;i<totalLib;i++)
    {
        lib[i]=i;
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
                      //***parameters are => 'totalbooks in library','totalsigning day f library',
                      //***               => 'totalshipping book of library/per day'
    for (int k = 0; k <totalLib ; ++k)
    {
        cout<<"enter parameter of library "<<k+1<<endl;
        for (int i = 0; i < 3; ++i)
        {
           cin>>parameters[k][i];
        }
        //***Assigning books to library***
        if(k==count)
        {
            booksINlib= new int[parameters[k][0]];
            cout<<"Assigning books to "<<k+1<<" library"<<endl;
            for (int j = 0; j <parameters[k][0] ; ++j)
            {
                cin >> booksINlib[j];
            }
           count++;
        }
    }
    count=0;
    cout<<"Parameters of library"<<endl;
    for (int k = 0; k <totalLib ; ++k)
    {
        cout<<"\nparameter of "<<k+1<<" library"<<endl;
        for (int i = 0; i < 3; ++i)
        {
            cout<<parameters[k][i]<<endl;
            if(k==count)
            {
                cout<<"Books in "<<k+1<<" library"<<endl;
                for (int j = 0; j < parameters[k][0]; ++j)
                {
                   cout<<booksINlib[j]<<"\t";
                }
                count++;
                cout<<endl;
                co
            }
        }
    }

    return 0;
}