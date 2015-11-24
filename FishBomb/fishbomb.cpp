/////////////////////////////////////////////////////////////////////////////
///@file fishbomb.cpp													  ///
///@author Jeff Goymerac 153 sec a										  ///
///@this file dynamically allocates a sonar grid for Bender then analyses ///
/// it for the for the maximum amount of fish that can be caught with 	  ///
/// a given power of dynamite.											  /// 			
/////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<iomanip>

using namespace std;

int main() {
char Enter;
int w , h, power, x=0, y=0, q=0, grids, sum, maxSum;
int **sonar;

cin>>grids;
do{
cin>>w;
cin>>h;
cin>>power;
maxSum=0;
sum=0;
sonar = new int* [h];
	for(int k=0; k < h; k++){
		sonar[k] = new int [w];
	}
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
		cin >> sonar[i][j];
		}
	}	

for(int columnStart=0; columnStart+power<=w; columnStart++){
   for(int rowStart=0; rowStart+power<=h; rowStart++){
		   sum=0;
		  for(int q=rowStart; q<power+rowStart; q++){
			  for (int r=columnStart; r<power+columnStart; r++){
			  sum+=sonar[q][r];
			}
		}
		
		
   if(sum>maxSum){
	   y=((rowStart+power)+rowStart)/2;
	   x=((columnStart+power)+columnStart)/2;
			maxSum=sum;
			
   }
   }
}
cout <<"\n #"<<q<<": ("<<x<<","<<y<<")  "<<maxSum<<"\n";
for(int k=0; k<h; k++){
	delete []sonar[k];
}
delete []sonar;

q++;
}while(q<grids);
return 0;
}
