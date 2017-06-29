/*
 * Main.java
 *  java program model for www.programming-challenges.com
 */

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
    public void run(){
    	String input;	//사용자에게 입력기 위한 변
    	int M, N;   //사용자에게 입력받을 지뢰밭의 크기(배열의 크기)
        int FieldNum=0;     //각 지뢰밭에 대한 필드 번호
        
        input=Main.ReadLn(100000);
        StringTokenizer stk = new StringTokenizer(input," ");
        M = Integer.parseInt(stk.nextToken());
        N = Integer.parseInt(stk.nextToken());

        
        while(M!=0&&N!=0){
            FieldNum++;
            System.out.println("Field #"+FieldNum+":");
            
            char array[][] = new char[M][N];//배열 생성
            
            /*사용자가 입력하는 값을 배열에 대입*/
            for(int i = 0 ; i <M ; i++){
            	input=Main.ReadLn(100000);
                for(int j = 0 ; j < N ; j++){
                    array[i][j]=input.charAt(j);
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
                                    }
                                }
                            }
                            System.out.print(count);
                    }
                    else
                    	System.out.print("*");
                }
                System.out.println();
            }
            input=Main.ReadLn(100000);
            stk = new StringTokenizer(input," ");
            M = Integer.parseInt(stk.nextToken());
            N = Integer.parseInt(stk.nextToken());
            
            if(M!=0&&N!=0)
            	System.out.println();
        }
        
    }
    
    // You can insert more classes here if you want.
}