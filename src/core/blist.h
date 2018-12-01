/*
 * Copyright 2017 Vitor Fernandes <email>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef BLIST_H
#define BLIST_H

#include <string>
#include <cstddef>
#include <iostream>

template <typename T>
class blist
{ 
public:
    
  typedef struct node{
      node(T v,node* p,node* n){
	value = v;
	next  = n;
	previous = p;
      }
      node(T v){
	value=v;
	next=NULL;
	previous=NULL;
      }
      T value;
      node* next;
      node* previous;
    } Node;

    blist(){
      this->rootNode = NULL;
      this->currentNode=this->rootNode;
      size = 0;
    };
    blist(T value){
      this->rootNode=new Node(value,NULL,NULL);
      this->currentNode=this->rootNode;
      size = 1;
    };
    blist(const blist<T>& other){
      this->rootNode = other.root();
    };
    void add(T value){
      if(this->rootNode==NULL){
	this->rootNode=new Node(value,NULL,NULL);
	this->currentNode=rootNode;
      }else{
	Node* newNode = new Node(value,currentNode,NULL);
	this->currentNode->next = newNode;
	currentNode=newNode;
      }
      size++;
    };
    ~blist(){
      std::cout << "Destructing list" << std::endl;
      Node *aux;
      while(this->currentNode!=this->rootNode){
	aux = this->currentNode;
	this->currentNode = this->currentNode->previous;
	delete aux;
      }
      delete this->rootNode;
    };
    blist<T>& operator=(const blist& other){
      this->rootNode = other.root();
    };
    bool operator==(const blist& other){
      this->rootNode==other.root();
    };
    Node * root() const {
      return this->rootNode;
    };
    Node * current() const {
      return this->currentNode;
    };
    
    T* values() {
      T *aux = new T[size];
      Node *naux = this->rootNode;
      for(int i=0;i<size;i++){
	aux[i]=naux->value;
	naux=naux->next;
      }
      return aux;
    };
    int getSize(){
      return size;
    };
private:
    Node * rootNode;
    Node * currentNode;
    int size;
};

#endif // BLIST_H
