//set many funcs template
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#define inf 1072114514
#define llinf 4154118101919364364
#define mod 1000000007
#define pi 3.1415926535897932384

int max(int a,int b){if(a>b){return a;}return b;}
int min(int a,int b){if(a<b){return a;}return b;}
int zt(int a,int b){return max(a,b)-min(a,b);}
int round(int a,int b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
int ceil(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}
int gcd(int a,int b){int c;while(b!=0){c=a%b;a=b;b=c;}return a;}
int lcm(int a,int b){int c=gcd(a,b);a/=c;return a*b;}
int nCr(int a,int b){int i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
int fact(int a){int i,r=1;for(i=1;i<=a;i++){r*=i;}return r;}
int pow(int a,int b){int i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}
long long llmax(long long a,long long b){if(a>b){return a;}return b;}
long long llmin(long long a,long long b){if(a<b){return a;}return b;}
long long llzt(long long a,long long b){return llmax(a,b)-llmin(a,b);}
long long llround(long long a,long long b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
long long llceil(long long a,long long b){if(a%b==0){return a/b;}return (a/b)+1;}
long long llgcd(long long a,long long b){long long c;while(b!=0){c=a%b;a=b;b=c;}return a;}
long long lllcm(long long a,long long b){long long c=llgcd(a,b);a/=c;return a*b;}
long long llnCr(long long a,long long b){long long i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
long long llfact(long long a){long long i,r=1;for(i=1;i<=a;i++){r*=i;}return r;}
long long llpow(long long a,long long b){long long i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}
double dbmax(double a,double b){if(a>b){return a;}return b;}
double dbmin(double a,double b){if(a<b){return a;}return b;}
double dbzt(double a,double b){return dbmax(a,b)-dbmin(a,b);}
int sortfncsj(const void *a,const void *b){if(*(int *)a>*(int *)b){return 1;}if(*(int *)a==*(int *)b){return 0;}return -1;}
int sortfnckj(const void *a,const void *b){if(*(int *)a<*(int *)b){return 1;}if(*(int *)a==*(int *)b){return 0;}return -1;}
int llsortfncsj(const void *a,const void *b){if(*(long long *)a>*(long long *)b){return 1;}if(*(long long *)a==*(long long *)b){return 0;}return -1;}
int llsortfnckj(const void *a,const void *b){if(*(long long *)a<*(long long *)b){return 1;}if(*(long long *)a==*(long long *)b){return 0;}return -1;}
int dbsortfncsj(const void *a,const void *b){if(*(double *)a>*(double *)b){return 1;}if(*(double *)a==*(double *)b){return 0;}return -1;}
int dbsortfnckj(const void *a,const void *b){if(*(double *)a<*(double *)b){return 1;}if(*(double *)a==*(double *)b){return 0;}return -1;}
int strsortfncsj(const void *a,const void *b){return strcmp((char *)a,(char *)b);}
int strsortfnckj(const void *a,const void *b){return strcmp((char *)b,(char *)a);}

typedef struct{
int single;
int score;
}smem;

int sortfnc(const void *a,const void *b){
if(((smem*)a)->single > ((smem*)b)->single){return 1;}
if(((smem*)a)->single < ((smem*)b)->single){return -1;}
if(((smem*)a)->score > ((smem*)b)->score){return 1;}
if(((smem*)a)->score < ((smem*)b)->score){return -1;}
return 0;
}

int main(void){
    int pt=0,fl[262144]={0},mid=-inf,nn,i,j,n,m,k,a[262144],b,c[262144]={0},w,r=0,l,t,id,bw;
    double d;
    char s[262144];
    smem dt[262144];
    scanf("%s",s);
    l=strlen(s);
    if(s[0]=='1'){printf("-1\n");return 0;}
    if(s[l-1]=='1'){printf("-1\n");return 0;}
    id=1;bw=0;a[0]=1;
    mid=max(mid,id);
    for(i=1;i<l;i++){
        nn=s[i]-'0';
        if(bw==nn){
            if(nn==1){id--;}
            else{id++;}
        }
        a[i]=id;
        if(id<=0){printf("-1\n");return 0;}
        bw=nn;
        mid=max(mid,id);
    }
    if(mid!=a[l-1]){printf("-1\n");return 0;}
    for(i=0;i<l;i++){
        dt[i].single=a[i];
        dt[i].score=i;
        fl[a[i]]=s[i]-'0';
        c[a[i]]++;
    }
    for(i=1;i<=mid;i++){
        if(fl[i]){printf("-1\n");return 0;}
    }
    qsort(dt,l,sizeof(smem),sortfnc);
    printf("%d\n",mid);
    for(i=1;i<=mid;i++){
        printf("%d",c[i]);
        for(j=0;j<c[i];j++){printf(" %d",1+dt[pt].score);pt++;}
        printf("\n");
    }
    return 0;
}