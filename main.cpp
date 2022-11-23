#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <chrono>

using namespace std;

vector<vector<int>> crt_mat(int r_s, int c_s){
    vector<vector<int>> m(r_s, vector<int>(c_s,0));
    for(int i = 0; i < r_s; i++) {
        for(int j = 0; j < c_s; j++) {
            m[i][j] = rand() % 1000;
        }
    }
    return m;
}
void print (vector<vector<int>> m) {
    for (int i = 0; i < m.size(); ++i) {
        cout<<"\n|";
        for(int j=0;j< m[i].size(); j++){
            cout<<m[i][j]<<" ";
        }
        cout<<"|";
    }
}
void write(vector<vector<int>> m, const char* str){
    ofstream out;
    out.open(str);
    for (int i = 0; i < m.size(); ++i) {
        for(int j=0;j< m[i].size(); j++) {
            out << m[i][j] << " ";
        }
        out<<endl;
    }
    out.close();
}
vector<vector<int>> mul(vector<vector<int>> m_1, vector<vector<int>> m_2){
    if(m_1[0].size()==m_2.size()){
        vector<vector<int>> res = crt_mat(m_1.size(), m_2[0].size());
        for(int i=0;i< res.size();i++){
            for(int j=0;j<res[0].size();j++){
                int sum = 0;
                for(int k=0; k<m_1[0].size();k++){
                    sum += m_1[i][k] * m_2[k][j];
                    res[i][j]=sum;
                }
            }
        }
        return res;
    }
    else{
        throw "Multiplication is impossible! Check matrix sizes.";
    }
}
vector<vector<int>> read_size(const char* str){
    std::string buf;
    ifstream data;
    data.open(str);
    int r_s=0;
    int count=0;
    while(data) {
        getline(data,buf);
        std::string::iterator it= buf.end();
        if (*it=='\0') r_s++;
        for(int i=0; i<buf.size();i++){
            if(buf[i]==' ') count++;
        }
    }
    data.close();
    vector<vector<int>> m= crt_mat(r_s-1,(count/(r_s-1)));
    return m;
}
vector<vector<int>> read(const char* str){
    vector<vector<int>> m= read_size(str);
    string buf;
    ifstream data;
    data.open(str);

    if(data.is_open()) {
        for(int i = 0; i < m.size(); i++) {
            for(int j = 0; j < m[i].size(); j++) {
                data >> m[i][j];
            }
        }

    }
    data.close();
    return m;
}
int main() {
    srand(time(NULL));
    int size=0;
    cout << "Enter matrixs size:";
    cin>> size;
    vector<vector<int>> m_1= crt_mat(size,size);
    vector<vector<int>> m_2= crt_mat(size,size);
    write(m_1,"Mat_1.txt");
    write(m_2,"Mat_2.txt");
    cout<<endl;
    try{
        ofstream out_data;
        out_data.open("data.txt", std::ios::app);
        chrono::steady_clock::time_point begin = chrono::steady_clock::now();
        vector<vector<int>> res= mul(m_1,m_2);
        chrono::steady_clock::time_point end = chrono::steady_clock::now();
        out_data<< size << ", " << chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " ";
        out_data.close();
        write(res,"Res.txt");
        cout<< "Diff(ms) = " << chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << endl;
    }
    catch (const char* str){
        cout<<str;
    }
    return 0;
}

