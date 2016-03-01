#include<iostream>
#include<cstring>
#include<cstdlib>
#include<iomanip>
#include<list>

using namespace std;


int main() {
    int n;
    const long double PI = 3.141592653589793238L;
    cin>>n;

    long long *vol = new long long[n];
    long long *res = new long long[n];
    memset(res, 0, sizeof(long long)*n);

    for(int i = 0; i < n; i++) {
        long long r, h;
        cin>>r>>h;
        vol[i] = r*r*h;
    }

    long long max = 0;
    list<long long> l;
    l.push_front(vol[n-1]);
    for(int i = n-2; i >= 0; i--) {
        int cnt = 0;
        list<long long>::iterator it = l.begin();
        long long sum = 0;
        bool replace = true;
        if(vol[i]>*it) {
            while(it != l.end()) {
                sum = sum + *it;
                if(vol[i]>*it && sum<=vol[i]) {
                    cnt++;
                    it++;
                } else if(vol[i]>*it && sum>vol[i]) {
                    replace = false;
                } else {
                    break;
                }
            }
        }
        if(replace) {
            while(cnt>0) {
                l.pop_front();
                cnt--;
            }
            l.push_front(vol[i]);
        }
    }
    list<long long>::iterator it = l.begin();
    while(it!=l.end()) {
        max = max + *it;
        it++;
    }
    cout<<setprecision(51)<<((long double)max)*PI<<endl;
    return 0;
}
