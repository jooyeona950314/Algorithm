//
//  main.cpp
//  C++
//
//  Created by 박주연 on 2017. 7. 5..
//  Copyright © 2017년 박주연. All rights reserved.
//

/* 문제 : 한 친구가 방금 새 컴퓨터를 샀다. 그 친구가 지금까지 샀던 가장 강력한 컴퓨터는 공학용 전자 계산기였다. 그런데 그 친구는 새 컴퓨터의 모니터보다 공학용 계산기에 있는 LCD 디스플레이가 더 좋다며 크게 실망하고 말았다. 그 친구를 만족시킬 수 있도록 숫자를 LCD 디스플레이 방식으로 출력하는 프로그램을 만들어보자.
 
 문제 해결 :
 1. 배열을 만든다
 2. 입력받은 숫자에 따라서 배열에 추가한다.
 3. 배열 전체를 출력한다.
 */

#include <iostream>
using namespace std;

void segment1(int s, int at);
void segment2(int s, int at);
void segment3(int s, int at);
void segment4(int s, int at);
void segment5(int s, int at);
void segment6(int s, int at);
void segment7(int s, int at);

int main(int argc, const char * argv[]) {
    int s=0;                //s: 숫자를 표시하는 크기
    string inputNum="";     //inputNum: 출력될 숫자
    
    cin >> s >> inputNum;   //s, inputNum을 입력받음
    
    while(s!=0 || inputNum!="0"){
        //배열 생성
        char array[2*s+3][(s+2)*inputNum.length()+inputNum.length()-1];
        
        for(int i = 0 ; i < inputNum.length();i++){
            switch (inputNum.at(i)) {
                case '0':
                    break;
                    
                default:
                    break;
            }
        }
        
        cin >> s >> inputNum;
    }
    
}
