#define redspeed 5



class Player{
      private:
     //protected:
      BITMAP* redbox;       
      int rx,ry;  //redbox x and redbox y 
      int death;  
    
    
//    public: 
     
      
      public:
    
     Player(): rx(0),ry(250),death(0) {}
   //   player(): rx(0),ry(250),death(0),redbox(load_bitmap("redb.bmp",NULL)) {}
     
     
     void setrb(BITMAP* rb){
          redbox=rb;
          }
     
     
     
     
     BITMAP* getrb(){
          return redbox;
          }
     
     int getrx(){
          return rx;
          }
        
     int getry(){
         return ry;
         }   
             
     void moveup(){
          if(ry>-25)
          ry-=redspeed;
          
          }        
      
      void movedown(){
           if(ry<540)
          ry+=redspeed;
          }
      
      void moveleft(){
           if(rx>-35)
          rx-=redspeed;
          }
          
      void moveright(){
           if(rx<735)
          rx+=redspeed;
          }    
          
          
       void setback(){
            rx=0;
            ry=250;
            }   
     //player movements     
      
      void operator ++(){
      death++;
      }     
      
      int showdeath(){
      return death;
      }
 
};  ///////////////////////////////   CLASS PLAYER
