#include<iostream>
#include<mutex>
#include<memory>

class Uncopyable {
 protected: 
    Uncopyable() {} 
    ~Uncopyable() {} 
 private:
    Uncopyable(const Uncopyable&); 
    Uncopyable& operator=(const Uncopyable&);
};



class Laptop
{
  protected:
        char *device_name;
        int id_laptop;
        int RAM;
        char *processor;
        int pret;
        bool locked;
        
  public:
        Laptop(char* device_name, int id_laptop, int RAM, char* processor, bool locked);
        Laptop& operator=(const Laptop &laptop);
        Laptop(const Laptop& laptop);
        ~Laptop();

        Laptop()=delete;


    void set_pret(int pret);
    void set_pret(float pret);
    void set_pret(int pret, int reducere);
    bool get_laptop_locked();
    void set_laptop_locked(bool locked);
 
    void print();
};



Laptop:: Laptop(char* device_name, int id_laptop, int RAM, char* processor, bool locked){
          this->device_name=device_name;
          this->id_laptop=id_laptop;
          this->RAM=RAM;
          this->processor=processor;
          this->locked=locked;
          std::cout<<"Constructor Laptop "<<std::endl;
        }



Laptop& Laptop:: operator=(const Laptop& laptop){
    	 if( this != &laptop ){   //self assignment check
          this->device_name=laptop.device_name;
          this->id_laptop=laptop.id_laptop;
          this->RAM=laptop.RAM;
          this->processor=laptop.processor;
          this->locked=locked;
    std::cout<<"Assignment constructor Laptop"<<std::endl;
         }
         else
    std::cout<<"Self assignment"<<std::endl;
    return *this;
}


Laptop::Laptop(const Laptop &laptop){
          this->device_name=laptop.device_name;
          this->id_laptop=laptop.id_laptop;
          this->RAM=laptop.RAM;
          this->processor=laptop.processor;
          this->locked=locked;
    std::cout<<"Copy constructor laptop"<<std::endl;
}

Laptop:: ~Laptop(){
           std::cout<<"Apel destructor Laptop "<<std::endl;
}
   
void Laptop:: set_pret(int pret){
       this->pret=pret;
       std::cout<<"Laptopul "<<this->device_name<<" costa "<<pret<<" lei"<<"\n";
}    

void Laptop:: set_pret(float pret){
       this->pret=pret;
       std::cout<<"Laptopul "<<this->device_name<<" costa "<<pret<<" lei"<<"\n";
}    

void Laptop:: set_pret(int pret, int reducere){
       this->pret=pret-reducere;
       std::cout<<"Laptopul "<<this->device_name<<" costa "<<this->pret<<" lei"<<"\n\n";
}  

void Laptop:: print(){
    std::cout<<"Device name:  "<<this->device_name<<" \n"<<"Id laptop: "<<this->id_laptop<<" \n"<<"RAM: "<<this->RAM<<" GB"<<" \n"<<"Processor: "<<this->processor<<"\n"<<"Is locked: "<<this->locked<< "\n\n";
}

bool Laptop:: get_laptop_locked(){
    return locked;
}

void Laptop:: set_laptop_locked(bool locked){
    this->locked=locked;
}

void lock(Laptop& laptop){
    laptop.set_laptop_locked(true);
    std::cout<<"Laptop locked"<<std::endl;
}

void unlock(Laptop& laptop){
    laptop.set_laptop_locked(false);
    std::cout<<"Laptop unlocked"<<std::endl;
}


class Laptop_gaming:public Laptop{
protected: 
  int refresh_rate;
  char *GPU;

  
  public:
  Laptop_gaming(char *device_name, int id_laptop, int RAM, char *processor, bool locked, int refresh_rate, char* GPU);
  Laptop_gaming& operator=(const Laptop_gaming &laptop_gaming);
  Laptop_gaming(const Laptop_gaming& laptop_gaming);
  ~Laptop_gaming();

   Laptop_gaming()=delete;

   void print();
   

};

Laptop_gaming:: Laptop_gaming(char *device_name, int id_laptop, int RAM, char *processor, bool locked, int refresh_rate, char* GPU):Laptop(device_name, id_laptop, RAM, processor, locked){
    
    this->refresh_rate=refresh_rate;
    this->GPU=GPU;
    std::cout<<"Constructor Laptop gaming \n";
 }


