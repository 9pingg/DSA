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
  
 