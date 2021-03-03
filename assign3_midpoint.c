#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void writeFile(int point[1025][1025])
{
    FILE *fo = NULL; 
    fo = fopen("result.txt","w");
    for (int i = 1; i < 1025;i++)
    {
        for (int j = 1; j < 1025;j++)
        {
            fprintf(fo,"%d",point[i][j]);
            if (j == 1024)
            {
                fprintf(fo,"\n");
            }
        }
    }
    fclose(fo);
}

void midLine(int x1, int y1, int x2, int y2, int point[1025][1025])
{
  int dx=abs(x2-x1);
  int dy=abs(y2-y1);
  int d = 0;
  int sx = x1 < x2 ? 1 : -1;
  int sy = y1 < y2 ? 1 : -1;
  int dx2 = 2*dx;
  int dy2 = 2*dy;
  int x=x1;
  int y=y1;
  if (dx >= dy)
  {
    while (1)
    {
      point[1025-y][x] = 1;
      if (x == x2)
      {
        break;
      }
      x = x + sx;
      d = d + dy2;
      if (d > dx)
      {
        y = y + sy;
        d = d - dx2;
      }
    }
  }
  else
	{
		while(1)
		{
		  point[1025-y][x] = 1;
			if(y == y2)
			{
				break;				
			}
			y = y + sy;
			d = d + dx2;
			if(d > dy)
			{
			  x = x + sx;
			  d = d - dy2;
			}
		}
	}
}

int main()
{
    int x1[10000],x2[10000],y1[10000],y2[10000];
    int count = 0;
    int point[1025][1025] = {0};
    FILE *fp = NULL;
    // time calculator (start)
    clock_t start, end;
    float seconds;
    start = clock();
    // open file
    fp = fopen("10000Lines_Case1.txt","r");
    if (fp == NULL)
    {
        printf("Error in reading file");
        exit(1);
    }
    // read file
    while (!feof(fp))
    {
        fscanf(fp,"%d %d %d %d",&x1[count],&y1[count],&x2[count],&y2[count]);
        count++;
    }
    fclose(fp);
    for (int i = 0; i<count;i++)
    {
      midLine(x1[i],y1[i],x2[i],y2[i],point);
    }
    // write output file
    writeFile(point);

    // time calculator (stop)
    end = clock();
    seconds = end - start;
    seconds /= CLOCKS_PER_SEC;
    printf("%lf\n", seconds);

    return 0;
}