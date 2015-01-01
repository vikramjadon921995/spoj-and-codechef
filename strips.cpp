#include<iostream>
#include<vector>
using namespace std;

long long int arr[1000000];
vector<long long int> check;

int main(){
	long int n,k;
	cin>>n>>k;
	long long int count = 0;
	
	for(int i = 0; i < n; i++){
		cin>>arr[i];
		if(i > 0){
			if(arr[i] == arr[i - 1])
				count++;
			else{
				check.push_back(count+1);
				count = 0;
			}
			if(i == n-1){
				check.push_back(count+1);
			}
		}
	}
	
	long long int flag = 0;
	long long int changes = 0;
	long long int run = 0;
	long long int walk = 0;
	for(long long int i = 0; i < n;){
		if(check[flag]&1 && check[flag] != 1){
			changes += check[flag]/2;
			while(walk < check[flag]){
				i++;
				walk++;
				if(i % 2 != 0){
					if(arr[i] == 0){
						arr[i] = 1;
					}
					else{
						arr[i] = 0;
					}
				}
			}
			walk = 0;
			flag++;
		}
		else{
			changes += check[flag]/2;
			while(walk < check[flag]){
				i++;
				walk++;
				long long int x = 1;
				if(x == check[flag] - 2){
					i = x;
					if((arr[i-1] == 0 && arr[i + 1] == 1) || (arr[i-1] == 1 && arr[i + 1] == 0))
						arr[i] = 2;
					else if((arr[i-1] == 0 && arr[i + 1] != 1) || (arr[i-1] != 1 && arr[i + 1] == 0))
						arr[i] = 1;
					else if((arr[i-1] != 0 && arr[i + 1] != 0) || (arr[i-1] != 0 && arr[i + 1] != 0))
					arr[i] = 0;		
				}
				else{
					if(x % 2 != 0){
						if(arr[i + x] == 0){
						arr[i + x] = 1;
						}
						else{
							arr[i + x] = 0;
						}
						i = i + x;
						x++;
					}
				}
			}
			if(walk == check[flag] - 1)
					walk = 0;
			flag++;
		}
	}
	cout<<changes<<endl;
	for(int i = 0; i < n; i++){
		cout<<arr[i];
	}
	cout<<endl;
}
