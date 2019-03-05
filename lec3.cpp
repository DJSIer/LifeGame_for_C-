#include<iostream>
#include<memory.h>
using namespace std;

//横の長さ
const int WIDTH=16;
//たての長さ
const int HEIGHT=16;

//マップ
int map[HEIGHT][WIDTH];

//八方向に何個生存しているマスがあるかを保持
int counterMap[HEIGHT][WIDTH];

//八方向ベクトル
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,1,-1,1,-1,-1,1};

int main()
{
    //sizeof(int)=4 16*16*4=1024
    memset(map,0,sizeof(map));
    memset(counterMap,0,sizeof(counterMap));

    //適当なマスに生存を設置
    map[2][1]=1;
    map[2][2]=1;
    map[2][3]=1;
    //map[3][2]=1;

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
    for(int i=0;i<HEIGHT;i++){
        for(int i2=0;i2<HEIGHT;i2++){
            int count=0;
            int x=i2;
            int y=i;
            //八方向を調べる
            //x+dx[0],y+dy[0]でmap[y+0][x+1]つまり右横
            //x+dx[1],y+dy[1]でmap[y+0][x-1]つまり左横
            //・・・
            //x+dx[7],y+dy[7]でmap[y+1][x-1]左下斜め
            for(int i3=0;i3<8;i3++){
                if(x + dx[i3] >=0 && x + dx[i3]<WIDTH){
                    if(y + dy[i3] >= 0 && y + dy[i3] <HEIGHT){
                        if(map[y+dy[i3]][x+dx[i3]]!=0){
                            counterMap[y][x]++;
                        }
                    }
                    /*if(map[i+1][i2]==1){
                        counterMap[i][i2]++;
                    }
                    if(map[i-1][i2]==1){
                        counterMap[i][i2]++;
                    }*/
                }
            }
        }
    }
    for(int i=0;i<HEIGHT;i++){
        for(int i2=0;i2<WIDTH;i2++){
            if(counterMap[i][i2]<=1){
                map[i][i2]=0;
            }
            if(map[i][i2]==0 && counterMap[i][i2]==3){
                map[i][i2]=1;
            }
            if(counterMap[i][i2]>=4){
                map[i][i2]=0;
            }
        }
    }

    for(int i=0;i<HEIGHT;i++){
        printf("|");
        for(int i2=0;i2<WIDTH;i2++){
            printf("%d",counterMap[i][i2]);
            printf("|");
        }
        printf("\n");
    }
        //エスケープシーケンス 
    //printf("\e[2\e[2J");
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