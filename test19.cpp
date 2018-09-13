#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool matchCore(char *str,char *pattern)
{
		if(*pattern=='\0' && *str=='\0')
			        return true;
		    else if(*pattern=='\0' && *str!='\0')
				            {
								                return false;
												            }
			         else if(*pattern!='\0' && *str=='\0')
						             {
										                return false;
														            }
					          
					     if(*(pattern+1)=='*')
							     {
									         if(*pattern==*str || (*pattern=='.' && *str!='\0'))
												         {
															             return matchCore(str+1,pattern) || matchCore(str+1,pattern+2)
																			                     || matchCore(str,pattern+2);
																								         }
											         else return matchCore(str,pattern+2);
													     }
						     else
								     {
										         if(*pattern==*str || (*pattern=='.' && *str!='\0'))
													             return matchCore(str+1,pattern+1);
												         else return false;
														     }
							     return false;
}

bool match(char *str,char *pattern)
{
		if(!str||!pattern)
				{
							return false;
								}

			return matchCore(str,pattern);
}

int main(int argc,char **argv)
{
	    if(argc!=3)
		{
			cout<<"input is invalid"<<endl;
			return -1;
		}
	    cout<<match(argv[1],argv[2])<<endl;
			return 0;
}

