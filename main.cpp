
#include<stdio.h>
#include<memory.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>


//横の長さ
const int WIDTH=16;
//たての長さ
const int HEIGHT=16;
//ランダムの生成回数
const int NUM = 50;

//マップ
int map[HEIGHT][WIDTH];
//八方向ベクトル
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,1,-1,1,-1,-1,1};

//初期化
int init(){
    /*for(int i=0;i<HEIGHT;i++){
        for(int i2=0;i2<WIDTH;i2++){
            map[i][i2]=0;
        }
    }*/
    //上記の意味とほぼ同じ
    memset(map,0,sizeof(map));
    //ランダム用
    for(int i=0;i<NUM;i++){
         //map[rand()%HEIGHT][rand()%WIDTH]=1;
    }
    //ペンタデカスロン
    /*map[5][5]=1;
    map[6][5]=1;
    map[7][5]=1;
    map[6][4]=1;

    map[5][10]=1;
    map[6][10]=1;
    map[7][10]=1;
    map[6][11]=1;
    */
}

//一周期をチェック
void check(){
    //次の周期のmapを用意
    int nextMap[HEIGHT][WIDTH];
    //現在の周期から次の周期にコピーする
    memcpy(nextMap,map,sizeof(map));
    //WIDTH * HEIGHTですべてのマスを調べる
    for(int y=0;y<HEIGHT;y++){
        for(int x=0;x<WIDTH;x++){
            //八方向にある生物をカウントする
            int count=0;
            for(int i3=0;i3<8;i3++){
                if(y+dy[i3]>=0&&y+dy[i3]<HEIGHT && x+dx[i3]>=0 && x + dx[i3]<WIDTH){
                    //もし生きていた場合
                    if(map[y+dy[i3]][x+dx[i3]]){
                        count++;
                    }
                }
                //八方向にある生物の状態から現在のマスの判定を行う
                switch (count)
                {
                    case 2:
                        if(map[y][x]){
                            nextMap[y][x]=1;
                        }
                        break;
                    case 3:
                        nextMap[y][x]=1;
                        break;
                    default:
                        nextMap[y][x]=0;
                        break;
                }
            }
        }
    }
    //次の世代のmapを現在のmapにコピーする
    memcpy(map,nextMap,sizeof(nextMap));
}

//フィールド表示
void print(){
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

int main()
{
    //擬似乱数の発生系列を変更
    srand((unsigned)time(NULL));
    //初期化
    init();

    while(1){
        print();
        //待機
        usleep(500000);
        check();
    }
}