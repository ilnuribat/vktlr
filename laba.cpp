#include <iostream>
#include <conio.h>

class triagle{
  private: int a, b, c;
  
  public:
  int getA(){ return this->a;} // Вот так мы можем "читать" данные с приватных переменных
  int getB(){ return this->b;}
  int getC(){ return this->c;}
  
  triangle();
  
  triangle(int a1, int b1, int c1)
  {
    a = a1;
    b = b1;
    c = c1;
  }
}

int main(){
  triangle a(3, 4, 5);//Создали экземпляр класса triangle и сразу заполнили данные 
  //теперь a.a = 3, a.b = 4, a.c = 5
  return 0;
}
