#include <iostream>
#include <vector>
using namespace std;

// Person Class: base class for all people in the problem, 
// has name, pointer to current match, matching preferences and virtual propose function
class Person{
    public:
        char name;
        Person* currentProposal;
        vector<Person*> preferences;
        //Attempts to match two people if they like each other more than current partners
        virtual void propose(Person &p){
        }
        //Default constructor: creates an empty person and an empty preferences vector
        Person(){
            preferences = vector<Person*>();
        }
};
// Man class: child class of Person that asks out people on its preferences list
class Man: public Person{
    public:
        //Non-default constructor: creates a single man named 'n'
        Man(char n){
            name = n;
            currentProposal = nullptr;     
        }
        //Proposes to first person in preferences and then deletes them from the vector.
        void propose(Person &p){
            preferences[0]->propose(*this);
            preferences.erase(preferences.begin());
        }
};
// Woman class: child class of Person that accepts or denies proposals
class Woman: public Person{
    public:
        //Non-default constructor: creates a single woman named 'n'
        Woman(char n){
            name = n;
            currentProposal = nullptr;
        }
        //Compares a proposal to current suitor (if any) and swaps if more preferred
        void propose(Person &m){
            if(currentProposal == nullptr){
                currentProposal = &m;
                m.currentProposal = this; 
            }
            else{
                for(Person* curr: preferences){
                    if((*curr).name==m.name){
                        (*currentProposal).currentProposal = nullptr;
                        *currentProposal = m;
                        m.currentProposal = this;
                        break;
                    }
                    if((*curr).name==currentProposal->name){
                        break;
                    }
                }
            } 
        }
};
//allAreCoupled function: checks if all the men are matched
bool allAreCoupled(Man* list[]){
    for (int i = 0; i < 3; i++)
    {
        if((*list[i]).currentProposal == nullptr) {return false;}
    }
    return true;
    
}
//match function: attempts to match every man with their top preference then checks if they're all matched
//if they are, the function ends, if not, the function repeats for single men
void match(Man* men[]){
    while(!allAreCoupled(men)){
        for (int i = 0; i < 3; i++)
        {
            if((*men[i]).currentProposal == nullptr) 
            {
                (men[i])->propose(*men[i]);
            }
        }
        
    }
    for (int i = 0; i < 3; i++)
        {
            /* code */
            cout<<(*men[i]).name<<", "<<(*men[i]).currentProposal->name<<endl;
    }
}

int main(){
    Man a('A');
    Man b('B');
    Man c('C');
    Woman one('1');
    Woman two('2');
    Woman three('3');
    //1st test case
    a.preferences = {&one,&two,&three};
    b.preferences = {&two,&three,&one};
    c.preferences = {&three,&one,&two};
    one.preferences = {&b,&a,&c};
    two.preferences = {&c,&b,&a};
    three.preferences = {&a,&c,&b};
    Man* men[] = {&a,&b,&c};
    match(men);
    
    //2nd test case
    a.currentProposal = nullptr;
    b.currentProposal = nullptr;
    c.currentProposal = nullptr;
    one.currentProposal = nullptr;
    two.currentProposal = nullptr;
    three.currentProposal = nullptr;
    a.preferences = {&one,&three,&two};
    b.preferences = {&three,&two,&one};
    c.preferences = {&two,&one,&three};
    one.preferences = {&a,&b,&c};
    two.preferences = {&b,&c,&a};
    three.preferences = {&c,&a,&b};
    match(men);

    //3rd test case
    a.currentProposal = nullptr;
    b.currentProposal = nullptr;
    c.currentProposal = nullptr;
    one.currentProposal = nullptr;
    two.currentProposal = nullptr;
    three.currentProposal = nullptr;
    a.preferences = {&three,&one,&two};
    b.preferences = {&one,&two,&three};
    c.preferences = {&two,&three,&one};
    one.preferences = {&c,&b,&a};
    two.preferences = {&a,&c,&b};
    three.preferences = {&b,&a,&c};
    match(men);

    //4th test case
    a.currentProposal = nullptr;
    b.currentProposal = nullptr;
    c.currentProposal = nullptr;
    one.currentProposal = nullptr;
    two.currentProposal = nullptr;
    three.currentProposal = nullptr;
    a.preferences = {&two,&one,&three};
    b.preferences = {&one,&three,&two};
    c.preferences = {&three,&two,&one};
    one.preferences = {&b,&c,&a};
    two.preferences = {&a,&b,&c};
    three.preferences = {&c,&a,&b};
    match(men);

    return 0;
}