Laptop_gaming& Laptop_gaming:: operator=(const Laptop_gaming& laptop_gaming){
    	 if( this != &laptop_gaming ){   //self assignment check
          this->refresh_rate=laptop_gaming.refresh_rate;
          this->GPU=laptop_gaming.GPU;
          
    std::cout<<"Assignment constructor Laptop_gaming"<<std::endl;
         }
         else
    std::cout<<"Self assignment for Laptop_gaming"<<std::endl;
    return *this;
}


Laptop_gaming::Laptop_gaming(const Laptop_gaming &laptop_gaming):Laptop(laptop_gaming){
          this->refresh_rate=laptop_gaming.refresh_rate;
          this->GPU=laptop_gaming.GPU;
    std::cout<<"Copy constructor Laptop_gaming"<<std::endl;
}

Laptop_gaming:: ~Laptop_gaming(){
     std::cout<<"Apel destructor Laptop_gaming "<<std::endl;
  };


void Laptop_gaming:: print(){
    std::cout<<"Device name:  "<<this->device_name<<" \n"<<"Id laptop: "<<this->id_laptop<<" \n"<<"RAM: "<<this->RAM<<" GB"<<" \n"<<"Processor: "<<this->processor<<" \n"<<"Is locked: "<<this->locked<<"\n";
    std::cout<<"Refresh_rate "<<this->refresh_rate<<" Hz \n"<<"GPU "<<this->GPU<<" \n\n";

}

class Laptop_2_in_1: public Laptop{
    protected:
    bool touchscreen;
    public:
    Laptop_2_in_1(char *device_name, int id_laptop, int RAM, char *processor, bool locked, bool touchscreen);
    Laptop_2_in_1& operator=(const Laptop_2_in_1& laptop_2_in_1);
    Laptop_2_in_1(const Laptop_2_in_1& laptop_2_in_1);

   ~Laptop_2_in_1();
   Laptop_2_in_1()=delete;

 
    void print();
 };

Laptop_2_in_1:: Laptop_2_in_1(char *device_name, int id_laptop, int RAM, char *processor, bool locked, bool touchscreen):Laptop(device_name, id_laptop, RAM, processor, locked){
   
    this->touchscreen=touchscreen;
    std::cout<<"Constructor Laptop 2 in 1\n";
 }

Laptop_2_in_1& Laptop_2_in_1::operator=(const Laptop_2_in_1& laptop_2_in_1){
    if(this!=&laptop_2_in_1){ //self assignment check
        this->touchscreen=laptop_2_in_1.touchscreen;
        std::cout<<"Assignment constructor Laptop_2_in_1"<<std::endl;
    }else{
        std::cout<<"Seft assignemnt for Laptop_2_in_1"<<std::endl;
    }
    return *this;
}

Laptop_2_in_1:: Laptop_2_in_1(const Laptop_2_in_1& laptop_2_in_1):Laptop(laptop_2_in_1){
    this->touchscreen=laptop_2_in_1.touchscreen;
    std::cout<<"Copy constructor for Laptop_2_in_1"<<std::endl;
}


Laptop_2_in_1:: ~Laptop_2_in_1(){
     std::cout<<"Apel destructor Laptop_2_in_1"<<std::endl;
}
   

 
void Laptop_2_in_1:: print(){
     std::cout<<"Device name:  "<<this->device_name<<" \n"<<"Id laptop: "<<this->id_laptop<<" \n"<<"RAM: "<<this->RAM<<" GB"<<" \n"<<"Processor: "<<this->processor<<"\n"<<"Is locked: "<<this->locked<<" \n";
     std::cout<<"Touchscreen "<<this->touchscreen<<" \n";
 
 }



class Lock:private Uncopyable{
 private:
        Laptop& laptopPtr;
    public:
        Lock(Laptop& ptr): laptopPtr(ptr) {
            lock(laptopPtr);
            
        }
        ~Lock() {
            unlock(laptopPtr);
            
        }
}; 


