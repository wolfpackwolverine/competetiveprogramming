#include<bits/stdc++.h>
using namespace std;
#define MAX_N 100005
int reset[MAX_N];

void KMPpreprocessor(string pat){
    int i=0,j=-1;
    reset[0]=-1;
    while(i<pat.size()){
        //check
        while(j>=0 && pat[i]!=pat[j]){
            j=reset[j];
        }
        i++;j++;
        reset[i]=j;
    }
}

int KMPsearchg(string str, string pat){
    KMPpreprocessor(pat);
    int i=0,j=0,ans=0;
    while(i<str.size()){
        while(j>=0 && str[i]!=pat[j]){
            j=reset[j];
        }
        i++;j++;
        if(j==pat.size()){
            ans++;
            j=reset[j];
        }
    }
    return ans;
}

int main(){
    memset(reset,-1,sizeof(reset)); 
    string str,pat;
    cin>>pat>>str;
    cout<<KMPsearchg(str,pat);
    return 0;
}