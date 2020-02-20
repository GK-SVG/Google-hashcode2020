#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    int **pizzas;
    int n;
    cin>>n;
    pizzas= new int*[n];
   // cout<<"enter values"<<endl;
    for (int i = 0; i < n; i++)
    {
        pizzas[i]= new int[n];   
    }
    cout<<"enter valus"<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>pizzas[i][j];
        }
        
    }
    cout<<"entered valus are"<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<pizzas[i][j]<<"\t";
        }
        
    }
    delete[] pizzas; 
    return 0;
    
}