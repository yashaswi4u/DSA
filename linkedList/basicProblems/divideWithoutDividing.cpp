#include<iostream>
#include<limits.h>
#include<math.h>
using namespace std;
int divide(int p,int k){
int sign=((p<0)^(k<0))?-1:1;
int res;
int final=0;
int n=abs(p);
int d=abs(k);
while(n>=d){
    int count=0;
    int result;
    
    while(n>=d<<(count)){
        count++;
    }
    count--;
     result =d<<count;
        final+=1<<count;
        n=n-result;
}
if(final>=pow(2,31) && sign==1){
    return INT_MAX;
}
else if(final>=pow(2,31) && sign==-1){
    return INT_MAX;
}
final=sign*final;
 return final;
}
int main(){
    int devisor=3;
    int devident=22;
    int res=divide(devident,devisor);
    cout<<res;
}