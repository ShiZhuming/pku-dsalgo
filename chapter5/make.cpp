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
        printf("%d\n",y);
        int countpop = 0;
        int countpush = 0;
        while(y--){
            z = rand()%2;
            if(z){
                printf("%d %d\n",z,rand()%(1<<30));
                countpush++;
            }
            else{
                if(countpop < countpush){
                    printf("%d\n",z+2);
                    countpop++;
                }
                else{
                    y++;
                }          
            }
        }
    }
}