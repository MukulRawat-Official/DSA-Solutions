class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0 , b = 0;
        int curr = colors[0] == 'A'; // 1-> A  2->B
        colors.push_back('C');
        int f = 1;
        for(int i= 1;i<colors.size();i++){
            if(colors[i] == colors[i-1])    f++;
            else{
                if(f > 2){
                    if(curr) a += (f-2);
                    else b += (f - 2);
                }
                
                curr = colors[i] == 'A';
                f = 1;
            }
        }
        
        return a > b;
        
    }
};