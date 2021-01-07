#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
int main(void){
    // Your code here!
    int n; // 配列の数
    int *current; // 正解の配列
    srand((unsigned int)time(NULL)); // 乱数初期化
    
    cout << "パスワード当てゲームへようこそ！！" << endl;
    cout << "このゲームはきめられた数字を当てるだけのゲームだよ！！" << endl;
    cout << "ただし '0' は含まれないから注意してね！" << endl;
    while(true){
        cout << "桁数を入力してください : ";
        try{
            cin >> n;
            cout << endl;
            
            if(n <= 0){
                throw 1;
            }else{
                break; // 正常に入力できた時
            }
        }catch(int e){
            cout << "正の整数を入力してください" << endl;
        }
    }
    
    current = new int[n];
    
    for(int i=0;i<n;i++){
        current[i] = rand() % 9 + 1; // ランダム関数で正解を作成する
    }
    
    int tm = 1; //何回挑戦したか
    
    while(true){
        /* デバッグ用
        for(int i=(n-1);i>=0;i--){
            cout << current[i];
        }
        cout << endl;
         ここまで*/
        cout << tm << "目の挑戦！" << endl;
        
        int *answer;
        answer = new int[n];
        int digit_number;
        int digit = 0; // 桁数
        
        cout << n << "桁の数字を入力してください : ";
        
        try{
            cin >> digit_number;
            while(digit_number != 0){ // 桁数計算
                answer[digit] = digit_number % 10;
                digit_number /= 10;
                digit++;
            }
            
            if(digit != n){ // 桁数確認
                throw 1;
            }
            
           
        }catch(int e){
                cout << "桁数が違います" << endl;
                delete[] answer;
                continue;
        }
        
         // おしいか正解か確かめる
        bool *res; // 惜しい数字の場所予約
        int close = 0; // 惜しい数字の数
        int ncurrent = 0; // 正解の数字の数
        res = new bool[n];
        for(int i = 0;i < n;i++){
            res[i] = false;
        }
        for(int i = 0;i<n;i++){
            if(answer[i] == current[i]){
                res[i] = true;
                ncurrent++;
                continue;
            }
            for(int j = 0;j<n;j++){
                if(answer[i] == current[j]){
                    if(res[j] == false){
                        res[j] = true;
                        close++;
                        break;
                    }
                    
                }
            }
        }

        delete[] res;
        tm++;
        delete[] answer;

        if(ncurrent == n){
            cout << "お見事！！正解!!" << endl;
            break;
        }else{
            cout << "正解の個数 : " << ncurrent << endl;
            cout << "おしい個数 : " << close << endl;
        }
    }
    
    delete[] current;
}
