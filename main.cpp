#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;
void mat (int a[10][10], int r, int c)
{
    for (int i=0;i<r ;i++)
    {
        for (int j=0;j<c ;j++)
        {
            cin >> a[i][j];
        }
    }
}
void sum(int a[10][10], int r1, int c1,int b[10][10],int r2,int c2 )
{
    if (r1==r2 && c1==c2)
    {
        for (int i=0;i<r1 ;i++)
       {
        for (int j=0;j<c1 ;j++)
        {
            cout <<round( a[i][j]+b[i][j]) << " ";
        }
        cout<<endl;
       }
    }
    else
    {
        cout<< "The operation you chose is invalid for the given matrices."<<endl;
    }

}
void sub(int a[10][10], int r1, int c1,int b[10][10],int r2,int c2 )
{
    if (r1==r2 && c1==c2)
    {
        for (int i=0;i<r1 ;i++)
       {
        for (int j=0;j<c1 ;j++)
        {
            cout <<round( a[i][j]-b[i][j]) << " ";
        }
        cout<<endl;
       }
    }
    else
    {
        cout<< "The operation you chose is invalid for the given matrices."<<endl;
    }

}
void mul(int a[10][10], int r1, int c1,int b[10][10],int r2,int c2 )
{
     if (c1==r2)
     {
     for (int i=0;i<r1 ;i++)
       {
        for (int j=0;j<c2 ;j++)
        {
            int m =0 ;
            for (int k=0 ; k<c1; k++)
            {
                m= m + a[i][k] * b[k][j];
            }
            cout<<m << " ";
        }
        cout<<endl;
       }
     }
     else{
        cout<< "The operation you chose is invalid for the given matrices."<<endl;
     }
}
int determinant( int b[10][10], int r) {
   int d = 0;
   int m[10][10];
   if(r==1)
    return (b[0][0]);
   else if (r == 2)
   return ((b[0][0] * b[1][1]) - (b[1][0] * b[0][1]));
   else {
    for (int k = 0; k < r; k++) {
        int x = 0;
        for (int i = 1; i < r; i++) {
        int y = 0;
        for (int j = 0; j < r; j++) {
            if (j == k)
               continue;
               m[x][y] = b[i][j];
               y++;
            }
            x++;
         }
         d = d + (pow(-1, k) * b[0][k] * determinant( m, r - 1 ));
      }
   }
   return d;
}
void division(int a[10][10],int r1,int c1,int b[10][10],int r2,int c2 )
{
    int d=determinant(b,r2);
        int m[10][10],n[10][10],t[10][10];
        if(r2==1)
        {
            if((round (a[0][0]/(double)b[0][0]))==0 )
            {
                cout<< "0"<<endl;
            }
            else{
            cout <<round (a[0][0]/(double)b[0][0])<<endl;
            }
        }
        else
        {
         for(int l=0 ;l<r2; l++)
         {
         for (int k = 0; k < r2; k++) {
         int x = 0;

         for (int i = 0; i < r2; i++) {
            if (i==l)
                continue;
            int y = 0;
            for (int j = 0; j < r2; j++) {
               if (j == k)
               continue;
               m[x][y] = b[i][j];
               y++;
            }
            x++;
         }
         n[l][k]=(determinant(m,r2-1))*(pow(-1,k+l));

      }
         }
         for(int g=0; g<r2;g++)
         {
             for(int o=0; o<r2; o++)
             {
                 t[g][o]=n[o][g];
             }
         }
      for (int q=0;q<r1 ;q++)
       {
        for (int u=0;u<c2 ;u++)
        {
            int s =0 ;
            for (int e=0 ; e<c1; e++)
            {
                s= s + a[q][e] * t[e][u];
            }
            if(round((s/(double) d)) == 0)
            {
                cout<< "0"<< " ";
            }
            else{
            cout<<round((s/(double) d)) << " ";
            }
        }
        cout<<endl;
       }
        }
}




int main()
{
    int r1,c1,r2,c2,op,i=1;
    int A[10][10],B[10][10];
    cout<<"Please enter dimensions of Matrix A:"<<endl;
    cin>>r1>>c1;
    cout <<"Please enter dimensions of Matrix B:"<<endl;
    cin >>r2>>c2;
    cout<< "Please enter values of Matrix A:"<<endl;
    mat(A,r1,c1) ;
    cout<< "Please enter values of Matrix B:"<<endl;
    mat(B,r2,c2) ;
    while( i>0)
    {
        cout<< "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):"<<endl;
        cin>>op;
        if (op>=1 && op<=7)
        {
          switch(op)
          {
        case 1:
            sum(A,r1,c1,B,r2,c2);
            break;
        case 2:
            sub(A,r1,c1,B,r2,c2);
            break;
        case 3:
            mul(A,r1,c1,B,r2,c2);
            break;
        case 4:
            if(determinant(B,r2)==0 || c1!=r2 || r2!=c2)
             {
                 cout<< "The operation you chose is invalid for the given matrices."<<endl;
             }
            else{
             division(A,r1,c1,B,r2,c2);
            }
            break ;
        case 5:
            if (r1==c1)
            {
            cout<<determinant(A,r1)<<endl;
            }
             else {
            cout<< "The operation you chose is invalid for the given matrices."<<endl;

        }
            break;
        case 6:
            if(r2==c2)
            {
            cout<<determinant(B,r2)<<endl;
            }
             else {
            cout<< "The operation you chose is invalid for the given matrices."<<endl;

        }
            break;
        case 7:
            cout<< "Thank you!"<<endl;
            return 0;
            break ;
        default :
           return 0;
           break;
         }
        }
    }






    return 0;
}
