#include <bits/stdc++.h>

/*
TIME COMPLEXITY
1.Best Case    --> constant(1) denoted by omega
2.Worst Case   --> directly proportional to n, denoted by 0
3.Avergae Case --> directly proportional to n, denoted by theta
*/

int main(void){
    std::vector<int> n = {1, 4, 5};
    for(auto i: n){
        std::cout<<sqrt(i)<<" ";
    }

    return EXIT_SUCCESS;
}