
#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

class Student{
    public:
    int roll_no;
    string name;
    int grade;
};
class Hash{

    private:
    int size;
    vector<vector<Student>>table;

    public:
    Hash(int size){
        this->size=size;
        this->table.resize(size);
    }

    int HashFunction(int roll_no){
        int hash_value = roll_no % size;
        return hash_value;
    }


void With_Chaning_without_replacement(Student student){
    int index = HashFunction(student.roll_no);
    if(table[index].size() == 0){
        table[index].push_back(student);
    }
    else{
        for(int i=0;i<table[index].size();i++){
            if(table[index][i].roll_no==student.roll_no){
                cout<<"error, entry alredy exit. "<<endl;
                return;
            }
        }
        table[index].push_back(student);
    }

}

  void WithChainingWithReplacement(Student student) {
        int index = HashFunction(student.roll_no);
        int i = index;
        int j = 1;
        while (table[i].size() != 0 && table[i][0].roll_no != student.roll_no && j < size) {
            i = (index + j) % size;
            j++;
        }
        if (j >= size) {
            cout << "Error: Hash table is full." << endl;
            return;
        }
        else if (table[i].size() == 0) {
            table[i].push_back(student);
        }
        else {
            table[i][0] = student;

        }
     }




void display(){
    for(int i=0; i< size;i++){
        cout<<"Index "<<i<<"    ";
        for(int j=0; j<table[i].size();j++){
            cout<<"("<<table[i][j].roll_no<<")"<<"";
            if(j!=table[i].size()-1){
                cout<<"->";
            }
        }
        cout<<endl;
}
}

};

int main(){

    int n;
   
    cout<<"Enter the no. of values: "<<" ";
    cin>>n;
    Hash H1(n);

    cout<<"Enter the respective(roll_no name grade) entrys :"<<endl;
    for(int i=1; i<=n; i++ ){
        int roll_no,grade;
        string name;
        cout<<i<<"th"<<endl;
        cin>> roll_no >> name >> grade ;
        Student s = {roll_no,name,grade};
         H1.With_Chaning_without_replacement(s);

    }

    H1.display();
    return 0;
}