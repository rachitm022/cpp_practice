#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int n = rand(2, 10);
    printf("%d\n", n);
    string a,b;
    string s = "abcdefghijklmnopqrstuvwxyz";
    for(int i = 0; i < n; ++i) {
        int x = rand(0,25);
        int y = rand(0,25); 
        // cout<<x<<" "<<s[x]<<" "<<y<<" "<<s[y]<<" "<<endl;
        a+=(s[x]);
        b+=(s[y]);
    }
    cout<<a<<endl<<b<<endl;

}