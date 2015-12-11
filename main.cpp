#include "mystring.h"
#include <stdlib.h>
using namespace std;
const String testdata("TESTDATA");//if necessary, you can change test value you want
void PrintMenu(){
    cout << "*** Test \"mystring.h\" ***" << endl << endl
        << "(1) ASSIGN" << endl
        << "(2) APPEND" << endl
        << "(3) DISPLAY_CURRENT_STATUS" << endl
        << "(4) INSERT_CHARACTER_TO_THE_STRING" << endl
        << "(5) GET_CHARACTER_FROM_THE_STRING" << endl
        << "(6) CLEAR" << endl
        << "(7) TEST_RELATIONAL_OPERATOR (COMPARE WITH " << testdata << ")" << endl
        << "(8) SELF_ADDITION" << endl
        << "(9) GET_CString" << endl
        << "(0) EXIT THE PROGRAM" << endl << endl;
}
int main(){
    int opt = 0;
    String ans;
    do{
        PrintMenu();
        cout << "Input your option...> ";
        cin >> opt;
        cin.get();
        String tmp;
        size_t pos = 0;
        switch(opt){
            case 1:     //ASSIGN
                cout << "Input the char or string...> ";
                cin >> tmp;
                ans = tmp;
                break;
            case 2:     //APPEND
                cout << "Input the char or string..> ";
                cin >> tmp;
                ans += tmp;
                break;
            case 3:     //DISPLAY_CURRENT_STATUS
                cout << ans << endl << "size: " << ans.size() << endl << "capacity: " << ans.capacity() << endl;
                break;
            case 4:     //INSERT_CHARACTER_TO_THE_STRING
                cout << "Input the position(start from 0) you want to insert...> ";
                char c;
                cin >> pos;
                cin.get();
                if(pos < ans.size()){
                    cout << "input the character you want to modify...> ";
                    cin >> c;
                    ans[pos] = c;
                }else{
                    cout << "the operation is prohibited" << endl;
                }
                break;
            case 5:     //GET_CHARACTER_FROM_THE_STRING
                cout << "Input the position(start from 0) you want to insert...> ";
                cin >> pos;
                cin.get();
                if(pos < ans.size())
                    cout << "You get '" << ans[pos] << "'" << endl;
                else
                    cout << "the operation is prohibited" << endl;
                break;
            case 6:     //CLEAR
                ans.clear();
                break;
            case 7:     //TEST_RELATIONAL_OPERATOR
                if ( ans >= testdata) cout << ans << ">=" << testdata << endl;
                if ( ans >  testdata) cout << ans << "> " << testdata << endl;
                if ( ans == testdata) cout << ans << "==" << testdata << endl;
                if ( ans != testdata) cout << ans << "!=" << testdata << endl;
                if ( ans <  testdata) cout << ans << "< " << testdata << endl;
                if ( ans <= testdata) cout << ans << "<=" << testdata << endl;
                break;
            case 8:     //SELF_ADDITION
                ans += ans;
                break;
            case 9:     //GET_CString
                const char *p = ans.c_str();
                cout << "You get CString: " << p;
                break;
        }
        system("pause");
        system("cls");
    }while(opt);
    return 0;
}
