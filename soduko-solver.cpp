#include <iostream>
#include <cmath>
using namespace std;

bool canplace(int mat[][9],int i,int j,int n, int number){
	//checking for row and coln
	for(int k=0;k<n;k++){
		if(mat[k][j]==number || mat[i][k]==number){
			return false;
		}
	}

	//checking for subgrid
	int sx,sy;
	int rn = sqrt(n);
	sx = (i/rn)*rn;
	sy = (j/rn)*rn;

	for(int l=sx;l<sx+rn;l++){
		for(int n=sy;n<sy+rn;n++){
			if(mat[l][n]==number){
				return false;
			}
		}
	}

	return true;
}

bool sodukosolver(int mat[][9],int i,int j,int n){
	//base case
	if(i==n){
		//print the mATRIX
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}


		return true;
	}

	//if a row ends move to next row
	if(j==n){
		return sodukosolver(mat,i+1,0,n);
	}

	//if a number is pre filled just move to next cell
	if(mat[i][j]!=0){

	 return sodukosolver(mat,i,j+1,n);
	}
	//for filling a current cell
	for(int number=1;number<=n;number++){
		if(canplace(mat,i,j,n,number)){
			mat[i][j]=number;

			bool nextsolve= sodukosolver(mat,i,j+1,n);
			if (nextsolve){
				return true;
			}

		}

	}
	//backtrack
				mat[i][j]=0;
				return false;


}

int main() {

	 int board[9][9];
	    for(int i=0;i<9;i++)
	    {
	        for(int j=0;j<9;j++)
	        {
	            int temp;
	            cin>>temp;
	            board[i][j]=temp;
	        }
	    }

	    bool hogya=sodukosolver(board,0,0,9);
	    if(hogya==false){
	    	cout<<"nahi ho rha"<<endl;
	    }

	return 0;
}
