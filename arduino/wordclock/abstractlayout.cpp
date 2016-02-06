#include "abstractlayout.h"

AbstractLayout::AbstractLayout(){

}


void AbstractLayout::getLayout(char hour, char minute, char sec, short* dest){
  this->append(&dest, 0, 1, 2, 3, -1);
}

void AbstractLayout::append(short** dest, short v){
    **dest = v;
    (*dest)++;
}

void AbstractLayout::append(short** dest, short v1, short v2){
  this->append(dest, v1);
  this->append(dest, v2);
}

void AbstractLayout::append(short** dest, short v1, short v2, short v3){
  this->append(dest, v1, v2);
  this->append(dest, v3);
}

void AbstractLayout::append(short** dest, short v1, short v2, short v3, short v4){
  this->append(dest, v1, v2, v3);
  this->append(dest, v4);
}

void AbstractLayout::append(short** dest, short v1, short v2, short v3, short v4, short v5){
  this->append(dest, v1, v2, v3, v4);
  this->append(dest, v5);
}

void AbstractLayout::append(short** dest, short v1, short v2, short v3, short v4, short v5, short v6){
  this->append(dest, v1, v2, v3, v4, v5);
  this->append(dest, v6);
}

void AbstractLayout::append(short** dest, short v1, short v2, short v3, short v4, short v5, short v6, short v7){
  this->append(dest, v1, v2, v3, v4, v5, v6);
  this->append(dest, v7);
}

void AbstractLayout::append(short** dest, short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8){
  this->append(dest, v1, v2, v3, v4, v5, v6, v7);
  this->append(dest, v8);
}

char* AbstractLayout::getDebugLayout(){
  return "todo";
}
