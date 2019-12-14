
#include <iostream>
#include<queue>
using namespace std;
const int value = 3;
class puzzle8{
    struct node {
        queue<int>puzzle;
        node* parent;
        node* children[];
        int array[value][value];
    };
    int array2[value][value];
    int x1;
    int y1;
public:


    void getpuzzle() {
        for (int x = 0;x < 3;++x) {
            for (int y = 0;y < 3;++y) {
                cin >> array2[x][y];
            }
        }
    }


    void displaypuzzle() {
        for (int x = 0;x < 3;++x) {
            for (int y = 0;y < 3;++y) {
                cout<< array2[x][y];
            }
        }

        void setpuzzle(node* temp){
            for (int x = 0;x < 3;++x) {
                for (int y = 0;y < 3;++y) {
                    temp.array[x][y] = array2[x][y];
                }
            }
        }
        bool checkpuzzle(node* temp1) {
            for (int x = 0;x < 3;++x) {
                for (int y = 0;y < 3;++y) {
                    if (temp1.array[x][y] != array2[x][y]) {
                        return false;
                   }
                }
            }
            return true;
        }

        void getblank() {
          
            for (int x = 0;x < 3;++x) {
                for (int z = 0;z < 3;++z) {
                    if (array2[x][z] == 0) {
                        x1 = x;
                        y1 = z;
                    }
                }
            }
        }

        int movexpansion(node* temp1) {
            int u;
            //up
            if (temp1.puzzle.front() != temp1.array[x1-1][y1] ){
                if (x1 == 0) {
                    return 0;
                }
                else {
                    node* temp2 = new node;
                    

             
                }

        }
            //down
         
            if (x1 == 2) {
                return 0;
            }
            else {
                u = temp1.array[x1][y1];
                temp1.array[x1][y1] = temp1.array[x1+1][y1];
                temp1.array[x1+1][y1] = u;
            }
            //right
            if (y1 ==2 ) {
                return 0;
            }
            else {
                u = temp1.array[x1][y1];
                temp1.array[x1][y1] = temp1.array[x1][y1 + 1];
                temp1.array[x1][y1 + 1] = u;
            }
            //left
            if (y1 == 0) {
                return 0;
            }
            else {
                u = temp1.array[x1][y1];
                temp1.array[x1][y1] = temp1.array[x1][y1 - 1];
                temp1.array[x1][y1 - 1] = u;
            }







        }

















    }















}

int main()
{
    std::cout << "Hello World!\n";
}


