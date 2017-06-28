//
//  main.cpp
//  java
//
//  Created by 박주연 on 2017. 6. 28..
//  Copyright © 2017년 박주연. All rights reserved.
//

/* 문제 : 어떤 정수 n에서 시작해 n이 짝수면 2로 나누고, 홀수면 3을 곱한 다음 1을 더한다.
 이렇게 해서 새로 만들어진 숫자를 n으로 놓고 n=1이 될때까지 같은 작업을 계속 반복한다.
 n이라는 값이 입력되었을 때 1이 나올 때까지 만들어진 수의 개수(1 포함)를 n의 사이클 길이라고 한다.
 i와 j라는 두 개의 수가 주어졌을 때 i와 j 사이의 모든 수(i,j 포함)에 대해 최대 사이클 길이를 구하라.
 
 문제 해결 방법
 
 1. 2개의 수 i와 j를 입력받음
 2. i의 값을 n에 대입
 3. n이 j와 작거나 같은지 판단
 4. n이 짝수인지 홀수인지 판단
 짝수일 경우 2로 나눔
 홀수일 경우 3을 곱한 후 1을 더함
 5. 연산한 값을 n에 대입 후 사이클 길이를 1만큼 증가
 6. n이 1이 될때까지 위의 코드를 반복한 후 1이 되면 최대 사이클 길이와 비교 후 더 클경우 최대 사이클 길이에 사이클 길이 대입
 7. 위의 코드를 i부터 j까지 반복
 
 */

import java.io.*;
import java.util.*;


class Main implements Runnable{
    static String ReadLn(int maxLength){  // utility function to read from stdin,
                                          // Provided by Programming-challenges, edit for style only
        byte line[] = new byte [maxLength];
        int length = 0;
        int input = -1;
        try{
            while (length < maxLength){//Read untill maxlength
                input = System.in.read();
                if ((input < 0) || (input == '\n')) break; //or untill end of line ninput
                line [length++] += input;
            }

            if ((input < 0) && (length == 0)) return null;  // eof
            return new String(line, 0, length);
        }catch (IOException e){
            return null;
        }
    }

    public static void main(String args[])  // entry point from OS
    {
        Main myWork = new Main();  // Construct the bootloader
        myWork.run();            // execute
    }

    public void run() {
        new myStuff().run();
    }
}
class myStuff implements Runnable{
	int MAX_CYCLE_LENGTH = 0;
    public void run(){

    	int i=0, j=0;    // 사용자에게 입력받을 두 수
    	String input;
    	
        while ((input=Main.ReadLn(100000))!=null) {
        	StringTokenizer stk = new StringTokenizer(input," ");
        	i = Integer.parseInt(stk.nextToken());
        	j = Integer.parseInt(stk.nextToken());
        	if(i < j){
                cycleLengthFunc(i, j);                
            }else{
                cycleLengthFunc(j, i);
            }
            System.out.println(i+" "+j+" "+MAX_CYCLE_LENGTH);
            MAX_CYCLE_LENGTH=0;
    }
    

        }
    
    // You can insert more classes here if you want.
        void cycleLengthFunc(int i, int j){
            int cycleLength = 0;    //n에 대한 사이클 수
            
            for(i=i; i <= j; i++){
                int n = i;
                while(n!=1){
                    if(n%2==0){
                        n=(n/2);
                    }else{
                        n=(n*3+1);
                    }
                    cycleLength++;
                }
                cycleLength++;
                
                if(cycleLength>=MAX_CYCLE_LENGTH)
                    MAX_CYCLE_LENGTH=cycleLength;
                cycleLength = 0;
            }
            //return MAX_CYCLE_LENGTH;
        }
}
