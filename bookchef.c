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
int c2 (const void * a, const void * b)
{

  normal *oA = (normal *)a;
  normal *oB = (normal *)b;

  return ( oB->p - oA->p );
}
int main(){
	int n,m,ret,j=-1,k=-1,f;
	scanf("%d %d",&n,&m);
	int a[n];
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
			ss[++j].f=f;
			scanf("%d %s",&ss[j].p,ss[j].s);
		}
		else{

			sn[++k].f=f;
			scanf("%d %s",&sn[k].p,sn[k].s);
		}			
	}
	
	//sort p and other
	qsort (ss, j, sizeof(spec), compare);
	for (int i=0;i<=j;i++){
		printf("%s\n",ss[i].s);
	}
	//sort p and others
	qsort (sn, k, sizeof(normal), c2);
	for (int i=0;i<=k;i++){
		printf("%s\n",sn[i].s);
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
