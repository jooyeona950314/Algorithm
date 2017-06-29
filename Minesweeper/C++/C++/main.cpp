//
//  main.cpp
//  C++
//
//  Created by 박주연 on 2017. 6. 29..
//  Copyright © 2017년 박주연. All rights reserved.
//

/* 문제 : 지뢰 찾기는 M*N 크기의 지뢰밭에서 모든 지뢰의 위치를 찾아내는 게임이다.
 이 게임에서는 각 칸에 인접한 칸에 몇 개의 지뢰가 있는지를 보여준다. 각 칸에는 최대 여덟 개의 인접한 칸이 있을 수 있다.
 
문제 해결 : 
 1. 사용자가 입력한 값 M, N에 따라 M*N 크기의 2차원 배열 생성
 2. 사용자가 입력하는 값을 배열에 대입
 3. 배열의 값이 '*'인 경우는 아무런 작업을 하지 않음
 4. 배열의 값이 '.'인 경우 해당 배열의 위치의 [x-1, y-1][x-1, y][x-1, y+1][x, y-1][x, y+1][x+1, y-1][x+1, y][x+1, y+1]의 값 중 '*'의 개수를 값으로 바꿈
 5. 모든 배열을 위와 같은 방식으로 끝낼 경우 해당 배열을 출력
 */

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int M, N;   //사용자에게 입력받을 지뢰밭의 크기(배열의 크기)
    int FieldNum=0;     //각 지뢰밭에 대한 필드 번호
    cin >> M >> N;

    while(M!=0&&N!=0){
        FieldNum++;
        cout << "Field #"<<FieldNum<<":"<<endl;
        char array[M][N];   //배열 생성
        for(int i = 0 ; i <M ; i++){
            for(int j = 0 ; j < N ; j++){
                array[i][j]='0';
            }
        }
    
        /*사용자가 입력하는 값을 배열에 대입*/
        for(int i = 0 ; i <M ; i++){
            for(int j = 0 ; j < N ; j++){
                cin >> array[i][j];
            }
        }
    
        /*배열의 값을 판단 후 지뢰 갯수 찾기*/
        for(int i = 0 ; i <M ; i++){
            for(int j = 0 ; j < N ; j++){
                if(array[i][j]=='.') {
                
                        int count = 0;
                        for(int k=-1; k<2; k++){
                            for(int l=-1; l<2; l++){
                                if(i+k>=0 && i+k<M && j+l>=0 && j+l<N && array[i+k][j+l]=='*'){
                                    count++;
                                //cout << "count add!" << endl;
                                }
                            }
                        }
                        cout << count;
                }
                else
                    cout << "*";
            }
            cout << endl;
        }
        cin >> M >> N;
        
        if(M!=0&&N!=0)
            cout << endl;
    }
    return 0;
}
