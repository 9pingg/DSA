void print_v(vector<int> &v){
    for(auto val : v){
        cout << val << " ";
    }
    cout << endl;
}


void print_m(map<int, int> &m){
    for(auto val : m){
        cout <<val.first << " " << val.second << endl;
    }
    cout << endl;
}

// other way to traverse maps
// for (auto i = m.begin(); i != m.end(); i++)
//     cout << i->first << " \t\t\t" << i->second << endl; or we can use cout << (*it).first
  
 
/*
a to z Ascii range (97 - 122)
A to Z Ascii range (65 - 90)
0 to 9 Ascii range (48 - 57)

or simply use isalnum()
more string functions islower, isupper, tolower, toupper

get the ascii value of a char by:
char c = 'A';
int a = (int)c;
*/
