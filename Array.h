/*
Creating and working with dynamic arrays v0.0.0.1
creator: Tarique Ali Mirza <tarique1988@gmail.com>
date of inception: 22nd August 2019
*/
#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <typeinfo>

using namespace std;

template <class T>
class Array {
  private:
    vector<T> v;
    int size;
  public:
    Array(){
      size = 0;
    }
    int sizeOf(){
      return size;
    }
    bool push(const T &data){
      try{
        v.push_back(data);
        ++size;
        return true;
      } catch(...){
        cout << "Type Mismatch!" << endl;
        // throw;
        return false;
      }
    }
    bool pop(){
      try{
        v.pop_back();
        --size;
        return true;
      } catch(...){
        cout << "Type Mismatch!" << endl;
        // throw;
        return false;
      }
    }
    bool slice(int pos){
      try{
        v.erase(v.begin()+pos);
        --size;
        return true;
      } catch(...){
        throw;
        return false;
      }
    }
    bool slice(int start, int end){
      try{
        v.erase(v.begin()+start,v.begin()+start+end);
        --size;
        return true;
      } catch(...){
        throw;
        return false;
      }
    }
    void print(){
      cout << toString() << endl;
    }
    void add(){}
    template <typename P1, typename ...Params>
    void add(const P1 &p, const Params& ...params){
      push(p);
      add(params...);
    }
    string toString(){
      stringstream ss;
      string start = "[", middle = ", ", end = "]";
      if(typeid(T).name() == typeid(string).name()){
        start = "[\"";
        end = "\"]";
        middle = "\", \"";
      } else if(typeid(T).name() == typeid(char).name()){
        start = "['";
        end = "']";
        middle = "', '";
      }
      for(int i = 0; i < size; ++i){
        if(i == 0 && size == 1){
          	ss << start << v[i] << end;
        } else if(i == 0 && size > 1){
          	ss << start << v[i] << middle;
        } else if( i == size - 1){
          	ss << v[i] << end;
        } else{
        	ss << v[i] << middle;
		}
      }
      return ss.str();
//	return start;
    }
};

#endif
