#include <cstdio>
#include <string.h>
#include <cmath>


void getMinBase(char* x, char &min_base){
	char* t;
	char max = '0';
	for(t = x; *t != '\0'; ++t){
		if(*t > max) max = *t;
	}
	min_base = max + 1;
}

int getValueFromThisBase(char *x, char base_num){
	int value_num = 0;
	//printf("Length:%d \n", (int)strlen(x));
	int len_num = (int)strlen(x);
	int num_power = len_num - 1;
	for(int i=0; i<len_num; ++i){
		printf("num: %d * base: %d exponente: %d \n", *x - '0', base_num - '0', num_power);	//casting
		value_num += (*x - '0') * pow(base_num - '0', num_power);
		num_power--;
		++x;
	}
	return value_num;
}

void getEqualValues(char *x, char min_base_x, char* y, char min_base_y){
	printf("test");
	int value_x=0, value_y=0;
	bool equal = 0;
	while(min_base_x - '0' <= 36 && min_base_y - '0' <= 36){
		printf("%s\n","Test");
		value_x = getValueFromThisBase(x,min_base_x);
		value_y = getValueFromThisBase(y,min_base_y);
		if(value_x == value_y){
			printf("GOT IT %d - %d \n", value_x, value_y);
			printf("%s (base %d) = %s (base %d)\n",x, min_base_x - '0', y, min_base_y - '0');
			return;
		}
		else if(value_x > value_y){
			min_base_y++;
		}
		else{
			min_base_x++;
		}
	}
}


int main(){
	char x[100], y[100];
	char min_base_x, min_base_y;
	int value_x=0, value_y=0;
	while(scanf("%s %s",x,y) != EOF){
		getMinBase(x, min_base_x);
		getMinBase(y, min_base_y);
		getEqualValues(x, min_base_x, y, min_base_y);
	}
	return 0;
}