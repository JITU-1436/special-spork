#include"header.h"
int test1( char *argv )
{
	int i = 0 , j;
	DIR *ptr;
	int *name , max;
	char ch[30];
	struct dirent *a;
	ptr = opendir("/home/ubuntu/pictures");
	if(!ptr)
	{
		perror("opendir");
		goto OUT;
	}
	name = (int *)malloc(sizeof(int));
	if(!name)
	{
		perror("malloc");
		goto OUT;
	}
	while(1)	
	{
		a = readdir(ptr );
		if(a == NULL)
			break;
		name[i] = atoi(a->d_name);
		printf("i : %d\n",i);
		name = realloc( name , (i*8)+16);
		if(!name)
		{
			perror("realloc");
			goto OUT;
		}
		i++;
	}
	max = name[0];
	for(j = 0 ; j < (i-1) ; j++)
	{
		if(max < name[j+1])
			max = name[j+1];
	}
	printf("%d\n",max);
	printf("%s\n",argv);
	sprintf(ch, "%s%d%s" , "/home/ubuntu/pictures/",(max+1),".jpeg");
	printf("%s\n",ch);
	rename(argv, ch);	
	return 0;
OUT:
	return -1;
}
