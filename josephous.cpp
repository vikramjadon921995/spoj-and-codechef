#include<iostream>
using namespace std;

int main(){
	
	while(1){
		long long int n,d;
		cin>>n>>d;
		
		if(n != 0 && d != 0){
			long int lookup = 1;
			
			for(int i = 2; i <= n; i++){
				lookup = (lookup + d-1)%i + 1;
			}
			
			cout<<n<<" "<<d<<" "<<lookup<<endl;
		}
		else{
			break;
		}
	}
}
