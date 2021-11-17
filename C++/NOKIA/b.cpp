
using namespace std;
 
#include <vector>
#include <iostream>

int solution(int M, vector<int>& A) {
    int N = A.size();
    vector<int> count(M + 1, 0);
    int maxOccurence = 0;
    int index = -1;
    for (int i = 0; i < N; i++) {
        if (count[A[i]] > 0) {
            int tmp = count[A[i]];
            if (tmp > maxOccurence) {
                maxOccurence = tmp;
                index = i;
            }
            count[A[i]] = tmp + 1;
        } else {
            count[A[i]] = 1;
            if (index == -1)
                index = i;
            
        }
    }
    return A[index];
}

int main()
{   
    vector<int> k = {1, 1, 2};
    cout << solution(2,  k);
    return 0;
}