#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

int main() {
    int n;
    cin>>n;
    int M[366];
    int F[366];
    memset(M, 0, sizeof(int)*366);
    memset(F, 0, sizeof(int)*366);

    for(int i = 0; i < n; i++) {
        int b, e;
        char s;
        cin>>s;
        cin>>b>>e;
        
        for(int j = b-1; j < e; j++) {
            if(s=='M')
                M[j]++;
            else
                F[j]++;
        }
    }
    int max = 0;
    for(int i = 0; i < 366; i++) {
        int m = 0;
        if(M[i]>0 && F[i]>0) {
            m = (M[i]<F[i])?M[i]:F[i];
        }
        if(max<m) {
            max = m;
        }
    }

    cout<<max*2<<endl;
    return 0;
}
