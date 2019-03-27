#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    //vector of alphabets
    vector<char> c;

    for(int i = 97; i <= 122; i++){
        if(i == 105){
            c.push_back('!');
            continue;
        }
        if(i == 106){
            continue;
        }
        c.push_back(i);
    }
    //represent the key

cout<<"\n";
cout<<"enter the key : "<<"\n";
cout<<"\n";

    string key;
    cin>>key;

cout<<"\n";

    vector<char> g;
    bool b = true;

    for(int i = 0; i < key.size(); i++){

            key[i] = tolower(key[i]);
            if(key[i] == 'i' || key[i] == 'j'){
                key[i] = '!';
            }
        for(int j = 0; j < g.size(); j++){

            if(key[i] == g[j]){
                b = false;
                break;
            }
        }
        if(b){
            g.push_back(key[i]);
            if(key[i] > 'j'){
                key[i]--;
            }
            if(key[i] == '!'){
                c[8] = '%';
            }else{
                c[key[i] - 97] = '%';
            }

        }
        b = true;
    }

    //the characters elements in the 5*5 PlayFair array

    for(char i : c){
        if(i != '%'){
            g.push_back(i);
        }
    }

    //prepare the 5*5 PlayFair array

    char arr[5][5];
    int k = 0;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            arr[i][j] = g[k];
            k++;
        }
    }

    //displaying the 5*5 PlayFair array

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }

    //---------------------------- insert the Text -------------------

cout<<"\n";
cout<<"press '1' for PlainText or '2' for CipherText"<<"\n";
cout<<"\n";
int type;
cin>>type;


    //---------------------------- insert the PlainText -------------------
    if(type == 1){

cout<<"\n";
cout<<"enter the PlainText : "<<"\n";
cout<<"\n";

        string str;
        getline(cin, str);

    cout<<"\n";

        getline(cin, str);
        vector<char> ptext;

cout<<"----------------------\n";
cout<<"the CipherText is : "<<"\n";
cout<<"\n";
    //---------------adding the PlainText characters into an array ----------

        for(int i = 0; i < str.size(); i++){

            if(str[i] != ' '){
                if(str[i] == 'i' || str[i] == 'j'){
                    ptext.push_back('!');
                }else{
                    ptext.push_back(str[i]);
                }
            }
        }

        //--------------- adding the extra Xs -----------------

        for(int i = 1; i < ptext.size(); i++){
            if((ptext[i] == ptext[i - 1]) && (i % 2 != 0)){
                ptext.insert(ptext.begin() + i, 'x');
            }
        }
        if(ptext.size() % 2 != 0){
            ptext.push_back('x');
        }

        //------------------- divide the text into 2 characters ------------------

        char x, y;
        for(int i = 0; i < ptext.size(); i+=2){

            x = ptext[i];
            y = ptext[i+1];

        //----- getting the indexes of the 2 characters in the 5 * 5 array ----

        int i1, j1, i2, j2;
        int ctn = 0;

            for(int j = 0; j < 5; j++){
                for(int k = 0; k < 5; k++){
                    if(arr[j][k] == x){
                        ctn++;
                        i1 = j;
                        j1 = k;
                    }
                    if(arr[j][k] == y){
                        ctn++;
                        i2 = j;
                        j2 = k;
                    }
                    if(ctn == 2){
                        j = 5;
                        break;
                    }
                }
            }

        //------ getting the indexes of the two encrypted characters --------

            if(i1 == i2){
                j1++;
                j2++;
                if(j1 > 4) j1 = 0;
                if(j2 > 4) j2 = 0;

            }else if(j1 == j2){
                i1++;
                i2++;
                if(i1 > 4) i1 = 0;
                if(i2 > 4) i2 = 0;
            }else{
                swap(j1, j2);
            }
            cout<<arr[i1][j1]<<arr[i2][j2]<<" ";
        }
        cout<<"\n";

        //---------------------------- insert the CipherText -------------------

    }else if(type == 2){

cout<<"\n";
cout<<"enter the CipherText"<<"\n";
cout<<"\n";

        string ctext;
        cin>>ctext;
        int x, y;
cout<<"----------------------\n";
cout<<"the PlainText is : "<<"\n";
cout<<"\n";
        for(int i = 0; i < ctext.size(); i++){

            ctext[i] = tolower(ctext[i]);

            if(ctext[i] == 'i' || ctext[i] == 'j'){
                ctext[i] = '!';
            }
        }

        //----------------- divide the CipherText into two characters ------------

        for(int i = 0; i < ctext.size(); i+=2){

            x = ctext[i];
            y = ctext[i+1];
            int i1, j1, i2, j2;
            int ctn = 0;

        //--------- getting the indexes of the two characters in the 5*5 array --------

            for(int j = 0; j < 5; j++){
                for(int k = 0; k < 5; k++){
                    if(arr[j][k] == x){
                        i1 = j;
                        j1 = k;
                        ctn++;
                    }
                    if(arr[j][k] == y){
                        i2 = j;
                        j2 = k;
                        ctn++;
                    }
                    if(ctn == 2){
                        j = 5;
                        break;
                    }
                }
            }

        //-------- getting the decrypted two characters from the array ----------

            if(i1 == i2){
                j1--;
                j2--;
                if(j1 < 0) j1 = 4;
                if(j2 < 0) j2 = 4;

            }else if(j1 == j2){
                i1--;
                i2--;
                if(i1 < 0) i1 = 4;
                if(i2 < 0) i2 = 4;
            }else{
                swap(j1, j2);
            }
        cout<<arr[i1][j1]<<arr[i2][j2]<<" ";
        }
        cout<<"\n";
}
    return 0;
}
