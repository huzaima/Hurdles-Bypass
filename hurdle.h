#define bluespeed 7
class Hurdle{
     
     
     private:
     //const int bluespeed;
     BITMAP* bluebox;
     
     public: 
          bool col;   
          bool rl,ll;   
          bool ul,dl;
          
     protected:
               
       int bx,by;
     
     
       
       public:
        
             
     void setbb(BITMAP* bb){
          bluebox=bb;
          }
      
     BITMAP* getbb(){
             return bluebox;
             }   
        
      void setbpos(int x,int y){
           bx=x;
           by=y;
           }  
      
     void setbypos(int y){
          by=y;
          } 
        
     void setbxpos(int x){
          bx=x;
          }   
        
       int getbx(){
           return bx;
            } 
              
      int getby(){
           return by;
           }      
           
           
       int upperloop(int y){
            
            if(rl){
   if(y<570)          
   y=y+bluespeed;
   if(y>=570){
   rl=false;
   ll=true;           
   }
   
   }//outer right loop
   
   if(ll){
   y=y-bluespeed;
   if(y<=0){
    ll=false;
    rl=true;          
   }// iner loop  
     
   }// outer left loop 
            return y;
            }    
  
  int sideloop(int x){
            
            if(ul){
   if(x<630)          
   x=x+bluespeed;
   if(x>=630){
   ul=false;
   dl=true;           
   }
   
   }//outer right loop
   
   if(dl){
   x=x-bluespeed;
   if(x<=90){
    dl=false;
    ul=true;          
   }// iner loop  
     
   }// outer left loop 
            return x;
            }
  
  
           
      };
