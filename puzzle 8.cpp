#include <iostream>
#include<queue>
#include<stack>
using namespace std;
const int value = 3;

class puzzle8 {
    struct  node{
        int visit[5];
        node* children[5];
        int array[value][value];
        node*parent=NULL;
    };
    node* parent = NULL;
    int array2[value][value];
    int array3[value][value];
    int array4[value][value];
    int x1;
    int y1;
public:
    queue<node*>visit;
    queue<node*>visit1;
    stack <node*>reverse;
    puzzle8() {
        parent = new node;
        setpuzzle(parent);
        visit.push(parent);
    }
    void initialpuzzle() {
        for (int x = 0;x < 3;++x) {
            for (int y = 0;y < 3;++y) {
                cin >> array3[x][y];
                array4[x][y]=array3[x][y];
            }
        }
    }
    void finalpuzzle() {
        for (int x = 0;x < 3;++x) {
            for (int y = 0;y < 3;++y) {
                cin >> array2[x][y];
            }
        }
    }
    node* sendroot() {
        return parent;
    }

    void displaypuzzle(node* temp) {
        for (int x = 0;x < 3;++x) {
            for (int y = 0;y < 3;++y) {
                cout << temp->array[x][y]<<" ";
            }
            cout << endl;
        }
    }

        void setpuzzle(node * temp) {
            for (int x = 0;x < 3;++x) {
                for (int y = 0;y < 3;++y) {
                    temp->array[x][y] = array3[x][y];
                }
            }
        }
        void resetpuzzle() {
            for (int x = 0;x < 3;++x) {
                for (int y = 0;y < 3;++y) {
                   array3[x][y] = array4[x][y];
                }
            }
        }
        
        bool checkpuzzle(node * temp1) {
            for (int x = 0;x < 3;++x) {
                for (int y = 0;y < 3;++y) {
                    if (temp1->array[x][y] != array2[x][y]) {
                        return false;
                    }
                }
            }
            return true;
        }

        void getblank() {

            for (int x = 0;x < 3;++x) {
                for (int z = 0;z < 3;++z) {
                    if (array3[x][z] == 0) {
                        x1 = x;
                        y1 = z;
                    }
                }
            }
        }

        bool search(node* temp23,int value) {
            for (int x = 0;x < 5;++x) {
                if (temp23->visit[x] == value) {
                    return false;
                }
           }
            return true;

        }
        void changearray(node* temp) {
            for (int x = 0;x < 3;++x) {
                for (int z = 0;z < 3;++z) {
                    array3[x][z] = temp->array[x][z];
                    array4[x][z] =temp->array[x][z];
                }
            }

        }
        int movexpansion(node*temp1) {
            int u;
             getblank();
            //up
            if ((search(temp1,temp1->array[x1-1][y1]) && x1!=0)){
                    node* temp0 = new node;
                    u = array3[x1][y1];
                    array3[x1][y1] = array3[x1-1][y1];
                    array3[x1 - 1][y1] = u;
                    temp1->visit[1] = array3[x1][y1];
                    temp0->visit[1] = temp1->visit[1];
                    setpuzzle(temp0);
                    resetpuzzle();
                    temp1->children[0] = temp0;
                    temp0->parent=temp1;
                    visit.push(temp0);
                    visit1.push(temp0);
            }
            //down
             if (search( temp1,temp1->array[x1 + 1][y1]) && x1 != 2){
                node* temp12 = new node;
                u = array3[x1][y1];
                array3[x1][y1] = array3[x1 + 1][y1];
                array3[x1 + 1][y1] = u;
                temp1->visit[2] = array3[x1][y1];
                temp12->visit[1] = temp1->visit[2];
                setpuzzle(temp12);
                resetpuzzle();
                temp1->children[1] = temp12;
                temp12->parent=temp1;
                visit.push(temp12);
                visit1.push(temp12);
            }
            // left
             if (search(temp1,temp1->array[x1][y1-1]) && y1 != 0) {
                node* temp2 = new node;
                u = array3[x1][y1];
                array3[x1][y1] = array3[x1][y1-1];
                array3[x1][y1-1] = u;
                temp1->visit[3] = array3[x1][y1];
                temp2->visit[1] = temp1->visit[3];
                setpuzzle(temp2);
                resetpuzzle();
                temp1->children[2] = temp2;
                temp2->parent=temp1;
                visit.push(temp2);
                visit1.push(temp2);
            }
            //right
            if ((search(temp1, temp1->array[x1][y1 + 1]) && y1 != 2)) {
              
                node* temp3 = new node;
                u = array3[x1][y1];
                array3[x1][y1] = array3[x1][y1 + 1];
                array3[x1][y1 + 1] = u;
                temp1->visit[4] = array3[x1][y1];
                temp3->visit[1]=temp1->visit[4];
                setpuzzle(temp3);
                resetpuzzle();
                temp1->children[3] = temp3;
                temp3->parent=temp1;
                visit.push(temp3);
                visit1.push(temp3);
            }
            else {

                return 0;

            }
        }
    
        void tracepath(node* temp){
        	if(temp==NULL)
        		return ;
			
            reverse.push(temp);
			tracepath(temp->parent);
			
		}
		
		
		};


        





int main()
{

    puzzle8 p1;
    cout << "please input the intial state of the puzzle " << endl;
    p1.initialpuzzle();
    cout << "please input the final state of the puzzle you want to find" << endl;
    p1.finalpuzzle();
    p1.setpuzzle(p1.sendroot());
    while (!p1.visit.empty()) {
    	if( p1.checkpuzzle(p1.visit.front())){
    		p1.tracepath(p1.visit.front());
    	while(!p1.reverse.empty()){
    		p1.displaypuzzle(p1.reverse.top());
    		p1.reverse.pop();
    		cout<<endl;
		}
    		break;
		}
        p1.movexpansion(p1.visit.front());
        p1.visit.pop();
        p1.changearray(p1.visit.front());
    }
    

cout<<"we found the state"<<endl;
	

    
}

