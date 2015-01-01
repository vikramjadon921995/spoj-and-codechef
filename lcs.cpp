#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

struct lcs{
		int len;
		char dir;
};
		
typedef struct lcs lcs;
		
lcs lcs_arr[103][103];

int main(){
	char s1[101],s2[101];
	while(1){
		if(scanf("%s %s",s1,s2) != 2)
			break;
		
		for(int i = 0; i <= strlen(s1); i++){
			for(int j = 0; j <= strlen(s2); j++){
				if(i == 0 || j == 0){
					lcs_arr[i][j].len = 0;
				}
				else{
					if(s1[i-1] == s2[j-1]){
						lcs_arr[i][j].len = lcs_arr[i-1][j-1].len + 1;
						lcs_arr[i][j].dir = 'd';
					}
					else{
						lcs_arr[i][j].len = max(lcs_arr[i-1][j].len,lcs_arr[i][j-1].len);
						(lcs_arr[i-1][j].len > lcs_arr[i][j-1].len) ? (lcs_arr[i][j].dir = 'u') : (lcs_arr[i][j].dir = 'l');
					}
				}
			}
		}
		
		int i = strlen(s1);
		int j = strlen(s2);
		
		int i1,j1,i2,j2,count = 0;
		
		if(lcs_arr[strlen(s1)][strlen(s2)].len == 0){
			cout<<s1<<s2<<endl;
		}
		else if(lcs_arr[strlen(s1)][strlen(s2)].len == 1){
			while(1){
				if(i == 0 || j == 0)
					break;
				if(lcs_arr[i][j].dir == 'd'){
					count++;
					if(count == 1){
						j1 = i-1;
						j2 = j-1;
					}
					if(count == lcs_arr[strlen(s1)][strlen(s2)].len){
						i1 = i-1;
						i2 = j-1;
					}
					
					i--;
					j--;	
				}
				else if(lcs_arr[i][j].dir == 'l'){
					j--;
				}
				else{
					i--;
				}
			}
			for(int i = 0; i < i2; i++){
					cout<<s2[i];
			}
			for(int i = 0; i <= i1; i++){
					cout<<s1[i];
			}
			for(int i = i2 + 1; i < strlen(s2); i++){
				cout<<s2[i];
			}
			for(int i = i1 + 1; i < strlen(s1); i++){
				cout<<s1[i];
			}
			cout<<endl;
		}
		else{
			while(1){
				if(i == 0 || j == 0)
					break;
				if(lcs_arr[i][j].dir == 'd'){
					count++;
					if(count == 1){
						j1 = i-1;
						j2 = j-1;
					}
					if(count == lcs_arr[strlen(s1)][strlen(s2)].len){
						i1 = i-1;
						i2 = j-1;
					}
					
					i--;
					j--;	
				}
				else if(lcs_arr[i][j].dir == 'l'){
					j--;
				}
				else{
					i--;
				}
			}
		
			int s1_arr[26], s2_arr[26],index = -1;
			
			for(int i = 0; i < 26; i++){
				s1_arr[i] = -1;
				s2_arr[i] = -1;
			}
			
			for(int i = i1; i <= j1; i++){
				s1_arr[(int)s1[i] - 97] = i;
			}
			for(int i = i2; i <= j2; i++){
				s2_arr[(int)s2[i] - 97] = i;
			}
			
			if((j1 - i1) >= (j2 - i2)){
				for(int i = 0; i < i2; i++){
					cout<<s2[i];
				}
				for(int i = 0; i <= i1; i++){
					cout<<s1[i];
				}
				int ind = i1 + 1;
				for(int i = i2+1; i <= j2; i++){
					if(s1_arr[(int)s2[i] - 97] == -1){
						cout<<s2[i];
					}
					else{
						while(s2[i] != s1[ind]){
							cout<<s1[ind];
							ind++;
						}
						cout<<s1[ind];
						ind++;
					}
				}
				for(int i = j1+1; i < strlen(s1); i++){
					cout<<s1[i];
				}
				for(int i = j2+1; i < strlen(s2); i++){
					cout<<s2[i];
				}
				cout<<endl;
			}
			else{
				for(int i = 0; i < i1; i++){
					cout<<s1[i];
				}
				for(int i = 0; i <= i2; i++){
					cout<<s2[i];
				}
				int ind = i2 + 1;
				for(int i = i1+1; i <= j1; i++){
					if(s2_arr[(int)s1[i] - 97] == -1){
						cout<<s1[i];
					}
					else{
						while(s1[i] != s2[ind]){
							cout<<s2[ind];
							ind++;
						}
						cout<<s2[ind];
						ind++;
					}
				}
				for(int i = j2 + 1; i < strlen(s2); i++){
					cout<<s2[i];
				}
				for(int i = j1+1; i < strlen(s1); i++){
					cout<<s1[i];
				}
				cout<<endl;
			}
		}
	}
}
