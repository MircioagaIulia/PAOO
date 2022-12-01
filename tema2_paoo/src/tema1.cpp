#include<iostream>

class Laptop
{
  protected:
        char *device_name;
        int id_laptop;
        int RAM;
        char *processor;
        int pret;
  public:
        Laptop(char* device_name, int id_laptop, int RAM, char* processor);
        Laptop& operator=(const Laptop &laptop);
        Laptop(const Laptop& laptop);
        ~Laptop();

        Laptop()=delete;


    void set_pret(int pret);
    void set_pret(float pret);
    void set_pret(int pret, int reducere);
 
    void print();
};



Laptop:: Laptop(char* device_name, int id_laptop, int RAM, char* processor){
          this->device_name=device_name;
          this->id_laptop=id_laptop;
          this->RAM=RAM;
          this->processor=processor;
          std::cout<<"Constructor Laptop "<<std::endl;
        }



Laptop& Laptop:: operator=(const Laptop& laptop){
    	 if( this != &laptop ){   //self assignment check
          this->device_name=laptop.device_name;
          this->id_laptop=laptop.id_laptop;
          this->RAM=laptop.RAM;
          this->processor=laptop.processor;
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
    std::cout<<"Device name:  "<<this->device_name<<" \n"<<"Id laptop: "<<this->id_laptop<<" \n"<<"RAM: "<<this->RAM<<" GB"<<" \n"<<"Processor: "<<this->processor<<" \n\n";
}

class Laptop_gaming:public Laptop{
protected: 
  int refresh_rate;
  char *GPU;

  
  public:
  Laptop_gaming(char *device_name, int id_laptop, int RAM, char *processor, int refresh_rate, char* GPU);
  Laptop_gaming& operator=(const Laptop_gaming &laptop_gaming);
  Laptop_gaming(const Laptop_gaming& laptop_gaming);
  ~Laptop_gaming();

   Laptop_gaming()=delete;

   void print();
   

};

Laptop_gaming:: Laptop_gaming(char *device_name, int id_laptop, int RAM, char *processor, int refresh_rate, char* GPU):Laptop(device_name, id_laptop, RAM, processor){
    
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
    std::cout<<"Device name:  "<<this->device_name<<" \n"<<"Id laptop: "<<this->id_laptop<<" \n"<<"RAM: "<<this->RAM<<" GB"<<" \n"<<"Processor: "<<this->processor<<" \n";
    std::cout<<"Refresh_rate "<<this->refresh_rate<<" Hz \n"<<"GPU "<<this->GPU<<" \n\n";

}

class Laptop_2_in_1: public Laptop{
    protected:
    bool touchscreen;
    public:
    Laptop_2_in_1(char *device_name, int id_laptop, int RAM, char *processor, bool touchscreen);
    Laptop_2_in_1& operator=(const Laptop_2_in_1& laptop_2_in_1);
    Laptop_2_in_1(const Laptop_2_in_1& laptop_2_in_1);

   ~Laptop_2_in_1();
   Laptop_2_in_1()=delete;

 
    void print();
 };

Laptop_2_in_1:: Laptop_2_in_1(char *device_name, int id_laptop, int RAM, char *processor, bool touchscreen):Laptop(device_name, id_laptop, RAM, processor){
   
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
     std::cout<<"Device name:  "<<this->device_name<<" \n"<<"Id laptop: "<<this->id_laptop<<" \n"<<"RAM: "<<this->RAM<<" GB"<<" \n"<<"Processor: "<<this->processor<<" \n";
     std::cout<<"Touchscreen "<<this->touchscreen<<" \n";
 
 }



int main()
{ 
   Laptop l("TLMP208W", 125, 8, "Intel I7");
   l.print();
   l.set_pret(1200);
   l.set_pret(1200, 90);

   Laptop l3("TMPL600W", 127, 16, "Intel I5");
   l3=l3;  //verify self assignment
   l3.print();

   Laptop l4(l); //call copy constructor
   l4.print();
   l4.set_pret(5220);

   Laptop l5=l4; //call copy constructor
   l5.print();
   l4.set_pret(100);


 


 
   Laptop_gaming lg2 ("TMPL700W", 157, 8, "Intel I5", 60, "AMD");
   lg2.print();
   lg2.set_pret(7000);
   Laptop_gaming lg3(lg2);
   lg3.print();


   Laptop_gaming lg4 ("TMPL5036A", 125, 6, "Intel I3", 52, "nVidia");
   lg4.print();
   Laptop l10=lg4; // call copy assignment for Laptop
   l10.print();
  
   lg4=lg2;  //call assignment constructor Laptop_gaming
   lg4=lg4; //handle self assignment
   
   Laptop_gaming* lg=new Laptop_gaming("TMPL600W", 127, 16, "Intel I5", 60, "nVidia");
   lg->print();
   lg->set_pret(2570);
   
   

   

   Laptop_2_in_1* l2=new Laptop_2_in_1("TMPL850W", 400, 4, "Intel I3", true);
   l2->print();
   l2->set_pret(6000);
   
   Laptop_2_in_1 l22 ("TMPL002W", 600, 16, "Intel I7", false);
   l22.print();
   l22.set_pret(2560, 160);

   Laptop_2_in_1 l23=l22;
   l23.print();
   l23.set_pret(2900);

   Laptop_2_in_1 l24(l23);
   l24.print();

   Laptop_2_in_1 l25 ("TMPL580W", 800, 16, "Intel I6", true);
   l22=l25;
   l22.print();
   l22.set_pret(8500);
   l25=l25;
 
    
}
