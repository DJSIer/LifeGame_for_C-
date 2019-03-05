#include<iostream>
#include<memory.h>
using namespace std;

//横の長さ
const int WIDTH=16;
//たての長さ
const int HEIGHT=16;

//マップ
int map[HEIGHT][WIDTH];

int main()
{
 
    //sizeof(int)=4 16*16*4=1024
    memset(map,0,sizeof(map));
    
    map[10][10]=1;
    //エスケープシーケンス 
    printf("\e[2\e[2J");
    for(int i=0;i<HEIGHT;i++){
        printf("|");
        for(int i2=0;i2<WIDTH;i2++){

            if(map[i][i2]){
                printf("■");
            }
            else{
                printf("□");
            }
            printf("|");
        }
        printf("\n");
    }
}