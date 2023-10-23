 #include <iostream>
 class Expression{
 public:
     virtual Expression *diff() = 0;
     virtual void print() = 0;

 };
 class Number :public Expression
 {
     float number;
 public:
     Number( double n){
         number = n;
     }
     Number()  {number=0.0;}
     Expression* diff() override
     {
         return new Number(0.0);
     }
     void print() override {
         std::cout << number;
     }
 };
 class Variable :public Expression
 {
     char per;
 public:
     Variable( char ch){
         per = ch;
     }
     Expression* diff() override
     {
         return new Number(1.0);
     }
     void print() override {
         std::cout << per;
     }
 };
 class Add :public Expression
 {
     Expression *e1,*e2;
 public:
     Add( Expression *slag1,Expression *slag2){
         e1=slag1;
         e2=slag2;
     }
     Expression* diff() override
     {
         return new Add(e1->diff(),e2->diff());
     }
     void print() override {
         std::cout<<'(';
         e1->print();
         std::cout<<'+';
         e2->print();
         std::cout<<')';
     }
 };
 class Sub :public Expression
 {
     Expression *e1,*e2;
 public:
     Sub( Expression *slag1,Expression *slag2){
         e1=slag1;
         e2=slag2;
     }
     Expression* diff() override
     {
         return new Sub(e1->diff(),e2->diff());
     }
     void print() override {
         std::cout<<'(';
         e1->print();
         std::cout<<'-';
         e2->print();
         std::cout<<')';
     }
 };
int main() {
    Expression *e = new Sub(new Number(1), new Variable('x'));
    e->print();
    std::cout << "\n";
    Expression *de = e->diff();
    de->print();
    std::cout << "\n";

    return 0;
}
