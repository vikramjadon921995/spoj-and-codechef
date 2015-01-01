#include<iostream>
using namespace std;

int main(){
	long long int tc;
	cin>>tc;
	
	while(tc--){
		int n,k,flag = 0;
		long long int arr[21],sum = 0,arr1[21] = {0};
		cin>>n>>k;
		
		for(long long int m = 0; m < n; m++){
			cin>>arr[m];
			sum += arr[m];
		}
		
		long long int j;
		long long int count = 0;
		
		if(sum % k == 0){
			for(long long int i = 1; i <= 1<<n; i++){
				long long int s = 0;
				
				for(j = 0; j < n; j++){
					if(i & 1<<j){
						if(arr[j] == -1)
							break;
						else{
							s += arr[j];
							arr1[j] = 1;
						}
					}
				}
				
				if(s == (sum/k) && j == n){
					for(long long int l = 0; l < n; l++){
						if(arr1[l] == 1){
							arr[l] = -1;
						}
						arr1[l] = 0;	
					}
					count++;
				}
				else{
					for(long long int l = 0; l < n; l++){
						arr1[l] = 0;
					}
				}
				
				if(count == k)
					break;
			}
			
			if(count == k){
				cout<<"yes"<<endl;
			}
			else{
				cout<<"no"<<endl;
			}
		}
		else{
			cout<<"no"<<endl;	
		}
	}
	return 0;
}
