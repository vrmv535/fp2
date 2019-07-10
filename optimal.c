#include <stdio.h>
#include <stdlib.h>

int f[100],ip[100]; 
int n,frames;
int delete[100];

int is_in(int page){
	int i;
	for(i=0;i<frames;i++){
		if(f[i]==page){
			return i;
		}
	}
	return -1;
}

void fifo(){

	int i,j,k;
	int hit=0,miss=0;
	j=0;
	for(i=0;i<n;i++){
		if(is_in(ip[i])>-1){
			hit++;
		}else{
			f[j]=ip[i];
			j=(j+1)%frames;
			miss++; 
		}
	}
	printf("Using FIFO algorithm :\n\tHits = %d,Misses = %d\n",hit,miss);
}


void optimal(){
	int i,j,k;
	int hit=0,miss=0;
	int count=0,place = -1;
	for(i=0;i<n;i++){
		if(is_in(ip[i])>-1){
			hit++;
			printf("Hit for %d\n",ip[i]);
		}
		else
		{
			printf("Miss for %d\n",ip[i]);
			miss++;
			count = 0;
			for(j=0;j<frames;j++){
				delete[j]=-1;
			}
			for(j=i+1;j<n && count<frames-1;j++){
				place = is_in(ip[j]);
				if(place != -1){
					delete[place]=0;
					count++;
				}
			}

			for(j=0;j<frames;j++){
				if(delete[j]==-1){
					f[j]=ip[i];
					break;
				}
			}

		}
	}
	printf("Using optimal algorithm :\n\t Hits = %d, Misses = %d\n",hit,miss);
}

void lru(){
	int i,j,k;
	int hit=0,miss=0;
	int count=0,place = -1;
	for(i=0;i<n;i++){
		if(is_in(ip[i])>-1){
			hit++;
			printf("Hit for %d\n",ip[i]);
		}
		else
		{
			printf("Miss for %d\n",ip[i]);
			miss++;
			count = 0;
			for(j=0;j<frames;j++){
				delete[j]=-1;
			}
			for(j=i-1;j>=0&&count<frames-1;j--){
				place = is_in(ip[j]);
				if(place != -1){
					delete[place]=0;
					count++;
				}
			}

			for(j=0;j<frames;j++){
				if(delete[j]==-1){
					f[j]=ip[i];
					break;
				}
			}

		}
	}
	printf("Using LRU algorithm :\n\t Hits = %d, Misses = %d\n",hit,miss);
}





int main()
{
	int i,j,k;
	printf("enter the number of frames and pages to rfer\n");
	scanf("%d %d",&frames,&n);
	printf("enter %d pages\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&ip[i]);
	}
	for(i=0;i<frames;i++){
		f[i]=-1;
		delete[i]=-1;
	}
	fifo();
	for(i=0;i<frames;i++){
		f[i]=-1;
		delete[i]=-1;
	}
	optimal();
	for(i=0;i<frames;i++){
		f[i]=-1;
		delete[i]=-1;           //resretting the frames after each operation
	}
	lru();
}
