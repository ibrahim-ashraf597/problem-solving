int mul(int x,int y) {
    return ((x%M)*(y%M))%M;
}

int add(int x,int y) {
    return ((x%M)+(y%M))%M;
}
int clc(int n,int bit) {
    int tot=(1LL<<(bit+1));
    int ans=mul(n/tot,1LL<<bit);
     n%=tot;
    ans=add(ans,max(0LL,n-(1LL<<bit)));
    return ans;
}
