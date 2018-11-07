#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

int main(){

		srand(time(0));
		for(int i=0; i<50; i++){
				int n=rand()%50;
				cout<<"Pos "<<i+1<<": "<<n<<endl;
		}

system("pause");
}