int main()
{  
    //item 13. Use objects to manage resources
    //auto_ptr smart pointer 
     
    std::auto_ptr <Laptop> laptop1(new Laptop("TLMP208W", 125, 8, "Intel I7", false));  //laptop1 points to the object returned from Laptop
    std::auto_ptr <Laptop> laptop2(new Laptop("TMPL600W", 127, 16, "Intel I5", false));    //laptop2 points now to the object, laptop1 is null
    laptop1->print();
    laptop2->print();

    laptop1=laptop2;   //laptop1 points to the object, laptop2 is null
    // laptop2->print();  it is illegal to attempt print method because leptop2 pointer isn't pointing to the second object anymore

    laptop1->print();
    


    std::auto_ptr <Laptop_gaming> laptop_gaming1(new Laptop_gaming("TMPL700W", 157, 8, "Intel I5", false, 60, "AMD"));  //laptop_gaming1 points to the object returned from Laptop_gaming
    std::auto_ptr <Laptop_gaming> laptop_gaming2(new Laptop_gaming("TMPL750W", 200, 4, "Intel I3", false, 40, "AMD"));    //laptop_gaming2 points now to the object, laptop_gaming1 is null
    laptop_gaming1->print();
    laptop_gaming2->print();

    laptop_gaming1=laptop_gaming2;   //laptop_gaming1 points to the object, laptop_gaming2 is ull

    // laptop_gaming2->print();  //it is illegal to attempt print method because leptop_gaming2 pointer isn't pointing to the second object anymore

    laptop_gaming1->print();
    



    //shared_ptr smart pointer

    std::shared_ptr <Laptop> laptop3(new Laptop("TLMP244W", 120, 8, "Intel I3", true));   //laptop3 points to the object returned from Laptop
    std::shared_ptr <Laptop> laptop4(new Laptop("TMPL257W", 127, 16, "Intel I5", true));   //both laptop3 and laptop 4 now points to the object
    laptop3->print();
    laptop4->print();

    laptop3=laptop4;

    laptop3->print();  
    laptop4->print();
      


    std::shared_ptr <Laptop_2_in_1> laptop_2_in_1_first(new Laptop_2_in_1("TMPL770W", 480, 6, "Intel I5", false,  true));   //laptop_2_in_1_first points to the object returned from Laptop_2_in_1
    std::shared_ptr <Laptop_2_in_1> laptop_2_in_1_second(new Laptop_2_in_1("TMPL260W", 207, 32, "Intel I5", false, false));   //both laptop_2_in_1_first and laptop_2_in_1_second now points to the object
    laptop_2_in_1_first->print();
    laptop_2_in_1_second->print();

    laptop_2_in_1_first=laptop_2_in_1_second;

    laptop_2_in_1_first->print();  
    laptop_2_in_1_second->print();


    //item 14.  Think carefully about copying behavior in resource-managing classes.


   
    Laptop lpt("TLMP208W", 125, 8, "Intel I7", false);
    std::cout<<lpt.get_laptop_locked()<<std::endl;
    Lock lpt2(lpt);
    std::cout<<lpt.get_laptop_locked()<<std::endl;


    Laptop_gaming lptg("TMPL5036A", 125, 6, "Intel I3", false,  52, "nVidia");
    std::cout<<lptg.get_laptop_locked()<<std::endl;
    Lock lptg2(lptg);
    std::cout<<lptg.get_laptop_locked()<<std::endl;
   

   
   /*
   Laptop l("TLMP208W", 125, 8, "Intel I7", false);
   l.print();
   l.set_pret(1200);
   l.set_pret(1200, 90);

   Laptop l3("TMPL600W", 127, 16, "Intel I5", false);
   l3=l3;  //verify self assignment
   l3.print();

   Laptop l4(l); //call copy constructor
   l4.print();
   l4.set_pret(5220);

   Laptop l5=l4; //call copy constructor
   l5.print();
   l4.set_pret(100);


 


 
   Laptop_gaming lg2 ("TMPL700W", 157, 8, "Intel I5", false,  60, "AMD");
   lg2.print();
   lg2.set_pret(7000);
   Laptop_gaming lg3(lg2);
   lg3.print();


   Laptop_gaming lg4 ("TMPL5036A", 125, 6, "Intel I3", false,  52, "nVidia");
   lg4.print();
   Laptop l10=lg4; // call copy assignment for Laptop
   l10.print();
  
   lg4=lg2;  //call assignment constructor Laptop_gaming
   lg4=lg4; //handle self assignment
   
   Laptop_gaming* lg=new Laptop_gaming("TMPL600W", 127, 16, "Intel I5", false, 60, "nVidia");
   lg->print();
   lg->set_pret(2570);
   
   

   

   Laptop_2_in_1* l2=new Laptop_2_in_1("TMPL850W", 400, 4, "Intel I3", false, true);
   l2->print();
   l2->set_pret(6000);
   
   Laptop_2_in_1 l22 ("TMPL002W", 600, 16, "Intel I7", false, false);
   l22.print();
   l22.set_pret(2560, 160);

   Laptop_2_in_1 l23=l22;
   l23.print();
   l23.set_pret(2900);

   Laptop_2_in_1 l24(l23);
   l24.print();

   Laptop_2_in_1 l25 ("TMPL580W", 800, 16, "Intel I6", false, true);
   l22=l25;
   l22.print();
   l22.set_pret(8500);
   l25=l25;
 
    */
}