#include "map.h"
#include<raylib.h>
#include<stdio.h>




//load the map
struct MAP LoadMap(void){

	struct MAP map; 
	char mapinfo[20][20];

	//===========================FILE LOAD START===========//
	FILE *f;
   	int value;

   	f = fopen("levels/1.lvl","rb");

   	int x=0, y=0;
   	while ((value = fgetc(f)) != EOF){
       if (value == '\n') continue;
       mapinfo[x][y] = value;
       if (y == 9){ x=(x+1)%20;} 
       y=(y+1)%20;}


	//===========================FILE LOAD END=============//

	//loding in struct
	for(int x=0;x<20;x++){
		for(int y=0;y<20;y++){
		map.mapdata[y][x]=mapinfo[y][x];
		}
	}
	return map;
}


//render the map

void RenderMap(struct MAP map,int cellx,int celly){

	for(int x=0;x<20;x++){         
		for(int y=0;y<20;y++){
			if(map.mapdata[y][x]=='#'){DrawRectangle(x*cellx,y*celly,cellx,celly,RED);}
			if(map.mapdata[y][x]=='8'){DrawRectangle(x*cellx,y*celly,cellx,celly,BLACK);}

			//DrawRectangle(x*cellx,y*celly,cellx,celly,RED);
		}
	}
}