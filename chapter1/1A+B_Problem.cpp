// 1:A+B Problem
// 查看 提交 统计 提问
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// Calculate a + b

// 输入
// Two integer a,,b (0 ≤ a,b ≤ 10)
// 输出
// Output a + b
// 样例输入
// 1 2
// 样例输出
// 3
// 提示
// Q: Where are the input and the output?

// A: Your program shall always read input from stdin (Standard Input) and write output to stdout (Standard Output). For example, you can use 'scanf' in C or 'cin' in C++ to read from stdin, and use 'printf' in C or 'cout' in C++ to write to stdout.

// You shall not output any extra data to standard output other than that required by the problem, otherwise you will get a "Wrong Answer".

// User programs are not allowed to open and read from/write to files. You will get a "Runtime Error" or a "Wrong Answer" if you try to do so. 

// Here is a sample solution for problem 1000 using C++/G++:

// #include <iostream>
// using namespace std;
// int  main()
// {
//     int a,b;
//     cin >> a >> b;
//     cout << a+b << endl;
//     return 0;
// }

// It's important that the return type of main() must be int when you use G++/GCC,or you may get compile error.

// Here is a sample solution for problem 1000 using C/GCC:

// #include <stdio.h>

// int main()
// {
//     int a,b;
//     scanf("%d %d",&a, &b);
//     printf("%d\n",a+b);
//     return 0;
// }

// Here is a sample solution for problem 1000 using PASCAL:

// program p1000(Input,Output); 
// var 
//   a,b:Integer; 
// begin 
//    Readln(a,b); 
//    Writeln(a+b); 
// end.

// Here is a sample solution for problem 1000 using JAVA:

// Now java compiler is jdk 1.5, next is program for 1000

// import java.io.*;
// import java.util.*;
// public class Main
// {
//             public static void main(String args[]) throws Exception
//             {
//                     Scanner cin=new Scanner(System.in);
//                     int a=cin.nextInt(),b=cin.nextInt();
//                     System.out.println(a+b);
//             }
// }

// Old program for jdk 1.4

// import java.io.*;
// import java.util.*;

// public class Main
// {
//     public static void main (String args[]) throws Exception
//     {
//         BufferedReader stdin = 
//             new BufferedReader(
//                 new InputStreamReader(System.in));

//         String line = stdin.readLine();
//         StringTokenizer st = new StringTokenizer(line);
//         int a = Integer.parseInt(st.nextToken());
//         int b = Integer.parseInt(st.nextToken());
//         System.out.println(a+b);
//     }
// }
// 来源
// POJ

#include<iostream>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    cout << a + b << endl;
    return 0;
}