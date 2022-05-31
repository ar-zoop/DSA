#include <stdio.h>
#include <stdlib.h>

int bin_search(int,int,int[]);

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

typedef struct special_friends{
	int f;
	int p;
	char s[100];
}spec;

typedef struct normal_friends{
	int f;
	int p;
	char s[100];
}normal;

//qsort for spec structure
int compare (const void * a, const void * b)
{

  spec *orderA = (spec *)a;
  spec *orderB = (spec *)b;

  return ( orderB->p - orderA->p );
}

//qsort for normal structure
int compare2 (const void * a, const void * b)
{

  normal *orderA = (normal *)a;
  normal *orderB = (normal *)b;

  return ( orderB->p - orderA->p );
}
int main(){
	int n,m,ret,j=-1,k=-1,f;
	scanf("%d %d",&n,&m);
	int a[n];
//	spec_f[m],normal_f[m],spec_p[m],normal_p[m];
//	char spec_s[m][100],normal_s[m][100];
	spec ss[m];
	normal sn[m];
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	//sorting special friends list
	qsort(a, n, sizeof(int), cmpfunc);
	for (int i=0;i<m;i++){
		scanf("%d",&f);
		ret=bin_search(f,n,a);
		if(ret==1){
//			spec_f[++j]=f;
			ss.f[++j]=f;
			scanf("%d %s",&ss.p[j],&ss.s[j]);
		}
		else{
//			normal_f[++k]=f;
			sn.f[++k]=f;
			scanf("%d %s",&sn.p[k],&&sn.s[k]);
		}			
	}
	//sort p and other
	for (int i=0;i<=j;i++){
		printf("%s\n",ss.s[i]);
	}
	//sort p and others
	for (int i=0;i<=k;i++){
		printf("%s\n",sn.s[i]);
	}
	return 0;
}

int bin_search(int ele,int high,int arr[]){
	int mid,low=0;
	while(low<=high)
	    {
	        mid=(low+high)/2;
	        if(arr[mid]==ele)
	        {
	            return 1;
	        }
	        else if(arr[mid]>ele)
	          high=mid-1;
	        else
	            low=mid+1;
	    }
	    if(low>high)
	        return 0;
}
