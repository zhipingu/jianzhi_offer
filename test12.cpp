#include<iostream>
#include<string>

using namespace std;

bool findcore(char matrix[],int rows,int cols,int row,int col,const char *str,int visited[])
{
	    static int length=0;
		    
			if(str[length]=='\0')return true;
				
				if(matrix!=nullptr&&row<rows&&row>=0&&col<cols&&col>=0)
						{
									if(matrix[row*cols+col]==str[length]) 
												{
																	visited[row*cols+col]=1;
																					++length;
																							}
										}
					bool flag=findcore(matrix,rows,cols,row,col-1,str,visited)
									||findcore(matrix,rows,cols,row-1,col,str,visited)
												||findcore(matrix,rows,cols,row,col+1,str,visited)
															||findcore(matrix,rows,cols,row+1,col,str,visited);
						if(!flag)
								{
											--length;
													visited[row*cols+col]=0;
														}
							return flag;
}

bool find(char matrix[],int rows,int cols,const char *str )
{
	    if(matrix==nullptr||rows<1||cols<1||str==nullptr)
			    {
					        cerr<<"input is invalid"<<endl;
							        exit(1);
									    }
			int visited[rows*cols]={0};
				for(int row=0;row<rows;++row)
						{
									for(int col=0;col<cols;++col)
												{
																	if(findcore(matrix,rows,cols,row,col,str,visited)) return true;
																			}
										}
					return false;
}
int main()
{
	    char matrix[]={'a','b','t','g','c','f','c','s','j','d','e','h','\0'};
		    cout<<find(matrix,3,4,"bfce")<<endl;
					return 0;
}

