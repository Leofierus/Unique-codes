#include<stdio.h>
#include<math.h>
void print(float a[20][20],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<=n;j++)
		{
			printf("%10.4f \t",a[i][j]);
		}
		printf("\n");
	}
}
float operation(float m[20][20],int i,int n)
{
	float tmp[20][20];
	float max=fabs(m[i][i]);
	int j,k=i;
	for(j=i;j<n;j++)
	{
		if(max<fabs(m[j][i]))
		{
		    max=fabs(m[j][i]);
			k=j;
		}
	}
	for(j=0;j<=n;j++)
	{
		tmp[i][j]=m[i][j];
		m[i][j]=m[k][j];
		m[k][j]=tmp[i][j];
	}
	return m[20][20];
}
float zero(float m[20][20],int i,int n)
{
	float tmp;
	int k=1,l,j;
	for(j=i;j<n-1;j++)
	{
		tmp=-((m[i+k][i])/(m[i][i]));
		for(l=0;l<=n;l++)
		{
			m[i+k][l]=(m[i+k][l])+(m[i][l]*tmp);
		}
		k++;
	}
	return m[20][20];
}
int main()
{
	int i,j,n,k=0,l;
	float m[20][20],mul,tmp[20][20],val,ans[20];
	printf("Total No.of Equations : ");
	scanf("%d",&n);
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("Enter Co-efficient(s) Of Equation %d & Total --->>>\n",i+1);
		for(j=0;j<=n;j++)
		{
	    	printf("r%d%d : ",i,j);
			scanf("%f",&m[i][j]);
		}
		printf("\n");
	}
	system("cls");
	printf(":::::::::::: Current Matrix ::::::::::::\n\n");
	print(m,n);
	for(i=0;i<n-1;i++)
	{
		printf("\n------->>>>>>>>>>>>>>>>>>>>>>>>-------- %d\n",i+1);
		m[20][20]=operation(m,i,n);
		print(m,n);
		printf("\n_______________________________________\n");
		m[20][20]=zero(m,i,n);
		print(m,n);
	}
	printf("\n\n Values are : \n");
	for(i=n-1;i>=0;i--)
	{
		l=n-1;
		mul=0;
		for(j=0;j<k;j++)
		{
			mul=mul+m[i][l]*ans[l];
			l--;
		}
		k++;
		ans[i]=(m[i][n]-mul)/m[i][i];
		printf("X%d = %.4f\n",i+1,ans[i]);
	}
	return 0;
}
