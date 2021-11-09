#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main() {
	int lenmax, len1, len2, carry = 0, ten, one, j = 0, resultt[1000], tem=0;
	char num1[110] = {}, num2[110] = {}, result[100][100] = {}, big[110] = {}, small[110] = {};
	scanf("%s", num1);
	scanf("%s", num2);
	lenmax = (strlen(num2) > strlen(num1)) ? strlen(num2) : strlen(num1);
	len1 = strlen(num1);
	len2 = strlen(num2);
	if (lenmax == len1) {
		strcpy(big, num1);
		strcpy(small , num2);
	}
	else {
		strcpy(big, num2);
		strcpy(small, num1);
	}
	len1 = strlen(big);
	len2 = strlen(small);
	for (int i = 0; i < len1; i++) {
		big[i] -= '0';
	}
	for (int j = 0; j < len2; j++) {
		small[j] -= '0';
	}
	for (int l = 0,k = len2 - 1; k >= 0; k--,l++) {
		for (int i = len1 - 1; i >= 0; i--) {
			ten = big[i] * small[k] + carry;
			if (ten >=10) {
				carry = ten / 10;
				one = ten % 10;
				result[l][j] = one;
			}
			else {
				carry = 0;
				result[l][j] = ten;
			}
			j++;
		}
		
		result[l][j] = carry;
		j = 0;
		tem++;
		j = tem;
		carry = 0;
	}
	for (int i = 0; i < len2; i++) {
		for (int j = 0; j < len1 + len2; j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
	
	for (int j = 0; j < len1 + len2; j++) {
		tem = 0;
		for (int i = 0; i < len2; i++) {
			tem += result[i][j];
		}
		tem =  tem + carry;
		if (tem >= 10) {
			one = tem;
			tem %= 10;
			carry = one / 10;
		}
		else {
			carry = 0;
		}
		resultt[j] = tem;
	}
	for (int i = len1 + len2 - 1; i >= 0; i--) {
		if (i == len1+len2-1 && resultt[i] == 0) {
			continue;
		}
		printf("%d", resultt[i]);
	}
}