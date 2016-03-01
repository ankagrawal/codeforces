#include<iostream>

using namespace std;

int factorial(int n) {
    int fact = 1;
    for(int i = 1; i <=n ; i++) {
        fact = fact * i;
    }
    return fact;
}

int permut2(int n) {
    //n! / (n-r)! r!
    if (n < 2)
        return 0;
    return (n*(n-1))/2;
}

int main() {
    int sz;
    cin>>sz;
    char **mat = new char*[sz];

    for(int i = 0; i < sz; i++) {
        mat[i] = new char[sz];
        for(int j = 0; j < sz; j++) {
            cin>>mat[i][j];
        }
    }

    int* row = new int[sz];
    int* col = new int[sz];

    for(int i = 0; i < sz; i++) {
        row[i] = 0;
        for(int j = 0; j < sz; j++) {
            row[i] += (mat[i][j] == 'C')?1:0;
        }
    }

    for(int i = 0; i < sz; i++) {
        col[i] = 0;
        for(int j = 0; j < sz; j++) {
            col[i] += (mat[j][i] == 'C')?1:0;
        }
    }

    int count = 0;
    for(int i = 0; i < sz; i++) {
        count += permut2(row[i]);
        count += permut2(col[i]);
    }
    cout<<count<<endl;
}
