 #include <iostream>
 class Expression{
 public:
     virtual Expression *diff() = 0;
     virtual void print() = 0;

     virtual double evaluate(double x)=0;

 };
 class Number :public Expression
 {
     double number;
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

     double  evaluate(double x) override
     {
         return number;
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
     double  evaluate(double x) override {return x;}
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
     double  evaluate(double x) override {return e1->evaluate(x)+e2->evaluate(x);}
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
     double  evaluate(double x) override {return e1->evaluate(x)-e2->evaluate(x);}
 };
 class Mul :public Expression
 {
     Expression *e1,*e2;
 public:
     Mul( Expression *mnoj1,Expression *mnoj2){
         e1=mnoj1;
         e2=mnoj2;
     }
     Expression* diff() override
     {
         return new Add(new Mul(e1->diff(),e2),new Mul(e1,e2->diff()));
     }
     void print() override {
         //std::cout<<'(';
         e1->print();
         std::cout<<'*';
         e2->print();
         //std::cout<<')';
     }
     double  evaluate(double x) override {return e1->evaluate(x)*e2->evaluate(x);}
 };
 class Div :public Expression
 {
     Expression *e1,*e2;
 public:
     Div( Expression *mnoj1,Expression *mnoj2){
         e1=mnoj1;
         e2=mnoj2;
     }
     Expression* diff() override
     {
         return new Div(new Sub(new Mul(e1->diff(),e2),new Mul(e1,e2->diff())),new Mul(e2,e2));
     }
     void print() override {
         //std::cout<<'(';
         e1->print();
         std::cout<<'/';
         std::cout<<'(';
         e2->print();
         std::cout<<')';
     }
     double  evaluate(double x) override {return e1->evaluate(x)/e2->evaluate(x);}
 };

int main() {
    //Expression *e = new Sub(new Number(1), new Add(new Variable('x'),new Number(3)));
    //Expression *e=new Mul(new Variable('x'), new Add(new Variable('x'),new Number(3)));
    //Expression *e=new Div(new Number(2),new Variable('x'));
    Expression *e=new Div(new Sub(new Variable('x'),new Number(1)),new Add(new Variable('x'),new Number(5)));
    //Expression *e = read_expression("((x+1)*x)");
    e->print();
    float a = e->evaluate(0);
    std::cout <<a << "\n";
    Expression *de = e->diff();
    //de->print();
    std::cout << "\n";

    return 0;
}
