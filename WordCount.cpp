#include <stdio.h>
#include <string.h>
int main (int argc, char *argv[])
{
    // argc 表示参数个数, *argv[]指针数组, 每一个指针指向一个字符串
    FILE *fp;
    int count = 0; // 统计数
    if ((fp=fopen(argv[2], "r")) == NULL)
    {
        puts("error!\n");
        return 0;
    }
    else{
		if (argv[1][1] == 'a') 
	    {
	        char str[1024];
	        while(fscanf(fp,"%s",str)!=EOF){
				count++;
				 for (int i = 1; i < strlen(str) - 1; i ++)
					if (str[i] == ',' && str[i - 1] != ',' && str[i + 1] != ',') 
					 count ++;//TODO
			};	
			printf("单词数=%d\n", count);  
	    }
	    else if (argv[1][1] == 'b')
	    {
	        char c;
	        while ((c = fgetc(fp)) != EOF) count ++;
	        printf("字符数=%d", count);
	    }
		} 
    
    fclose(fp);
    return 0;
}
