#include<iostream>
using namespace std;

class TicTacToe {
    private:
    char circle='O';
    char cross='X';
    char state[10];
    char turn=0;
    int num=0;
    
    public:
    
    void reset(){
        turn=cross; // turn = cross或circle
        num=0;
        state[0]=0; // state[0]: 0是開始，cross是玩家1贏，circle是玩家2贏，1是平手
        state[1]='1';
        state[2]='2';
        state[3]='3';
        state[4]='4';
        state[5]='5';
        state[6]='6';
        state[7]='7';
        state[8]='8';
        state[9]='9';
    }
    
    
    
    void run(){
        
        reset();
        
        while(state[0]==0){
            
            print();
            
            if (
                (state[1] == cross && state[2] == cross && state[3] == cross) ||
                (state[4] == cross && state[5] == cross && state[6] == cross) ||
                (state[7] == cross && state[8] == cross && state[9] == cross) ||
                (state[1] == cross && state[4] == cross && state[7] == cross) ||
                (state[2] == cross && state[5] == cross && state[8] == cross) ||
                (state[3] == cross && state[6] == cross && state[9] == cross) ||
                (state[1] == cross && state[5] == cross && state[9] == cross) ||
                (state[3] == cross && state[5] == cross && state[7] == cross)
            ) {
                cout <<"==> Player 1 win" << endl;
                state[0] = cross; 
                break;
            } else if (
                (state[1] == circle && state[2] == circle && state[3] == circle) ||
                (state[4] == circle && state[5] == circle && state[6] == circle) ||
                (state[7] == circle && state[8] == circle && state[9] == circle) ||
                (state[1] == circle && state[4] == circle && state[7] == circle) ||
                (state[2] == circle && state[5] == circle && state[8] == circle) ||
                (state[3] == circle && state[6] == circle && state[9] == circle) ||
                (state[1] == circle && state[5] == circle && state[9] == circle) ||
                (state[3] == circle && state[5] == circle && state[7] == circle)
            ) {
                cout <<"==> Player 2 win" << endl;
                state[0] = circle; 
                break;
            }
            else if(
                state[1]!='1' && state[2]!='2' && state[3]!='3' &&
                state[4]!='4' && state[5]!='5' && state[6]!='6' &&
                state[7]!='7' && state[8]!='8' && state[9]!='9'
            ){
                cout<<"==>Game draw"<<endl;
                state[0] = 1;
                break;
            }
            else if(
                turn==cross
            ){
                cout<<"Player 1,請輸入『1~9』的數字: ";
            }
            else if(
                turn==circle
            ){
                cout<<"Player 2,請輸入『1~9』的數字: ";
            } 
            
            input();
            cout<<" "<<endl;
        
        
        }
    }
    
    void input(){
        
        cin>>num;
            
            if(
              (num>=1 && num<=9) &&
              state[num]!=cross &&
              state[num]!= circle
            ){
               if(turn==circle){
                    state[num]=circle;
                    turn=cross;
               }else if(turn==cross){
                    state[num]=cross;
                    turn=circle;
               }
                
            }   else {
            cout<<"請重新輸入下一步";
            input();
            }
        
        
        
    }
    
    void print(){
        
        cout<<"-- Tic Tac Toe -- CSIE@CGU"<<endl;
        cout<<"Player 1 (×)  -  Player 2 (○)"<<endl;
        cout<<" "<<endl;
        cout<<"     ██     ██"<<endl;
        cout<<"  "<<state[1]<<"  ██  "<<state[2]<<"  ██  "<<state[3]<<endl;
        cout<<"     ██     ██"<<endl;
        cout<<"████████████████████"<<endl;
        cout<<"     ██     ██"<<endl;
        cout<<"  "<<state[4]<<"  ██  "<<state[5]<<"  ██  "<<state[6]<<endl;
        cout<<"     ██     ██"<<endl;
        cout<<"████████████████████"<<endl;
        cout<<"     ██     ██"<<endl;
        cout<<"  "<<state[7]<<"  ██  "<<state[8]<<"  ██  "<<state[9]<<endl;
        cout<<"     ██     ██"<<endl;
        cout<<" "<<endl;
        
        
    }
};



int main(){
    TicTacToe game;
    game.run();
    return 0;
}
