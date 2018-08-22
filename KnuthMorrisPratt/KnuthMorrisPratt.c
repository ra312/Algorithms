 #include <assert.h>
 #include <limits.h>
 #include <math.h>
 #include <stdbool.h>
 #include <stddef.h>
 #include <stdint.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
int* prefix_function(char* s) {
		int n = strlen(s);
		int i;
		int* pi = (int*)malloc(n*sizeof(int));
		for (i=0; i<n; i++) pi[i]=0;
		for (int i = 1; i < n; i++) {
				 int j = pi[i-1];
				 while (j > 0 && s[i] != s[j])
						 j = pi[j-1];
				 if (s[i] == s[j])
						 j++;
				 pi[i] = j;
		 }
		return pi;
}

// The function KMP returns 1 if A is a substring of B and returns 0 otherwise

int KMP(char* A, char* B)
{
	int len_B = strlen(B);
	int len_A = strlen(A);

	int len;
	int i;
	char* A_hash_B;

	len = len_A+len_B+1;

	A_hash_B = (char*)malloc(sizeof(char)*len);
	for (i=0; i<len; i++)
		A_hash_B[i]='\0';

	for (i=0; i<len_A; i++)
		A_hash_B[i]=A[i];
	A_hash_B[len_A]='#';
	for (i=0; i<len_B; i++)
		 A_hash_B[i+len_A+1]=B[i];
	A_hash_B[len]='\0';

	int* l = prefix_function(A_hash_B);
	for (i=0; i<len; i++)
		if (l[i]==len_A)
			return 1;
	return 0;
}

int main()
{
	char* A = "ab";
	char* B = "acd";
	if (KMP(A,B))
	{
		printf("%s is a substring of %s\n",A,B);
	}
	else
	{
		printf("%s is NOT a substring of %s\n",A,B);
	}
	return 0;
}
