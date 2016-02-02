#define P 3.14159
#define e 2.71828
inline double fact(int x) {
    return (x == 1 ? x : x * fact(x - 1));
}
int nCr(int n,int r) {
    return (fact(n)/(fact(n-r)*fact(r)));
}
int nPr(int n,int r) {
    return (fact(n)/fact(n-r));
}
double log(int a,int n) {
    return log(a)/log(n);
}
double ln(int a) {
    return log(a)/log(e);
}
double cot(int a) {
    return 1/tan(a);
}
double sec(int a) {
    return 1/cos(a);
}
double csc(int a) {
    return 1/sin(a);
}
double acot(int a) {
    if(a==0) return -1;
    return atan(1.0f/a);
}
double acoth(int a) {
    if(a==0) return -1;
    return atanh(1.0f/a);
}
double acsc(int a) {
    if(a<1&&a>-1) return -1;
    return asin(1.0f/a);
}
double acsch(int a) {
    if(a<1&&a>-1) return -1;
    return asin(1.0f/a);
}
