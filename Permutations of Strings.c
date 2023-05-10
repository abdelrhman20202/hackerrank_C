#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define SWAP(a, b, type) do{type TEMP = a; a=b; b=TEMP;}while(0);


bool is_reverse_sorted(int n, char**s){
    for (int i=1; i<n; i++){
        if (strcmp(s[i-1], s[i]) < 0){
            return false;
        }
    }
    return true;
}

void reverse_arr(int n, char** s){
    for(int i=0; i<(n+1)/2; i++){
        SWAP(s[i], s[n-i-1], char*);
    }
}

void swap_first_with_next_bigger(int n, char **s) {
  // requires indexes from 1 to the end sorted

  for (int i = 1; i < n; i++) {
    if (strcmp(s[0], s[i]) < 0) {
      SWAP(s[0], s[i], char *);
      break;
    }
  }
}

int next_permutation(int n, char **s){
    if (is_reverse_sorted(n-1, s+1)){
        if(strcmp(s[0], s[1])>=0){
            return 0;
        }else{
            reverse_arr(n-1, s+1);
            swap_first_with_next_bigger(n, s);
            return 1;
        }
        
    }else{
        next_permutation(n-1, s+1);
        return 1;
    }
}
int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}