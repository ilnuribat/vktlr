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
