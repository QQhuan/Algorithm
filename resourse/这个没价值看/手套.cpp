#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <malloc.h> 
enum Color{
	RED = 1, YELLOW, GREEN	
};
enum Way{
	left = 1, right
};
typedef struct{
	int order;  //序号 
	enum Color c; //颜色 
	enum Way w; //方向 
} Glove, *Gloves;

int large = 1, least = 1;

void max(Glove str[]){
	for(int i = 1; i < 22; i++){
		if(str[i].c == GREEN && str[i].w == right)
			continue;
		else{
			large++;
		} 
	} 
	large++;
}

void min(){
	least++;
}


int main(){
	Glove str[22];
	//初始化数组，红黄绿各自的左右手套 
	for(int i = 0; i <= 3; i++){
		str[i].order = i+1;
		str[i].c = GREEN;
		str[i].w = left;
		if(i > 1)
			str[i].w = right;
	}
	for(int i = 4; i <= 13; i++){
		str[i].order = i+1;
		str[i].c = RED;
		str[i].w = left;
		if(i > 8)
			str[i].w = right;
	}
	for(int i = 14; i <= 21; i++){
		str[i].order = i+1;
		str[i].c = YELLOW;
		str[i].w = left;
		if(i > 17)
			str[i].w = right;
	}
	max(str);
	min();
	printf("最好的情况下，只需要%d次就能找出一双匹配的袜子\n", least);
	printf("最坏的情况下，共需要%d次才能找出一双匹配的袜子\n", large);
	getchar();
	return 0;
}
