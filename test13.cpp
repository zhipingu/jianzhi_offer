#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

int get_dig_sum(int key)
{
    int sum=0;
    while(key>0)
    {
        sum+=key%10;
        key/=10;
    }
    return sum;
}


int movecore(int threshold,int rows,int cols,int row,int col,int *visited)
{
    int count=0;
    if(row>=0&&row<rows&&col>=0&&col<cols&&!visited[row*cols+col]&&get_dig_sum (row)+get_dig_sum (col)<=threshold)
    {
        visited[row*cols+col]=1;
        count=1+movecore(threshold,rows,cols,row,col-1,visited)+
              movecore(threshold,rows,cols,row-1,col,visited)+
              movecore(threshold,rows,cols,row,col+1,visited)+
              movecore(threshold,rows,cols,row+1,col,visited);
    }
    return count;
}
int move(int threshold,int rows,int cols)
{
    if(threshold<=0||rows<=0||cols<=0)
    {
        cerr<<"input is invalid"<<endl;
        exit(1);
    }
    int *visited=new int[rows*cols]();
    int count=movecore (threshold,rows,cols,0,0,visited);
    delete [] visited;
    return count;
    
}
int main()
{
    int threshold=6;
    cout<<move(threshold,5,5)<<endl;
}
