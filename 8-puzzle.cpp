
#include <iostream>
#include<queue>
using namespace std;
const int value = 3;
class puzzle8{
    struct node {
        queue<int>puzzle;
        node* next;
        int array[value][value];
    };
    node* parent = new node;
    int array2[value][value];

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
        bool checkpuzzle() {

            for (int x = 0;x < 3;++x) {
                for (int y = 0;y < 3;++y) {
                    if (temp.array[x][y] != array2[x][y]) {
                        return false;
                   }
                }
            }
            return true;


        }

















    }















}

int main()
{
    std::cout << "Hello World!\n";
}


