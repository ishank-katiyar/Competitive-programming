#include<bits/stdc++.h>

using namespace std;

#define FILE_NAME "input"
#define INPUT_NAME "IN"
#define OUTPUT_NAME "OUT"


void check () {
    freopen(FILE_NAME, "r", stdin);
    string s;
    cin>>s;
    if(s.empty()) {
        cerr << "Input file is Empty!!!!";
        fclose(stdin);
        exit(0);
    }
}

bool fd (string &s,const string &ss) {
    int sz=s.size();
    int ssz=ss.size();
    for(auto i = 0; i <= sz - ssz; i++){
        if(s.substr(i,ssz)==ss)return true;
    }
    return false;
}

int main(){
    check();
    freopen(FILE_NAME,"r",stdin);
    string s;
    getline(cin,s);
    int test_case = 1;
    while(fd(s,"Input</div><pre>")){
        while(s.size()){
            if(s.substr(0,16)!="Input</div><pre>"){
                s.erase(s.begin());
            }
            else {
                int q=16;
                while(q--)s.erase(s.begin());
                break;
            }
        }
        string tcase="";
        while(s.substr(0,12)!="</pre></div>"){
            tcase+=s[0];
            s.erase(s.begin());
        }
        //cout<<"Input";
        string R = string(INPUT_NAME) + to_string(test_case);
        int SZ = (int) R.size();
        char char_array[SZ + 1];
        strcpy(char_array, R.c_str());
        freopen(char_array,"w",stdout);
        cout << tcase << '\n';
        //int sz=tcase.size();
        //for(auto i=0;i<sz;i++){
            //if(i+1<sz && tcase[i]==(char)92 && tcase[i+1]=='n')cout<<endl , i++;
            //else cout<<tcase[i];
        //}
        while(s.size()){
            if(s.substr(0,17)!="Output</div><pre>"){
                s.erase(s.begin());
            }
            else {
                int q=17;
                while(q--)s.erase(s.begin());
                break;
            }
        }
        tcase="";
        while(s.substr(0,12)!="</pre></div>"){
            tcase+=s[0];
            s.erase(s.begin());
        }
        //cout<<"Output";
        string R1 = string(OUTPUT_NAME) + to_string(test_case);
        int SZ1 = (int) R1.size();
        char char_array1[SZ1 + 1];
        strcpy(char_array1, R1.c_str());
        freopen(char_array1,"w",stdout);
        cout << tcase << '\n';
        //sz=tcase.size();
        //for(auto i=0;i<sz;i++){
            //if(i+1<sz && tcase[i]==(char)92 && tcase[i+1]=='n')cout<<endl , i++;
            //else cout<<tcase[i];
        //}
        //cout<<endl;
        test_case++;
    }
}
