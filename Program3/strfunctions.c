#include<string.h>
#include<stdio.h>
#include<ctype.h>

int myStrStr(char haystack[], char needle[], char buffer[])
{
	int hlen=strlen(haystack);
	int nlen=strlen(needle);

	int temp=0, i=0, j=0, flag=0, x=0, y=0, count1=0, array[30], buff=0;
	while(temp<hlen)
	{
		buffer[temp]=0;
		temp++;
	}

	while(i<hlen)
	{
		if(needle[j]==haystack[i])
		{
			buffer[x]=needle[j];
			j++;
			x++;
			array[buff]=1;
			buff++;		//count of buffer where match occurs
		}
		else
		{
			buffer[x]=0;
			flag=1;
			array[buff]=0;
			buff++;
     		}
		i++;
    	}

	while(y<buff)
	{
		if(array[y]==0)
		count1++;
		y++;
	}

	int g=count1-1;
	if(g==nlen)
	{
		flag=2;			//substring found!
	}

	if(count1==buff)
	flag=2;

	if(flag==0)
	buffer[x]=0;

	if(flag==1 || flag==0)
	return 1;

	if(flag==2)
	return 0;

return 0;
}

void findJediName(char* first, char* last, char buffer[])
{
	int x=0,i=0;
	while(x<3)
	{
		buffer[i]=last[x];
		i++;
		x++;
	}
	x=0;
	while(x<2)
	{
		buffer[i]=first[x];
		i++;
		x++;
	}
}

int findAllJediNames(char * filename, char buffer[50][10])
{
	char * c;
	FILE *fp;
	int read;
	int lastline=0;
	size_t len = 0;
	char * line = NULL;
	fp = fopen("names.txt", "r");
	int noline=0;

    while ((read = getline(&line, &len, fp)) != -1)
	{
		noline++;
	}

	fp = fopen("names.txt", "r");

   while ((read = getline(&line, &len, fp)) != -1)
	{
        c = strtok (line,",");
        char e[4];
        int i;
        int j=0;
        int x=0;
        while (c != NULL)
        {
			if(x==0)
			{
				for(i=0;i<3;i++)
				{
                    buffer[lastline][j]=c[i];
                    j++;
                }
            }
            else if(x==1)
			{
                for(i=0;i<2;i++)
                    {
                        buffer[lastline][j]=tolower(c[i]);
                        j++;
                    }
                    buffer[lastline][j]='\0';
                    lastline++;
			}
            c = strtok (NULL, " ,.-");
            x++;
		}
    }

return lastline;
}

void extraCredit()
{

	char fname[10], lname[10], htown[20];
	printf("\n Please enter first name :");
	scanf("%s", &fname);
	printf("\n Please enter last name :");
	scanf("%s", &lname);
	printf("\n Please enter hometown :");
	scanf("%s", &htown);

	char buffer[40];

	//findJediName(fname, lname, buffer);
	int k,i=0;
	for(k=0;k<3;k++)
	{
		buffer[i]=lname[k];
		i++;
	}

	for(k=0;k<2;k++)
	{
		buffer[i]=fname[k];
		i++;
	}

	int htownlen=strlen(htown);

	char space[]=" ";
	strcat(buffer,space);

	char ian[]="ian";
	strcat(htown,ian);
	strcat(buffer,htown);

//	printf("\n True Jedi Name :%s \n",buffer);

	FILE *fp;
	fp=fopen("jedi.txt","w");
	fprintf(fp,buffer);
	fclose(fp);

}
