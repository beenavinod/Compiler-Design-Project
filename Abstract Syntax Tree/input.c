#include<stdio.h>
int main(){
	
	int x, y;
	x=10;
	y = x*2 + 3; //Value of 'y' here is 23
	if(y>0){
		int z;
		z = x + y;
		/* Here, z has local scope.
		But it can access 'x' and 'y' from outside
		and its value will be 33*/
		z = x + y;
	}
}