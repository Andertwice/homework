 #include <stdio.h>
 #include <stdlib.h>
 #include <ctype.h>
 #include <String.h>
 int main(int argc, char *argv[])
 {
     
     if( argc == 3 ){
         
         //尝试读取文件的内容
         char data;
         FILE *fp = fopen(argv[2],"r");
         
         if(!fp){
             printf("错误：文件读取失败\n");
             return -1;
         }        
         
         //对参数进行判断
         
         
         if( !strcmp(argv[1],"-c") ){//字符数
             char temp;
             int num = 0;
             temp = fgetc(fp);
             while( temp != EOF ){
                 temp = fgetc(fp);
                 num++;
             }
             printf("该文本文件的字符数为：%d\n",num);
             
         }
         else if( !strcmp(argv[1],"-w") ){//单词数
             int w = 0;
             char a = fgetc(fp);
             while( a != EOF){
                 if( (a >='a' && a <='z') || ( a >='A' && a <='Z') || ( a >='0' && a <='9') ){
                     while( (a >='a' && a <='z') || ( a >='A' && a <='Z') || ( a >='0' && a <='9') )
                         a =fgetc(fp);
                     w++;
                     a =fgetc(fp);
                     
                 }
                 else
                     a =fgetc(fp);
             }
             printf("该文本文件的单词数为：%d\n",w);
             
         }
         else if( !strcmp(argv[1],"-l") ){//行数
             char temp;
             int num = 1;
             temp = fgetc(fp);
             while( temp != EOF ){
                 
                 //putchar(temp);
                 if(temp == '\n'){//字符需要用单引号扩住
                     num++;
                 }
                 temp = fgetc(fp);
                 
                 
             }
             printf("该文本文件的行数为：%d\n",num);
     
         }
         else{
             printf("错误：参数超出范围！\n");
             printf("允许参数：-c，-w，-l\n");
         }
         int n=fclose(fp);
     }
     else{
         printf("错误：运行参数必须要3个\n");
         printf("用法：wordcount.exe [parameter] [file_name]\n");
     }
     system("pause");
     return 0;
 }