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
        Laptop(char* device_name, int id_laptop, int RAM, char* processor){
          this->device_name=device_name;
          this->id_laptop=id_laptop;
          this->RAM=RAM;
          this->processor=processor;
          std::cout<<"Constructor Laptop "<<std::endl;
        }
        ~Laptop(){
           std::cout<<"Apel destructor Laptop "<<std::endl;
        }


         Laptop()=delete;


    void set_pret(int pret){
       this->pret=pret;
       std::cout<<"Laptopul "<<this->device_name<<" costa "<<pret<<" lei"<<"\n\n";
       

    }    
 
  void print(){
    std::cout<<"Device name:  "<<this->device_name<<" \n"<<"Id laptop: "<<this->id_laptop<<" \n"<<"RAM: "<<this->RAM<<" GB"<<" \n"<<"Processor: "<<this->processor<<" \n\n";
 }
  

};

class Laptop_gaming:public Laptop{
protected: 
  int refresh_rate;
  char *GPU;

  
  public:
  Laptop_gaming(char *device_name, int id_laptop, int RAM, char *processor, int refresh_rate, char* GPU):Laptop(device_name, id_laptop, RAM, processor){
    
    this->refresh_rate=refresh_rate;
    this->GPU=GPU;
    std::cout<<"Constructor Laptop gaming \n";
 }

   Laptop_gaming()=delete;

  void print(){
    std::cout<<"Device name:  "<<this->device_name<<" \n"<<"Id laptop: "<<this->id_laptop<<" \n"<<"RAM: "<<this->RAM<<" GB"<<" \n"<<"Processor: "<<this->processor<<" \n";
    std::cout<<"Refresh_rate "<<this->refresh_rate<<" Hz \n"<<"GPU "<<this->GPU<<" \n\n";

 }

  ~Laptop_gaming(){
     std::cout<<"Apel destructor Laptop_gaming "<<std::endl;
  };
   

};

class Laptop_2_in_1: public Laptop{
    protected:
    bool touchscreen;
    public:
    Laptop_2_in_1(char *device_name, int id_laptop, int RAM, char *processor, bool touchscreen):Laptop(device_name, id_laptop, RAM, processor){
    
    this->touchscreen=touchscreen;
    std::cout<<"Constructor Laptop 2 in 1\n";
 }
 ~Laptop_2_in_1(){
     std::cout<<"Apel destructor Laptop_2_in_1"<<std::endl;
  };
   Laptop_2_in_1()=delete;

 
  void print(){
     std::cout<<"Device name:  "<<this->device_name<<" \n"<<"Id laptop: "<<this->id_laptop<<" \n"<<"RAM: "<<this->RAM<<" GB"<<" \n"<<"Processor: "<<this->processor<<" \n";
     std::cout<<"Touchscreen "<<this->touchscreen<<" \n";
 
 }
 };
 class Laptop_copie{
   public:
   int nr;
   public:
   Laptop_copie(int nr){
      this->nr=nr;
   };
   ~Laptop_copie(){
      std::cout<<"destructor";
   }
   void afisare(){
      std::cout<<"ana are mere ";
 }}
 ;

int main()
{ Laptop* l=new Laptop("TLMP208W", 125, 8, "Intel I7");
   l->print();
   l->set_pret(1200);

   Laptop_gaming* lg=new Laptop_gaming("TMPL600W", 127, 16, "Intel I5", 60, "nVidia");
   lg->print();
   lg->set_pret(2570);

   Laptop_gaming lg2 ("TMPL600W", 127, 16, "Intel I5", 60, "AMD");
   lg->print();
   lg->set_pret(7000);

   Laptop_2_in_1* l2=new Laptop_2_in_1("TMPL850W", 400, 4, "Intel I3", true);
   l2->print();
   l2->set_pret(6000);
   
   Laptop_2_in_1 l22 ("TMPL002W", 600, 16, "Intel I7", false);
   l2->print();
   l2->set_pret(8500);
   
   

 
    
}
