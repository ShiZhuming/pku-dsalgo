#include <cstdio>
#include <cstdlib>
using namespace std;
#define TEST 1000
int main(){
    int test = TEST;
    while(test--){
        system("./make.out");
        system("./mine.out");
        system("./ex.out");
        if(system("diff _mine.out _ex.out")){
            printf("WA\n");return 0;
        }
        else printf("AC\n");
    }
    return 0;
}