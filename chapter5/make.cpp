#include <cstdio>
#include <cstdlib>
#include <ctime>
#define MAXCASE 100000
using namespace std;

int main(){
    freopen("_make.out","w",stdout);
    int x,y,z;
    srand(time(NULL));
    // x = rand()%MAXCASE + 1;
    x = 10;
    printf("%d\n",x);
    while(x--){
        y = rand()%MAXCASE + 1;
        printf("%d\n",2*y);
        int countpop = 0;
        int countpush = 0;
        while(y--){
            // z = rand()%2;
            // if()
            // if(z){
                printf("%d %d\n",1,rand()%(1<<30));
                countpush++;
            // }
        
        }
            // else{
                // if(countpop < countpush){
        while(countpush--){
                    printf("%d\n",2);
                    // countpop++;
                // }
                // else{
                    // y++;
                // }          
            // }
        }
    }
    return 0;
}