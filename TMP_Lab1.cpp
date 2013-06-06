#include <iostream>
#include <conio.h>

using namespace std;
#define n 6
int main()
{
    int X,j,i,A[6];
    for (i=0;i<n;i++){
        cout<<"A["<<i<<"]=";
        cin>>A[i];
    }

    for (i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;

    for (i=0;i<n-1;i++)
        for (j=0;j<n-1-i;j++)
            if (A[j]>A[j+1]){
                X=A[j];
                A[j]=A[j+1];
                A[j+1]=X;
            }
    for (i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;

    system("pause");
    return 0;
}