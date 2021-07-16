#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);

int findMin(int N, int A[]) {
    int a = A[0];
    for (int i=0; i<N; i++){
        a= min(a,A[i]);
    }
    return a;
}

string gradeMin(int N, int A[]) {
    startTime();
    int ans = findMin(N, A);
    int endTime = stopTime();
    int correctAnswer = findMin(N, A);
    if(endTime > 500) return "Time Limit Exceeded";
    if(ans != correctAnswer) return "Wrong Answer";
    return "Accepted";
}

