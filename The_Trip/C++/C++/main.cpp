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
 
 
 문제 해결 방법(본인)
 1. 학생 수를 입력받음.
 2. 학생들이 지불한 값을 입력받음.
 3. 모든 학생이 지불한 값의 평균값을 구함.
 4. 평균값 이상으로 지불한 학생들을 선발하여 그 학생들이 지불한 금액에서 평균값의 차액을 모두 합산
 
 문제 해결 방법(해설지)
 만약 돈의 단위가 센트가 아니여서 어떤 경우에도 사람들이 돈을 똑같이 낼 수 있다고 해보자. 이 경우에는 직관적인 방법으로 해결할 수 있는데, 사람들이 사용한 금액의 평균을 구해 그 평균과 각 사람이 실제 쓴 금액의 차를 구해서 모두 더한 뒤, 그 결과를 2로 나누면 최적의 결과를 구할 수 있다.
 
 다음으로 두번째 입력 데이터를 예로 들어 돈의 단위가 센트인 경우를 생각해보면, 4명이 지불한 금액은 총 $36.02다. 이 금액을 4명에게 센트 단위까지 나누면, 한 사람당 $9.00씩 돌아간다. 그리고 $0.02가 남으므로, 이것을 첫 두 사람에게 $0.01씩 배당하면 이 2명은 총 $9.01가 되고, 나머지 2명은 $9.00가 된다. 이렇게 배당하는 것이 센트 단위까지 고려할 때 가장 공평한 경우다.
 
 그런데 누가 $9.01을 지불할 것인가? 당연히 돈을 가장 많이 냈던 사람에게 순서대로 부담시키는 것이 마땅하다.
 
 모범 답안은, 일단 입력된 금액을 내림차순으로 정렬한 뒤, 돈을 가장 공평하게 부담하기 위해서 각 사람이 내야 하는 금액을 구한 뒤, 이 금액과 실제 지불했던 금액의 차액을 구하고, 이 액수의 총 합을 구해(센트 단위가 항상 짝수인 것이 보장된다), 2로 나누어 출력하는 알고리즘을 사용한다.
 이런 종류의 문제는, 직관적이고 재치있게 생각하는 것이 프로그램 작성보다 더 중요하다.
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
        float sum=0.0;
        int average;
        
        float array[studentNum];
        
        //입력된 금액 내림차순 정렬
        for(int i = 0 ; i < studentNum-1; i++){
            for(int j = i+1; j<studentNum; j++){
                if(array[i] < array[j]){
                    float temp = array[j];
                    array[j] = array[i];
                    array[i] = temp;
                }
            }
        }
        
        for(int i = 0 ; i < studentNum; i++){
            cin>>array[i];
            sum+=(int)(array[i]);
        }
        average = (int)(sum/studentNum);
        
        float spendArray[studentNum];
        
        for(int i = 0 ; i < studentNum; i++){
            spendArray[i]=average;
        }
        
        float answer=0.0;
        for(int i = 0 ; i < studentNum; i++){
            answer+=abs((spendArray[i]-array[i]));   
        }
        
        answer/=2;
        
        cout<<fixed;         //소수점 고정
        cout.precision(2);
        cout << "$" << answer << endl;
        
        cin >> studentNum;
    }
    return 0;
}
