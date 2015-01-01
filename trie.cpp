#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

struct node_trie{
	int value;
	bool leaf;
	node_trie *children[10];
};

typedef struct node_trie node_trie;

node_trie* init(){
	node_trie *node = NULL;
	node = (node_trie*)malloc(sizeof(node_trie));
	
	node->value = -1;
	node->leaf = 1;
	for(int i = 0; i < 10; i++){
		node->children[i] = NULL;
	}
	
	return node;
}

int main(){
	int tc;
	//cin>>tc;
	scanf("%d",&tc);
	
	while(tc--){
		int n,ans = 0;
		//cin>>n;
		scanf("%d",&n);
		
		node_trie *root = NULL;
		root = init();
		root->leaf = 0;
		
		while(n--){
			char s[10];
			//cin>>s;
			scanf("%s",s);
			int check = 0,count = 0;
			
			node_trie *ptr = root;
            
			for(int i = 0; i < strlen(s); i++){
				int val = (int)s[i] - 48;
				
				if(check == 0){
					if(ptr->leaf == 1){
						if(i == (strlen(s) - 1))
							ans = 0;
						else{
							ans = 1;
							break;
						}
					}
					else{
						if(i == (strlen(s) - 1))
							ans = 1;
					}
				}
				
				if(ptr->children[val] == NULL){
					node_trie *node = NULL;
					node = (node_trie*)malloc(sizeof(node_trie));
					node->value = val;
					node->leaf = 1;
					if(i != (strlen(s)-1))
						node->leaf = 0;
					ptr->children[val] = node;
					ptr = node;
					check++;	
				}
				else{
					ptr = ptr->children[val];
					count++;
				}
			}
			
			if(check != 0){
				ans = 0;
			}
			else{
				if(strlen(s) == count)
					if(ptr->leaf == 1)
						ans = 0;
			}
 
			if(ans == 1){
				break;
			}	   
		}
		
		if(ans == 1)
			//cout<<"NO"<<endl;
			printf("NO\n");
		else
			//cout<<"YES"<<endl;
			printf("YES\n");
	}
}
