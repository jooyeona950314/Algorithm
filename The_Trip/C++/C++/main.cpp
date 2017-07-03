//
//  main.cpp
//  C++
//
//  Created by 박주연 on 2017. 7. 3..
//  Copyright © 2017년 박주연. All rights reserved.
//

/* 문제 : 일 년에 한 번씩 다른 여행지로 여행을 가는 학생 모임이 있다. 이번 봄에는 아인트호벤으로 여행을 갈 계획이다.
 
    이 학생들은 여행 경비를 모두 똑같이 부담하기로 합의했지만 돈을 쓸 때마다 나너서 내는 것은 별로 실용적이지 못하다. 그래서 한 명씩 식비, 호텔비, 택시비, 비행기표를 부담하기로 한다.
    여행이 끝난 후에 각 학생이 지출한 내역을 계산한 다음 1신트 단위 내에서 모든 학생들이 쓴 돈이 같도록 돈을 주고 받는다.
    지출 내역이 주어졌을 때 모든 학생이 쓴 돈이 (1센트 단위 내에서) 똑같아지기 위해 전달되어야 하는 최소 액수를 구해보자.
 
 
 문제 해결 방법
 
 1. 학생 수를 입력받음.
 2. 학생들이 지불한 값을 입력받음.
 3. 모든 학생이 지불한 값의 평균값을 구함.
 4. 평균값 이하로 지불한 학생들을 선발하여 평균값에서 그 학생들이 지불한 금액의 차액을 모두 합산
 */

#include <cmath>
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int studentNum;
    
    cin >> studentNum;
    
    while(studentNum!=0)
    {
        float average=0.0;
        float array[studentNum];
        
        for(int i = 0 ; i < studentNum; i++){
            cin >> array[i];
            average+=array[i];
        }
        
        
        average=(int)(average/studentNum);
        
        float sum=0.0;
        for(int i = 0 ; i < studentNum ; i++){
            if(array[i]<average){
                sum+=average-array[i];
            }
        }
        
        cout<<fixed;         //소수점 고정
        cout.precision(2);
        
        cout << "$" << sum << endl;
        
        cin >> studentNum;
    }
    return 0;
}
