#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    char* _a = *((char**)a);
    char* _b = *((char**)b);
    return strcmp(_a,_b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    char* _a = *((char**)a);
    char* _b = *((char**)b);
    return strcmp(_a,_b) * (-1);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    char* _a = *((char**)a);
    char* _b = *((char**)b);
    int len_a = strlen(_a);
    int len_b = strlen(_b);    
    
    int i = 0;
    int distinct_a = 0;
    int distinct_b = 0;
    int result = 0;
    char lowercase_letters_hash[26] = {0};
    
    distinct_a = 0;
    (void)memset(lowercase_letters_hash,0,26);
    for(i = 0; i < len_a; i++){
        if(!lowercase_letters_hash[_a[i] - 'a']){
            lowercase_letters_hash[_a[i] - 'a'] = 1;
            distinct_a++;
        }
    }
    distinct_b = 0;
    (void)memset(lowercase_letters_hash,0,26);
    for(i = 0; i < len_b; i++){
        if(!lowercase_letters_hash[_b[i] - 'a']){
            lowercase_letters_hash[_b[i] - 'a'] = 1;
            distinct_b++;
        }
    }
    result = distinct_a - distinct_b;       
    return (result != 0) ? result : lexicographic_sort(a,b);
}

int sort_by_length(const char* a, const char* b) {
    char* _a = *((char**)a);
    char* _b = *((char**)b);
    int result = strlen(_a) - strlen(_b);
    return (result != 0) ? result : lexicographic_sort(a,b);
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    qsort(arr, len, sizeof(char*), (int (*)(const void*, const void*))cmp_func);
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}