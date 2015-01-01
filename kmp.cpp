#include<iostream>
#include<vector>
#include<stdlib.h>
#include<set>
using namespace std;

struct comp{
	bool operator()(const int lhs, const int rhs){
		return lhs < rhs;
	}
};

int main(){
	while(1){
		long long int len;
		cin>>len;
		if(cin.eof())
			break;
		vector<char> pat(len);
		multiset<long long int,comp> occurences;
		
		for(long long int i = 0; i < len; i++){
			cin>>pat[i];
		}	
		cin.ignore();
		
		long long int ff[len + 1],j;
		ff[0] = ff[1] = 0;
		for(long long int i = 2; i <= len; i++){
			j = ff[i-1];
			for( ; ; ){
				if(pat[j] == pat[i-1]){
					ff[i] = j + 1;
					break;
				}
				if(j == 0){
					ff[i] = 0;
					break;
				}
				j = ff[j];
			}
		}
		
		char text;
		long long int text_count = 0;
		int index = 0;
		while((text = getchar()) != '\n'){
			text_count++;
			for( ; ; ){
				if(text == pat[index]){
					index++;
					if(index == len){
						occurences.insert(text_count - len);
					}
					break;
				}
				else if(index > 0){
					index = ff[index];
				}
				else{
					break;
				}
			}
		}
		
		for(multiset<long long int>::const_iterator it(occurences.begin()),end(occurences.end()); it != end; it++){
			cout<<*it<<endl;
		}
		cout<<endl;
	}
}
